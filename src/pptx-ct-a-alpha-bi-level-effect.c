#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-alpha-bi-level-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_alpha_bi_level_effect_s {
    pptx_string thresh;
    int32_t index;
} pptx_ct_a_alpha_bi_level_effect;

pptx_ct_a_alpha_bi_level_effect *
pptx_ct_a_alpha_bi_level_effect_new(xmlNode *node)
{
    pptx_ct_a_alpha_bi_level_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->thresh = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "thresh");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_alpha_bi_level_effect_get_thresh(const pptx_ct_a_alpha_bi_level_effect *const obj)
{
    return obj->thresh;
}

int32_t
pptx_ct_a_alpha_bi_level_effect_get_index(pptx_ct_a_alpha_bi_level_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_alpha_bi_level_effect_free(pptx_ct_a_alpha_bi_level_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->thresh);
    free(obj);
}