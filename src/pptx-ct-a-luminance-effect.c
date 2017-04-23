#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-luminance-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_luminance_effect_s {
    pptx_string bright;
    pptx_string contrast;
    int32_t index;
} pptx_ct_a_luminance_effect;

pptx_ct_a_luminance_effect *
pptx_ct_a_luminance_effect_new(xmlNode *node)
{
    pptx_ct_a_luminance_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->bright = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "bright");
    obj->contrast = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "contrast");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_luminance_effect_get_bright(const pptx_ct_a_luminance_effect *const obj)
{
    return obj->bright;
}

pptx_string 
pptx_ct_a_luminance_effect_get_contrast(const pptx_ct_a_luminance_effect *const obj)
{
    return obj->contrast;
}

int32_t
pptx_ct_a_luminance_effect_get_index(pptx_ct_a_luminance_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_luminance_effect_free(pptx_ct_a_luminance_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->bright);
    xmlFree(obj->contrast);
    free(obj);
}