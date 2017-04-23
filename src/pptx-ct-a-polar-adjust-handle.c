#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-polar-adjust-handle.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-adj-point-2d.h>

typedef struct pptx_ct_a_polar_adjust_handle_s {
    pptx_ct_a_adj_point_2d *pos;
    pptx_string gd_ref_r;
    pptx_string min_r;
    pptx_string max_r;
    pptx_string gd_ref_ang;
    pptx_string min_ang;
    pptx_string max_ang;
    int32_t index;
} pptx_ct_a_polar_adjust_handle;

pptx_ct_a_polar_adjust_handle *
pptx_ct_a_polar_adjust_handle_new(xmlNode *node)
{
    pptx_ct_a_polar_adjust_handle *obj;
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
    obj->gd_ref_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "gdRefR");
    obj->min_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minR");
    obj->max_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "maxR");
    obj->gd_ref_ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "gdRefAng");
    obj->min_ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minAng");
    obj->max_ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "maxAng");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_adj_point_2d *
pptx_ct_a_polar_adjust_handle_get_pos(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->pos;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_gd_ref_r(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->gd_ref_r;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_min_r(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->min_r;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_max_r(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->max_r;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_gd_ref_ang(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->gd_ref_ang;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_min_ang(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->min_ang;
}

pptx_string 
pptx_ct_a_polar_adjust_handle_get_max_ang(const pptx_ct_a_polar_adjust_handle *const obj)
{
    return obj->max_ang;
}

int32_t
pptx_ct_a_polar_adjust_handle_get_index(pptx_ct_a_polar_adjust_handle *obj)
{
    return obj->index;
}

void
pptx_ct_a_polar_adjust_handle_free(pptx_ct_a_polar_adjust_handle *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_adj_point_2d_free(obj->pos);
    xmlFree(obj->gd_ref_r);
    xmlFree(obj->min_r);
    xmlFree(obj->max_r);
    xmlFree(obj->gd_ref_ang);
    xmlFree(obj->min_ang);
    xmlFree(obj->max_ang);
    free(obj);
}