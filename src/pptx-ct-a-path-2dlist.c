#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-2dlist.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-path-2d.h>

typedef struct pptx_ct_a_path_2dlist_s {
    pptx_ct_a_path_2d **path;
    int32_t index;
} pptx_ct_a_path_2dlist;

pptx_ct_a_path_2dlist *
pptx_ct_a_path_2dlist_new(xmlNode *node)
{
    pptx_ct_a_path_2dlist *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:path");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->path = malloc((nodes->nodeNr + 1) * sizeof *obj->path);
            if (obj->path != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->path;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2d_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->path);
                    obj->path = NULL;
                } else {
                    obj->path[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->path = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->path = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_path_2d **
pptx_ct_a_path_2dlist_get_path(const pptx_ct_a_path_2dlist *const obj)
{
    return obj->path;
}

int32_t
pptx_ct_a_path_2dlist_get_index(pptx_ct_a_path_2dlist *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_2dlist_free(pptx_ct_a_path_2dlist *obj)
{
    if (obj == NULL)
        return;
    if (obj->path != NULL) {
        for (int i = 0; obj->path[i] != NULL; ++i) {
            pptx_ct_a_path_2d_free(obj->path[i]);
        }
        free(obj->path);
    }

    free(obj);
}