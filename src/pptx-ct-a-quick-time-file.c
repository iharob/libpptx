#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-quick-time-file.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_quick_time_file_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string link;
    int32_t index;
} pptx_ct_a_quick_time_file;

pptx_ct_a_quick_time_file *
pptx_ct_a_quick_time_file_new(xmlNode *node)
{
    pptx_ct_a_quick_time_file *obj;
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
    obj->link = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:link");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_quick_time_file_get_ext_lst(const pptx_ct_a_quick_time_file *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_quick_time_file_get_link(const pptx_ct_a_quick_time_file *const obj)
{
    return obj->link;
}

int32_t
pptx_ct_a_quick_time_file_get_index(pptx_ct_a_quick_time_file *obj)
{
    return obj->index;
}

void
pptx_ct_a_quick_time_file_free(pptx_ct_a_quick_time_file *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->link);
    free(obj);
}