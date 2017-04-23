#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-character-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-properties.h>
#include <private/pptx-ct-a-no-fill-properties.h>
#include <private/pptx-ct-a-solid-color-fill-properties.h>
#include <private/pptx-ct-a-gradient-fill-properties.h>
#include <private/pptx-ct-a-blip-fill-properties.h>
#include <private/pptx-ct-a-pattern-fill-properties.h>
#include <private/pptx-ct-a-group-fill-properties.h>
#include <private/pptx-ct-a-effect-list.h>
#include <private/pptx-ct-a-effect-container.h>
#include <private/pptx-ct-a-color.h>
#include <private/pptx-ct-a-text-underline-line-follow-text.h>
#include <private/pptx-ct-a-text-underline-fill-follow-text.h>
#include <private/pptx-ct-a-text-underline-fill-group-wrapper.h>
#include <private/pptx-ct-a-text-font.h>
#include <private/pptx-ct-a-hyperlink.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-text-underline-type.h>
#include <private/pptx-st-text-strike-type.h>
#include <private/pptx-st-text-caps-type.h>

typedef struct pptx_ct_a_text_character_properties_s {
    pptx_ct_a_line_properties *ln;
    pptx_ct_a_no_fill_properties *fill_properties_no_fill;
    pptx_ct_a_solid_color_fill_properties *fill_properties_solid_fill;
    pptx_ct_a_gradient_fill_properties *fill_properties_grad_fill;
    pptx_ct_a_blip_fill_properties *fill_properties_blip_fill;
    pptx_ct_a_pattern_fill_properties *fill_properties_patt_fill;
    pptx_ct_a_group_fill_properties *fill_properties_grp_fill;
    pptx_ct_a_effect_list *effect_properties_effect_lst;
    pptx_ct_a_effect_container *effect_properties_effect_dag;
    pptx_ct_a_color *highlight;
    pptx_ct_a_text_underline_line_follow_text *text_underline_line_u_ln_tx;
    pptx_ct_a_line_properties *text_underline_line_u_ln;
    pptx_ct_a_text_underline_fill_follow_text *text_underline_fill_u_fill_tx;
    pptx_ct_a_text_underline_fill_group_wrapper *text_underline_fill_u_fill;
    pptx_ct_a_text_font *latin;
    pptx_ct_a_text_font *ea;
    pptx_ct_a_text_font *cs;
    pptx_ct_a_text_font *sym;
    pptx_ct_a_hyperlink *hlink_click;
    pptx_ct_a_hyperlink *hlink_mouse_over;
    pptx_bool rtl;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_bool kumimoji;
    pptx_string lang;
    pptx_string alt_lang;
    pptx_int sz;
    pptx_bool b;
    pptx_bool i;
    pptx_st_text_underline_type_token_enum u;
    pptx_st_text_strike_type_token_enum strike;
    pptx_int kern;
    pptx_st_text_caps_type_token_enum cap;
    pptx_string spc;
    pptx_bool normalize_h;
    pptx_string baseline;
    pptx_bool no_proof;
    pptx_bool dirty;
    pptx_bool err;
    pptx_bool smt_clean;
    pptx_uint smt_id;
    pptx_string bmk;
    int32_t index;
} pptx_ct_a_text_character_properties;

