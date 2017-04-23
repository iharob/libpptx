#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-part-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-style-text-style.h>
#include <private/pptx-ct-a-table-style-cell-style.h>

typedef struct pptx_ct_a_table_part_style_s {
    pptx_ct_a_table_style_text_style *tc_tx_style;
    pptx_ct_a_table_style_cell_style *tc_style;
    int32_t index;
} pptx_ct_a_table_part_style;

pptx_ct_a_table_part_style *
pptx_ct_a_table_part_style_new(xmlNode *node)
{
    pptx_ct_a_table_part_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tcTxStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tc_tx_style = NULL;
        } else {
            obj->tc_tx_style = pptx_ct_a_table_style_text_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tc_tx_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tcStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tc_style = NULL;
        } else {
            obj->tc_style = pptx_ct_a_table_style_cell_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tc_style = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_style_text_style *
pptx_ct_a_table_part_style_get_tc_tx_style(const pptx_ct_a_table_part_style *const obj)
{
    return obj->tc_tx_style;
}

pptx_ct_a_table_style_cell_style *
pptx_ct_a_table_part_style_get_tc_style(const pptx_ct_a_table_part_style *const obj)
{
    return obj->tc_style;
}

int32_t
pptx_ct_a_table_part_style_get_index(pptx_ct_a_table_part_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_part_style_free(pptx_ct_a_table_part_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_table_style_text_style_free(obj->tc_tx_style);
    pptx_ct_a_table_style_cell_style_free(obj->tc_style);
    free(obj);
}