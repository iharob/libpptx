#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-resize-handles.h>
/* Imported internal stuff */
#include <private/pptx-st-resize-handles-str.h>

typedef struct pptx_ct_dgm_resize_handles_s {
    pptx_st_resize_handles_str_token_enum val;
    int32_t index;
} pptx_ct_dgm_resize_handles;

pptx_ct_dgm_resize_handles *
pptx_ct_dgm_resize_handles_new(xmlNode *node)
{
    pptx_ct_dgm_resize_handles *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_resize_handles_str(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_resize_handles_str_token_enum 
pptx_ct_dgm_resize_handles_get_val(const pptx_ct_dgm_resize_handles *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_resize_handles_get_index(pptx_ct_dgm_resize_handles *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_resize_handles_free(pptx_ct_dgm_resize_handles *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}