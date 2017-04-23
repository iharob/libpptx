#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-direction.h>
/* Imported internal stuff */
#include <private/pptx-st-direction.h>

typedef struct pptx_ct_dgm_direction_s {
    pptx_st_direction_token_enum val;
    int32_t index;
} pptx_ct_dgm_direction;

pptx_ct_dgm_direction *
pptx_ct_dgm_direction_new(xmlNode *node)
{
    pptx_ct_dgm_direction *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_direction(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_direction_token_enum 
pptx_ct_dgm_direction_get_val(const pptx_ct_dgm_direction *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_direction_get_index(pptx_ct_dgm_direction *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_direction_free(pptx_ct_dgm_direction *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}