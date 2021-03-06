#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dsp-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-dsp-shape-non-visual.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-shape-style.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-transform-2d.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_dsp_shape_s {
    pptx_ct_dsp_shape_non_visual *nv_sp_pr;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_shape_style *style;
    pptx_ct_a_text_body *tx_body;
    pptx_ct_a_transform_2d *tx_xfrm;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string model_id;
    int32_t index;
} pptx_ct_dsp_shape;

pptx_ct_dsp_shape *
pptx_ct_dsp_shape_new(xmlNode *node)
{
    pptx_ct_dsp_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:nvSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_sp_pr = NULL;
        } else {
            obj->nv_sp_pr = pptx_ct_dsp_shape_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:spPr");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:style");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:txBody");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:txXfrm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_xfrm = NULL;
        } else {
            obj->tx_xfrm = pptx_ct_a_transform_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_xfrm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:extLst");
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
    obj->model_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "modelId");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dsp_shape_non_visual *
pptx_ct_dsp_shape_get_nv_sp_pr(const pptx_ct_dsp_shape *const obj)
{
    return obj->nv_sp_pr;
}

pptx_ct_a_shape_properties *
pptx_ct_dsp_shape_get_sp_pr(const pptx_ct_dsp_shape *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_shape_style *
pptx_ct_dsp_shape_get_style(const pptx_ct_dsp_shape *const obj)
{
    return obj->style;
}

pptx_ct_a_text_body *
pptx_ct_dsp_shape_get_tx_body(const pptx_ct_dsp_shape *const obj)
{
    return obj->tx_body;
}

pptx_ct_a_transform_2d *
pptx_ct_dsp_shape_get_tx_xfrm(const pptx_ct_dsp_shape *const obj)
{
    return obj->tx_xfrm;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dsp_shape_get_ext_lst(const pptx_ct_dsp_shape *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dsp_shape_get_model_id(const pptx_ct_dsp_shape *const obj)
{
    return obj->model_id;
}

int32_t
pptx_ct_dsp_shape_get_index(pptx_ct_dsp_shape *obj)
{
    return obj->index;
}

void
pptx_ct_dsp_shape_free(pptx_ct_dsp_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dsp_shape_non_visual_free(obj->nv_sp_pr);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_shape_style_free(obj->style);
    pptx_ct_a_text_body_free(obj->tx_body);
    pptx_ct_a_transform_2d_free(obj->tx_xfrm);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->model_id);
    free(obj);
}