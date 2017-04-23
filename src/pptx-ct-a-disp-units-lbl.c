#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-disp-units-lbl.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-layout.h>
#include <private/pptx-ct-a-tx.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>

typedef struct pptx_ct_a_disp_units_lbl_s {
    pptx_ct_a_layout *layout;
    pptx_ct_a_tx *tx;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *tx_pr;
    int32_t index;
} pptx_ct_a_disp_units_lbl;

pptx_ct_a_disp_units_lbl *
pptx_ct_a_disp_units_lbl_new(xmlNode *node)
{
    pptx_ct_a_disp_units_lbl *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:layout");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->layout = NULL;
        } else {
            obj->layout = pptx_ct_a_layout_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->layout = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx = NULL;
        } else {
            obj->tx = pptx_ct_a_tx_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx = NULL;
    }

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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_layout *
pptx_ct_a_disp_units_lbl_get_layout(const pptx_ct_a_disp_units_lbl *const obj)
{
    return obj->layout;
}

pptx_ct_a_tx *
pptx_ct_a_disp_units_lbl_get_tx(const pptx_ct_a_disp_units_lbl *const obj)
{
    return obj->tx;
}

pptx_ct_a_shape_properties *
pptx_ct_a_disp_units_lbl_get_sp_pr(const pptx_ct_a_disp_units_lbl *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_disp_units_lbl_get_tx_pr(const pptx_ct_a_disp_units_lbl *const obj)
{
    return obj->tx_pr;
}

int32_t
pptx_ct_a_disp_units_lbl_get_index(pptx_ct_a_disp_units_lbl *obj)
{
    return obj->index;
}

void
pptx_ct_a_disp_units_lbl_free(pptx_ct_a_disp_units_lbl *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_layout_free(obj->layout);
    pptx_ct_a_tx_free(obj->tx);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->tx_pr);
    free(obj);
}