#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-vector-3d.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_vector_3d_s {
    pptx_string dx;
    pptx_string dy;
    pptx_string dz;
    int32_t index;
} pptx_ct_a_vector_3d;

pptx_ct_a_vector_3d *
pptx_ct_a_vector_3d_new(xmlNode *node)
{
    pptx_ct_a_vector_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->dx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "dx");
    obj->dy = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "dy");
    obj->dz = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "dz");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_vector_3d_get_dx(const pptx_ct_a_vector_3d *const obj)
{
    return obj->dx;
}

pptx_string 
pptx_ct_a_vector_3d_get_dy(const pptx_ct_a_vector_3d *const obj)
{
    return obj->dy;
}

pptx_string 
pptx_ct_a_vector_3d_get_dz(const pptx_ct_a_vector_3d *const obj)
{
    return obj->dz;
}

int32_t
pptx_ct_a_vector_3d_get_index(pptx_ct_a_vector_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_vector_3d_free(pptx_ct_a_vector_3d *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->dx);
    xmlFree(obj->dy);
    xmlFree(obj->dz);
    free(obj);
}