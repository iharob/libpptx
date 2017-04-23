#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-thickness.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_thickness_s {
    pptx_uint val;
    int32_t index;
} pptx_ct_a_thickness;

pptx_ct_a_thickness *
pptx_ct_a_thickness_new(xmlNode *node)
{
    pptx_ct_a_thickness *obj;
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
pptx_ct_a_thickness_get_val(const pptx_ct_a_thickness *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_thickness_get_index(pptx_ct_a_thickness *obj)
{
    return obj->index;
}

void
pptx_ct_a_thickness_free(pptx_ct_a_thickness *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}