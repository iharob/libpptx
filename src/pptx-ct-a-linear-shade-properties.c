#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-linear-shade-properties.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_linear_shade_properties_s {
    pptx_int ang;
    pptx_bool scaled;
    int32_t index;
} pptx_ct_a_linear_shade_properties;

pptx_ct_a_linear_shade_properties *
pptx_ct_a_linear_shade_properties_new(xmlNode *node)
{
    pptx_ct_a_linear_shade_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->ang = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "ang");
    obj->scaled = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "scaled");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_linear_shade_properties_get_ang(const pptx_ct_a_linear_shade_properties *const obj)
{
    return obj->ang;
}

pptx_bool 
pptx_ct_a_linear_shade_properties_get_scaled(const pptx_ct_a_linear_shade_properties *const obj)
{
    return obj->scaled;
}

int32_t
pptx_ct_a_linear_shade_properties_get_index(pptx_ct_a_linear_shade_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_linear_shade_properties_free(pptx_ct_a_linear_shade_properties *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}