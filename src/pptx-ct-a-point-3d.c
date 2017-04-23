#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-point-3d.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_point_3d_s {
    pptx_string x;
    pptx_string y;
    pptx_string z;
    int32_t index;
} pptx_ct_a_point_3d;

pptx_ct_a_point_3d *
pptx_ct_a_point_3d_new(xmlNode *node)
{
    pptx_ct_a_point_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->x = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "x");
    obj->y = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "y");
    obj->z = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "z");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_point_3d_get_x(const pptx_ct_a_point_3d *const obj)
{
    return obj->x;
}

pptx_string 
pptx_ct_a_point_3d_get_y(const pptx_ct_a_point_3d *const obj)
{
    return obj->y;
}

pptx_string 
pptx_ct_a_point_3d_get_z(const pptx_ct_a_point_3d *const obj)
{
    return obj->z;
}

int32_t
pptx_ct_a_point_3d_get_index(pptx_ct_a_point_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_point_3d_free(pptx_ct_a_point_3d *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->x);
    xmlFree(obj->y);
    xmlFree(obj->z);
    free(obj);
}