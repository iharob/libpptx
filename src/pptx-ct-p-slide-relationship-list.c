#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-relationship-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-slide-relationship-list-entry.h>

typedef struct pptx_ct_p_slide_relationship_list_s {
    pptx_ct_p_slide_relationship_list_entry **sld;
    int32_t index;
} pptx_ct_p_slide_relationship_list;

pptx_ct_p_slide_relationship_list *
pptx_ct_p_slide_relationship_list_new(xmlNode *node)
{
    pptx_ct_p_slide_relationship_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sld");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->sld = malloc((nodes->nodeNr + 1) * sizeof *obj->sld);
            if (obj->sld != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->sld;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_slide_relationship_list_entry_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->sld);
                    obj->sld = NULL;
                } else {
                    obj->sld[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->sld = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_slide_relationship_list_entry **
pptx_ct_p_slide_relationship_list_get_sld(const pptx_ct_p_slide_relationship_list *const obj)
{
    return obj->sld;
}

int32_t
pptx_ct_p_slide_relationship_list_get_index(pptx_ct_p_slide_relationship_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_relationship_list_free(pptx_ct_p_slide_relationship_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->sld != NULL) {
        for (int i = 0; obj->sld[i] != NULL; ++i) {
            pptx_ct_p_slide_relationship_list_entry_free(obj->sld[i]);
        }
        free(obj->sld);
    }

    free(obj);
}