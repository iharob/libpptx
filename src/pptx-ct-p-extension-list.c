#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-extension-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension.h>

typedef struct pptx_ct_p_extension_list_s {
    pptx_ct_p_extension **extension_list_ext;
    int32_t index;
} pptx_ct_p_extension_list;

pptx_ct_p_extension_list *
pptx_ct_p_extension_list_new(xmlNode *node)
{
    pptx_ct_p_extension_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:ext");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->extension_list_ext = malloc((nodes->nodeNr + 1) * sizeof *obj->extension_list_ext);
            if (obj->extension_list_ext != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->extension_list_ext;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_extension_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->extension_list_ext);
                    obj->extension_list_ext = NULL;
                } else {
                    obj->extension_list_ext[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->extension_list_ext = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->extension_list_ext = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension **
pptx_ct_p_extension_list_get_extension_list_ext(const pptx_ct_p_extension_list *const obj)
{
    return obj->extension_list_ext;
}

int32_t
pptx_ct_p_extension_list_get_index(pptx_ct_p_extension_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_extension_list_free(pptx_ct_p_extension_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->extension_list_ext != NULL) {
        for (int i = 0; obj->extension_list_ext[i] != NULL; ++i) {
            pptx_ct_p_extension_free(obj->extension_list_ext[i]);
        }
        free(obj->extension_list_ext);
    }

    free(obj);
}