#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-xyadjust-handle.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-adj-point-2d.h>

typedef struct pptx_ct_a_xyadjust_handle_s {
    pptx_ct_a_adj_point_2d *pos;
    pptx_string gd_ref_x;
    pptx_string min_x;
    pptx_string max_x;
    pptx_string gd_ref_y;
    pptx_string min_y;
    pptx_string max_y;
    int32_t index;
} pptx_ct_a_xyadjust_handle;

pptx_ct_a_xyadjust_handle *
pptx_ct_a_xyadjust_handle_new(xmlNode *node)
{
    pptx_ct_a_xyadjust_handle *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pos = NULL;
        } else {
            obj->pos = pptx_ct_a_adj_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pos = NULL;
    }
    obj->gd_ref_x = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "gdRefX");
    obj->min_x = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minX");
    obj->max_x = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "maxX");
    obj->gd_ref_y = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "gdRefY");
    obj->min_y = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minY");
    obj->max_y = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "maxY");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_adj_point_2d *
pptx_ct_a_xyadjust_handle_get_pos(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->pos;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_gd_ref_x(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->gd_ref_x;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_min_x(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->min_x;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_max_x(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->max_x;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_gd_ref_y(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->gd_ref_y;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_min_y(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->min_y;
}

pptx_string 
pptx_ct_a_xyadjust_handle_get_max_y(const pptx_ct_a_xyadjust_handle *const obj)
{
    return obj->max_y;
}

int32_t
pptx_ct_a_xyadjust_handle_get_index(pptx_ct_a_xyadjust_handle *obj)
{
    return obj->index;
}

void
pptx_ct_a_xyadjust_handle_free(pptx_ct_a_xyadjust_handle *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_adj_point_2d_free(obj->pos);
    xmlFree(obj->gd_ref_x);
    xmlFree(obj->min_x);
    xmlFree(obj->max_x);
    xmlFree(obj->gd_ref_y);
    xmlFree(obj->min_y);
    xmlFree(obj->max_y);
    free(obj);
}