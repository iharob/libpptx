#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-sync-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_slide_sync_properties_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_string server_sld_id;
    pptx_string server_sld_modified_time;
    pptx_string client_inserted_time;
    int32_t index;
} pptx_ct_p_slide_sync_properties;

pptx_ct_p_slide_sync_properties *
pptx_ct_p_slide_sync_properties_new(xmlNode *node)
{
    pptx_ct_p_slide_sync_properties *obj;
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
    obj->server_sld_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "serverSldId");
    obj->server_sld_modified_time = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "serverSldModifiedTime");
    obj->client_inserted_time = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "clientInsertedTime");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_slide_sync_properties_get_ext_lst(const pptx_ct_p_slide_sync_properties *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_p_slide_sync_properties_get_server_sld_id(const pptx_ct_p_slide_sync_properties *const obj)
{
    return obj->server_sld_id;
}

pptx_string 
pptx_ct_p_slide_sync_properties_get_server_sld_modified_time(const pptx_ct_p_slide_sync_properties *const obj)
{
    return obj->server_sld_modified_time;
}

pptx_string 
pptx_ct_p_slide_sync_properties_get_client_inserted_time(const pptx_ct_p_slide_sync_properties *const obj)
{
    return obj->client_inserted_time;
}

int32_t
pptx_ct_p_slide_sync_properties_get_index(pptx_ct_p_slide_sync_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_sync_properties_free(pptx_ct_p_slide_sync_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->server_sld_id);
    xmlFree(obj->server_sld_modified_time);
    xmlFree(obj->client_inserted_time);
    free(obj);
}