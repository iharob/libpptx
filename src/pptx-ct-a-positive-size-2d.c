#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-positive-size-2d.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_positive_size_2d_s {
    pptx_long cx;
    pptx_long cy;
    int32_t index;
} pptx_ct_a_positive_size_2d;

pptx_ct_a_positive_size_2d *
pptx_ct_a_positive_size_2d_new(xmlNode *node)
{
    pptx_ct_a_positive_size_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->cx = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "cx");
    obj->cy = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "cy");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_long 
pptx_ct_a_positive_size_2d_get_cx(const pptx_ct_a_positive_size_2d *const obj)
{
    return obj->cx;
}

pptx_long 
pptx_ct_a_positive_size_2d_get_cy(const pptx_ct_a_positive_size_2d *const obj)
{
    return obj->cy;
}

int32_t
pptx_ct_a_positive_size_2d_get_index(pptx_ct_a_positive_size_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_positive_size_2d_free(pptx_ct_a_positive_size_2d *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}