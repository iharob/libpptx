#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-hyperlink.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-embedded-wavaudio-file.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_hyperlink_s {
    pptx_ct_a_embedded_wavaudio_file *snd;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string r_id;
    pptx_string invalid_url;
    pptx_string action;
    pptx_string tgt_frame;
    pptx_string tooltip;
    pptx_bool history;
    pptx_bool highlight_click;
    pptx_bool end_snd;
    int32_t index;
} pptx_ct_a_hyperlink;

pptx_ct_a_hyperlink *
pptx_ct_a_hyperlink_new(xmlNode *node)
{
    pptx_ct_a_hyperlink *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:snd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->snd = NULL;
        } else {
            obj->snd = pptx_ct_a_embedded_wavaudio_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->snd = NULL;
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
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->invalid_url = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "invalidUrl");
    obj->action = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "action");
    obj->tgt_frame = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tgtFrame");
    obj->tooltip = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tooltip");
    obj->history = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "history");
    obj->highlight_click = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "highlightClick");
    obj->end_snd = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "endSnd");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_embedded_wavaudio_file *
pptx_ct_a_hyperlink_get_snd(const pptx_ct_a_hyperlink *const obj)
{
    return obj->snd;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_hyperlink_get_ext_lst(const pptx_ct_a_hyperlink *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_hyperlink_get_r_id(const pptx_ct_a_hyperlink *const obj)
{
    return obj->r_id;
}

pptx_string 
pptx_ct_a_hyperlink_get_invalid_url(const pptx_ct_a_hyperlink *const obj)
{
    return obj->invalid_url;
}

pptx_string 
pptx_ct_a_hyperlink_get_action(const pptx_ct_a_hyperlink *const obj)
{
    return obj->action;
}

pptx_string 
pptx_ct_a_hyperlink_get_tgt_frame(const pptx_ct_a_hyperlink *const obj)
{
    return obj->tgt_frame;
}

pptx_string 
pptx_ct_a_hyperlink_get_tooltip(const pptx_ct_a_hyperlink *const obj)
{
    return obj->tooltip;
}

pptx_bool 
pptx_ct_a_hyperlink_get_history(const pptx_ct_a_hyperlink *const obj)
{
    return obj->history;
}

pptx_bool 
pptx_ct_a_hyperlink_get_highlight_click(const pptx_ct_a_hyperlink *const obj)
{
    return obj->highlight_click;
}

pptx_bool 
pptx_ct_a_hyperlink_get_end_snd(const pptx_ct_a_hyperlink *const obj)
{
    return obj->end_snd;
}

int32_t
pptx_ct_a_hyperlink_get_index(pptx_ct_a_hyperlink *obj)
{
    return obj->index;
}

void
pptx_ct_a_hyperlink_free(pptx_ct_a_hyperlink *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_embedded_wavaudio_file_free(obj->snd);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->r_id);
    xmlFree(obj->invalid_url);
    xmlFree(obj->action);
    xmlFree(obj->tgt_frame);
    xmlFree(obj->tooltip);
    free(obj);
}