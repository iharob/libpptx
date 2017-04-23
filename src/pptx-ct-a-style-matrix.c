#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-style-matrix.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-fill-style-list.h>
#include <private/pptx-ct-a-line-style-list.h>
#include <private/pptx-ct-a-effect-style-list.h>
#include <private/pptx-ct-a-background-fill-style-list.h>

typedef struct pptx_ct_a_style_matrix_s {
    pptx_ct_a_fill_style_list *fill_style_lst;
    pptx_ct_a_line_style_list *ln_style_lst;
    pptx_ct_a_effect_style_list *effect_style_lst;
    pptx_ct_a_background_fill_style_list *bg_fill_style_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_a_style_matrix;

pptx_ct_a_style_matrix *
pptx_ct_a_style_matrix_new(xmlNode *node)
{
    pptx_ct_a_style_matrix *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillStyleLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_style_lst = NULL;
        } else {
            obj->fill_style_lst = pptx_ct_a_fill_style_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_style_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnStyleLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_style_lst = NULL;
        } else {
            obj->ln_style_lst = pptx_ct_a_line_style_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_style_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectStyleLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_style_lst = NULL;
        } else {
            obj->effect_style_lst = pptx_ct_a_effect_style_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_style_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bgFillStyleLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bg_fill_style_lst = NULL;
        } else {
            obj->bg_fill_style_lst = pptx_ct_a_background_fill_style_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bg_fill_style_lst = NULL;
    }
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_fill_style_list *
pptx_ct_a_style_matrix_get_fill_style_lst(const pptx_ct_a_style_matrix *const obj)
{
    return obj->fill_style_lst;
}

pptx_ct_a_line_style_list *
pptx_ct_a_style_matrix_get_ln_style_lst(const pptx_ct_a_style_matrix *const obj)
{
    return obj->ln_style_lst;
}

pptx_ct_a_effect_style_list *
pptx_ct_a_style_matrix_get_effect_style_lst(const pptx_ct_a_style_matrix *const obj)
{
    return obj->effect_style_lst;
}

pptx_ct_a_background_fill_style_list *
pptx_ct_a_style_matrix_get_bg_fill_style_lst(const pptx_ct_a_style_matrix *const obj)
{
    return obj->bg_fill_style_lst;
}

pptx_string 
pptx_ct_a_style_matrix_get_name(const pptx_ct_a_style_matrix *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_style_matrix_get_index(pptx_ct_a_style_matrix *obj)
{
    return obj->index;
}

void
pptx_ct_a_style_matrix_free(pptx_ct_a_style_matrix *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_fill_style_list_free(obj->fill_style_lst);
    pptx_ct_a_line_style_list_free(obj->ln_style_lst);
    pptx_ct_a_effect_style_list_free(obj->effect_style_lst);
    pptx_ct_a_background_fill_style_list_free(obj->bg_fill_style_lst);
    xmlFree(obj->name);
    free(obj);
}