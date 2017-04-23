#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-optional-black-transition.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_optional_black_transition_s {
    pptx_bool thru_blk;
    int32_t index;
} pptx_ct_p_optional_black_transition;

pptx_ct_p_optional_black_transition *
pptx_ct_p_optional_black_transition_new(xmlNode *node)
{
    pptx_ct_p_optional_black_transition *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->thru_blk = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "thruBlk");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_p_optional_black_transition_get_thru_blk(const pptx_ct_p_optional_black_transition *const obj)
{
    return obj->thru_blk;
}

int32_t
pptx_ct_p_optional_black_transition_get_index(pptx_ct_p_optional_black_transition *obj)
{
    return obj->index;
}

void
pptx_ct_p_optional_black_transition_free(pptx_ct_p_optional_black_transition *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}