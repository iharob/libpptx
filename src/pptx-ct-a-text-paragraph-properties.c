#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-paragraph-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-spacing.h>
#include <private/pptx-ct-a-text-bullet-color-follow-text.h>
#include <private/pptx-ct-a-color.h>
#include <private/pptx-ct-a-text-bullet-size-follow-text.h>
#include <private/pptx-ct-a-text-bullet-size-percent.h>
#include <private/pptx-ct-a-text-bullet-size-point.h>
#include <private/pptx-ct-a-text-bullet-typeface-follow-text.h>
#include <private/pptx-ct-a-text-font.h>
#include <private/pptx-ct-a-text-no-bullet.h>
#include <private/pptx-ct-a-text-autonumber-bullet.h>
#include <private/pptx-ct-a-text-char-bullet.h>
#include <private/pptx-ct-a-text-blip-bullet.h>
#include <private/pptx-ct-a-text-tab-stop-list.h>
#include <private/pptx-ct-a-text-character-properties.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-text-align-type.h>
#include <private/pptx-st-text-font-align-type.h>

typedef struct pptx_ct_a_text_paragraph_properties_s {
    pptx_ct_a_text_spacing *ln_spc;
    pptx_ct_a_text_spacing *spc_bef;
    pptx_ct_a_text_spacing *spc_aft;
    pptx_ct_a_text_bullet_color_follow_text *text_bullet_color_bu_clr_tx;
    pptx_ct_a_color *text_bullet_color_bu_clr;
    pptx_ct_a_text_bullet_size_follow_text *text_bullet_size_bu_sz_tx;
    pptx_ct_a_text_bullet_size_percent *text_bullet_size_bu_sz_pct;
    pptx_ct_a_text_bullet_size_point *text_bullet_size_bu_sz_pts;
    pptx_ct_a_text_bullet_typeface_follow_text *text_bullet_typeface_bu_font_tx;
    pptx_ct_a_text_font *text_bullet_typeface_bu_font;
    pptx_ct_a_text_no_bullet *text_bullet_bu_none;
    pptx_ct_a_text_autonumber_bullet *text_bullet_bu_auto_num;
    pptx_ct_a_text_char_bullet *text_bullet_bu_char;
    pptx_ct_a_text_blip_bullet *text_bullet_bu_blip;
    pptx_ct_a_text_tab_stop_list *tab_lst;
    pptx_ct_a_text_character_properties *def_rpr;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_int mar_l;
    pptx_int mar_r;
    pptx_int lvl;
    pptx_int indent;
    pptx_st_text_align_type_token_enum algn;
    pptx_string def_tab_sz;
    pptx_bool rtl;
    pptx_bool ea_ln_brk;
    pptx_st_text_font_align_type_token_enum font_algn;
    pptx_bool latin_ln_brk;
    pptx_bool hanging_punct;
    int32_t index;
} pptx_ct_a_text_paragraph_properties;

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_paragraph_properties_new(xmlNode *node)
{
    pptx_ct_a_text_paragraph_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnSpc");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_spc = NULL;
        } else {
            obj->ln_spc = pptx_ct_a_text_spacing_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_spc = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spcBef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->spc_bef = NULL;
        } else {
            obj->spc_bef = pptx_ct_a_text_spacing_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->spc_bef = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spcAft");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->spc_aft = NULL;
        } else {
            obj->spc_aft = pptx_ct_a_text_spacing_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->spc_aft = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buClrTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_color_bu_clr_tx = NULL;
        } else {
            obj->text_bullet_color_bu_clr_tx = pptx_ct_a_text_bullet_color_follow_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_color_bu_clr_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_color_bu_clr = NULL;
        } else {
            obj->text_bullet_color_bu_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_color_bu_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buSzTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_size_bu_sz_tx = NULL;
        } else {
            obj->text_bullet_size_bu_sz_tx = pptx_ct_a_text_bullet_size_follow_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_size_bu_sz_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buSzPct");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_size_bu_sz_pct = NULL;
        } else {
            obj->text_bullet_size_bu_sz_pct = pptx_ct_a_text_bullet_size_percent_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_size_bu_sz_pct = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buSzPts");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_size_bu_sz_pts = NULL;
        } else {
            obj->text_bullet_size_bu_sz_pts = pptx_ct_a_text_bullet_size_point_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_size_bu_sz_pts = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buFontTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_typeface_bu_font_tx = NULL;
        } else {
            obj->text_bullet_typeface_bu_font_tx = pptx_ct_a_text_bullet_typeface_follow_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_typeface_bu_font_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buFont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_typeface_bu_font = NULL;
        } else {
            obj->text_bullet_typeface_bu_font = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_typeface_bu_font = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buNone");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_bu_none = NULL;
        } else {
            obj->text_bullet_bu_none = pptx_ct_a_text_no_bullet_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_bu_none = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buAutoNum");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_bu_auto_num = NULL;
        } else {
            obj->text_bullet_bu_auto_num = pptx_ct_a_text_autonumber_bullet_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_bu_auto_num = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buChar");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_bu_char = NULL;
        } else {
            obj->text_bullet_bu_char = pptx_ct_a_text_char_bullet_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_bu_char = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:buBlip");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_bullet_bu_blip = NULL;
        } else {
            obj->text_bullet_bu_blip = pptx_ct_a_text_blip_bullet_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_bullet_bu_blip = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tabLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tab_lst = NULL;
        } else {
            obj->tab_lst = pptx_ct_a_text_tab_stop_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tab_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:defRPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->def_rpr = NULL;
        } else {
            obj->def_rpr = pptx_ct_a_text_character_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->def_rpr = NULL;
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
    obj->mar_l = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "marL");
    obj->mar_r = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "marR");
    obj->lvl = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "lvl");
    obj->indent = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "indent");
    obj->algn = pptx_get_st_text_align_type(node, (const xmlChar *) "algn");
    obj->def_tab_sz = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "defTabSz");
    obj->rtl = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rtl");
    obj->ea_ln_brk = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "eaLnBrk");
    obj->font_algn = pptx_get_st_text_font_align_type(node, (const xmlChar *) "fontAlgn");
    obj->latin_ln_brk = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "latinLnBrk");
    obj->hanging_punct = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hangingPunct");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_spacing *
