#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-tab-stop.h>
/* Imported internal stuff */
#include <private/pptx-st-text-tab-align-type.h>

typedef struct pptx_ct_a_text_tab_stop_s {
    pptx_string pos;
    pptx_st_text_tab_align_type_token_enum algn;
    int32_t index;
} pptx_ct_a_text_tab_stop;

pptx_ct_a_text_tab_stop *
pptx_ct_a_text_tab_stop_new(xmlNode *node)
{
    pptx_ct_a_text_tab_stop *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->pos = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "pos");
    obj->algn = pptx_get_st_text_tab_align_type(node, (const xmlChar *) "algn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_text_tab_stop_get_pos(const pptx_ct_a_text_tab_stop *const obj)
{
    return obj->pos;
}

pptx_st_text_tab_align_type_token_enum 
pptx_ct_a_text_tab_stop_get_algn(const pptx_ct_a_text_tab_stop *const obj)
{
    return obj->algn;
}

int32_t
pptx_ct_a_text_tab_stop_get_index(pptx_ct_a_text_tab_stop *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_tab_stop_free(pptx_ct_a_text_tab_stop *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->pos);
    free(obj);
}