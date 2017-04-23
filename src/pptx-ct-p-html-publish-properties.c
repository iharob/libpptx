#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-html-publish-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-p-index-range.h>
#include <private/pptx-ct-p-custom-show-id.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_html_publish_properties_s {
    pptx_ct_p_empty *slide_list_choice_sld_all;
    pptx_ct_p_index_range *slide_list_choice_sld_rg;
    pptx_ct_p_custom_show_id *slide_list_choice_cust_show;
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool show_speaker_notes;
    pptx_string target;
    pptx_string title;
    pptx_string r_id;
    int32_t index;
} pptx_ct_p_html_publish_properties;

pptx_ct_p_html_publish_properties *
pptx_ct_p_html_publish_properties_new(xmlNode *node)
{
    pptx_ct_p_html_publish_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldAll");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->slide_list_choice_sld_all = NULL;
        } else {
            obj->slide_list_choice_sld_all = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->slide_list_choice_sld_all = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldRg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->slide_list_choice_sld_rg = NULL;
        } else {
            obj->slide_list_choice_sld_rg = pptx_ct_p_index_range_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->slide_list_choice_sld_rg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custShow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->slide_list_choice_cust_show = NULL;
        } else {
            obj->slide_list_choice_cust_show = pptx_ct_p_custom_show_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->slide_list_choice_cust_show = NULL;
    }

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
    obj->show_speaker_notes = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showSpeakerNotes");
    obj->target = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "target");
    obj->title = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "title");
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_empty *
pptx_ct_p_html_publish_properties_get_slide_list_choice_sld_all(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->slide_list_choice_sld_all;
}

pptx_ct_p_index_range *
pptx_ct_p_html_publish_properties_get_slide_list_choice_sld_rg(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->slide_list_choice_sld_rg;
}

pptx_ct_p_custom_show_id *
pptx_ct_p_html_publish_properties_get_slide_list_choice_cust_show(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->slide_list_choice_cust_show;
}

pptx_ct_p_extension_list *
pptx_ct_p_html_publish_properties_get_ext_lst(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_html_publish_properties_get_show_speaker_notes(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->show_speaker_notes;
}

pptx_string 
pptx_ct_p_html_publish_properties_get_target(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->target;
}

pptx_string 
pptx_ct_p_html_publish_properties_get_title(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->title;
}

pptx_string 
pptx_ct_p_html_publish_properties_get_r_id(const pptx_ct_p_html_publish_properties *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_p_html_publish_properties_get_index(pptx_ct_p_html_publish_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_html_publish_properties_free(pptx_ct_p_html_publish_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_empty_free(obj->slide_list_choice_sld_all);
    pptx_ct_p_index_range_free(obj->slide_list_choice_sld_rg);
    pptx_ct_p_custom_show_id_free(obj->slide_list_choice_cust_show);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->target);
    xmlFree(obj->title);
    xmlFree(obj->r_id);
    free(obj);
}