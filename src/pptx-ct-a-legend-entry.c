#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-legend-entry.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_legend_entry_s {
    pptx_uint idx;
    pptx_bool delete;
    pptx_ct_a_text_body *legend_entry_data_tx_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_legend_entry;

pptx_ct_a_legend_entry *
pptx_ct_a_legend_entry_new(xmlNode *node)
{
    pptx_ct_a_legend_entry *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->idx = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:idx");
    obj->delete = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:delete");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->legend_entry_data_tx_pr = NULL;
        } else {
            obj->legend_entry_data_tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->legend_entry_data_tx_pr = NULL;
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
pptx_ct_a_legend_entry_get_idx(const pptx_ct_a_legend_entry *const obj)
{
    return obj->idx;
}

pptx_bool 
pptx_ct_a_legend_entry_get_delete(const pptx_ct_a_legend_entry *const obj)
{
    return obj->delete;
}

pptx_ct_a_text_body *
pptx_ct_a_legend_entry_get_legend_entry_data_tx_pr(const pptx_ct_a_legend_entry *const obj)
{
    return obj->legend_entry_data_tx_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_legend_entry_get_ext_lst(const pptx_ct_a_legend_entry *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_legend_entry_get_index(pptx_ct_a_legend_entry *obj)
{
    return obj->index;
}

void
pptx_ct_a_legend_entry_free(pptx_ct_a_legend_entry *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_body_free(obj->legend_entry_data_tx_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}