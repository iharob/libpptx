#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-num-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-num-val.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_num_data_s {
    pptx_string format_code;
    pptx_uint pt_count;
    pptx_ct_a_num_val **pt;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_num_data;

pptx_ct_a_num_data *
pptx_ct_a_num_data_new(xmlNode *node)
{
    pptx_ct_a_num_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->format_code = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:formatCode");
    obj->pt_count = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:ptCount");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pt");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_num_val_new;;
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

pptx_string 
pptx_ct_a_num_data_get_format_code(const pptx_ct_a_num_data *const obj)
{
    return obj->format_code;
}

pptx_uint 
pptx_ct_a_num_data_get_pt_count(const pptx_ct_a_num_data *const obj)
{
    return obj->pt_count;
}

pptx_ct_a_num_val **
pptx_ct_a_num_data_get_pt(const pptx_ct_a_num_data *const obj)
{
    return obj->pt;
}

pptx_ct_a_extension_list *
pptx_ct_a_num_data_get_ext_lst(const pptx_ct_a_num_data *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_num_data_get_index(pptx_ct_a_num_data *obj)
{
    return obj->index;
}

void
pptx_ct_a_num_data_free(pptx_ct_a_num_data *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->format_code);
    if (obj->pt != NULL) {
        for (int i = 0; obj->pt[i] != NULL; ++i) {
            pptx_ct_a_num_val_free(obj->pt[i]);
        }
        free(obj->pt);
    }

    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}