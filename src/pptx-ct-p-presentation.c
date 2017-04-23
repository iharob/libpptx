#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-presentation.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-slide-master-id-list.h>
#include <private/pptx-ct-p-notes-master-id-list.h>
#include <private/pptx-ct-p-handout-master-id-list.h>
#include <private/pptx-ct-p-slide-id-list.h>
#include <private/pptx-ct-p-slide-size.h>
#include <private/pptx-ct-a-positive-size-2d.h>
#include <private/pptx-ct-p-smart-tags.h>
#include <private/pptx-ct-p-embedded-font-list.h>
#include <private/pptx-ct-p-custom-show-list.h>
#include <private/pptx-ct-p-photo-album.h>
#include <private/pptx-ct-p-customer-data-list.h>
#include <private/pptx-ct-p-kinsoku.h>
#include <private/pptx-ct-a-text-list-style.h>
#include <private/pptx-ct-p-modify-verifier.h>
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-conformance-class.h>

typedef struct pptx_ct_p_presentation_s {
    pptx_ct_p_slide_master_id_list *sld_master_id_lst;
    pptx_ct_p_notes_master_id_list *notes_master_id_lst;
    pptx_ct_p_handout_master_id_list *handout_master_id_lst;
    pptx_ct_p_slide_id_list *sld_id_lst;
    pptx_ct_p_slide_size *sld_sz;
    pptx_ct_a_positive_size_2d *notes_sz;
    pptx_ct_p_smart_tags *smart_tags;
    pptx_ct_p_embedded_font_list *embedded_font_lst;
    pptx_ct_p_custom_show_list *cust_show_lst;
    pptx_ct_p_photo_album *photo_album;
    pptx_ct_p_customer_data_list *cust_data_lst;
    pptx_ct_p_kinsoku *kinsoku;
    pptx_ct_a_text_list_style *default_text_style;
    pptx_ct_p_modify_verifier *modify_verifier;
    pptx_ct_p_extension_list *ext_lst;
    pptx_string server_zoom;
    pptx_int first_slide_num;
    pptx_bool show_special_pls_on_title_sld;
    pptx_bool rtl;
    pptx_bool remove_personal_info_on_save;
    pptx_bool compat_mode;
    pptx_bool strict_first_and_last_chars;
    pptx_bool embed_true_type_fonts;
    pptx_bool save_subset_fonts;
    pptx_bool auto_compress_pictures;
    pptx_uint bookmark_id_seed;
    pptx_st_conformance_class_text_enum conformance;
    int32_t index;
} pptx_ct_p_presentation;

pptx_ct_p_presentation *
pptx_ct_p_presentation_new(xmlNode *node)
{
    pptx_ct_p_presentation *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldMasterIdLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sld_master_id_lst = NULL;
        } else {
            obj->sld_master_id_lst = pptx_ct_p_slide_master_id_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_master_id_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesMasterIdLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_master_id_lst = NULL;
        } else {
            obj->notes_master_id_lst = pptx_ct_p_notes_master_id_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_master_id_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:handoutMasterIdLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->handout_master_id_lst = NULL;
        } else {
            obj->handout_master_id_lst = pptx_ct_p_handout_master_id_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->handout_master_id_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldIdLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sld_id_lst = NULL;
        } else {
            obj->sld_id_lst = pptx_ct_p_slide_id_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_id_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldSz");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sld_sz = NULL;
        } else {
            obj->sld_sz = pptx_ct_p_slide_size_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_sz = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesSz");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_sz = NULL;
        } else {
            obj->notes_sz = pptx_ct_a_positive_size_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_sz = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:smartTags");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->smart_tags = NULL;
        } else {
            obj->smart_tags = pptx_ct_p_smart_tags_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->smart_tags = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:embeddedFontLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->embedded_font_lst = NULL;
        } else {
            obj->embedded_font_lst = pptx_ct_p_embedded_font_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->embedded_font_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custShowLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_show_lst = NULL;
        } else {
            obj->cust_show_lst = pptx_ct_p_custom_show_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_show_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:photoAlbum");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->photo_album = NULL;
        } else {
            obj->photo_album = pptx_ct_p_photo_album_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->photo_album = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custDataLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_data_lst = NULL;
        } else {
            obj->cust_data_lst = pptx_ct_p_customer_data_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_data_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:kinsoku");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->kinsoku = NULL;
        } else {
            obj->kinsoku = pptx_ct_p_kinsoku_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->kinsoku = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:defaultTextStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->default_text_style = NULL;
        } else {
            obj->default_text_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->default_text_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:modifyVerifier");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->modify_verifier = NULL;
        } else {
            obj->modify_verifier = pptx_ct_p_modify_verifier_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->modify_verifier = NULL;
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
    obj->server_zoom = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "serverZoom");
    obj->first_slide_num = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "firstSlideNum");
    obj->show_special_pls_on_title_sld = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showSpecialPlsOnTitleSld");
    obj->rtl = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rtl");
    obj->remove_personal_info_on_save = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "removePersonalInfoOnSave");
    obj->compat_mode = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "compatMode");
    obj->strict_first_and_last_chars = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "strictFirstAndLastChars");
    obj->embed_true_type_fonts = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "embedTrueTypeFonts");
    obj->save_subset_fonts = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "saveSubsetFonts");
    obj->auto_compress_pictures = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "autoCompressPictures");
    obj->bookmark_id_seed = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "bookmarkIdSeed");
    obj->conformance = pptx_get_st_conformance_class(node, (const xmlChar *) "conformance");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_slide_master_id_list *
pptx_ct_p_presentation_get_sld_master_id_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->sld_master_id_lst;
}

