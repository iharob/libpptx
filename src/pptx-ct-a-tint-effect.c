#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-tint-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_tint_effect_s {
    pptx_int hue;
    pptx_string amt;
    int32_t index;
} pptx_ct_a_tint_effect;

pptx_ct_a_tint_effect *
pptx_ct_a_tint_effect_new(xmlNode *node)
{
    pptx_ct_a_tint_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->hue = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "hue");
    obj->amt = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "amt");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_tint_effect_get_hue(const pptx_ct_a_tint_effect *const obj)
{
    return obj->hue;
}

pptx_string 
pptx_ct_a_tint_effect_get_amt(const pptx_ct_a_tint_effect *const obj)
{
    return obj->amt;
}

int32_t
pptx_ct_a_tint_effect_get_index(pptx_ct_a_tint_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_tint_effect_free(pptx_ct_a_tint_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->amt);
    free(obj);
}