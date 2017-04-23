#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-custom-show-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-custom-show.h>

typedef struct pptx_ct_p_custom_show_list_s {
    pptx_ct_p_custom_show **cust_show;
    int32_t index;
} pptx_ct_p_custom_show_list;

pptx_ct_p_custom_show_list *
pptx_ct_p_custom_show_list_new(xmlNode *node)
{
    pptx_ct_p_custom_show_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custShow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cust_show = malloc((nodes->nodeNr + 1) * sizeof *obj->cust_show);
            if (obj->cust_show != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cust_show;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_custom_show_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cust_show);
                    obj->cust_show = NULL;
                } else {
                    obj->cust_show[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cust_show = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_show = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_custom_show **
pptx_ct_p_custom_show_list_get_cust_show(const pptx_ct_p_custom_show_list *const obj)
{
    return obj->cust_show;
}

int32_t
pptx_ct_p_custom_show_list_get_index(pptx_ct_p_custom_show_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_custom_show_list_free(pptx_ct_p_custom_show_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cust_show != NULL) {
        for (int i = 0; obj->cust_show[i] != NULL; ++i) {
            pptx_ct_p_custom_show_free(obj->cust_show[i]);
        }
        free(obj->cust_show);
    }

    free(obj);
}