pptx_ct_a_text_character_properties *
pptx_ct_a_text_character_properties_new(xmlNode *node)
{
    pptx_ct_a_text_character_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ln");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln = NULL;
        } else {
            obj->ln = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:noFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_no_fill = NULL;
        } else {
            obj->fill_properties_no_fill = pptx_ct_a_no_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_no_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:solidFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_solid_fill = NULL;
        } else {
            obj->fill_properties_solid_fill = pptx_ct_a_solid_color_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_solid_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gradFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_grad_fill = NULL;
        } else {
            obj->fill_properties_grad_fill = pptx_ct_a_gradient_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grad_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blipFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_blip_fill = NULL;
        } else {
            obj->fill_properties_blip_fill = pptx_ct_a_blip_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_blip_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pattFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_patt_fill = NULL;
        } else {
            obj->fill_properties_patt_fill = pptx_ct_a_pattern_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_patt_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_grp_fill = NULL;
        } else {
            obj->fill_properties_grp_fill = pptx_ct_a_group_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grp_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_lst = NULL;
        } else {
            obj->effect_properties_effect_lst = pptx_ct_a_effect_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectDag");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_dag = NULL;
        } else {
            obj->effect_properties_effect_dag = pptx_ct_a_effect_container_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_dag = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:highlight");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->highlight = NULL;
        } else {
            obj->highlight = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->highlight = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:uLnTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_underline_line_u_ln_tx = NULL;
        } else {
            obj->text_underline_line_u_ln_tx = pptx_ct_a_text_underline_line_follow_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_underline_line_u_ln_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:uLn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_underline_line_u_ln = NULL;
        } else {
            obj->text_underline_line_u_ln = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_underline_line_u_ln = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:uFillTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_underline_fill_u_fill_tx = NULL;
        } else {
            obj->text_underline_fill_u_fill_tx = pptx_ct_a_text_underline_fill_follow_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_underline_fill_u_fill_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:uFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_underline_fill_u_fill = NULL;
        } else {
            obj->text_underline_fill_u_fill = pptx_ct_a_text_underline_fill_group_wrapper_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_underline_fill_u_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:latin");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->latin = NULL;
        } else {
            obj->latin = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->latin = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ea");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ea = NULL;
        } else {
            obj->ea = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ea = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cs");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cs = NULL;
        } else {
            obj->cs = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cs = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sym");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sym = NULL;
        } else {
            obj->sym = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sym = NULL;
    }

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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hlinkMouseOver");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hlink_mouse_over = NULL;
        } else {
            obj->hlink_mouse_over = pptx_ct_a_hyperlink_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hlink_mouse_over = NULL;
    }
    obj->rtl = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:rtl");

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
    obj->kumimoji = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "kumimoji");
    obj->lang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lang");
    obj->alt_lang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "altLang");
    obj->sz = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "sz");
    obj->b = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "b");
    obj->i = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "i");
    obj->u = pptx_get_st_text_underline_type(node, (const xmlChar *) "u");
    obj->strike = pptx_get_st_text_strike_type(node, (const xmlChar *) "strike");
    obj->kern = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "kern");
    obj->cap = pptx_get_st_text_caps_type(node, (const xmlChar *) "cap");
    obj->spc = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "spc");
    obj->normalize_h = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "normalizeH");
    obj->baseline = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "baseline");
    obj->no_proof = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noProof");
    obj->dirty = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "dirty");
    obj->err = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "err");
    obj->smt_clean = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "smtClean");
    obj->smt_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "smtId");
    obj->bmk = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "bmk");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_line_properties *
pptx_ct_a_text_character_properties_get_ln(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->ln;
}

pptx_ct_a_no_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_no_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_no_fill;
}

pptx_ct_a_solid_color_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_solid_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_solid_fill;
}

pptx_ct_a_gradient_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_grad_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_grad_fill;
}

pptx_ct_a_blip_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_blip_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_blip_fill;
}

pptx_ct_a_pattern_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_patt_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_patt_fill;
}

pptx_ct_a_group_fill_properties *
pptx_ct_a_text_character_properties_get_fill_properties_grp_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->fill_properties_grp_fill;
}

pptx_ct_a_effect_list *
pptx_ct_a_text_character_properties_get_effect_properties_effect_lst(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->effect_properties_effect_lst;
}

pptx_ct_a_effect_container *
pptx_ct_a_text_character_properties_get_effect_properties_effect_dag(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->effect_properties_effect_dag;
}

pptx_ct_a_color *
pptx_ct_a_text_character_properties_get_highlight(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->highlight;
}

pptx_ct_a_text_underline_line_follow_text *
pptx_ct_a_text_character_properties_get_text_underline_line_u_ln_tx(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->text_underline_line_u_ln_tx;
}

pptx_ct_a_line_properties *
pptx_ct_a_text_character_properties_get_text_underline_line_u_ln(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->text_underline_line_u_ln;
}

pptx_ct_a_text_underline_fill_follow_text *
pptx_ct_a_text_character_properties_get_text_underline_fill_u_fill_tx(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->text_underline_fill_u_fill_tx;
}

pptx_ct_a_text_underline_fill_group_wrapper *
pptx_ct_a_text_character_properties_get_text_underline_fill_u_fill(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->text_underline_fill_u_fill;
}

