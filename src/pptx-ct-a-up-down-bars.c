#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-up-down-bars.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-gap-amount.h>
#include <private/pptx-ct-a-up-down-bar.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_up_down_bars_s {
    pptx_ct_a_gap_amount *gap_width;
    pptx_ct_a_up_down_bar *up_bars;
    pptx_ct_a_up_down_bar *down_bars;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_up_down_bars;

pptx_ct_a_up_down_bars *
pptx_ct_a_up_down_bars_new(xmlNode *node)
{
    pptx_ct_a_up_down_bars *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gapWidth");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->gap_width = NULL;
        } else {
            obj->gap_width = pptx_ct_a_gap_amount_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->gap_width = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:upBars");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->up_bars = NULL;
        } else {
            obj->up_bars = pptx_ct_a_up_down_bar_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->up_bars = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:downBars");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->down_bars = NULL;
        } else {
            obj->down_bars = pptx_ct_a_up_down_bar_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->down_bars = NULL;
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

pptx_ct_a_gap_amount *
pptx_ct_a_up_down_bars_get_gap_width(const pptx_ct_a_up_down_bars *const obj)
{
    return obj->gap_width;
}

pptx_ct_a_up_down_bar *
pptx_ct_a_up_down_bars_get_up_bars(const pptx_ct_a_up_down_bars *const obj)
{
    return obj->up_bars;
}

pptx_ct_a_up_down_bar *
pptx_ct_a_up_down_bars_get_down_bars(const pptx_ct_a_up_down_bars *const obj)
{
    return obj->down_bars;
}

pptx_ct_a_extension_list *
pptx_ct_a_up_down_bars_get_ext_lst(const pptx_ct_a_up_down_bars *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_up_down_bars_get_index(pptx_ct_a_up_down_bars *obj)
{
    return obj->index;
}

void
pptx_ct_a_up_down_bars_free(pptx_ct_a_up_down_bars *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_gap_amount_free(obj->gap_width);
    pptx_ct_a_up_down_bar_free(obj->up_bars);
    pptx_ct_a_up_down_bar_free(obj->down_bars);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}