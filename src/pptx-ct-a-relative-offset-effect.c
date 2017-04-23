#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-relative-offset-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_relative_offset_effect_s {
    pptx_string tx;
    pptx_string ty;
    int32_t index;
} pptx_ct_a_relative_offset_effect;

pptx_ct_a_relative_offset_effect *
pptx_ct_a_relative_offset_effect_new(xmlNode *node)
{
    pptx_ct_a_relative_offset_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->tx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tx");
    obj->ty = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ty");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_relative_offset_effect_get_tx(const pptx_ct_a_relative_offset_effect *const obj)
{
    return obj->tx;
}

pptx_string 
pptx_ct_a_relative_offset_effect_get_ty(const pptx_ct_a_relative_offset_effect *const obj)
{
    return obj->ty;
}

int32_t
pptx_ct_a_relative_offset_effect_get_index(pptx_ct_a_relative_offset_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_relative_offset_effect_free(pptx_ct_a_relative_offset_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->tx);
    xmlFree(obj->ty);
    free(obj);
}