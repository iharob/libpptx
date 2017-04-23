#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-body-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-preset-text-shape.h>
#include <private/pptx-ct-a-text-no-autofit.h>
#include <private/pptx-ct-a-text-normal-autofit.h>
#include <private/pptx-ct-a-text-shape-autofit.h>
#include <private/pptx-ct-a-scene-3d.h>
#include <private/pptx-ct-a-shape-3d.h>
#include <private/pptx-ct-a-flat-text.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-text-vert-overflow-type.h>
#include <private/pptx-st-text-horz-overflow-type.h>
#include <private/pptx-st-text-vertical-type.h>
#include <private/pptx-st-text-wrapping-type.h>
#include <private/pptx-st-text-anchoring-type.h>

typedef struct pptx_ct_a_text_body_properties_s {
    pptx_ct_a_preset_text_shape *prst_tx_warp;
    pptx_ct_a_text_no_autofit *text_autofit_no_autofit;
    pptx_ct_a_text_normal_autofit *text_autofit_norm_autofit;
    pptx_ct_a_text_shape_autofit *text_autofit_sp_auto_fit;
    pptx_ct_a_scene_3d *scene3d;
    pptx_ct_a_shape_3d *text_3d_sp3d;
    pptx_ct_a_flat_text *text_3d_flat_tx;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_int rot;
    pptx_bool spc_first_last_para;
    pptx_st_text_vert_overflow_type_token_enum vert_overflow;
    pptx_st_text_horz_overflow_type_token_enum horz_overflow;
    pptx_st_text_vertical_type_token_enum vert;
    pptx_st_text_wrapping_type_token_enum wrap;
    pptx_string l_ins;
    pptx_string t_ins;
    pptx_string r_ins;
    pptx_string b_ins;
    pptx_int num_col;
    pptx_int spc_col;
    pptx_bool rtl_col;
    pptx_bool from_word_art;
    pptx_st_text_anchoring_type_token_enum anchor;
    pptx_bool anchor_ctr;
    pptx_bool force_aa;
    pptx_bool upright;
    pptx_bool compat_ln_spc;
    int32_t index;
} pptx_ct_a_text_body_properties;

pptx_ct_a_text_body_properties *
pptx_ct_a_text_body_properties_new(xmlNode *node)
{
    pptx_ct_a_text_body_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstTxWarp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->prst_tx_warp = NULL;
        } else {
            obj->prst_tx_warp = pptx_ct_a_preset_text_shape_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->prst_tx_warp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:noAutofit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_autofit_no_autofit = NULL;
        } else {
            obj->text_autofit_no_autofit = pptx_ct_a_text_no_autofit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_autofit_no_autofit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:normAutofit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_autofit_norm_autofit = NULL;
        } else {
            obj->text_autofit_norm_autofit = pptx_ct_a_text_normal_autofit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_autofit_norm_autofit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spAutoFit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_autofit_sp_auto_fit = NULL;
        } else {
            obj->text_autofit_sp_auto_fit = pptx_ct_a_text_shape_autofit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_autofit_sp_auto_fit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scene3d");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->scene3d = NULL;
        } else {
            obj->scene3d = pptx_ct_a_scene_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->scene3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sp3d");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_3d_sp3d = NULL;
        } else {
            obj->text_3d_sp3d = pptx_ct_a_shape_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_3d_sp3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:flatTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_3d_flat_tx = NULL;
        } else {
            obj->text_3d_flat_tx = pptx_ct_a_flat_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_3d_flat_tx = NULL;
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
    obj->rot = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "rot");
    obj->spc_first_last_para = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "spcFirstLastPara");
    obj->vert_overflow = pptx_get_st_text_vert_overflow_type(node, (const xmlChar *) "vertOverflow");
    obj->horz_overflow = pptx_get_st_text_horz_overflow_type(node, (const xmlChar *) "horzOverflow");
    obj->vert = pptx_get_st_text_vertical_type(node, (const xmlChar *) "vert");
    obj->wrap = pptx_get_st_text_wrapping_type(node, (const xmlChar *) "wrap");
    obj->l_ins = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lIns");
    obj->t_ins = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tIns");
    obj->r_ins = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "rIns");
    obj->b_ins = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "bIns");
    obj->num_col = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "numCol");
    obj->spc_col = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "spcCol");
    obj->rtl_col = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rtlCol");
    obj->from_word_art = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "fromWordArt");
    obj->anchor = pptx_get_st_text_anchoring_type(node, (const xmlChar *) "anchor");
    obj->anchor_ctr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "anchorCtr");
    obj->force_aa = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "forceAA");
    obj->upright = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "upright");
    obj->compat_ln_spc = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "compatLnSpc");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_preset_text_shape *
