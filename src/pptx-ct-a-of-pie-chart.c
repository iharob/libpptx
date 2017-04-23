#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-of-pie-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-of-pie-type.h>
#include <private/pptx-ct-a-pie-ser.h>
#include <private/pptx-ct-a-dlbls.h>
#include <private/pptx-ct-a-gap-amount.h>
#include <private/pptx-ct-a-split-type.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-cust-split.h>
#include <private/pptx-ct-a-second-pie-size.h>
#include <private/pptx-ct-a-chart-lines.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_of_pie_chart_s {
    pptx_ct_a_of_pie_type *of_pie_type;
    pptx_bool pie_chart_shared_vary_colors;
    pptx_ct_a_pie_ser **pie_chart_shared_ser;
    pptx_ct_a_dlbls *pie_chart_shared_d_lbls;
    pptx_ct_a_gap_amount *gap_width;
    pptx_ct_a_split_type *split_type;
    pptx_ct_a_double *split_pos;
    pptx_ct_a_cust_split *cust_split;
    pptx_ct_a_second_pie_size *second_pie_size;
    pptx_ct_a_chart_lines **ser_lines;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_of_pie_chart;

pptx_ct_a_of_pie_chart *
pptx_ct_a_of_pie_chart_new(xmlNode *node)
{
    pptx_ct_a_of_pie_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ofPieType");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->of_pie_type = NULL;
        } else {
            obj->of_pie_type = pptx_ct_a_of_pie_type_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->of_pie_type = NULL;
    }
    obj->pie_chart_shared_vary_colors = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:varyColors");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ser");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pie_chart_shared_ser = malloc((nodes->nodeNr + 1) * sizeof *obj->pie_chart_shared_ser);
            if (obj->pie_chart_shared_ser != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pie_chart_shared_ser;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_pie_ser_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->pie_chart_shared_ser);
                    obj->pie_chart_shared_ser = NULL;
                } else {
                    obj->pie_chart_shared_ser[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pie_chart_shared_ser = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pie_chart_shared_ser = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLbls");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pie_chart_shared_d_lbls = NULL;
        } else {
            obj->pie_chart_shared_d_lbls = pptx_ct_a_dlbls_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pie_chart_shared_d_lbls = NULL;
    }

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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:splitType");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->split_type = NULL;
        } else {
            obj->split_type = pptx_ct_a_split_type_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->split_type = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:splitPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->split_pos = NULL;
        } else {
            obj->split_pos = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->split_pos = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:custSplit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_split = NULL;
        } else {
            obj->cust_split = pptx_ct_a_cust_split_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_split = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:secondPieSize");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->second_pie_size = NULL;
        } else {
            obj->second_pie_size = pptx_ct_a_second_pie_size_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->second_pie_size = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:serLines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ser_lines = malloc((nodes->nodeNr + 1) * sizeof *obj->ser_lines);
            if (obj->ser_lines != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ser_lines;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_chart_lines_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ser_lines);
                    obj->ser_lines = NULL;
                } else {
                    obj->ser_lines[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ser_lines = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ser_lines = NULL;
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

pptx_ct_a_of_pie_type *
pptx_ct_a_of_pie_chart_get_of_pie_type(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->of_pie_type;
}

pptx_bool 
pptx_ct_a_of_pie_chart_get_pie_chart_shared_vary_colors(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->pie_chart_shared_vary_colors;
}

pptx_ct_a_pie_ser **
pptx_ct_a_of_pie_chart_get_pie_chart_shared_ser(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->pie_chart_shared_ser;
}

pptx_ct_a_dlbls *
pptx_ct_a_of_pie_chart_get_pie_chart_shared_d_lbls(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->pie_chart_shared_d_lbls;
}

pptx_ct_a_gap_amount *
pptx_ct_a_of_pie_chart_get_gap_width(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->gap_width;
}

pptx_ct_a_split_type *
pptx_ct_a_of_pie_chart_get_split_type(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->split_type;
}

pptx_ct_a_double *
pptx_ct_a_of_pie_chart_get_split_pos(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->split_pos;
}

pptx_ct_a_cust_split *
pptx_ct_a_of_pie_chart_get_cust_split(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->cust_split;
}

pptx_ct_a_second_pie_size *
pptx_ct_a_of_pie_chart_get_second_pie_size(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->second_pie_size;
}

pptx_ct_a_chart_lines **
pptx_ct_a_of_pie_chart_get_ser_lines(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->ser_lines;
}

pptx_ct_a_extension_list *
pptx_ct_a_of_pie_chart_get_ext_lst(const pptx_ct_a_of_pie_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_of_pie_chart_get_index(pptx_ct_a_of_pie_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_of_pie_chart_free(pptx_ct_a_of_pie_chart *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_of_pie_type_free(obj->of_pie_type);
    if (obj->pie_chart_shared_ser != NULL) {
        for (int i = 0; obj->pie_chart_shared_ser[i] != NULL; ++i) {
            pptx_ct_a_pie_ser_free(obj->pie_chart_shared_ser[i]);
        }
        free(obj->pie_chart_shared_ser);
    }

    pptx_ct_a_dlbls_free(obj->pie_chart_shared_d_lbls);
    pptx_ct_a_gap_amount_free(obj->gap_width);
    pptx_ct_a_split_type_free(obj->split_type);
    pptx_ct_a_double_free(obj->split_pos);
    pptx_ct_a_cust_split_free(obj->cust_split);
    pptx_ct_a_second_pie_size_free(obj->second_pie_size);
    if (obj->ser_lines != NULL) {
        for (int i = 0; obj->ser_lines[i] != NULL; ++i) {
            pptx_ct_a_chart_lines_free(obj->ser_lines[i]);
        }
        free(obj->ser_lines);
    }

    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}