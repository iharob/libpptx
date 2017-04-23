#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-guide.h>
/* Imported internal stuff */
#include <private/pptx-st-direction.h>

typedef struct pptx_ct_p_guide_s {
    pptx_st_direction_token_enum orient;
    pptx_string pos;
    int32_t index;
} pptx_ct_p_guide;

pptx_ct_p_guide *
pptx_ct_p_guide_new(xmlNode *node)
{
    pptx_ct_p_guide *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->orient = pptx_get_st_direction(node, (const xmlChar *) "orient");
    obj->pos = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "pos");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_direction_token_enum 
pptx_ct_p_guide_get_orient(const pptx_ct_p_guide *const obj)
{
    return obj->orient;
}

pptx_string 
pptx_ct_p_guide_get_pos(const pptx_ct_p_guide *const obj)
{
    return obj->pos;
}

int32_t
pptx_ct_p_guide_get_index(pptx_ct_p_guide *obj)
{
    return obj->index;
}

void
pptx_ct_p_guide_free(pptx_ct_p_guide *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->pos);
    free(obj);
}