pptx_ct_a_text_body_properties_get_prst_tx_warp(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->prst_tx_warp;
}

pptx_ct_a_text_no_autofit *
pptx_ct_a_text_body_properties_get_text_autofit_no_autofit(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->text_autofit_no_autofit;
}

pptx_ct_a_text_normal_autofit *
pptx_ct_a_text_body_properties_get_text_autofit_norm_autofit(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->text_autofit_norm_autofit;
}

pptx_ct_a_text_shape_autofit *
pptx_ct_a_text_body_properties_get_text_autofit_sp_auto_fit(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->text_autofit_sp_auto_fit;
}

pptx_ct_a_scene_3d *
pptx_ct_a_text_body_properties_get_scene3d(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->scene3d;
}

pptx_ct_a_shape_3d *
pptx_ct_a_text_body_properties_get_text_3d_sp3d(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->text_3d_sp3d;
}

pptx_ct_a_flat_text *
pptx_ct_a_text_body_properties_get_text_3d_flat_tx(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->text_3d_flat_tx;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_text_body_properties_get_ext_lst(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->ext_lst;
}

pptx_int 
pptx_ct_a_text_body_properties_get_rot(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->rot;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_spc_first_last_para(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->spc_first_last_para;
}

pptx_st_text_vert_overflow_type_token_enum 
pptx_ct_a_text_body_properties_get_vert_overflow(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->vert_overflow;
}

pptx_st_text_horz_overflow_type_token_enum 
pptx_ct_a_text_body_properties_get_horz_overflow(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->horz_overflow;
}

pptx_st_text_vertical_type_token_enum 
pptx_ct_a_text_body_properties_get_vert(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->vert;
}

pptx_st_text_wrapping_type_token_enum 
pptx_ct_a_text_body_properties_get_wrap(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->wrap;
}

pptx_string 
pptx_ct_a_text_body_properties_get_l_ins(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->l_ins;
}

pptx_string 
pptx_ct_a_text_body_properties_get_t_ins(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->t_ins;
}

pptx_string 
pptx_ct_a_text_body_properties_get_r_ins(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->r_ins;
}

pptx_string 
pptx_ct_a_text_body_properties_get_b_ins(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->b_ins;
}

pptx_int 
pptx_ct_a_text_body_properties_get_num_col(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->num_col;
}

pptx_int 
pptx_ct_a_text_body_properties_get_spc_col(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->spc_col;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_rtl_col(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->rtl_col;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_from_word_art(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->from_word_art;
}

pptx_st_text_anchoring_type_token_enum 
pptx_ct_a_text_body_properties_get_anchor(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->anchor;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_anchor_ctr(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->anchor_ctr;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_force_aa(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->force_aa;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_upright(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->upright;
}

pptx_bool 
pptx_ct_a_text_body_properties_get_compat_ln_spc(const pptx_ct_a_text_body_properties *const obj)
{
    return obj->compat_ln_spc;
}

int32_t
pptx_ct_a_text_body_properties_get_index(pptx_ct_a_text_body_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_body_properties_free(pptx_ct_a_text_body_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_preset_text_shape_free(obj->prst_tx_warp);
    pptx_ct_a_text_no_autofit_free(obj->text_autofit_no_autofit);
    pptx_ct_a_text_normal_autofit_free(obj->text_autofit_norm_autofit);
    pptx_ct_a_text_shape_autofit_free(obj->text_autofit_sp_auto_fit);
    pptx_ct_a_scene_3d_free(obj->scene3d);
    pptx_ct_a_shape_3d_free(obj->text_3d_sp3d);
    pptx_ct_a_flat_text_free(obj->text_3d_flat_tx);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->l_ins);
    xmlFree(obj->t_ins);
    xmlFree(obj->r_ins);
    xmlFree(obj->b_ins);
    free(obj);
}