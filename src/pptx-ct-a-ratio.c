#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-ratio.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_ratio_s {
    pptx_long n;
    pptx_long d;
    int32_t index;
} pptx_ct_a_ratio;

pptx_ct_a_ratio *
pptx_ct_a_ratio_new(xmlNode *node)
{
    pptx_ct_a_ratio *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->n = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "n");
    obj->d = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "d");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_long 
pptx_ct_a_ratio_get_n(const pptx_ct_a_ratio *const obj)
{
    return obj->n;
}

pptx_long 
pptx_ct_a_ratio_get_d(const pptx_ct_a_ratio *const obj)
{
    return obj->d;
}

int32_t
pptx_ct_a_ratio_get_index(pptx_ct_a_ratio *obj)
{
    return obj->index;
}

void
pptx_ct_a_ratio_free(pptx_ct_a_ratio *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}