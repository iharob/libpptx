#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-shape-non-visual.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-shape-style.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_shape_s {
    pptx_ct_p_shape_non_visual *nv_sp_pr;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_shape_style *style;
    pptx_ct_a_text_body *tx_body;
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_bool use_bg_fill;
    int32_t index;
} pptx_ct_p_shape;

pptx_ct_p_shape *
pptx_ct_p_shape_new(xmlNode *node)
{
    pptx_ct_p_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:nvSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_sp_pr = NULL;
        } else {
            obj->nv_sp_pr = pptx_ct_p_shape_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:style");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->style = NULL;
        } else {
            obj->style = pptx_ct_a_shape_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:txBody");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_body = NULL;
        } else {
            obj->tx_body = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_body = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->use_bg_fill = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useBgFill");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_shape_non_visual *
pptx_ct_p_shape_get_nv_sp_pr(const pptx_ct_p_shape *const obj)
{
    return obj->nv_sp_pr;
}

pptx_ct_a_shape_properties *
pptx_ct_p_shape_get_sp_pr(const pptx_ct_p_shape *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_shape_style *
pptx_ct_p_shape_get_style(const pptx_ct_p_shape *const obj)
{
    return obj->style;
}

pptx_ct_a_text_body *
pptx_ct_p_shape_get_tx_body(const pptx_ct_p_shape *const obj)
{
    return obj->tx_body;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_shape_get_ext_lst(const pptx_ct_p_shape *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_shape_get_use_bg_fill(const pptx_ct_p_shape *const obj)
{
    return obj->use_bg_fill;
}

int32_t
pptx_ct_p_shape_get_index(pptx_ct_p_shape *obj)
{
    return obj->index;
}

void
pptx_ct_p_shape_free(pptx_ct_p_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_shape_non_visual_free(obj->nv_sp_pr);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_shape_style_free(obj->style);
    pptx_ct_a_text_body_free(obj->tx_body);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}