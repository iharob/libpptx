#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-boolean.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_boolean_s {
    pptx_bool val;
    int32_t index;
} pptx_ct_a_boolean;

pptx_ct_a_boolean *
pptx_ct_a_boolean_new(xmlNode *node)
{
    pptx_ct_a_boolean *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_a_boolean_get_val(const pptx_ct_a_boolean *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_boolean_get_index(pptx_ct_a_boolean *obj)
{
    return obj->index;
}

void
pptx_ct_a_boolean_free(pptx_ct_a_boolean *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}