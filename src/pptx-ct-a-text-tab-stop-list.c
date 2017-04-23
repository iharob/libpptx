#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-tab-stop-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-tab-stop.h>

typedef struct pptx_ct_a_text_tab_stop_list_s {
    pptx_ct_a_text_tab_stop **tab;
    int32_t index;
} pptx_ct_a_text_tab_stop_list;

pptx_ct_a_text_tab_stop_list *
pptx_ct_a_text_tab_stop_list_new(xmlNode *node)
{
    pptx_ct_a_text_tab_stop_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_tab_stop **
pptx_ct_a_text_tab_stop_list_get_tab(const pptx_ct_a_text_tab_stop_list *const obj)
{
    return obj->tab;
}

int32_t
pptx_ct_a_text_tab_stop_list_get_index(pptx_ct_a_text_tab_stop_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_tab_stop_list_free(pptx_ct_a_text_tab_stop_list *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}