pptx_ct_a_text_paragraph_properties_get_ln_spc(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->ln_spc;
}

pptx_ct_a_text_spacing *
pptx_ct_a_text_paragraph_properties_get_spc_bef(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->spc_bef;
}

pptx_ct_a_text_spacing *
pptx_ct_a_text_paragraph_properties_get_spc_aft(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->spc_aft;
}

pptx_ct_a_text_bullet_color_follow_text *
pptx_ct_a_text_paragraph_properties_get_text_bullet_color_bu_clr_tx(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_color_bu_clr_tx;
}

pptx_ct_a_color *
pptx_ct_a_text_paragraph_properties_get_text_bullet_color_bu_clr(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_color_bu_clr;
}

pptx_ct_a_text_bullet_size_follow_text *
pptx_ct_a_text_paragraph_properties_get_text_bullet_size_bu_sz_tx(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_size_bu_sz_tx;
}

pptx_ct_a_text_bullet_size_percent *
pptx_ct_a_text_paragraph_properties_get_text_bullet_size_bu_sz_pct(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_size_bu_sz_pct;
}

pptx_ct_a_text_bullet_size_point *
pptx_ct_a_text_paragraph_properties_get_text_bullet_size_bu_sz_pts(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_size_bu_sz_pts;
}

pptx_ct_a_text_bullet_typeface_follow_text *
pptx_ct_a_text_paragraph_properties_get_text_bullet_typeface_bu_font_tx(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_typeface_bu_font_tx;
}

pptx_ct_a_text_font *
pptx_ct_a_text_paragraph_properties_get_text_bullet_typeface_bu_font(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_typeface_bu_font;
}

