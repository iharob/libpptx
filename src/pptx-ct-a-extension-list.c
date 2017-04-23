#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-extension-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-extension.h>

typedef struct pptx_ct_a_extension_list_s {
    pptx_ct_a_extension **ext;
    int32_t index;
} pptx_ct_a_extension_list;

pptx_ct_a_extension_list *
pptx_ct_a_extension_list_new(xmlNode *node)
{
    pptx_ct_a_extension_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ext");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ext = malloc((nodes->nodeNr + 1) * sizeof *obj->ext);
            if (obj->ext != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ext;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_extension_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ext);
                    obj->ext = NULL;
                } else {
                    obj->ext[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ext = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_extension **
pptx_ct_a_extension_list_get_ext(const pptx_ct_a_extension_list *const obj)
{
    return obj->ext;
}

int32_t
pptx_ct_a_extension_list_get_index(pptx_ct_a_extension_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_extension_list_free(pptx_ct_a_extension_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->ext != NULL) {
        for (int i = 0; obj->ext[i] != NULL; ++i) {
            pptx_ct_a_extension_free(obj->ext[i]);
        }
        free(obj->ext);
    }

    free(obj);
}