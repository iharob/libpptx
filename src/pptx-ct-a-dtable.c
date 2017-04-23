#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-dtable.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_dtable_s {
    pptx_bool show_horz_border;
    pptx_bool show_vert_border;
    pptx_bool show_outline;
    pptx_bool show_keys;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *tx_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_dtable;

pptx_ct_a_dtable *
pptx_ct_a_dtable_new(xmlNode *node)
{
    pptx_ct_a_dtable *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->show_horz_border = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showHorzBorder");
    obj->show_vert_border = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showVertBorder");
    obj->show_outline = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showOutline");
    obj->show_keys = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showKeys");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_pr = NULL;
        } else {
            obj->tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_pr = NULL;
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

pptx_bool 
pptx_ct_a_dtable_get_show_horz_border(const pptx_ct_a_dtable *const obj)
{
    return obj->show_horz_border;
}

pptx_bool 
pptx_ct_a_dtable_get_show_vert_border(const pptx_ct_a_dtable *const obj)
{
    return obj->show_vert_border;
}

pptx_bool 
pptx_ct_a_dtable_get_show_outline(const pptx_ct_a_dtable *const obj)
{
    return obj->show_outline;
}

pptx_bool 
pptx_ct_a_dtable_get_show_keys(const pptx_ct_a_dtable *const obj)
{
    return obj->show_keys;
}

pptx_ct_a_shape_properties *
pptx_ct_a_dtable_get_sp_pr(const pptx_ct_a_dtable *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_dtable_get_tx_pr(const pptx_ct_a_dtable *const obj)
{
    return obj->tx_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_dtable_get_ext_lst(const pptx_ct_a_dtable *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_dtable_get_index(pptx_ct_a_dtable *obj)
{
    return obj->index;
}

void
pptx_ct_a_dtable_free(pptx_ct_a_dtable *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->tx_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}