#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-radar-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-radar-style.h>
#include <private/pptx-ct-a-radar-ser.h>
#include <private/pptx-ct-a-dlbls.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_radar_chart_s {
    pptx_ct_a_radar_style *radar_style;
    pptx_bool vary_colors;
    pptx_ct_a_radar_ser **ser;
    pptx_ct_a_dlbls *d_lbls;

    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_radar_chart;

pptx_ct_a_radar_chart *
pptx_ct_a_radar_chart_new(xmlNode *node)
{
    pptx_ct_a_radar_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:radarStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->radar_style = NULL;
        } else {
            obj->radar_style = pptx_ct_a_radar_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->radar_style = NULL;
    }
    obj->vary_colors = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:varyColors");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ser");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ser = malloc((nodes->nodeNr + 1) * sizeof *obj->ser);
            if (obj->ser != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ser;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_radar_ser_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ser);
                    obj->ser = NULL;
                } else {
                    obj->ser[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ser = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ser = NULL;
    }

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

pptx_ct_a_radar_style *
pptx_ct_a_radar_chart_get_radar_style(const pptx_ct_a_radar_chart *const obj)
{
    return obj->radar_style;
}

pptx_bool 
pptx_ct_a_radar_chart_get_vary_colors(const pptx_ct_a_radar_chart *const obj)
{
    return obj->vary_colors;
}

pptx_ct_a_radar_ser **
pptx_ct_a_radar_chart_get_ser(const pptx_ct_a_radar_chart *const obj)
{
    return obj->ser;
}

pptx_ct_a_dlbls *
pptx_ct_a_radar_chart_get_d_lbls(const pptx_ct_a_radar_chart *const obj)
{
    return obj->d_lbls;
}

pptx_ct_a_extension_list *
pptx_ct_a_radar_chart_get_ext_lst(const pptx_ct_a_radar_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_radar_chart_get_index(pptx_ct_a_radar_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_radar_chart_free(pptx_ct_a_radar_chart *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_radar_style_free(obj->radar_style);
    if (obj->ser != NULL) {
        for (int i = 0; obj->ser[i] != NULL; ++i) {
            pptx_ct_a_radar_ser_free(obj->ser[i]);
        }
        free(obj->ser);
    }

    pptx_ct_a_dlbls_free(obj->d_lbls);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}