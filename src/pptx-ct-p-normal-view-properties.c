#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-normal-view-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-normal-view-portion.h>
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-splitter-bar-state.h>

typedef struct pptx_ct_p_normal_view_properties_s {
    pptx_ct_p_normal_view_portion *restored_left;
    pptx_ct_p_normal_view_portion *restored_top;
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool show_outline_icons;
    pptx_bool snap_vert_splitter;
    pptx_st_splitter_bar_state_token_enum vert_bar_state;
    pptx_st_splitter_bar_state_token_enum horz_bar_state;
    pptx_bool prefer_single_view;
    int32_t index;
} pptx_ct_p_normal_view_properties;

pptx_ct_p_normal_view_properties *
pptx_ct_p_normal_view_properties_new(xmlNode *node)
{
    pptx_ct_p_normal_view_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:restoredLeft");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->restored_left = NULL;
        } else {
            obj->restored_left = pptx_ct_p_normal_view_portion_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->restored_left = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:restoredTop");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->restored_top = NULL;
        } else {
            obj->restored_top = pptx_ct_p_normal_view_portion_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->restored_top = NULL;
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
    obj->show_outline_icons = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showOutlineIcons");
    obj->snap_vert_splitter = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "snapVertSplitter");
    obj->vert_bar_state = pptx_get_st_splitter_bar_state(node, (const xmlChar *) "vertBarState");
    obj->horz_bar_state = pptx_get_st_splitter_bar_state(node, (const xmlChar *) "horzBarState");
    obj->prefer_single_view = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "preferSingleView");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_normal_view_portion *
pptx_ct_p_normal_view_properties_get_restored_left(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->restored_left;
}

pptx_ct_p_normal_view_portion *
pptx_ct_p_normal_view_properties_get_restored_top(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->restored_top;
}

pptx_ct_p_extension_list *
pptx_ct_p_normal_view_properties_get_ext_lst(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_normal_view_properties_get_show_outline_icons(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->show_outline_icons;
}

pptx_bool 
pptx_ct_p_normal_view_properties_get_snap_vert_splitter(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->snap_vert_splitter;
}

pptx_st_splitter_bar_state_token_enum 
pptx_ct_p_normal_view_properties_get_vert_bar_state(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->vert_bar_state;
}

pptx_st_splitter_bar_state_token_enum 
pptx_ct_p_normal_view_properties_get_horz_bar_state(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->horz_bar_state;
}

pptx_bool 
pptx_ct_p_normal_view_properties_get_prefer_single_view(const pptx_ct_p_normal_view_properties *const obj)
{
    return obj->prefer_single_view;
}

int32_t
pptx_ct_p_normal_view_properties_get_index(pptx_ct_p_normal_view_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_normal_view_properties_free(pptx_ct_p_normal_view_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_normal_view_portion_free(obj->restored_left);
    pptx_ct_p_normal_view_portion_free(obj->restored_top);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}