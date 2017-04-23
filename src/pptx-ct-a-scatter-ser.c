#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-scatter-ser.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-ser-tx.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-marker.h>
#include <private/pptx-ct-a-dpt.h>
#include <private/pptx-ct-a-dlbls.h>
#include <private/pptx-ct-a-trendline.h>
#include <private/pptx-ct-a-err-bars.h>
#include <private/pptx-ct-a-ax-data-source.h>
#include <private/pptx-ct-a-num-data-source.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_scatter_ser_s {
    pptx_uint ser_shared_idx;
    pptx_uint ser_shared_order;
    pptx_ct_a_ser_tx *ser_shared_tx;
    pptx_ct_a_shape_properties *ser_shared_sp_pr;
    pptx_ct_a_marker *marker;
    pptx_ct_a_dpt **d_pt;
    pptx_ct_a_dlbls *d_lbls;
    pptx_ct_a_trendline **trendline;
    pptx_ct_a_err_bars **err_bars;
    pptx_ct_a_ax_data_source *x_val;
    pptx_ct_a_num_data_source *y_val;
    pptx_bool smooth;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_scatter_ser;

pptx_ct_a_scatter_ser *
pptx_ct_a_scatter_ser_new(xmlNode *node)
{
    pptx_ct_a_scatter_ser *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->ser_shared_idx = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:idx");
    obj->ser_shared_order = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:order");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ser_shared_tx = NULL;
        } else {
            obj->ser_shared_tx = pptx_ct_a_ser_tx_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ser_shared_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ser_shared_sp_pr = NULL;
        } else {
            obj->ser_shared_sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ser_shared_sp_pr = NULL;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dPt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->d_pt = malloc((nodes->nodeNr + 1) * sizeof *obj->d_pt);
            if (obj->d_pt != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->d_pt;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_dpt_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->d_pt);
                    obj->d_pt = NULL;
                } else {
                    obj->d_pt[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->d_pt = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->d_pt = NULL;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:trendline");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->trendline = malloc((nodes->nodeNr + 1) * sizeof *obj->trendline);
            if (obj->trendline != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->trendline;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_trendline_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->trendline);
                    obj->trendline = NULL;
                } else {
                    obj->trendline[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->trendline = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->trendline = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:xVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->x_val = NULL;
        } else {
            obj->x_val = pptx_ct_a_ax_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->x_val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:yVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->y_val = NULL;
        } else {
            obj->y_val = pptx_ct_a_num_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->y_val = NULL;
    }
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

pptx_uint 
pptx_ct_a_scatter_ser_get_ser_shared_idx(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->ser_shared_idx;
}

pptx_uint 
pptx_ct_a_scatter_ser_get_ser_shared_order(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->ser_shared_order;
}

pptx_ct_a_ser_tx *
pptx_ct_a_scatter_ser_get_ser_shared_tx(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->ser_shared_tx;
}

pptx_ct_a_shape_properties *
pptx_ct_a_scatter_ser_get_ser_shared_sp_pr(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->ser_shared_sp_pr;
}

pptx_ct_a_marker *
pptx_ct_a_scatter_ser_get_marker(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->marker;
}

pptx_ct_a_dpt **
pptx_ct_a_scatter_ser_get_d_pt(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->d_pt;
}

pptx_ct_a_dlbls *
pptx_ct_a_scatter_ser_get_d_lbls(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->d_lbls;
}

pptx_ct_a_trendline **
pptx_ct_a_scatter_ser_get_trendline(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->trendline;
}

pptx_ct_a_err_bars **
pptx_ct_a_scatter_ser_get_err_bars(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->err_bars;
}

pptx_ct_a_ax_data_source *
pptx_ct_a_scatter_ser_get_x_val(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->x_val;
}

pptx_ct_a_num_data_source *
pptx_ct_a_scatter_ser_get_y_val(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->y_val;
}

pptx_bool 
pptx_ct_a_scatter_ser_get_smooth(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->smooth;
}

pptx_ct_a_extension_list *
pptx_ct_a_scatter_ser_get_ext_lst(const pptx_ct_a_scatter_ser *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_scatter_ser_get_index(pptx_ct_a_scatter_ser *obj)
{
    return obj->index;
}

void
pptx_ct_a_scatter_ser_free(pptx_ct_a_scatter_ser *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_ser_tx_free(obj->ser_shared_tx);
    pptx_ct_a_shape_properties_free(obj->ser_shared_sp_pr);
    pptx_ct_a_marker_free(obj->marker);
    if (obj->d_pt != NULL) {
        for (int i = 0; obj->d_pt[i] != NULL; ++i) {
            pptx_ct_a_dpt_free(obj->d_pt[i]);
        }
        free(obj->d_pt);
    }

    pptx_ct_a_dlbls_free(obj->d_lbls);
    if (obj->trendline != NULL) {
        for (int i = 0; obj->trendline[i] != NULL; ++i) {
            pptx_ct_a_trendline_free(obj->trendline[i]);
        }
        free(obj->trendline);
    }

    pptx_ct_a_ax_data_source_free(obj->x_val);
    pptx_ct_a_num_data_source_free(obj->y_val);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}