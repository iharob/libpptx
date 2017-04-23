#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-non-visual-connector-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-connector-locking.h>
#include <private/pptx-ct-a-connection.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_non_visual_connector_properties_s {
    pptx_ct_a_connector_locking *cxn_sp_locks;
    pptx_ct_a_connection *st_cxn;
    pptx_ct_a_connection *end_cxn;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_non_visual_connector_properties;

pptx_ct_a_non_visual_connector_properties *
pptx_ct_a_non_visual_connector_properties_new(xmlNode *node)
{
    pptx_ct_a_non_visual_connector_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cxnSpLocks");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cxn_sp_locks = NULL;
        } else {
            obj->cxn_sp_locks = pptx_ct_a_connector_locking_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn_sp_locks = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:stCxn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->st_cxn = NULL;
        } else {
            obj->st_cxn = pptx_ct_a_connection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->st_cxn = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:endCxn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end_cxn = NULL;
        } else {
            obj->end_cxn = pptx_ct_a_connection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end_cxn = NULL;
    }

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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_connector_locking *
pptx_ct_a_non_visual_connector_properties_get_cxn_sp_locks(const pptx_ct_a_non_visual_connector_properties *const obj)
{
    return obj->cxn_sp_locks;
}

pptx_ct_a_connection *
pptx_ct_a_non_visual_connector_properties_get_st_cxn(const pptx_ct_a_non_visual_connector_properties *const obj)
{
    return obj->st_cxn;
}

pptx_ct_a_connection *
pptx_ct_a_non_visual_connector_properties_get_end_cxn(const pptx_ct_a_non_visual_connector_properties *const obj)
{
    return obj->end_cxn;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_non_visual_connector_properties_get_ext_lst(const pptx_ct_a_non_visual_connector_properties *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_non_visual_connector_properties_get_index(pptx_ct_a_non_visual_connector_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_non_visual_connector_properties_free(pptx_ct_a_non_visual_connector_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_connector_locking_free(obj->cxn_sp_locks);
    pptx_ct_a_connection_free(obj->st_cxn);
    pptx_ct_a_connection_free(obj->end_cxn);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}