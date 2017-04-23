#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-layout.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-common-slide-data.h>
#include <private/pptx-ct-a-color-mapping-override.h>
#include <private/pptx-ct-p-slide-transition.h>
#include <private/pptx-ct-p-slide-timing.h>
#include <private/pptx-ct-p-header-footer.h>
#include <private/pptx-ct-p-extension-list-modify.h>
#include <private/pptx-st-slide-layout-type.h>

typedef struct pptx_ct_p_slide_layout_s {
    pptx_ct_p_common_slide_data *c_sld;
    pptx_ct_a_color_mapping_override *child_slide_clr_map_ovr;
    pptx_ct_p_slide_transition *transition;
    pptx_ct_p_slide_timing *timing;
    pptx_ct_p_header_footer *hf;
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_bool show_master_sp;
    pptx_bool show_master_ph_anim;
    pptx_string matching_name;
    pptx_st_slide_layout_type_token_enum type;
    pptx_bool preserve;
    pptx_bool user_drawn;
    int32_t index;
} pptx_ct_p_slide_layout;

pptx_ct_p_slide_layout *
pptx_ct_p_slide_layout_new(xmlNode *node)
{
    pptx_ct_p_slide_layout *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cSld");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_sld = NULL;
        } else {
            obj->c_sld = pptx_ct_p_common_slide_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_sld = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:clrMapOvr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->child_slide_clr_map_ovr = NULL;
        } else {
            obj->child_slide_clr_map_ovr = pptx_ct_a_color_mapping_override_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->child_slide_clr_map_ovr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:transition");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->transition = NULL;
        } else {
            obj->transition = pptx_ct_p_slide_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->transition = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:timing");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->timing = NULL;
        } else {
            obj->timing = pptx_ct_p_slide_timing_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->timing = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:hf");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hf = NULL;
        } else {
            obj->hf = pptx_ct_p_header_footer_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hf = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->show_master_sp = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showMasterSp");
    obj->show_master_ph_anim = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showMasterPhAnim");
    obj->matching_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "matchingName");
    obj->type = pptx_get_st_slide_layout_type(node, (const xmlChar *) "type");
    obj->preserve = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "preserve");
    obj->user_drawn = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "userDrawn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_common_slide_data *
pptx_ct_p_slide_layout_get_c_sld(const pptx_ct_p_slide_layout *const obj)
{
    return obj->c_sld;
}

pptx_ct_a_color_mapping_override *
pptx_ct_p_slide_layout_get_child_slide_clr_map_ovr(const pptx_ct_p_slide_layout *const obj)
{
    return obj->child_slide_clr_map_ovr;
}

pptx_ct_p_slide_transition *
pptx_ct_p_slide_layout_get_transition(const pptx_ct_p_slide_layout *const obj)
{
    return obj->transition;
}

pptx_ct_p_slide_timing *
pptx_ct_p_slide_layout_get_timing(const pptx_ct_p_slide_layout *const obj)
{
    return obj->timing;
}

pptx_ct_p_header_footer *
pptx_ct_p_slide_layout_get_hf(const pptx_ct_p_slide_layout *const obj)
{
    return obj->hf;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_slide_layout_get_ext_lst(const pptx_ct_p_slide_layout *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_slide_layout_get_show_master_sp(const pptx_ct_p_slide_layout *const obj)
{
    return obj->show_master_sp;
}

pptx_bool 
pptx_ct_p_slide_layout_get_show_master_ph_anim(const pptx_ct_p_slide_layout *const obj)
{
    return obj->show_master_ph_anim;
}

pptx_string 
pptx_ct_p_slide_layout_get_matching_name(const pptx_ct_p_slide_layout *const obj)
{
    return obj->matching_name;
}

pptx_st_slide_layout_type_token_enum 
pptx_ct_p_slide_layout_get_type(const pptx_ct_p_slide_layout *const obj)
{
    return obj->type;
}

pptx_bool 
pptx_ct_p_slide_layout_get_preserve(const pptx_ct_p_slide_layout *const obj)
{
    return obj->preserve;
}

pptx_bool 
pptx_ct_p_slide_layout_get_user_drawn(const pptx_ct_p_slide_layout *const obj)
{
    return obj->user_drawn;
}

int32_t
pptx_ct_p_slide_layout_get_index(pptx_ct_p_slide_layout *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_layout_free(pptx_ct_p_slide_layout *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_common_slide_data_free(obj->c_sld);
    pptx_ct_a_color_mapping_override_free(obj->child_slide_clr_map_ovr);
    pptx_ct_p_slide_transition_free(obj->transition);
    pptx_ct_p_slide_timing_free(obj->timing);
    pptx_ct_p_header_footer_free(obj->hf);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    xmlFree(obj->matching_name);
    free(obj);
}