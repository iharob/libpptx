#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-show-info-browse.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_show_info_browse_s {
    pptx_bool show_scrollbar;
    int32_t index;
} pptx_ct_p_show_info_browse;

pptx_ct_p_show_info_browse *
pptx_ct_p_show_info_browse_new(xmlNode *node)
{
    pptx_ct_p_show_info_browse *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->show_scrollbar = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showScrollbar");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_p_show_info_browse_get_show_scrollbar(const pptx_ct_p_show_info_browse *const obj)
{
    return obj->show_scrollbar;
}

int32_t
pptx_ct_p_show_info_browse_get_index(pptx_ct_p_show_info_browse *obj)
{
    return obj->index;
}

void
pptx_ct_p_show_info_browse_free(pptx_ct_p_show_info_browse *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}