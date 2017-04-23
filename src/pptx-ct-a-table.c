#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-properties.h>
#include <private/pptx-ct-a-table-grid.h>
#include <private/pptx-ct-a-table-row.h>

typedef struct pptx_ct_a_table_s {
    pptx_ct_a_table_properties *tbl_pr;
    pptx_ct_a_table_grid *tbl_grid;
    pptx_ct_a_table_row **tr;
    int32_t index;
} pptx_ct_a_table;

pptx_ct_a_table *
pptx_ct_a_table_new(xmlNode *node)
{
    pptx_ct_a_table *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tblPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tbl_pr = NULL;
        } else {
            obj->tbl_pr = pptx_ct_a_table_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tbl_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tblGrid");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tbl_grid = NULL;
        } else {
            obj->tbl_grid = pptx_ct_a_table_grid_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tbl_grid = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tr = malloc((nodes->nodeNr + 1) * sizeof *obj->tr);
            if (obj->tr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_table_row_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tr);
                    obj->tr = NULL;
                } else {
                    obj->tr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_properties *
pptx_ct_a_table_get_tbl_pr(const pptx_ct_a_table *const obj)
{
    return obj->tbl_pr;
}

pptx_ct_a_table_grid *
pptx_ct_a_table_get_tbl_grid(const pptx_ct_a_table *const obj)
{
    return obj->tbl_grid;
}

pptx_ct_a_table_row **
pptx_ct_a_table_get_tr(const pptx_ct_a_table *const obj)
{
    return obj->tr;
}

int32_t
pptx_ct_a_table_get_index(pptx_ct_a_table *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_free(pptx_ct_a_table *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_table_properties_free(obj->tbl_pr);
    pptx_ct_a_table_grid_free(obj->tbl_grid);
    if (obj->tr != NULL) {
        for (int i = 0; obj->tr[i] != NULL; ++i) {
            pptx_ct_a_table_row_free(obj->tr[i]);
        }
        free(obj->tr);
    }

    free(obj);
}