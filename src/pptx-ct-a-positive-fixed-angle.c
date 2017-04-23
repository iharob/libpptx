#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-positive-fixed-angle.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_positive_fixed_angle_s {
    pptx_int val;
    int32_t index;
} pptx_ct_a_positive_fixed_angle;

pptx_ct_a_positive_fixed_angle *
pptx_ct_a_positive_fixed_angle_new(xmlNode *node)
{
    pptx_ct_a_positive_fixed_angle *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_positive_fixed_angle_get_val(const pptx_ct_a_positive_fixed_angle *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_positive_fixed_angle_get_index(pptx_ct_a_positive_fixed_angle *obj)
{
    return obj->index;
}

void
pptx_ct_a_positive_fixed_angle_free(pptx_ct_a_positive_fixed_angle *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}