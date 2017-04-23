#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-rot-y.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_rot_y_s {
    pptx_ushort val;
    int32_t index;
} pptx_ct_a_rot_y;

pptx_ct_a_rot_y *
pptx_ct_a_rot_y_new(xmlNode *node)
{
    pptx_ct_a_rot_y *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_ushort(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ushort 
pptx_ct_a_rot_y_get_val(const pptx_ct_a_rot_y *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_rot_y_get_index(pptx_ct_a_rot_y *obj)
{
    return obj->index;
}

void
pptx_ct_a_rot_y_free(pptx_ct_a_rot_y *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}