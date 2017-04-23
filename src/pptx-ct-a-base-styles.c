#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-base-styles.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color-scheme.h>
#include <private/pptx-ct-a-font-scheme.h>
#include <private/pptx-ct-a-style-matrix.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_base_styles_s {
    pptx_ct_a_color_scheme *clr_scheme;
    pptx_ct_a_font_scheme *font_scheme;
    pptx_ct_a_style_matrix *fmt_scheme;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_base_styles;

pptx_ct_a_base_styles *
pptx_ct_a_base_styles_new(xmlNode *node)
{
    pptx_ct_a_base_styles *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrScheme");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_scheme = NULL;
        } else {
            obj->clr_scheme = pptx_ct_a_color_scheme_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_scheme = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fontScheme");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->font_scheme = NULL;
        } else {
            obj->font_scheme = pptx_ct_a_font_scheme_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->font_scheme = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fmtScheme");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fmt_scheme = NULL;
        } else {
            obj->fmt_scheme = pptx_ct_a_style_matrix_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fmt_scheme = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color_scheme *
pptx_ct_a_base_styles_get_clr_scheme(const pptx_ct_a_base_styles *const obj)
{
    return obj->clr_scheme;
}

pptx_ct_a_font_scheme *
pptx_ct_a_base_styles_get_font_scheme(const pptx_ct_a_base_styles *const obj)
{
    return obj->font_scheme;
}

pptx_ct_a_style_matrix *
pptx_ct_a_base_styles_get_fmt_scheme(const pptx_ct_a_base_styles *const obj)
{
    return obj->fmt_scheme;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_base_styles_get_ext_lst(const pptx_ct_a_base_styles *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_base_styles_get_index(pptx_ct_a_base_styles *obj)
{
    return obj->index;
}

void
pptx_ct_a_base_styles_free(pptx_ct_a_base_styles *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_color_scheme_free(obj->clr_scheme);
    pptx_ct_a_font_scheme_free(obj->font_scheme);
    pptx_ct_a_style_matrix_free(obj->fmt_scheme);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}