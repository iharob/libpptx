#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-style-text-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-font-collection.h>
#include <private/pptx-ct-a-font-reference.h>
#include <private/pptx-ct-a-sc-rgb-color.h>
#include <private/pptx-ct-a-srgb-color.h>
#include <private/pptx-ct-a-hsl-color.h>
#include <private/pptx-ct-a-system-color.h>
#include <private/pptx-ct-a-scheme-color.h>
#include <private/pptx-ct-a-preset-color.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-on-off-style-type.h>

typedef struct pptx_ct_a_table_style_text_style_s {
    pptx_ct_a_font_collection *themeable_font_styles_font;
    pptx_ct_a_font_reference *themeable_font_styles_font_ref;
    pptx_ct_a_sc_rgb_color *color_choice_scrgb_clr;
    pptx_ct_a_srgb_color *color_choice_srgb_clr;
    pptx_ct_a_hsl_color *color_choice_hsl_clr;
    pptx_ct_a_system_color *color_choice_sys_clr;
    pptx_ct_a_scheme_color *color_choice_scheme_clr;
    pptx_ct_a_preset_color *color_choice_prst_clr;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_on_off_style_type_token_enum b;
    pptx_st_on_off_style_type_token_enum i;
    int32_t index;
} pptx_ct_a_table_style_text_style;

pptx_ct_a_table_style_text_style *
pptx_ct_a_table_style_text_style_new(xmlNode *node)
{
    pptx_ct_a_table_style_text_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:font");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_font_styles_font = NULL;
        } else {
            obj->themeable_font_styles_font = pptx_ct_a_font_collection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_font_styles_font = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fontRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_font_styles_font_ref = NULL;
        } else {
            obj->themeable_font_styles_font_ref = pptx_ct_a_font_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_font_styles_font_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scrgbClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_scrgb_clr = NULL;
        } else {
            obj->color_choice_scrgb_clr = pptx_ct_a_sc_rgb_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scrgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:srgbClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_srgb_clr = NULL;
        } else {
            obj->color_choice_srgb_clr = pptx_ct_a_srgb_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_srgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hslClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_hsl_clr = NULL;
        } else {
            obj->color_choice_hsl_clr = pptx_ct_a_hsl_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_hsl_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sysClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_sys_clr = NULL;
        } else {
            obj->color_choice_sys_clr = pptx_ct_a_system_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_sys_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:schemeClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_scheme_clr = NULL;
        } else {
            obj->color_choice_scheme_clr = pptx_ct_a_scheme_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scheme_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_prst_clr = NULL;
        } else {
            obj->color_choice_prst_clr = pptx_ct_a_preset_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_prst_clr = NULL;
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
    obj->b = pptx_get_st_on_off_style_type(node, (const xmlChar *) "b");
    obj->i = pptx_get_st_on_off_style_type(node, (const xmlChar *) "i");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_font_collection *
pptx_ct_a_table_style_text_style_get_themeable_font_styles_font(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->themeable_font_styles_font;
}

pptx_ct_a_font_reference *
pptx_ct_a_table_style_text_style_get_themeable_font_styles_font_ref(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->themeable_font_styles_font_ref;
}

pptx_ct_a_sc_rgb_color *
pptx_ct_a_table_style_text_style_get_color_choice_scrgb_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_scrgb_clr;
}

pptx_ct_a_srgb_color *
pptx_ct_a_table_style_text_style_get_color_choice_srgb_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_srgb_clr;
}

pptx_ct_a_hsl_color *
pptx_ct_a_table_style_text_style_get_color_choice_hsl_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_hsl_clr;
}

pptx_ct_a_system_color *
pptx_ct_a_table_style_text_style_get_color_choice_sys_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_sys_clr;
}

pptx_ct_a_scheme_color *
pptx_ct_a_table_style_text_style_get_color_choice_scheme_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_scheme_clr;
}

pptx_ct_a_preset_color *
pptx_ct_a_table_style_text_style_get_color_choice_prst_clr(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->color_choice_prst_clr;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_style_text_style_get_ext_lst(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->ext_lst;
}

pptx_st_on_off_style_type_token_enum 
pptx_ct_a_table_style_text_style_get_b(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->b;
}

pptx_st_on_off_style_type_token_enum 
pptx_ct_a_table_style_text_style_get_i(const pptx_ct_a_table_style_text_style *const obj)
{
    return obj->i;
}

int32_t
pptx_ct_a_table_style_text_style_get_index(pptx_ct_a_table_style_text_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_style_text_style_free(pptx_ct_a_table_style_text_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_font_collection_free(obj->themeable_font_styles_font);
    pptx_ct_a_font_reference_free(obj->themeable_font_styles_font_ref);
    pptx_ct_a_sc_rgb_color_free(obj->color_choice_scrgb_clr);
    pptx_ct_a_srgb_color_free(obj->color_choice_srgb_clr);
    pptx_ct_a_hsl_color_free(obj->color_choice_hsl_clr);
    pptx_ct_a_system_color_free(obj->color_choice_sys_clr);
    pptx_ct_a_scheme_color_free(obj->color_choice_scheme_clr);
    pptx_ct_a_preset_color_free(obj->color_choice_prst_clr);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}