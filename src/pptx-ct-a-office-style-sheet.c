#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-office-style-sheet.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-base-styles.h>
#include <private/pptx-ct-a-object-style-defaults.h>
#include <private/pptx-ct-a-color-scheme-list.h>
#include <private/pptx-ct-a-custom-color-list.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_office_style_sheet_s {
    pptx_ct_a_base_styles *theme_elements;
    pptx_ct_a_object_style_defaults *object_defaults;
    pptx_ct_a_color_scheme_list *extra_clr_scheme_lst;
    pptx_ct_a_custom_color_list *cust_clr_lst;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_a_office_style_sheet;

pptx_ct_a_office_style_sheet *
pptx_ct_a_office_style_sheet_new(xmlNode *node)
{
    pptx_ct_a_office_style_sheet *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:themeElements");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->theme_elements = NULL;
        } else {
            obj->theme_elements = pptx_ct_a_base_styles_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->theme_elements = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:objectDefaults");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->object_defaults = NULL;
        } else {
            obj->object_defaults = pptx_ct_a_object_style_defaults_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->object_defaults = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extraClrSchemeLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->extra_clr_scheme_lst = NULL;
        } else {
            obj->extra_clr_scheme_lst = pptx_ct_a_color_scheme_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->extra_clr_scheme_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:custClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_clr_lst = NULL;
        } else {
            obj->cust_clr_lst = pptx_ct_a_custom_color_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_clr_lst = NULL;
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
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_base_styles *
pptx_ct_a_office_style_sheet_get_theme_elements(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->theme_elements;
}

pptx_ct_a_object_style_defaults *
pptx_ct_a_office_style_sheet_get_object_defaults(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->object_defaults;
}

pptx_ct_a_color_scheme_list *
pptx_ct_a_office_style_sheet_get_extra_clr_scheme_lst(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->extra_clr_scheme_lst;
}

pptx_ct_a_custom_color_list *
pptx_ct_a_office_style_sheet_get_cust_clr_lst(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->cust_clr_lst;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_office_style_sheet_get_ext_lst(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_office_style_sheet_get_name(const pptx_ct_a_office_style_sheet *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_office_style_sheet_get_index(pptx_ct_a_office_style_sheet *obj)
{
    return obj->index;
}

void
pptx_ct_a_office_style_sheet_free(pptx_ct_a_office_style_sheet *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_base_styles_free(obj->theme_elements);
    pptx_ct_a_object_style_defaults_free(obj->object_defaults);
    pptx_ct_a_color_scheme_list_free(obj->extra_clr_scheme_lst);
    pptx_ct_a_custom_color_list_free(obj->cust_clr_lst);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}