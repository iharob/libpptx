#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-categories.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-category.h>

typedef struct pptx_ct_dgm_categories_s {
    pptx_ct_dgm_category **cat;
    int32_t index;
} pptx_ct_dgm_categories;

pptx_ct_dgm_categories *
pptx_ct_dgm_categories_new(xmlNode *node)
{
    pptx_ct_dgm_categories *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:cat");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cat = malloc((nodes->nodeNr + 1) * sizeof *obj->cat);
            if (obj->cat != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cat;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_category_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cat);
                    obj->cat = NULL;
                } else {
                    obj->cat[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cat = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cat = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_category **
pptx_ct_dgm_categories_get_cat(const pptx_ct_dgm_categories *const obj)
{
    return obj->cat;
}

int32_t
pptx_ct_dgm_categories_get_index(pptx_ct_dgm_categories *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_categories_free(pptx_ct_dgm_categories *obj)
{
    if (obj == NULL)
        return;
    if (obj->cat != NULL) {
        for (int i = 0; obj->cat[i] != NULL; ++i) {
            pptx_ct_dgm_category_free(obj->cat[i]);
        }
        free(obj->cat);
    }

    free(obj);
}