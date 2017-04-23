#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-layout-id-list-entry.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_slide_layout_id_list_entry_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_uint id;
    pptx_string r_id;
    int32_t index;
} pptx_ct_p_slide_layout_id_list_entry;

pptx_ct_p_slide_layout_id_list_entry *
pptx_ct_p_slide_layout_id_list_entry_new(xmlNode *node)
{
    pptx_ct_p_slide_layout_id_list_entry *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_slide_layout_id_list_entry_get_ext_lst(const pptx_ct_p_slide_layout_id_list_entry *const obj)
{
    return obj->ext_lst;
}

pptx_uint 
pptx_ct_p_slide_layout_id_list_entry_get_id(const pptx_ct_p_slide_layout_id_list_entry *const obj)
{
    return obj->id;
}

pptx_string 
pptx_ct_p_slide_layout_id_list_entry_get_r_id(const pptx_ct_p_slide_layout_id_list_entry *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_p_slide_layout_id_list_entry_get_index(pptx_ct_p_slide_layout_id_list_entry *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_layout_id_list_entry_free(pptx_ct_p_slide_layout_id_list_entry *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->r_id);
    free(obj);
}