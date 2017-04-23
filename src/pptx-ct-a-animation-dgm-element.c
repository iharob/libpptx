#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-animation-dgm-element.h>
/* Imported internal stuff */
#include <private/pptx-st-dgm-build-step.h>

typedef struct pptx_ct_a_animation_dgm_element_s {
    pptx_string id;
    pptx_st_dgm_build_step_token_enum bld_step;
    int32_t index;
} pptx_ct_a_animation_dgm_element;

pptx_ct_a_animation_dgm_element *
pptx_ct_a_animation_dgm_element_new(xmlNode *node)
{
    pptx_ct_a_animation_dgm_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "id");
    obj->bld_step = pptx_get_st_dgm_build_step(node, (const xmlChar *) "bldStep");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_animation_dgm_element_get_id(const pptx_ct_a_animation_dgm_element *const obj)
{
    return obj->id;
}

pptx_st_dgm_build_step_token_enum 
pptx_ct_a_animation_dgm_element_get_bld_step(const pptx_ct_a_animation_dgm_element *const obj)
{
    return obj->bld_step;
}

int32_t
pptx_ct_a_animation_dgm_element_get_index(pptx_ct_a_animation_dgm_element *obj)
{
    return obj->index;
}

void
pptx_ct_a_animation_dgm_element_free(pptx_ct_a_animation_dgm_element *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->id);
    free(obj);
}