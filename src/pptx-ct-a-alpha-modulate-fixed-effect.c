#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-alpha-modulate-fixed-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_alpha_modulate_fixed_effect_s {
    pptx_string amt;
    int32_t index;
} pptx_ct_a_alpha_modulate_fixed_effect;

pptx_ct_a_alpha_modulate_fixed_effect *
pptx_ct_a_alpha_modulate_fixed_effect_new(xmlNode *node)
{
    pptx_ct_a_alpha_modulate_fixed_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->amt = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "amt");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_alpha_modulate_fixed_effect_get_amt(const pptx_ct_a_alpha_modulate_fixed_effect *const obj)
{
    return obj->amt;
}

int32_t
pptx_ct_a_alpha_modulate_fixed_effect_get_index(pptx_ct_a_alpha_modulate_fixed_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_alpha_modulate_fixed_effect_free(pptx_ct_a_alpha_modulate_fixed_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->amt);
    free(obj);
}