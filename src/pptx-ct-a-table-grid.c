#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-grid.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-col.h>

typedef struct pptx_ct_a_table_grid_s {
    pptx_ct_a_table_col **grid_col;
    int32_t index;
} pptx_ct_a_table_grid;

pptx_ct_a_table_grid *
pptx_ct_a_table_grid_new(xmlNode *node)
{
    pptx_ct_a_table_grid *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gridCol");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->grid_col = malloc((nodes->nodeNr + 1) * sizeof *obj->grid_col);
            if (obj->grid_col != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->grid_col;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_table_col_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->grid_col);
                    obj->grid_col = NULL;
                } else {
                    obj->grid_col[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->grid_col = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grid_col = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_col **
pptx_ct_a_table_grid_get_grid_col(const pptx_ct_a_table_grid *const obj)
{
    return obj->grid_col;
}

int32_t
pptx_ct_a_table_grid_get_index(pptx_ct_a_table_grid *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_grid_free(pptx_ct_a_table_grid *obj)
{
    if (obj == NULL)
        return;
    if (obj->grid_col != NULL) {
        for (int i = 0; obj->grid_col[i] != NULL; ++i) {
            pptx_ct_a_table_col_free(obj->grid_col[i]);
        }
        free(obj->grid_col);
    }

    free(obj);
}