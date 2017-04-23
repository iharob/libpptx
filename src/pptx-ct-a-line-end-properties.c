#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-end-properties.h>
/* Imported internal stuff */
#include <private/pptx-st-line-end-type.h>
#include <private/pptx-st-line-end-width.h>
#include <private/pptx-st-line-end-length.h>

typedef struct pptx_ct_a_line_end_properties_s {
    pptx_st_line_end_type_token_enum type;
    pptx_st_line_end_width_token_enum w;
    pptx_st_line_end_length_token_enum len;
    int32_t index;
} pptx_ct_a_line_end_properties;

pptx_ct_a_line_end_properties *
pptx_ct_a_line_end_properties_new(xmlNode *node)
{
    pptx_ct_a_line_end_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->type = pptx_get_st_line_end_type(node, (const xmlChar *) "type");
    obj->w = pptx_get_st_line_end_width(node, (const xmlChar *) "w");
    obj->len = pptx_get_st_line_end_length(node, (const xmlChar *) "len");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_line_end_type_token_enum 
pptx_ct_a_line_end_properties_get_type(const pptx_ct_a_line_end_properties *const obj)
{
    return obj->type;
}

pptx_st_line_end_width_token_enum 
pptx_ct_a_line_end_properties_get_w(const pptx_ct_a_line_end_properties *const obj)
{
    return obj->w;
}

pptx_st_line_end_length_token_enum 
pptx_ct_a_line_end_properties_get_len(const pptx_ct_a_line_end_properties *const obj)
{
    return obj->len;
}

int32_t
pptx_ct_a_line_end_properties_get_index(pptx_ct_a_line_end_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_end_properties_free(pptx_ct_a_line_end_properties *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}