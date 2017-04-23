#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-outline-view-slide-entry.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_outline_view_slide_entry_s {
    pptx_string r_id;
    pptx_bool collapse;
    int32_t index;
} pptx_ct_p_outline_view_slide_entry;

pptx_ct_p_outline_view_slide_entry *
pptx_ct_p_outline_view_slide_entry_new(xmlNode *node)
{
    pptx_ct_p_outline_view_slide_entry *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->collapse = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "collapse");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_outline_view_slide_entry_get_r_id(const pptx_ct_p_outline_view_slide_entry *const obj)
{
    return obj->r_id;
}

pptx_bool 
pptx_ct_p_outline_view_slide_entry_get_collapse(const pptx_ct_p_outline_view_slide_entry *const obj)
{
    return obj->collapse;
}

int32_t
pptx_ct_p_outline_view_slide_entry_get_index(pptx_ct_p_outline_view_slide_entry *obj)
{
    return obj->index;
}

void
pptx_ct_p_outline_view_slide_entry_free(pptx_ct_p_outline_view_slide_entry *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r_id);
    free(obj);
}