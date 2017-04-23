#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-pivot-source.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_pivot_source_s {
    pptx_string name;
    pptx_uint fmt_id;
    pptx_ct_a_extension_list **ext_lst;
    int32_t index;
} pptx_ct_a_pivot_source;

pptx_ct_a_pivot_source *
pptx_ct_a_pivot_source_new(xmlNode *node)
{
    pptx_ct_a_pivot_source *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->name = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:name");
    obj->fmt_id = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:fmtId");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ext_lst = malloc((nodes->nodeNr + 1) * sizeof *obj->ext_lst);
            if (obj->ext_lst != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ext_lst;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_extension_list_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ext_lst);
                    obj->ext_lst = NULL;
                } else {
                    obj->ext_lst[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ext_lst = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_pivot_source_get_name(const pptx_ct_a_pivot_source *const obj)
{
    return obj->name;
}

pptx_uint 
pptx_ct_a_pivot_source_get_fmt_id(const pptx_ct_a_pivot_source *const obj)
{
    return obj->fmt_id;
}

pptx_ct_a_extension_list **
pptx_ct_a_pivot_source_get_ext_lst(const pptx_ct_a_pivot_source *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_pivot_source_get_index(pptx_ct_a_pivot_source *obj)
{
    return obj->index;
}

void
pptx_ct_a_pivot_source_free(pptx_ct_a_pivot_source *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->name);
    if (obj->ext_lst != NULL) {
        for (int i = 0; obj->ext_lst[i] != NULL; ++i) {
            pptx_ct_a_extension_list_free(obj->ext_lst[i]);
        }
        free(obj->ext_lst);
    }

    free(obj);
}