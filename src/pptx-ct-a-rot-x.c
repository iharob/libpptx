#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-rot-x.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_rot_x_s {
    pptx_byte val;
    int32_t index;
} pptx_ct_a_rot_x;

pptx_ct_a_rot_x *
pptx_ct_a_rot_x_new(xmlNode *node)
{
    pptx_ct_a_rot_x *obj;
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
pptx_ct_a_rot_x_get_val(const pptx_ct_a_rot_x *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_rot_x_get_index(pptx_ct_a_rot_x *obj)
{
    return obj->index;
}

void
pptx_ct_a_rot_x_free(pptx_ct_a_rot_x *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}