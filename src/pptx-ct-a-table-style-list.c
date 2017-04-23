#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-style-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-style.h>

typedef struct pptx_ct_a_table_style_list_s {
    pptx_ct_a_table_style **tbl_style;
    pptx_string def;
    int32_t index;
} pptx_ct_a_table_style_list;

pptx_ct_a_table_style_list *
pptx_ct_a_table_style_list_new(xmlNode *node)
{
    pptx_ct_a_table_style_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tblStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tbl_style = malloc((nodes->nodeNr + 1) * sizeof *obj->tbl_style);
            if (obj->tbl_style != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tbl_style;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_table_style_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tbl_style);
                    obj->tbl_style = NULL;
                } else {
                    obj->tbl_style[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tbl_style = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tbl_style = NULL;
    }
    obj->def = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "def");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_style **
pptx_ct_a_table_style_list_get_tbl_style(const pptx_ct_a_table_style_list *const obj)
{
    return obj->tbl_style;
}

pptx_string 
pptx_ct_a_table_style_list_get_def(const pptx_ct_a_table_style_list *const obj)
{
    return obj->def;
}

int32_t
pptx_ct_a_table_style_list_get_index(pptx_ct_a_table_style_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_style_list_free(pptx_ct_a_table_style_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->tbl_style != NULL) {
        for (int i = 0; obj->tbl_style[i] != NULL; ++i) {
            pptx_ct_a_table_style_free(obj->tbl_style[i]);
        }
        free(obj->tbl_style);
    }

    xmlFree(obj->def);
    free(obj);
}