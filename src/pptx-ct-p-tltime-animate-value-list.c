#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-animate-value-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltime-animate-value.h>

typedef struct pptx_ct_p_tltime_animate_value_list_s {
    pptx_ct_p_tltime_animate_value **tav;
    int32_t index;
} pptx_ct_p_tltime_animate_value_list;

pptx_ct_p_tltime_animate_value_list *
pptx_ct_p_tltime_animate_value_list_new(xmlNode *node)
{
    pptx_ct_p_tltime_animate_value_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tav");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tav = malloc((nodes->nodeNr + 1) * sizeof *obj->tav);
            if (obj->tav != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tav;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tltime_animate_value_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tav);
                    obj->tav = NULL;
                } else {
                    obj->tav[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tav = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tav = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltime_animate_value **
pptx_ct_p_tltime_animate_value_list_get_tav(const pptx_ct_p_tltime_animate_value_list *const obj)
{
    return obj->tav;
}

int32_t
pptx_ct_p_tltime_animate_value_list_get_index(pptx_ct_p_tltime_animate_value_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_animate_value_list_free(pptx_ct_p_tltime_animate_value_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->tav != NULL) {
        for (int i = 0; obj->tav[i] != NULL; ++i) {
            pptx_ct_p_tltime_animate_value_free(obj->tav[i]);
        }
        free(obj->tav);
    }

    free(obj);
}