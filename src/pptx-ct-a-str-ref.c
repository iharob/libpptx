#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-str-ref.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-str-data.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_str_ref_s {
    pptx_string f;
    pptx_ct_a_str_data *str_cache;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_str_ref;

pptx_ct_a_str_ref *
pptx_ct_a_str_ref_new(xmlNode *node)
{
    pptx_ct_a_str_ref *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->f = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:f");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:strCache");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->str_cache = NULL;
        } else {
            obj->str_cache = pptx_ct_a_str_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->str_cache = NULL;
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
pptx_ct_a_str_ref_get_f(const pptx_ct_a_str_ref *const obj)
{
    return obj->f;
}

pptx_ct_a_str_data *
pptx_ct_a_str_ref_get_str_cache(const pptx_ct_a_str_ref *const obj)
{
    return obj->str_cache;
}

pptx_ct_a_extension_list *
pptx_ct_a_str_ref_get_ext_lst(const pptx_ct_a_str_ref *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_str_ref_get_index(pptx_ct_a_str_ref *obj)
{
    return obj->index;
}

void
pptx_ct_a_str_ref_free(pptx_ct_a_str_ref *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->f);
    pptx_ct_a_str_data_free(obj->str_cache);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}