#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-eight-direction-transition.h>
/* Imported internal stuff */
#include <private/pptx-st-transition-corner-direction-type.h>

typedef struct pptx_ct_p_eight_direction_transition_s {
    pptx_st_transition_corner_direction_type_token_enum dir;
    int32_t index;
} pptx_ct_p_eight_direction_transition;

pptx_ct_p_eight_direction_transition *
pptx_ct_p_eight_direction_transition_new(xmlNode *node)
{
    pptx_ct_p_eight_direction_transition *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->dir = pptx_get_st_transition_corner_direction_type(node, (const xmlChar *) "dir");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_transition_corner_direction_type_token_enum 
pptx_ct_p_eight_direction_transition_get_dir(const pptx_ct_p_eight_direction_transition *const obj)
{
    return obj->dir;
}

int32_t
pptx_ct_p_eight_direction_transition_get_index(pptx_ct_p_eight_direction_transition *obj)
{
    return obj->index;
}

void
pptx_ct_p_eight_direction_transition_free(pptx_ct_p_eight_direction_transition *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}