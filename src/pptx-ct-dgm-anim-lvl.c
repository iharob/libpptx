#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-anim-lvl.h>
/* Imported internal stuff */
#include <private/pptx-st-anim-lvl-str.h>

typedef struct pptx_ct_dgm_anim_lvl_s {
    pptx_st_anim_lvl_str_token_enum val;
    int32_t index;
} pptx_ct_dgm_anim_lvl;

pptx_ct_dgm_anim_lvl *
pptx_ct_dgm_anim_lvl_new(xmlNode *node)
{
    pptx_ct_dgm_anim_lvl *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_anim_lvl_str(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_anim_lvl_str_token_enum 
pptx_ct_dgm_anim_lvl_get_val(const pptx_ct_dgm_anim_lvl *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_anim_lvl_get_index(pptx_ct_dgm_anim_lvl *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_anim_lvl_free(pptx_ct_dgm_anim_lvl *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}