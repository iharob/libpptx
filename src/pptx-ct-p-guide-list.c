#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-guide-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-guide.h>

typedef struct pptx_ct_p_guide_list_s {
    pptx_ct_p_guide **guide;
    int32_t index;
} pptx_ct_p_guide_list;

pptx_ct_p_guide_list *
pptx_ct_p_guide_list_new(xmlNode *node)
{
    pptx_ct_p_guide_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:guide");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->guide = malloc((nodes->nodeNr + 1) * sizeof *obj->guide);
            if (obj->guide != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->guide;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_guide_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->guide);
                    obj->guide = NULL;
                } else {
                    obj->guide[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->guide = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->guide = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_guide **
pptx_ct_p_guide_list_get_guide(const pptx_ct_p_guide_list *const obj)
{
    return obj->guide;
}

int32_t
pptx_ct_p_guide_list_get_index(pptx_ct_p_guide_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_guide_list_free(pptx_ct_p_guide_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->guide != NULL) {
        for (int i = 0; obj->guide[i] != NULL; ++i) {
            pptx_ct_p_guide_free(obj->guide[i]);
        }
        free(obj->guide);
    }

    free(obj);
}