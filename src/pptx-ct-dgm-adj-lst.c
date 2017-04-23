#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-adj-lst.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-adj.h>

typedef struct pptx_ct_dgm_adj_lst_s {
    pptx_ct_dgm_adj **adj;
    int32_t index;
} pptx_ct_dgm_adj_lst;

pptx_ct_dgm_adj_lst *
pptx_ct_dgm_adj_lst_new(xmlNode *node)
{
    pptx_ct_dgm_adj_lst *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:adj");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->adj = malloc((nodes->nodeNr + 1) * sizeof *obj->adj);
            if (obj->adj != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->adj;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_adj_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->adj);
                    obj->adj = NULL;
                } else {
                    obj->adj[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->adj = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->adj = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_adj **
pptx_ct_dgm_adj_lst_get_adj(const pptx_ct_dgm_adj_lst *const obj)
{
    return obj->adj;
}

int32_t
pptx_ct_dgm_adj_lst_get_index(pptx_ct_dgm_adj_lst *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_adj_lst_free(pptx_ct_dgm_adj_lst *obj)
{
    if (obj == NULL)
        return;
    if (obj->adj != NULL) {
        for (int i = 0; obj->adj[i] != NULL; ++i) {
            pptx_ct_dgm_adj_free(obj->adj[i]);
        }
        free(obj->adj);
    }

    free(obj);
}