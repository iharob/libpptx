#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlby-rgb-color-transform.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tlby_rgb_color_transform_s {
    pptx_string r;
    pptx_string g;
    pptx_string b;
    int32_t index;
} pptx_ct_p_tlby_rgb_color_transform;

pptx_ct_p_tlby_rgb_color_transform *
pptx_ct_p_tlby_rgb_color_transform_new(xmlNode *node)
{
    pptx_ct_p_tlby_rgb_color_transform *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r");
    obj->g = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "g");
    obj->b = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "b");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_tlby_rgb_color_transform_get_r(const pptx_ct_p_tlby_rgb_color_transform *const obj)
{
    return obj->r;
}

pptx_string 
pptx_ct_p_tlby_rgb_color_transform_get_g(const pptx_ct_p_tlby_rgb_color_transform *const obj)
{
    return obj->g;
}

pptx_string 
pptx_ct_p_tlby_rgb_color_transform_get_b(const pptx_ct_p_tlby_rgb_color_transform *const obj)
{
    return obj->b;
}

int32_t
pptx_ct_p_tlby_rgb_color_transform_get_index(pptx_ct_p_tlby_rgb_color_transform *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlby_rgb_color_transform_free(pptx_ct_p_tlby_rgb_color_transform *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r);
    xmlFree(obj->g);
    xmlFree(obj->b);
    free(obj);
}