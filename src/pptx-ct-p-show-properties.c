#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-show-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-p-show-info-browse.h>
#include <private/pptx-ct-p-show-info-kiosk.h>
#include <private/pptx-ct-p-index-range.h>
#include <private/pptx-ct-p-custom-show-id.h>
#include <private/pptx-ct-a-color.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_show_properties_s {
    pptx_ct_p_empty *show_type_present;
    pptx_ct_p_show_info_browse *show_type_browse;
    pptx_ct_p_show_info_kiosk *show_type_kiosk;
    pptx_ct_p_empty *slide_list_choice_sld_all;
    pptx_ct_p_index_range *slide_list_choice_sld_rg;
    pptx_ct_p_custom_show_id *slide_list_choice_cust_show;
    pptx_ct_a_color *pen_clr;
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool loop;
    pptx_bool show_narration;
    pptx_bool show_animation;
    pptx_bool use_timings;
    int32_t index;
} pptx_ct_p_show_properties;

pptx_ct_p_show_properties *
pptx_ct_p_show_properties_new(xmlNode *node)
{
    pptx_ct_p_show_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:present");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->show_type_present = NULL;
        } else {
            obj->show_type_present = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->show_type_present = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:browse");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->show_type_browse = NULL;
        } else {
            obj->show_type_browse = pptx_ct_p_show_info_browse_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->show_type_browse = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:kiosk");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->show_type_kiosk = NULL;
        } else {
            obj->show_type_kiosk = pptx_ct_p_show_info_kiosk_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->show_type_kiosk = NULL;
    }

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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:penClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pen_clr = NULL;
        } else {
            obj->pen_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pen_clr = NULL;
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
    obj->loop = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "loop");
    obj->show_narration = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showNarration");
    obj->show_animation = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showAnimation");
    obj->use_timings = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useTimings");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_empty *
pptx_ct_p_show_properties_get_show_type_present(const pptx_ct_p_show_properties *const obj)
{
    return obj->show_type_present;
}

pptx_ct_p_show_info_browse *
pptx_ct_p_show_properties_get_show_type_browse(const pptx_ct_p_show_properties *const obj)
{
    return obj->show_type_browse;
}

pptx_ct_p_show_info_kiosk *
pptx_ct_p_show_properties_get_show_type_kiosk(const pptx_ct_p_show_properties *const obj)
{
    return obj->show_type_kiosk;
}

pptx_ct_p_empty *
pptx_ct_p_show_properties_get_slide_list_choice_sld_all(const pptx_ct_p_show_properties *const obj)
{
    return obj->slide_list_choice_sld_all;
}

pptx_ct_p_index_range *
pptx_ct_p_show_properties_get_slide_list_choice_sld_rg(const pptx_ct_p_show_properties *const obj)
{
    return obj->slide_list_choice_sld_rg;
}

pptx_ct_p_custom_show_id *
pptx_ct_p_show_properties_get_slide_list_choice_cust_show(const pptx_ct_p_show_properties *const obj)
{
    return obj->slide_list_choice_cust_show;
}

pptx_ct_a_color *
pptx_ct_p_show_properties_get_pen_clr(const pptx_ct_p_show_properties *const obj)
{
    return obj->pen_clr;
}

pptx_ct_p_extension_list *
pptx_ct_p_show_properties_get_ext_lst(const pptx_ct_p_show_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_show_properties_get_loop(const pptx_ct_p_show_properties *const obj)
{
    return obj->loop;
}

pptx_bool 
pptx_ct_p_show_properties_get_show_narration(const pptx_ct_p_show_properties *const obj)
{
    return obj->show_narration;
}

pptx_bool 
pptx_ct_p_show_properties_get_show_animation(const pptx_ct_p_show_properties *const obj)
{
    return obj->show_animation;
}

pptx_bool 
pptx_ct_p_show_properties_get_use_timings(const pptx_ct_p_show_properties *const obj)
{
    return obj->use_timings;
}

int32_t
pptx_ct_p_show_properties_get_index(pptx_ct_p_show_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_show_properties_free(pptx_ct_p_show_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_empty_free(obj->show_type_present);
    pptx_ct_p_show_info_browse_free(obj->show_type_browse);
    pptx_ct_p_show_info_kiosk_free(obj->show_type_kiosk);
    pptx_ct_p_empty_free(obj->slide_list_choice_sld_all);
    pptx_ct_p_index_range_free(obj->slide_list_choice_sld_rg);
    pptx_ct_p_custom_show_id_free(obj->slide_list_choice_cust_show);
    pptx_ct_a_color_free(obj->pen_clr);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}