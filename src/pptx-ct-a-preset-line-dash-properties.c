#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-preset-line-dash-properties.h>
/* Imported internal stuff */
#include <private/pptx-st-preset-line-dash-val.h>

typedef struct pptx_ct_a_preset_line_dash_properties_s {
    pptx_st_preset_line_dash_val_token_enum val;
    int32_t index;
} pptx_ct_a_preset_line_dash_properties;

pptx_ct_a_preset_line_dash_properties *
pptx_ct_a_preset_line_dash_properties_new(xmlNode *node)
{
    pptx_ct_a_preset_line_dash_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_preset_line_dash_val(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_preset_line_dash_val_token_enum 
pptx_ct_a_preset_line_dash_properties_get_val(const pptx_ct_a_preset_line_dash_properties *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_preset_line_dash_properties_get_index(pptx_ct_a_preset_line_dash_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_preset_line_dash_properties_free(pptx_ct_a_preset_line_dash_properties *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}