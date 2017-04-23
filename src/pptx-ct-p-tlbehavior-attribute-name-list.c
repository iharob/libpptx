#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlbehavior-attribute-name-list.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tlbehavior_attribute_name_list_s {

    int32_t index;
} pptx_ct_p_tlbehavior_attribute_name_list;

pptx_ct_p_tlbehavior_attribute_name_list *
pptx_ct_p_tlbehavior_attribute_name_list_new(xmlNode *node)
{
    pptx_ct_p_tlbehavior_attribute_name_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

int32_t
pptx_ct_p_tlbehavior_attribute_name_list_get_index(pptx_ct_p_tlbehavior_attribute_name_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlbehavior_attribute_name_list_free(pptx_ct_p_tlbehavior_attribute_name_list *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}