#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-skip.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_skip_s {
    pptx_uint val;
    int32_t index;
} pptx_ct_a_skip;

pptx_ct_a_skip *
pptx_ct_a_skip_new(xmlNode *node)
{
    pptx_ct_a_skip *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_skip_get_val(const pptx_ct_a_skip *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_skip_get_index(pptx_ct_a_skip *obj)
{
    return obj->index;
}

void
pptx_ct_a_skip_free(pptx_ct_a_skip *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}