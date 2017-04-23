#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-bevel.h>
/* Imported internal stuff */
#include <private/pptx-st-bevel-preset-type.h>

typedef struct pptx_ct_a_bevel_s {
    pptx_long w;
    pptx_long h;
    pptx_st_bevel_preset_type_token_enum prst;
    int32_t index;
} pptx_ct_a_bevel;

pptx_ct_a_bevel *
pptx_ct_a_bevel_new(xmlNode *node)
{
    pptx_ct_a_bevel *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->w = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "w");
    obj->h = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "h");
    obj->prst = pptx_get_st_bevel_preset_type(node, (const xmlChar *) "prst");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_long 
pptx_ct_a_bevel_get_w(const pptx_ct_a_bevel *const obj)
{
    return obj->w;
}

pptx_long 
pptx_ct_a_bevel_get_h(const pptx_ct_a_bevel *const obj)
{
    return obj->h;
}

pptx_st_bevel_preset_type_token_enum 
pptx_ct_a_bevel_get_prst(const pptx_ct_a_bevel *const obj)
{
    return obj->prst;
}

int32_t
pptx_ct_a_bevel_get_index(pptx_ct_a_bevel *obj)
{
    return obj->index;
}

void
pptx_ct_a_bevel_free(pptx_ct_a_bevel *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}