pptx_ct_a_text_no_bullet *
pptx_ct_a_text_paragraph_properties_get_text_bullet_bu_none(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_bu_none;
}

pptx_ct_a_text_autonumber_bullet *
pptx_ct_a_text_paragraph_properties_get_text_bullet_bu_auto_num(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_bu_auto_num;
}

pptx_ct_a_text_char_bullet *
pptx_ct_a_text_paragraph_properties_get_text_bullet_bu_char(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_bu_char;
}

pptx_ct_a_text_blip_bullet *
pptx_ct_a_text_paragraph_properties_get_text_bullet_bu_blip(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->text_bullet_bu_blip;
}

pptx_ct_a_text_tab_stop_list *
pptx_ct_a_text_paragraph_properties_get_tab_lst(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->tab_lst;
}

pptx_ct_a_text_character_properties *
pptx_ct_a_text_paragraph_properties_get_def_rpr(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->def_rpr;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_text_paragraph_properties_get_ext_lst(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->ext_lst;
}

pptx_int 
pptx_ct_a_text_paragraph_properties_get_mar_l(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->mar_l;
}

pptx_int 
pptx_ct_a_text_paragraph_properties_get_mar_r(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->mar_r;
}

pptx_int 
pptx_ct_a_text_paragraph_properties_get_lvl(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->lvl;
}

pptx_int 
pptx_ct_a_text_paragraph_properties_get_indent(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->indent;
}

pptx_st_text_align_type_token_enum 
pptx_ct_a_text_paragraph_properties_get_algn(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->algn;
}

pptx_string 
pptx_ct_a_text_paragraph_properties_get_def_tab_sz(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->def_tab_sz;
}

pptx_bool 
pptx_ct_a_text_paragraph_properties_get_rtl(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->rtl;
}

pptx_bool 
pptx_ct_a_text_paragraph_properties_get_ea_ln_brk(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->ea_ln_brk;
}

pptx_st_text_font_align_type_token_enum 
pptx_ct_a_text_paragraph_properties_get_font_algn(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->font_algn;
}

pptx_bool 
pptx_ct_a_text_paragraph_properties_get_latin_ln_brk(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->latin_ln_brk;
}

pptx_bool 
pptx_ct_a_text_paragraph_properties_get_hanging_punct(const pptx_ct_a_text_paragraph_properties *const obj)
{
    return obj->hanging_punct;
}

int32_t
pptx_ct_a_text_paragraph_properties_get_index(pptx_ct_a_text_paragraph_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_paragraph_properties_free(pptx_ct_a_text_paragraph_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_spacing_free(obj->ln_spc);
    pptx_ct_a_text_spacing_free(obj->spc_bef);
    pptx_ct_a_text_spacing_free(obj->spc_aft);
    pptx_ct_a_text_bullet_color_follow_text_free(obj->text_bullet_color_bu_clr_tx);
    pptx_ct_a_color_free(obj->text_bullet_color_bu_clr);
    pptx_ct_a_text_bullet_size_follow_text_free(obj->text_bullet_size_bu_sz_tx);
    pptx_ct_a_text_bullet_size_percent_free(obj->text_bullet_size_bu_sz_pct);
    pptx_ct_a_text_bullet_size_point_free(obj->text_bullet_size_bu_sz_pts);
    pptx_ct_a_text_bullet_typeface_follow_text_free(obj->text_bullet_typeface_bu_font_tx);
    pptx_ct_a_text_font_free(obj->text_bullet_typeface_bu_font);
    pptx_ct_a_text_no_bullet_free(obj->text_bullet_bu_none);
    pptx_ct_a_text_autonumber_bullet_free(obj->text_bullet_bu_auto_num);
    pptx_ct_a_text_char_bullet_free(obj->text_bullet_bu_char);
    pptx_ct_a_text_blip_bullet_free(obj->text_bullet_bu_blip);
    pptx_ct_a_text_tab_stop_list_free(obj->tab_lst);
    pptx_ct_a_text_character_properties_free(obj->def_rpr);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->def_tab_sz);
    free(obj);
}