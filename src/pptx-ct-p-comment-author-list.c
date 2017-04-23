#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-comment-author-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-comment-author.h>

typedef struct pptx_ct_p_comment_author_list_s {
    pptx_ct_p_comment_author **cm_author;
    int32_t index;
} pptx_ct_p_comment_author_list;

pptx_ct_p_comment_author_list *
pptx_ct_p_comment_author_list_new(xmlNode *node)
{
    pptx_ct_p_comment_author_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cmAuthor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cm_author = malloc((nodes->nodeNr + 1) * sizeof *obj->cm_author);
            if (obj->cm_author != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cm_author;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_comment_author_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cm_author);
                    obj->cm_author = NULL;
                } else {
                    obj->cm_author[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cm_author = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cm_author = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_comment_author **
pptx_ct_p_comment_author_list_get_cm_author(const pptx_ct_p_comment_author_list *const obj)
{
    return obj->cm_author;
}

int32_t
pptx_ct_p_comment_author_list_get_index(pptx_ct_p_comment_author_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_comment_author_list_free(pptx_ct_p_comment_author_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cm_author != NULL) {
        for (int i = 0; obj->cm_author[i] != NULL; ++i) {
            pptx_ct_p_comment_author_free(obj->cm_author[i]);
        }
        free(obj->cm_author);
    }

    free(obj);
}