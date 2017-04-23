#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-stock-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-ser.h>
#include <private/pptx-ct-a-dlbls.h>
#include <private/pptx-ct-a-chart-lines.h>
#include <private/pptx-ct-a-up-down-bars.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_stock_chart_s {
    pptx_ct_a_line_ser **ser;
    pptx_ct_a_dlbls *d_lbls;
    pptx_ct_a_chart_lines *drop_lines;
    pptx_ct_a_chart_lines *hi_low_lines;
    pptx_ct_a_up_down_bars *up_down_bars;

    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_stock_chart;

pptx_ct_a_stock_chart *
pptx_ct_a_stock_chart_new(xmlNode *node)
{
    pptx_ct_a_stock_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLbls");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->d_lbls = NULL;
        } else {
            obj->d_lbls = pptx_ct_a_dlbls_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->d_lbls = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dropLines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->drop_lines = NULL;
        } else {
            obj->drop_lines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->drop_lines = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hiLowLines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hi_low_lines = NULL;
        } else {
            obj->hi_low_lines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hi_low_lines = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:upDownBars");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->up_down_bars = NULL;
        } else {
            obj->up_down_bars = pptx_ct_a_up_down_bars_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->up_down_bars = NULL;
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

pptx_ct_a_line_ser **
pptx_ct_a_stock_chart_get_ser(const pptx_ct_a_stock_chart *const obj)
{
    return obj->ser;
}

pptx_ct_a_dlbls *
pptx_ct_a_stock_chart_get_d_lbls(const pptx_ct_a_stock_chart *const obj)
{
    return obj->d_lbls;
}

pptx_ct_a_chart_lines *
pptx_ct_a_stock_chart_get_drop_lines(const pptx_ct_a_stock_chart *const obj)
{
    return obj->drop_lines;
}

pptx_ct_a_chart_lines *
pptx_ct_a_stock_chart_get_hi_low_lines(const pptx_ct_a_stock_chart *const obj)
{
    return obj->hi_low_lines;
}

pptx_ct_a_up_down_bars *
pptx_ct_a_stock_chart_get_up_down_bars(const pptx_ct_a_stock_chart *const obj)
{
    return obj->up_down_bars;
}

pptx_ct_a_extension_list *
pptx_ct_a_stock_chart_get_ext_lst(const pptx_ct_a_stock_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_stock_chart_get_index(pptx_ct_a_stock_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_stock_chart_free(pptx_ct_a_stock_chart *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_dlbls_free(obj->d_lbls);
    pptx_ct_a_chart_lines_free(obj->drop_lines);
    pptx_ct_a_chart_lines_free(obj->hi_low_lines);
    pptx_ct_a_up_down_bars_free(obj->up_down_bars);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}