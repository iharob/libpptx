#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-control-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-control.h>

typedef struct pptx_ct_p_control_list_s {
    pptx_ct_p_control **control;
    int32_t index;
} pptx_ct_p_control_list;

pptx_ct_p_control_list *
pptx_ct_p_control_list_new(xmlNode *node)
{
    pptx_ct_p_control_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:control");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->control = malloc((nodes->nodeNr + 1) * sizeof *obj->control);
            if (obj->control != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->control;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_control_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->control);
                    obj->control = NULL;
                } else {
                    obj->control[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->control = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->control = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_control **
pptx_ct_p_control_list_get_control(const pptx_ct_p_control_list *const obj)
{
    return obj->control;
}

int32_t
pptx_ct_p_control_list_get_index(pptx_ct_p_control_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_control_list_free(pptx_ct_p_control_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->control != NULL) {
        for (int i = 0; obj->control[i] != NULL; ++i) {
            pptx_ct_p_control_free(obj->control[i]);
        }
        free(obj->control);
    }

    free(obj);
}