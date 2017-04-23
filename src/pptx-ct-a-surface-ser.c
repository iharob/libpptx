#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-surface-ser.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-ser-tx.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-ax-data-source.h>
#include <private/pptx-ct-a-num-data-source.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_surface_ser_s {
    pptx_uint ser_shared_idx;
    pptx_uint ser_shared_order;
    pptx_ct_a_ser_tx *ser_shared_tx;
    pptx_ct_a_shape_properties *ser_shared_sp_pr;
    pptx_ct_a_ax_data_source *cat;
    pptx_ct_a_num_data_source *val;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_surface_ser;

pptx_ct_a_surface_ser *
pptx_ct_a_surface_ser_new(xmlNode *node)
{
    pptx_ct_a_surface_ser *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cat");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cat = NULL;
        } else {
            obj->cat = pptx_ct_a_ax_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cat = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:val");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->val = NULL;
        } else {
            obj->val = pptx_ct_a_num_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->val = NULL;
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
pptx_ct_a_surface_ser_get_ser_shared_idx(const pptx_ct_a_surface_ser *const obj)
{
    return obj->ser_shared_idx;
}

pptx_uint 
pptx_ct_a_surface_ser_get_ser_shared_order(const pptx_ct_a_surface_ser *const obj)
{
    return obj->ser_shared_order;
}

pptx_ct_a_ser_tx *
pptx_ct_a_surface_ser_get_ser_shared_tx(const pptx_ct_a_surface_ser *const obj)
{
    return obj->ser_shared_tx;
}

pptx_ct_a_shape_properties *
pptx_ct_a_surface_ser_get_ser_shared_sp_pr(const pptx_ct_a_surface_ser *const obj)
{
    return obj->ser_shared_sp_pr;
}

pptx_ct_a_ax_data_source *
pptx_ct_a_surface_ser_get_cat(const pptx_ct_a_surface_ser *const obj)
{
    return obj->cat;
}

pptx_ct_a_num_data_source *
pptx_ct_a_surface_ser_get_val(const pptx_ct_a_surface_ser *const obj)
{
    return obj->val;
}

pptx_ct_a_extension_list *
pptx_ct_a_surface_ser_get_ext_lst(const pptx_ct_a_surface_ser *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_surface_ser_get_index(pptx_ct_a_surface_ser *obj)
{
    return obj->index;
}

void
pptx_ct_a_surface_ser_free(pptx_ct_a_surface_ser *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_ser_tx_free(obj->ser_shared_tx);
    pptx_ct_a_shape_properties_free(obj->ser_shared_sp_pr);
    pptx_ct_a_ax_data_source_free(obj->cat);
    pptx_ct_a_num_data_source_free(obj->val);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}