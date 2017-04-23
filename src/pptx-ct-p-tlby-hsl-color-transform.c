#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlby-hsl-color-transform.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tlby_hsl_color_transform_s {
    pptx_int h;
    pptx_string s;
    pptx_string l;
    int32_t index;
} pptx_ct_p_tlby_hsl_color_transform;

pptx_ct_p_tlby_hsl_color_transform *
pptx_ct_p_tlby_hsl_color_transform_new(xmlNode *node)
{
    pptx_ct_p_tlby_hsl_color_transform *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->h = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "h");
    obj->s = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "s");
    obj->l = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "l");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_p_tlby_hsl_color_transform_get_h(const pptx_ct_p_tlby_hsl_color_transform *const obj)
{
    return obj->h;
}

pptx_string 
pptx_ct_p_tlby_hsl_color_transform_get_s(const pptx_ct_p_tlby_hsl_color_transform *const obj)
{
    return obj->s;
}

pptx_string 
pptx_ct_p_tlby_hsl_color_transform_get_l(const pptx_ct_p_tlby_hsl_color_transform *const obj)
{
    return obj->l;
}

int32_t
pptx_ct_p_tlby_hsl_color_transform_get_index(pptx_ct_p_tlby_hsl_color_transform *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlby_hsl_color_transform_free(pptx_ct_p_tlby_hsl_color_transform *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->s);
    xmlFree(obj->l);
    free(obj);
}