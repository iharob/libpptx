#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-ole-object-link.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_ole_object_link_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool update_automatic;
    int32_t index;
} pptx_ct_p_ole_object_link;

pptx_ct_p_ole_object_link *
pptx_ct_p_ole_object_link_new(xmlNode *node)
{
    pptx_ct_p_ole_object_link *obj;
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
    obj->update_automatic = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "updateAutomatic");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_ole_object_link_get_ext_lst(const pptx_ct_p_ole_object_link *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_ole_object_link_get_update_automatic(const pptx_ct_p_ole_object_link *const obj)
{
    return obj->update_automatic;
}

int32_t
pptx_ct_p_ole_object_link_get_index(pptx_ct_p_ole_object_link *obj)
{
    return obj->index;
}

void
pptx_ct_p_ole_object_link_free(pptx_ct_p_ole_object_link *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}