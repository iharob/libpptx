#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-condition-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltime-condition.h>

typedef struct pptx_ct_p_tltime_condition_list_s {
    pptx_ct_p_tltime_condition **cond;
    int32_t index;
} pptx_ct_p_tltime_condition_list;

pptx_ct_p_tltime_condition_list *
pptx_ct_p_tltime_condition_list_new(xmlNode *node)
{
    pptx_ct_p_tltime_condition_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cond");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cond = malloc((nodes->nodeNr + 1) * sizeof *obj->cond);
            if (obj->cond != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cond;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tltime_condition_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->cond);
                    obj->cond = NULL;
                } else {
                    obj->cond[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cond = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cond = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltime_condition **
pptx_ct_p_tltime_condition_list_get_cond(const pptx_ct_p_tltime_condition_list *const obj)
{
    return obj->cond;
}

int32_t
pptx_ct_p_tltime_condition_list_get_index(pptx_ct_p_tltime_condition_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_condition_list_free(pptx_ct_p_tltime_condition_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cond != NULL) {
        for (int i = 0; obj->cond[i] != NULL; ++i) {
            pptx_ct_p_tltime_condition_free(obj->cond[i]);
        }
        free(obj->cond);
    }

    free(obj);
}