#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-relative-rect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_relative_rect_s {
    pptx_string l;
    pptx_string t;
    pptx_string r;
    pptx_string b;
    int32_t index;
} pptx_ct_a_relative_rect;

pptx_ct_a_relative_rect *
pptx_ct_a_relative_rect_new(xmlNode *node)
{
    pptx_ct_a_relative_rect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->l = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "l");
    obj->t = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "t");
    obj->r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r");
    obj->b = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "b");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_relative_rect_get_l(const pptx_ct_a_relative_rect *const obj)
{
    return obj->l;
}

pptx_string 
pptx_ct_a_relative_rect_get_t(const pptx_ct_a_relative_rect *const obj)
{
    return obj->t;
}

pptx_string 
pptx_ct_a_relative_rect_get_r(const pptx_ct_a_relative_rect *const obj)
{
    return obj->r;
}

pptx_string 
pptx_ct_a_relative_rect_get_b(const pptx_ct_a_relative_rect *const obj)
{
    return obj->b;
}

int32_t
pptx_ct_a_relative_rect_get_index(pptx_ct_a_relative_rect *obj)
{
    return obj->index;
}

void
pptx_ct_a_relative_rect_free(pptx_ct_a_relative_rect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->l);
    xmlFree(obj->t);
    xmlFree(obj->r);
    xmlFree(obj->b);
    free(obj);
}