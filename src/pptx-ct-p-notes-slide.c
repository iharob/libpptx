#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-notes-slide.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-common-slide-data.h>
#include <private/pptx-ct-a-color-mapping-override.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_notes_slide_s {
    pptx_ct_p_common_slide_data *c_sld;
    pptx_ct_a_color_mapping_override *child_slide_clr_map_ovr;
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_bool show_master_sp;
    pptx_bool show_master_ph_anim;
    int32_t index;
} pptx_ct_p_notes_slide;

pptx_ct_p_notes_slide *
pptx_ct_p_notes_slide_new(xmlNode *node)
{
    pptx_ct_p_notes_slide *obj;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_common_slide_data *
pptx_ct_p_notes_slide_get_c_sld(const pptx_ct_p_notes_slide *const obj)
{
    return obj->c_sld;
}

pptx_ct_a_color_mapping_override *
pptx_ct_p_notes_slide_get_child_slide_clr_map_ovr(const pptx_ct_p_notes_slide *const obj)
{
    return obj->child_slide_clr_map_ovr;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_notes_slide_get_ext_lst(const pptx_ct_p_notes_slide *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_notes_slide_get_show_master_sp(const pptx_ct_p_notes_slide *const obj)
{
    return obj->show_master_sp;
}

pptx_bool 
pptx_ct_p_notes_slide_get_show_master_ph_anim(const pptx_ct_p_notes_slide *const obj)
{
    return obj->show_master_ph_anim;
}

int32_t
pptx_ct_p_notes_slide_get_index(pptx_ct_p_notes_slide *obj)
{
    return obj->index;
}

void
pptx_ct_p_notes_slide_free(pptx_ct_p_notes_slide *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_common_slide_data_free(obj->c_sld);
    pptx_ct_a_color_mapping_override_free(obj->child_slide_clr_map_ovr);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}