#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-non-visual-drawing-props.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-hyperlink.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_non_visual_drawing_props_s {
    pptx_ct_a_hyperlink *hlink_click;
    pptx_ct_a_hyperlink *hlink_hover;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_uint id;
    pptx_string name;
    pptx_string descr;
    pptx_bool hidden;
    pptx_string title;
    int32_t index;
} pptx_ct_a_non_visual_drawing_props;

pptx_ct_a_non_visual_drawing_props *
pptx_ct_a_non_visual_drawing_props_new(xmlNode *node)
{
    pptx_ct_a_non_visual_drawing_props *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hlinkClick");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hlink_click = NULL;
        } else {
            obj->hlink_click = pptx_ct_a_hyperlink_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hlink_click = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hlinkHover");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hlink_hover = NULL;
        } else {
            obj->hlink_hover = pptx_ct_a_hyperlink_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hlink_hover = NULL;
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
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->descr = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "descr");
    obj->hidden = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hidden");
    obj->title = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "title");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_hyperlink *
pptx_ct_a_non_visual_drawing_props_get_hlink_click(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->hlink_click;
}

pptx_ct_a_hyperlink *
pptx_ct_a_non_visual_drawing_props_get_hlink_hover(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->hlink_hover;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_non_visual_drawing_props_get_ext_lst(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->ext_lst;
}

pptx_uint 
pptx_ct_a_non_visual_drawing_props_get_id(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->id;
}

pptx_string 
pptx_ct_a_non_visual_drawing_props_get_name(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->name;
}

pptx_string 
pptx_ct_a_non_visual_drawing_props_get_descr(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->descr;
}

pptx_bool 
pptx_ct_a_non_visual_drawing_props_get_hidden(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->hidden;
}

pptx_string 
pptx_ct_a_non_visual_drawing_props_get_title(const pptx_ct_a_non_visual_drawing_props *const obj)
{
    return obj->title;
}

int32_t
pptx_ct_a_non_visual_drawing_props_get_index(pptx_ct_a_non_visual_drawing_props *obj)
{
    return obj->index;
}

void
pptx_ct_a_non_visual_drawing_props_free(pptx_ct_a_non_visual_drawing_props *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_hyperlink_free(obj->hlink_click);
    pptx_ct_a_hyperlink_free(obj->hlink_hover);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    xmlFree(obj->descr);
    xmlFree(obj->title);
    free(obj);
}