#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-comment-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-comment.h>

typedef struct pptx_ct_p_comment_list_s {
    pptx_ct_p_comment **cm;
    int32_t index;
} pptx_ct_p_comment_list;

pptx_ct_p_comment_list *
pptx_ct_p_comment_list_new(xmlNode *node)
{
    pptx_ct_p_comment_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cm = malloc((nodes->nodeNr + 1) * sizeof *obj->cm);
            if (obj->cm != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cm;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_comment_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cm);
                    obj->cm = NULL;
                } else {
                    obj->cm[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cm = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cm = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_comment **
pptx_ct_p_comment_list_get_cm(const pptx_ct_p_comment_list *const obj)
{
    return obj->cm;
}

int32_t
pptx_ct_p_comment_list_get_index(pptx_ct_p_comment_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_comment_list_free(pptx_ct_p_comment_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cm != NULL) {
        for (int i = 0; obj->cm[i] != NULL; ++i) {
            pptx_ct_p_comment_free(obj->cm[i]);
        }
        free(obj->cm);
    }

    free(obj);
}