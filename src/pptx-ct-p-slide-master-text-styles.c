#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-master-text-styles.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-list-style.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_slide_master_text_styles_s {
    pptx_ct_a_text_list_style *title_style;
    pptx_ct_a_text_list_style *body_style;
    pptx_ct_a_text_list_style *other_style;
    pptx_ct_p_extension_list *ext_lst;
    int32_t index;
} pptx_ct_p_slide_master_text_styles;

pptx_ct_p_slide_master_text_styles *
pptx_ct_p_slide_master_text_styles_new(xmlNode *node)
{
    pptx_ct_p_slide_master_text_styles *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:titleStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->title_style = NULL;
        } else {
            obj->title_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->title_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bodyStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->body_style = NULL;
        } else {
            obj->body_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->body_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:otherStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->other_style = NULL;
        } else {
            obj->other_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->other_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_list_style *
pptx_ct_p_slide_master_text_styles_get_title_style(const pptx_ct_p_slide_master_text_styles *const obj)
{
    return obj->title_style;
}

pptx_ct_a_text_list_style *
pptx_ct_p_slide_master_text_styles_get_body_style(const pptx_ct_p_slide_master_text_styles *const obj)
{
    return obj->body_style;
}

pptx_ct_a_text_list_style *
pptx_ct_p_slide_master_text_styles_get_other_style(const pptx_ct_p_slide_master_text_styles *const obj)
{
    return obj->other_style;
}

pptx_ct_p_extension_list *
pptx_ct_p_slide_master_text_styles_get_ext_lst(const pptx_ct_p_slide_master_text_styles *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_p_slide_master_text_styles_get_index(pptx_ct_p_slide_master_text_styles *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_master_text_styles_free(pptx_ct_p_slide_master_text_styles *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_list_style_free(obj->title_style);
    pptx_ct_a_text_list_style_free(obj->body_style);
    pptx_ct_a_text_list_style_free(obj->other_style);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}