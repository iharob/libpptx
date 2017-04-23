#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-log-base.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_log_base_s {
    pptx_double val;
    int32_t index;
} pptx_ct_a_log_base;

pptx_ct_a_log_base *
pptx_ct_a_log_base_new(xmlNode *node)
{
    pptx_ct_a_log_base *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_double 
pptx_ct_a_log_base_get_val(const pptx_ct_a_log_base *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_log_base_get_index(pptx_ct_a_log_base *obj)
{
    return obj->index;
}

void
pptx_ct_a_log_base_free(pptx_ct_a_log_base *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}