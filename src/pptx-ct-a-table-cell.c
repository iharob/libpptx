#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-cell.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-table-cell-properties.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_table_cell_s {
    pptx_ct_a_text_body *tx_body;
    pptx_ct_a_table_cell_properties *tc_pr;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_int row_span;
    pptx_int grid_span;
    pptx_bool h_merge;
    pptx_bool v_merge;
    pptx_string id;
    int32_t index;
} pptx_ct_a_table_cell;

pptx_ct_a_table_cell *
pptx_ct_a_table_cell_new(xmlNode *node)
{
    pptx_ct_a_table_cell *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txBody");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tcPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tc_pr = NULL;
        } else {
            obj->tc_pr = pptx_ct_a_table_cell_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tc_pr = NULL;
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
    obj->row_span = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "rowSpan");
    obj->grid_span = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "gridSpan");
    obj->h_merge = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hMerge");
    obj->v_merge = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "vMerge");
    obj->id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_body *
pptx_ct_a_table_cell_get_tx_body(const pptx_ct_a_table_cell *const obj)
{
    return obj->tx_body;
}

pptx_ct_a_table_cell_properties *
pptx_ct_a_table_cell_get_tc_pr(const pptx_ct_a_table_cell *const obj)
{
    return obj->tc_pr;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_cell_get_ext_lst(const pptx_ct_a_table_cell *const obj)
{
    return obj->ext_lst;
}

pptx_int 
pptx_ct_a_table_cell_get_row_span(const pptx_ct_a_table_cell *const obj)
{
    return obj->row_span;
}

pptx_int 
pptx_ct_a_table_cell_get_grid_span(const pptx_ct_a_table_cell *const obj)
{
    return obj->grid_span;
}

pptx_bool 
pptx_ct_a_table_cell_get_h_merge(const pptx_ct_a_table_cell *const obj)
{
    return obj->h_merge;
}

pptx_bool 
pptx_ct_a_table_cell_get_v_merge(const pptx_ct_a_table_cell *const obj)
{
    return obj->v_merge;
}

pptx_string 
pptx_ct_a_table_cell_get_id(const pptx_ct_a_table_cell *const obj)
{
    return obj->id;
}

int32_t
pptx_ct_a_table_cell_get_index(pptx_ct_a_table_cell *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_cell_free(pptx_ct_a_table_cell *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_body_free(obj->tx_body);
    pptx_ct_a_table_cell_properties_free(obj->tc_pr);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->id);
    free(obj);
}