#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tag-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-string-tag.h>

typedef struct pptx_ct_p_tag_list_s {
    pptx_ct_p_string_tag **tag;
    int32_t index;
} pptx_ct_p_tag_list;

pptx_ct_p_tag_list *
pptx_ct_p_tag_list_new(xmlNode *node)
{
    pptx_ct_p_tag_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tag");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tag = malloc((nodes->nodeNr + 1) * sizeof *obj->tag);
            if (obj->tag != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tag;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_string_tag_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tag);
                    obj->tag = NULL;
                } else {
                    obj->tag[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tag = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tag = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_string_tag **
pptx_ct_p_tag_list_get_tag(const pptx_ct_p_tag_list *const obj)
{
    return obj->tag;
}

int32_t
pptx_ct_p_tag_list_get_index(pptx_ct_p_tag_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_tag_list_free(pptx_ct_p_tag_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->tag != NULL) {
        for (int i = 0; obj->tag[i] != NULL; ++i) {
            pptx_ct_p_string_tag_free(obj->tag[i]);
        }
        free(obj->tag);
    }

    free(obj);
}