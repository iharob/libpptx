#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-pt-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-pt.h>

typedef struct pptx_ct_dgm_pt_list_s {
    pptx_ct_dgm_pt **pt;
    int32_t index;
} pptx_ct_dgm_pt_list;

pptx_ct_dgm_pt_list *
pptx_ct_dgm_pt_list_new(xmlNode *node)
{
    pptx_ct_dgm_pt_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:pt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pt = malloc((nodes->nodeNr + 1) * sizeof *obj->pt);
            if (obj->pt != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pt;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_pt_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->pt);
                    obj->pt = NULL;
                } else {
                    obj->pt[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pt = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pt = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_pt **
pptx_ct_dgm_pt_list_get_pt(const pptx_ct_dgm_pt_list *const obj)
{
    return obj->pt;
}

int32_t
pptx_ct_dgm_pt_list_get_index(pptx_ct_dgm_pt_list *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_pt_list_free(pptx_ct_dgm_pt_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->pt != NULL) {
        for (int i = 0; obj->pt[i] != NULL; ++i) {
            pptx_ct_dgm_pt_free(obj->pt[i]);
        }
        free(obj->pt);
    }

    free(obj);
}