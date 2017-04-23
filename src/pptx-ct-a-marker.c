#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-marker.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-marker-style.h>
#include <private/pptx-ct-a-marker-size.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_marker_s {
    pptx_ct_a_marker_style *symbol;
    pptx_ct_a_marker_size *size;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_marker;

pptx_ct_a_marker *
pptx_ct_a_marker_new(xmlNode *node)
{
    pptx_ct_a_marker *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:symbol");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->symbol = NULL;
        } else {
            obj->symbol = pptx_ct_a_marker_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->symbol = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:size");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->size = NULL;
        } else {
            obj->size = pptx_ct_a_marker_size_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->size = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
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

pptx_ct_a_marker_style *
pptx_ct_a_marker_get_symbol(const pptx_ct_a_marker *const obj)
{
    return obj->symbol;
}

pptx_ct_a_marker_size *
pptx_ct_a_marker_get_size(const pptx_ct_a_marker *const obj)
{
    return obj->size;
}

pptx_ct_a_shape_properties *
pptx_ct_a_marker_get_sp_pr(const pptx_ct_a_marker *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_marker_get_ext_lst(const pptx_ct_a_marker *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_marker_get_index(pptx_ct_a_marker *obj)
{
    return obj->index;
}

void
pptx_ct_a_marker_free(pptx_ct_a_marker *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_marker_style_free(obj->symbol);
    pptx_ct_a_marker_size_free(obj->size);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}