#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-effect-reference.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_effect_reference_s {
    pptx_string ref;
    int32_t index;
} pptx_ct_a_effect_reference;

pptx_ct_a_effect_reference *
pptx_ct_a_effect_reference_new(xmlNode *node)
{
    pptx_ct_a_effect_reference *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->ref = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ref");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_effect_reference_get_ref(const pptx_ct_a_effect_reference *const obj)
{
    return obj->ref;
}

int32_t
pptx_ct_a_effect_reference_get_index(pptx_ct_a_effect_reference *obj)
{
    return obj->index;
}

void
pptx_ct_a_effect_reference_free(pptx_ct_a_effect_reference *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->ref);
    free(obj);
}