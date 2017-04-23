#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-size.h>
/* Imported internal stuff */
#include <private/pptx-st-slide-size-type.h>

typedef struct pptx_ct_p_slide_size_s {
    pptx_int cx;
    pptx_int cy;
    pptx_st_slide_size_type_token_enum type;
    int32_t index;
} pptx_ct_p_slide_size;

pptx_ct_p_slide_size *
pptx_ct_p_slide_size_new(xmlNode *node)
{
    pptx_ct_p_slide_size *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->cx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "cx");
    obj->cy = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "cy");
    obj->type = pptx_get_st_slide_size_type(node, (const xmlChar *) "type");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_p_slide_size_get_cx(const pptx_ct_p_slide_size *const obj)
{
    return obj->cx;
}

pptx_int 
pptx_ct_p_slide_size_get_cy(const pptx_ct_p_slide_size *const obj)
{
    return obj->cy;
}

pptx_st_slide_size_type_token_enum 
pptx_ct_p_slide_size_get_type(const pptx_ct_p_slide_size *const obj)
{
    return obj->type;
}

int32_t
pptx_ct_p_slide_size_get_index(pptx_ct_p_slide_size *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_size_free(pptx_ct_p_slide_size *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}