#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-wheel-transition.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_wheel_transition_s {
    pptx_uint spokes;
    int32_t index;
} pptx_ct_p_wheel_transition;

pptx_ct_p_wheel_transition *
pptx_ct_p_wheel_transition_new(xmlNode *node)
{
    pptx_ct_p_wheel_transition *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->spokes = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spokes");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_wheel_transition_get_spokes(const pptx_ct_p_wheel_transition *const obj)
{
    return obj->spokes;
}

int32_t
pptx_ct_p_wheel_transition_get_index(pptx_ct_p_wheel_transition *obj)
{
    return obj->index;
}

void
pptx_ct_p_wheel_transition_free(pptx_ct_p_wheel_transition *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}