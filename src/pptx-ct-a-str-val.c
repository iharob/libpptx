#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-str-val.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_str_val_s {
    pptx_string v;
    pptx_uint idx;
    int32_t index;
} pptx_ct_a_str_val;

pptx_ct_a_str_val *
pptx_ct_a_str_val_new(xmlNode *node)
{
    pptx_ct_a_str_val *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->v = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:v");
    obj->idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "idx");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_str_val_get_v(const pptx_ct_a_str_val *const obj)
{
    return obj->v;
}

pptx_uint 
pptx_ct_a_str_val_get_idx(const pptx_ct_a_str_val *const obj)
{
    return obj->idx;
}

int32_t
pptx_ct_a_str_val_get_index(pptx_ct_a_str_val *obj)
{
    return obj->index;
}

void
pptx_ct_a_str_val_free(pptx_ct_a_str_val *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->v);
    free(obj);
}