#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-grouping.h>
#include <private/pptx-ct-a-line-ser.h>
#include <private/pptx-ct-a-dlbls.h>
#include <private/pptx-ct-a-chart-lines.h>
#include <private/pptx-ct-a-up-down-bars.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_line_chart_s {
    pptx_ct_a_grouping *line_chart_shared_grouping;
    pptx_bool line_chart_shared_vary_colors;
    pptx_ct_a_line_ser **line_chart_shared_ser;
    pptx_ct_a_dlbls *line_chart_shared_d_lbls;
    pptx_ct_a_chart_lines *line_chart_shared_drop_lines;
    pptx_ct_a_chart_lines *hi_low_lines;
    pptx_ct_a_up_down_bars *up_down_bars;
    pptx_bool marker;
    pptx_bool smooth;

    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_line_chart;

pptx_ct_a_line_chart *
pptx_ct_a_line_chart_new(xmlNode *node)
{
    pptx_ct_a_line_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grouping");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_chart_shared_grouping = NULL;
        } else {
            obj->line_chart_shared_grouping = pptx_ct_a_grouping_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_chart_shared_grouping = NULL;
    }
    obj->line_chart_shared_vary_colors = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:varyColors");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ser");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->line_chart_shared_ser = malloc((nodes->nodeNr + 1) * sizeof *obj->line_chart_shared_ser);
            if (obj->line_chart_shared_ser != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->line_chart_shared_ser;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_line_ser_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->line_chart_shared_ser);
                    obj->line_chart_shared_ser = NULL;
                } else {
                    obj->line_chart_shared_ser[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->line_chart_shared_ser = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_chart_shared_ser = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLbls");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_chart_shared_d_lbls = NULL;
        } else {
            obj->line_chart_shared_d_lbls = pptx_ct_a_dlbls_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_chart_shared_d_lbls = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dropLines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_chart_shared_drop_lines = NULL;
        } else {
            obj->line_chart_shared_drop_lines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_chart_shared_drop_lines = NULL;
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
    obj->marker = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:marker");
    obj->smooth = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:smooth");

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

pptx_ct_a_grouping *
pptx_ct_a_line_chart_get_line_chart_shared_grouping(const pptx_ct_a_line_chart *const obj)
{
    return obj->line_chart_shared_grouping;
}

pptx_bool 
pptx_ct_a_line_chart_get_line_chart_shared_vary_colors(const pptx_ct_a_line_chart *const obj)
{
    return obj->line_chart_shared_vary_colors;
}

pptx_ct_a_line_ser **
pptx_ct_a_line_chart_get_line_chart_shared_ser(const pptx_ct_a_line_chart *const obj)
{
    return obj->line_chart_shared_ser;
}

pptx_ct_a_dlbls *
pptx_ct_a_line_chart_get_line_chart_shared_d_lbls(const pptx_ct_a_line_chart *const obj)
{
    return obj->line_chart_shared_d_lbls;
}

pptx_ct_a_chart_lines *
pptx_ct_a_line_chart_get_line_chart_shared_drop_lines(const pptx_ct_a_line_chart *const obj)
{
    return obj->line_chart_shared_drop_lines;
}

pptx_ct_a_chart_lines *
pptx_ct_a_line_chart_get_hi_low_lines(const pptx_ct_a_line_chart *const obj)
{
    return obj->hi_low_lines;
}

pptx_ct_a_up_down_bars *
pptx_ct_a_line_chart_get_up_down_bars(const pptx_ct_a_line_chart *const obj)
{
    return obj->up_down_bars;
}

pptx_bool 
pptx_ct_a_line_chart_get_marker(const pptx_ct_a_line_chart *const obj)
{
    return obj->marker;
}

pptx_bool 
pptx_ct_a_line_chart_get_smooth(const pptx_ct_a_line_chart *const obj)
{
    return obj->smooth;
}

pptx_ct_a_extension_list *
pptx_ct_a_line_chart_get_ext_lst(const pptx_ct_a_line_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_line_chart_get_index(pptx_ct_a_line_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_chart_free(pptx_ct_a_line_chart *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_grouping_free(obj->line_chart_shared_grouping);
    if (obj->line_chart_shared_ser != NULL) {
        for (int i = 0; obj->line_chart_shared_ser[i] != NULL; ++i) {
            pptx_ct_a_line_ser_free(obj->line_chart_shared_ser[i]);
        }
        free(obj->line_chart_shared_ser);
    }

    pptx_ct_a_dlbls_free(obj->line_chart_shared_d_lbls);
    pptx_ct_a_chart_lines_free(obj->line_chart_shared_drop_lines);
    pptx_ct_a_chart_lines_free(obj->hi_low_lines);
    pptx_ct_a_up_down_bars_free(obj->up_down_bars);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}