pptx_ct_p_notes_master_id_list *
pptx_ct_p_presentation_get_notes_master_id_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->notes_master_id_lst;
}

pptx_ct_p_handout_master_id_list *
pptx_ct_p_presentation_get_handout_master_id_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->handout_master_id_lst;
}

pptx_ct_p_slide_id_list *
pptx_ct_p_presentation_get_sld_id_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->sld_id_lst;
}

pptx_ct_p_slide_size *
pptx_ct_p_presentation_get_sld_sz(const pptx_ct_p_presentation *const obj)
{
    return obj->sld_sz;
}

pptx_ct_a_positive_size_2d *
pptx_ct_p_presentation_get_notes_sz(const pptx_ct_p_presentation *const obj)
{
    return obj->notes_sz;
}

pptx_ct_p_smart_tags *
pptx_ct_p_presentation_get_smart_tags(const pptx_ct_p_presentation *const obj)
{
    return obj->smart_tags;
}

pptx_ct_p_embedded_font_list *
pptx_ct_p_presentation_get_embedded_font_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->embedded_font_lst;
}

pptx_ct_p_custom_show_list *
pptx_ct_p_presentation_get_cust_show_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->cust_show_lst;
}

pptx_ct_p_photo_album *
pptx_ct_p_presentation_get_photo_album(const pptx_ct_p_presentation *const obj)
{
    return obj->photo_album;
}

pptx_ct_p_customer_data_list *
pptx_ct_p_presentation_get_cust_data_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->cust_data_lst;
}

pptx_ct_p_kinsoku *
pptx_ct_p_presentation_get_kinsoku(const pptx_ct_p_presentation *const obj)
{
    return obj->kinsoku;
}

pptx_ct_a_text_list_style *
pptx_ct_p_presentation_get_default_text_style(const pptx_ct_p_presentation *const obj)
{
    return obj->default_text_style;
}

pptx_ct_p_modify_verifier *
pptx_ct_p_presentation_get_modify_verifier(const pptx_ct_p_presentation *const obj)
{
    return obj->modify_verifier;
}

pptx_ct_p_extension_list *
pptx_ct_p_presentation_get_ext_lst(const pptx_ct_p_presentation *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_p_presentation_get_server_zoom(const pptx_ct_p_presentation *const obj)
{
    return obj->server_zoom;
}

pptx_int 
pptx_ct_p_presentation_get_first_slide_num(const pptx_ct_p_presentation *const obj)
{
    return obj->first_slide_num;
}

pptx_bool 
pptx_ct_p_presentation_get_show_special_pls_on_title_sld(const pptx_ct_p_presentation *const obj)
{
    return obj->show_special_pls_on_title_sld;
}

pptx_bool 
pptx_ct_p_presentation_get_rtl(const pptx_ct_p_presentation *const obj)
{
    return obj->rtl;
}

pptx_bool 
pptx_ct_p_presentation_get_remove_personal_info_on_save(const pptx_ct_p_presentation *const obj)
{
    return obj->remove_personal_info_on_save;
}

pptx_bool 
pptx_ct_p_presentation_get_compat_mode(const pptx_ct_p_presentation *const obj)
{
    return obj->compat_mode;
}

pptx_bool 
pptx_ct_p_presentation_get_strict_first_and_last_chars(const pptx_ct_p_presentation *const obj)
{
    return obj->strict_first_and_last_chars;
}

pptx_bool 
pptx_ct_p_presentation_get_embed_true_type_fonts(const pptx_ct_p_presentation *const obj)
{
    return obj->embed_true_type_fonts;
}

pptx_bool 
pptx_ct_p_presentation_get_save_subset_fonts(const pptx_ct_p_presentation *const obj)
{
    return obj->save_subset_fonts;
}

pptx_bool 
pptx_ct_p_presentation_get_auto_compress_pictures(const pptx_ct_p_presentation *const obj)
{
    return obj->auto_compress_pictures;
}

pptx_uint 
pptx_ct_p_presentation_get_bookmark_id_seed(const pptx_ct_p_presentation *const obj)
{
    return obj->bookmark_id_seed;
}

pptx_st_conformance_class_text_enum 
pptx_ct_p_presentation_get_conformance(const pptx_ct_p_presentation *const obj)
{
    return obj->conformance;
}

int32_t
pptx_ct_p_presentation_get_index(pptx_ct_p_presentation *obj)
{
    return obj->index;
}

void
pptx_ct_p_presentation_free(pptx_ct_p_presentation *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_slide_master_id_list_free(obj->sld_master_id_lst);
    pptx_ct_p_notes_master_id_list_free(obj->notes_master_id_lst);
    pptx_ct_p_handout_master_id_list_free(obj->handout_master_id_lst);
    pptx_ct_p_slide_id_list_free(obj->sld_id_lst);
    pptx_ct_p_slide_size_free(obj->sld_sz);
    pptx_ct_a_positive_size_2d_free(obj->notes_sz);
    pptx_ct_p_smart_tags_free(obj->smart_tags);
    pptx_ct_p_embedded_font_list_free(obj->embedded_font_lst);
    pptx_ct_p_custom_show_list_free(obj->cust_show_lst);
    pptx_ct_p_photo_album_free(obj->photo_album);
    pptx_ct_p_customer_data_list_free(obj->cust_data_lst);
    pptx_ct_p_kinsoku_free(obj->kinsoku);
    pptx_ct_a_text_list_style_free(obj->default_text_style);
    pptx_ct_p_modify_verifier_free(obj->modify_verifier);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->server_zoom);
    free(obj);
}