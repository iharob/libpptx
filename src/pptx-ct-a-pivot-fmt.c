#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-pivot-fmt.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-marker.h>
#include <private/pptx-ct-a-dlbl.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_pivot_fmt_s {
    pptx_uint idx;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *tx_pr;
    pptx_ct_a_marker *marker;
    pptx_ct_a_dlbl *d_lbl;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_pivot_fmt;

pptx_ct_a_pivot_fmt *
pptx_ct_a_pivot_fmt_new(xmlNode *node)
{
    pptx_ct_a_pivot_fmt *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->idx = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:idx");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_pr = NULL;
        } else {
            obj->tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:marker");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->marker = NULL;
        } else {
            obj->marker = pptx_ct_a_marker_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->marker = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLbl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->d_lbl = NULL;
        } else {
            obj->d_lbl = pptx_ct_a_dlbl_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->d_lbl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_pivot_fmt_get_idx(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->idx;
}

pptx_ct_a_shape_properties *
pptx_ct_a_pivot_fmt_get_sp_pr(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_pivot_fmt_get_tx_pr(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->tx_pr;
}

pptx_ct_a_marker *
pptx_ct_a_pivot_fmt_get_marker(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->marker;
}

pptx_ct_a_dlbl *
pptx_ct_a_pivot_fmt_get_d_lbl(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->d_lbl;
}

pptx_ct_a_extension_list *
pptx_ct_a_pivot_fmt_get_ext_lst(const pptx_ct_a_pivot_fmt *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_pivot_fmt_get_index(pptx_ct_a_pivot_fmt *obj)
{
    return obj->index;
}

void
pptx_ct_a_pivot_fmt_free(pptx_ct_a_pivot_fmt *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->tx_pr);
    pptx_ct_a_marker_free(obj->marker);
    pptx_ct_a_dlbl_free(obj->d_lbl);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}