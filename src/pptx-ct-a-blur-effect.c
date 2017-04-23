#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-blur-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_blur_effect_s {
    pptx_long rad;
    pptx_bool grow;
    int32_t index;
} pptx_ct_a_blur_effect;

pptx_ct_a_blur_effect *
pptx_ct_a_blur_effect_new(xmlNode *node)
{
    pptx_ct_a_blur_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->rad = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "rad");
    obj->grow = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "grow");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_long 
pptx_ct_a_blur_effect_get_rad(const pptx_ct_a_blur_effect *const obj)
{
    return obj->rad;
}

pptx_bool 
pptx_ct_a_blur_effect_get_grow(const pptx_ct_a_blur_effect *const obj)
{
    return obj->grow;
}

int32_t
pptx_ct_a_blur_effect_get_index(pptx_ct_a_blur_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_blur_effect_free(pptx_ct_a_blur_effect *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}