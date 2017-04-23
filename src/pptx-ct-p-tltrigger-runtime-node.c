#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltrigger-runtime-node.h>
/* Imported internal stuff */
#include <private/pptx-st-tltrigger-runtime-node.h>

typedef struct pptx_ct_p_tltrigger_runtime_node_s {
    pptx_st_tltrigger_runtime_node_token_enum val;
    int32_t index;
} pptx_ct_p_tltrigger_runtime_node;

pptx_ct_p_tltrigger_runtime_node *
pptx_ct_p_tltrigger_runtime_node_new(xmlNode *node)
{
    pptx_ct_p_tltrigger_runtime_node *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_tltrigger_runtime_node(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_tltrigger_runtime_node_token_enum 
pptx_ct_p_tltrigger_runtime_node_get_val(const pptx_ct_p_tltrigger_runtime_node *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_p_tltrigger_runtime_node_get_index(pptx_ct_p_tltrigger_runtime_node *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltrigger_runtime_node_free(pptx_ct_p_tltrigger_runtime_node *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}