pptx_ct_a_text_font *
pptx_ct_a_text_character_properties_get_latin(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->latin;
}

pptx_ct_a_text_font *
pptx_ct_a_text_character_properties_get_ea(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->ea;
}

pptx_ct_a_text_font *
pptx_ct_a_text_character_properties_get_cs(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->cs;
}

pptx_ct_a_text_font *
pptx_ct_a_text_character_properties_get_sym(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->sym;
}

pptx_ct_a_hyperlink *
pptx_ct_a_text_character_properties_get_hlink_click(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->hlink_click;
}

pptx_ct_a_hyperlink *
pptx_ct_a_text_character_properties_get_hlink_mouse_over(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->hlink_mouse_over;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_rtl(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->rtl;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_text_character_properties_get_ext_lst(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_kumimoji(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->kumimoji;
}

pptx_string 
pptx_ct_a_text_character_properties_get_lang(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->lang;
}

pptx_string 
pptx_ct_a_text_character_properties_get_alt_lang(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->alt_lang;
}

pptx_int 
pptx_ct_a_text_character_properties_get_sz(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->sz;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_b(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->b;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_i(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->i;
}

pptx_st_text_underline_type_token_enum 
pptx_ct_a_text_character_properties_get_u(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->u;
}

pptx_st_text_strike_type_token_enum 
pptx_ct_a_text_character_properties_get_strike(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->strike;
}

pptx_int 
pptx_ct_a_text_character_properties_get_kern(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->kern;
}

pptx_st_text_caps_type_token_enum 
pptx_ct_a_text_character_properties_get_cap(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->cap;
}

pptx_string 
pptx_ct_a_text_character_properties_get_spc(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->spc;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_normalize_h(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->normalize_h;
}

pptx_string 
pptx_ct_a_text_character_properties_get_baseline(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->baseline;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_no_proof(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->no_proof;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_dirty(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->dirty;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_err(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->err;
}

pptx_bool 
pptx_ct_a_text_character_properties_get_smt_clean(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->smt_clean;
}

pptx_uint 
pptx_ct_a_text_character_properties_get_smt_id(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->smt_id;
}

pptx_string 
pptx_ct_a_text_character_properties_get_bmk(const pptx_ct_a_text_character_properties *const obj)
{
    return obj->bmk;
}

int32_t
pptx_ct_a_text_character_properties_get_index(pptx_ct_a_text_character_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_character_properties_free(pptx_ct_a_text_character_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_line_properties_free(obj->ln);
    pptx_ct_a_no_fill_properties_free(obj->fill_properties_no_fill);
    pptx_ct_a_solid_color_fill_properties_free(obj->fill_properties_solid_fill);
    pptx_ct_a_gradient_fill_properties_free(obj->fill_properties_grad_fill);
    pptx_ct_a_blip_fill_properties_free(obj->fill_properties_blip_fill);
    pptx_ct_a_pattern_fill_properties_free(obj->fill_properties_patt_fill);
    pptx_ct_a_group_fill_properties_free(obj->fill_properties_grp_fill);
    pptx_ct_a_effect_list_free(obj->effect_properties_effect_lst);
    pptx_ct_a_effect_container_free(obj->effect_properties_effect_dag);
    pptx_ct_a_color_free(obj->highlight);
    pptx_ct_a_text_underline_line_follow_text_free(obj->text_underline_line_u_ln_tx);
    pptx_ct_a_line_properties_free(obj->text_underline_line_u_ln);
    pptx_ct_a_text_underline_fill_follow_text_free(obj->text_underline_fill_u_fill_tx);
    pptx_ct_a_text_underline_fill_group_wrapper_free(obj->text_underline_fill_u_fill);
    pptx_ct_a_text_font_free(obj->latin);
    pptx_ct_a_text_font_free(obj->ea);
    pptx_ct_a_text_font_free(obj->cs);
    pptx_ct_a_text_font_free(obj->sym);
    pptx_ct_a_hyperlink_free(obj->hlink_click);
    pptx_ct_a_hyperlink_free(obj->hlink_mouse_over);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->lang);
    xmlFree(obj->alt_lang);
    xmlFree(obj->spc);
    xmlFree(obj->baseline);
    xmlFree(obj->bmk);
    free(obj);
}