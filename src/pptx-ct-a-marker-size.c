#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-marker-size.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_marker_size_s {
    pptx_byte val;
    int32_t index;
} pptx_ct_a_marker_size;

pptx_ct_a_marker_size *
pptx_ct_a_marker_size_new(xmlNode *node)
{
    pptx_ct_a_marker_size *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_byte(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_byte 
pptx_ct_a_marker_size_get_val(const pptx_ct_a_marker_size *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_marker_size_get_index(pptx_ct_a_marker_size *obj)
{
    return obj->index;
}

void
pptx_ct_a_marker_size_free(pptx_ct_a_marker_size *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}