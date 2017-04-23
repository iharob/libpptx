#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-row.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-cell.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_table_row_s {
    pptx_ct_a_table_cell **tc;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string h;
    int32_t index;
} pptx_ct_a_table_row;

pptx_ct_a_table_row *
pptx_ct_a_table_row_new(xmlNode *node)
{
    pptx_ct_a_table_row *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tc");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tc = malloc((nodes->nodeNr + 1) * sizeof *obj->tc);
            if (obj->tc != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tc;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_table_cell_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tc);
                    obj->tc = NULL;
                } else {
                    obj->tc[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tc = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tc = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->h = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "h");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_cell **
pptx_ct_a_table_row_get_tc(const pptx_ct_a_table_row *const obj)
{
    return obj->tc;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_row_get_ext_lst(const pptx_ct_a_table_row *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_table_row_get_h(const pptx_ct_a_table_row *const obj)
{
    return obj->h;
}

int32_t
pptx_ct_a_table_row_get_index(pptx_ct_a_table_row *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_row_free(pptx_ct_a_table_row *obj)
{
    if (obj == NULL)
        return;
    if (obj->tc != NULL) {
        for (int i = 0; obj->tc[i] != NULL; ++i) {
            pptx_ct_a_table_cell_free(obj->tc[i]);
        }
        free(obj->tc);
    }

    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->h);
    free(obj);
}