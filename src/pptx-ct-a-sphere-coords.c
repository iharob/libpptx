#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-sphere-coords.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_sphere_coords_s {
    pptx_int lat;
    pptx_int lon;
    pptx_int rev;
    int32_t index;
} pptx_ct_a_sphere_coords;

pptx_ct_a_sphere_coords *
pptx_ct_a_sphere_coords_new(xmlNode *node)
{
    pptx_ct_a_sphere_coords *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->lat = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "lat");
    obj->lon = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "lon");
    obj->rev = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "rev");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_sphere_coords_get_lat(const pptx_ct_a_sphere_coords *const obj)
{
    return obj->lat;
}

pptx_int 
pptx_ct_a_sphere_coords_get_lon(const pptx_ct_a_sphere_coords *const obj)
{
    return obj->lon;
}

pptx_int 
pptx_ct_a_sphere_coords_get_rev(const pptx_ct_a_sphere_coords *const obj)
{
    return obj->rev;
}

int32_t
pptx_ct_a_sphere_coords_get_index(pptx_ct_a_sphere_coords *obj)
{
    return obj->index;
}

void
pptx_ct_a_sphere_coords_free(pptx_ct_a_sphere_coords *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}