#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-col.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_table_col_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string w;
    int32_t index;
} pptx_ct_a_table_col;

pptx_ct_a_table_col *
pptx_ct_a_table_col_new(xmlNode *node)
{
    pptx_ct_a_table_col *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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
    obj->w = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "w");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_col_get_ext_lst(const pptx_ct_a_table_col *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_table_col_get_w(const pptx_ct_a_table_col *const obj)
{
    return obj->w;
}

int32_t
pptx_ct_a_table_col_get_index(pptx_ct_a_table_col *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_col_free(pptx_ct_a_table_col *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->w);
    free(obj);
}