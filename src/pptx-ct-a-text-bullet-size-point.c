#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-bullet-size-point.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_text_bullet_size_point_s {
    pptx_int val;
    int32_t index;
} pptx_ct_a_text_bullet_size_point;

pptx_ct_a_text_bullet_size_point *
pptx_ct_a_text_bullet_size_point_new(xmlNode *node)
{
    pptx_ct_a_text_bullet_size_point *obj;
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
pptx_ct_a_text_bullet_size_point_get_val(const pptx_ct_a_text_bullet_size_point *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_text_bullet_size_point_get_index(pptx_ct_a_text_bullet_size_point *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_bullet_size_point_free(pptx_ct_a_text_bullet_size_point *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}