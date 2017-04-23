#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-multi-lvl-str-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-lvl.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_multi_lvl_str_data_s {
    pptx_uint pt_count;
    pptx_ct_a_lvl **lvl;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_multi_lvl_str_data;

pptx_ct_a_multi_lvl_str_data *
pptx_ct_a_multi_lvl_str_data_new(xmlNode *node)
{
    pptx_ct_a_multi_lvl_str_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->pt_count = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:ptCount");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->lvl = malloc((nodes->nodeNr + 1) * sizeof *obj->lvl);
            if (obj->lvl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->lvl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_lvl_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->lvl);
                    obj->lvl = NULL;
                } else {
                    obj->lvl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->lvl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_multi_lvl_str_data_get_pt_count(const pptx_ct_a_multi_lvl_str_data *const obj)
{
    return obj->pt_count;
}

pptx_ct_a_lvl **
pptx_ct_a_multi_lvl_str_data_get_lvl(const pptx_ct_a_multi_lvl_str_data *const obj)
{
    return obj->lvl;
}

pptx_ct_a_extension_list *
pptx_ct_a_multi_lvl_str_data_get_ext_lst(const pptx_ct_a_multi_lvl_str_data *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_multi_lvl_str_data_get_index(pptx_ct_a_multi_lvl_str_data *obj)
{
    return obj->index;
}

void
pptx_ct_a_multi_lvl_str_data_free(pptx_ct_a_multi_lvl_str_data *obj)
{
    if (obj == NULL)
        return;
    if (obj->lvl != NULL) {
        for (int i = 0; obj->lvl[i] != NULL; ++i) {
            pptx_ct_a_lvl_free(obj->lvl[i]);
        }
        free(obj->lvl);
    }

    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}