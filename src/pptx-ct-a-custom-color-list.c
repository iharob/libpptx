#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-custom-color-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-custom-color.h>

typedef struct pptx_ct_a_custom_color_list_s {
    pptx_ct_a_custom_color **cust_clr;
    int32_t index;
} pptx_ct_a_custom_color_list;

pptx_ct_a_custom_color_list *
pptx_ct_a_custom_color_list_new(xmlNode *node)
{
    pptx_ct_a_custom_color_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:custClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cust_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->cust_clr);
            if (obj->cust_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cust_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_custom_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cust_clr);
                    obj->cust_clr = NULL;
                } else {
                    obj->cust_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cust_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_clr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_custom_color **
pptx_ct_a_custom_color_list_get_cust_clr(const pptx_ct_a_custom_color_list *const obj)
{
    return obj->cust_clr;
}

int32_t
pptx_ct_a_custom_color_list_get_index(pptx_ct_a_custom_color_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_custom_color_list_free(pptx_ct_a_custom_color_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cust_clr != NULL) {
        for (int i = 0; obj->cust_clr[i] != NULL; ++i) {
            pptx_ct_a_custom_color_free(obj->cust_clr[i]);
        }
        free(obj->cust_clr);
    }

    free(obj);
}