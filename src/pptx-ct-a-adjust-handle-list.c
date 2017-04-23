#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-adjust-handle-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-xyadjust-handle.h>
#include <private/pptx-ct-a-polar-adjust-handle.h>

typedef struct pptx_ct_a_adjust_handle_list_s {
    pptx_ct_a_xyadjust_handle **ah_xy;
    pptx_ct_a_polar_adjust_handle **ah_polar;
    int32_t index;
} pptx_ct_a_adjust_handle_list;

pptx_ct_a_adjust_handle_list *
pptx_ct_a_adjust_handle_list_new(xmlNode *node)
{
    pptx_ct_a_adjust_handle_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ahXY");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ah_xy = malloc((nodes->nodeNr + 1) * sizeof *obj->ah_xy);
            if (obj->ah_xy != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ah_xy;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_xyadjust_handle_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ah_xy);
                    obj->ah_xy = NULL;
                } else {
                    obj->ah_xy[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ah_xy = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ah_xy = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ahPolar");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ah_polar = malloc((nodes->nodeNr + 1) * sizeof *obj->ah_polar);
            if (obj->ah_polar != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ah_polar;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_polar_adjust_handle_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ah_polar);
                    obj->ah_polar = NULL;
                } else {
                    obj->ah_polar[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ah_polar = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ah_polar = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_xyadjust_handle **
pptx_ct_a_adjust_handle_list_get_ah_xy(const pptx_ct_a_adjust_handle_list *const obj)
{
    return obj->ah_xy;
}

pptx_ct_a_polar_adjust_handle **
pptx_ct_a_adjust_handle_list_get_ah_polar(const pptx_ct_a_adjust_handle_list *const obj)
{
    return obj->ah_polar;
}

int32_t
pptx_ct_a_adjust_handle_list_get_index(pptx_ct_a_adjust_handle_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_adjust_handle_list_free(pptx_ct_a_adjust_handle_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->ah_xy != NULL) {
        for (int i = 0; obj->ah_xy[i] != NULL; ++i) {
            pptx_ct_a_xyadjust_handle_free(obj->ah_xy[i]);
        }
        free(obj->ah_xy);
    }

    if (obj->ah_polar != NULL) {
        for (int i = 0; obj->ah_polar[i] != NULL; ++i) {
            pptx_ct_a_polar_adjust_handle_free(obj->ah_polar[i]);
        }
        free(obj->ah_polar);
    }

    free(obj);
}