#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltemplate-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltemplate.h>

typedef struct pptx_ct_p_tltemplate_list_s {
    pptx_ct_p_tltemplate **tmpl;
    int32_t index;
} pptx_ct_p_tltemplate_list;

pptx_ct_p_tltemplate_list *
pptx_ct_p_tltemplate_list_new(xmlNode *node)
{
    pptx_ct_p_tltemplate_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltemplate **
pptx_ct_p_tltemplate_list_get_tmpl(const pptx_ct_p_tltemplate_list *const obj)
{
    return obj->tmpl;
}

int32_t
pptx_ct_p_tltemplate_list_get_index(pptx_ct_p_tltemplate_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltemplate_list_free(pptx_ct_p_tltemplate_list *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}