#ifndef __PPTX_CT_P_PRESENTATION_H__
#define __PPTX_CT_P_PRESENTATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_slide_master_id_list_s pptx_ct_p_slide_master_id_list;
typedef struct pptx_ct_p_notes_master_id_list_s pptx_ct_p_notes_master_id_list;
typedef struct pptx_ct_p_handout_master_id_list_s pptx_ct_p_handout_master_id_list;
typedef struct pptx_ct_p_slide_id_list_s pptx_ct_p_slide_id_list;
typedef struct pptx_ct_p_slide_size_s pptx_ct_p_slide_size;
typedef struct pptx_ct_a_positive_size_2d_s pptx_ct_a_positive_size_2d;
typedef struct pptx_ct_p_smart_tags_s pptx_ct_p_smart_tags;
typedef struct pptx_ct_p_embedded_font_list_s pptx_ct_p_embedded_font_list;
typedef struct pptx_ct_p_custom_show_list_s pptx_ct_p_custom_show_list;
typedef struct pptx_ct_p_photo_album_s pptx_ct_p_photo_album;
typedef struct pptx_ct_p_customer_data_list_s pptx_ct_p_customer_data_list;
typedef struct pptx_ct_p_kinsoku_s pptx_ct_p_kinsoku;
typedef struct pptx_ct_a_text_list_style_s pptx_ct_a_text_list_style;
typedef struct pptx_ct_p_modify_verifier_s pptx_ct_p_modify_verifier;
typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;
typedef enum pptx_st_conformance_class_text_enum pptx_st_conformance_class_text_enum;

typedef struct pptx_ct_p_presentation_s pptx_ct_p_presentation;
pptx_ct_p_presentation *pptx_ct_p_presentation_new(xmlNode *node);
void pptx_ct_p_presentation_free(pptx_ct_p_presentation *obj);
pptx_ct_p_slide_master_id_list *pptx_ct_p_presentation_get_sld_master_id_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_notes_master_id_list *pptx_ct_p_presentation_get_notes_master_id_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_handout_master_id_list *pptx_ct_p_presentation_get_handout_master_id_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_slide_id_list *pptx_ct_p_presentation_get_sld_id_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_slide_size *pptx_ct_p_presentation_get_sld_sz(const pptx_ct_p_presentation *const obj);
pptx_ct_a_positive_size_2d *pptx_ct_p_presentation_get_notes_sz(const pptx_ct_p_presentation *const obj);
pptx_ct_p_smart_tags *pptx_ct_p_presentation_get_smart_tags(const pptx_ct_p_presentation *const obj);
pptx_ct_p_embedded_font_list *pptx_ct_p_presentation_get_embedded_font_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_custom_show_list *pptx_ct_p_presentation_get_cust_show_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_photo_album *pptx_ct_p_presentation_get_photo_album(const pptx_ct_p_presentation *const obj);
pptx_ct_p_customer_data_list *pptx_ct_p_presentation_get_cust_data_lst(const pptx_ct_p_presentation *const obj);
pptx_ct_p_kinsoku *pptx_ct_p_presentation_get_kinsoku(const pptx_ct_p_presentation *const obj);
pptx_ct_a_text_list_style *pptx_ct_p_presentation_get_default_text_style(const pptx_ct_p_presentation *const obj);
pptx_ct_p_modify_verifier *pptx_ct_p_presentation_get_modify_verifier(const pptx_ct_p_presentation *const obj);
pptx_ct_p_extension_list *pptx_ct_p_presentation_get_ext_lst(const pptx_ct_p_presentation *const obj);
pptx_string pptx_ct_p_presentation_get_server_zoom(const pptx_ct_p_presentation *const obj);
pptx_int pptx_ct_p_presentation_get_first_slide_num(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_show_special_pls_on_title_sld(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_rtl(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_remove_personal_info_on_save(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_compat_mode(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_strict_first_and_last_chars(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_embed_true_type_fonts(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_save_subset_fonts(const pptx_ct_p_presentation *const obj);
pptx_bool pptx_ct_p_presentation_get_auto_compress_pictures(const pptx_ct_p_presentation *const obj);
pptx_uint pptx_ct_p_presentation_get_bookmark_id_seed(const pptx_ct_p_presentation *const obj);
pptx_st_conformance_class_text_enum pptx_ct_p_presentation_get_conformance(const pptx_ct_p_presentation *const obj);
int32_t pptx_ct_p_presentation_get_index(pptx_ct_p_presentation *obj);

#endif /* __PPTX_CT_P_PRESENTATION_H__ */
