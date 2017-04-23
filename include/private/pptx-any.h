#ifndef __PPTX_ANY_H__
#define __PPTX_ANY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>
typedef struct pptx_any_s pptx_any;
typedef struct pptx_ct_p_slide_s pptx_ct_p_slide;
typedef struct pptx_ct_p_ole_object_s pptx_ct_p_ole_object;
typedef struct pptx_ct_p_handout_master_s pptx_ct_p_handout_master;
typedef struct pptx_ct_dgm_diagram_definition_s pptx_ct_dgm_diagram_definition;
typedef struct pptx_ct_p_slide_master_s pptx_ct_p_slide_master;
typedef struct pptx_ct_p_view_properties_s pptx_ct_p_view_properties;
typedef struct pptx_ct_dgm_color_transform_header_lst_s pptx_ct_dgm_color_transform_header_lst;
typedef struct pptx_ct_a_rel_id_s pptx_ct_a_rel_id;
typedef struct pptx_ct_a_table_style_list_s pptx_ct_a_table_style_list;
typedef struct pptx_ct_p_notes_slide_s pptx_ct_p_notes_slide;
typedef struct pptx_ct_a_office_style_sheet_s pptx_ct_a_office_style_sheet;
typedef struct pptx_ct_dgm_data_model_s pptx_ct_dgm_data_model;
typedef struct pptx_ct_a_video_file_s pptx_ct_a_video_file;
typedef struct pptx_ct_dsp_drawing_s pptx_ct_dsp_drawing;
typedef struct pptx_ct_dgm_color_transform_s pptx_ct_dgm_color_transform;
typedef struct pptx_ct_dgm_style_definition_header_lst_s pptx_ct_dgm_style_definition_header_lst;
typedef struct pptx_ct_dgm_color_transform_header_s pptx_ct_dgm_color_transform_header;
typedef struct pptx_ct_a_graphical_object_s pptx_ct_a_graphical_object;
typedef struct pptx_ct_p_slide_layout_s pptx_ct_p_slide_layout;
typedef struct pptx_ct_a_picture_s pptx_ct_a_picture;
typedef struct pptx_ct_dgm_rel_ids_s pptx_ct_dgm_rel_ids;
typedef struct pptx_ct_p_comment_author_list_s pptx_ct_p_comment_author_list;
typedef struct pptx_ct_a_blip_s pptx_ct_a_blip;
typedef struct pptx_ct_p_comment_list_s pptx_ct_p_comment_list;
typedef struct pptx_ct_p_tag_list_s pptx_ct_p_tag_list;
typedef struct pptx_ct_dsp_data_model_ext_block_s pptx_ct_dsp_data_model_ext_block;
typedef struct pptx_ct_dgm_style_definition_s pptx_ct_dgm_style_definition;
typedef struct pptx_ct_dgm_diagram_definition_header_s pptx_ct_dgm_diagram_definition_header;
typedef struct pptx_ct_p_presentation_s pptx_ct_p_presentation;
typedef struct pptx_ct_p_presentation_properties_s pptx_ct_p_presentation_properties;
typedef struct pptx_ct_dgm_diagram_definition_header_lst_s pptx_ct_dgm_diagram_definition_header_lst;
typedef struct pptx_ct_p_notes_master_s pptx_ct_p_notes_master;
typedef struct pptx_ct_a_empty_element_s pptx_ct_a_empty_element;
typedef struct pptx_ct_p_slide_sync_properties_s pptx_ct_p_slide_sync_properties;
typedef struct pptx_ct_a_table_s pptx_ct_a_table;
typedef struct pptx_ct_dgm_style_definition_header_s pptx_ct_dgm_style_definition_header;
typedef struct pptx_ct_a_base_styles_override_s pptx_ct_a_base_styles_override;
typedef struct pptx_ct_a_chart_space_s pptx_ct_a_chart_space;

typedef enum pptx_any_type_id {
    PPTX_ANY_CT_P_SLIDE,
    PPTX_ANY_CT_P_OLE_OBJECT,
    PPTX_ANY_CT_P_HANDOUT_MASTER,
    PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION,
    PPTX_ANY_CT_P_SLIDE_MASTER,
    PPTX_ANY_CT_P_VIEW_PROPERTIES,
    PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER_LST,
    PPTX_ANY_CT_A_REL_ID,
    PPTX_ANY_CT_A_TABLE_STYLE_LIST,
    PPTX_ANY_CT_P_NOTES_SLIDE,
    PPTX_ANY_CT_A_OFFICE_STYLE_SHEET,
    PPTX_ANY_CT_DGM_DATA_MODEL,
    PPTX_ANY_CT_A_VIDEO_FILE,
    PPTX_ANY_CT_DSP_DRAWING,
    PPTX_ANY_CT_DGM_COLOR_TRANSFORM,
    PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER_LST,
    PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER,
    PPTX_ANY_CT_A_GRAPHICAL_OBJECT,
    PPTX_ANY_CT_P_SLIDE_LAYOUT,
    PPTX_ANY_CT_A_PICTURE,
    PPTX_ANY_CT_DGM_REL_IDS,
    PPTX_ANY_CT_P_COMMENT_AUTHOR_LIST,
    PPTX_ANY_CT_A_BLIP,
    PPTX_ANY_CT_P_COMMENT_LIST,
    PPTX_ANY_CT_P_TAG_LIST,
    PPTX_ANY_CT_DSP_DATA_MODEL_EXT_BLOCK,
    PPTX_ANY_CT_DGM_STYLE_DEFINITION,
    PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER,
    PPTX_ANY_CT_P_PRESENTATION,
    PPTX_ANY_CT_P_PRESENTATION_PROPERTIES,
    PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER_LST,
    PPTX_ANY_CT_P_NOTES_MASTER,
    PPTX_ANY_CT_A_EMPTY_ELEMENT,
    PPTX_ANY_CT_P_SLIDE_SYNC_PROPERTIES,
    PPTX_ANY_CT_A_TABLE,
    PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER,
    PPTX_ANY_CT_A_BASE_STYLES_OVERRIDE,
    PPTX_ANY_CT_A_CHART_SPACE
} pptx_any_type_id;

struct pptx_any_s {
    union {
        pptx_ct_p_slide *p_slide;
        pptx_ct_p_ole_object *p_ole_object;
        pptx_ct_p_handout_master *p_handout_master;
        pptx_ct_dgm_diagram_definition *dgm_diagram_definition;
        pptx_ct_p_slide_master *p_slide_master;
        pptx_ct_p_view_properties *p_view_properties;
        pptx_ct_dgm_color_transform_header_lst *dgm_color_transform_header_lst;
        pptx_ct_a_rel_id *a_rel_id;
        pptx_ct_a_table_style_list *a_table_style_list;
        pptx_ct_p_notes_slide *p_notes_slide;
        pptx_ct_a_office_style_sheet *a_office_style_sheet;
        pptx_ct_dgm_data_model *dgm_data_model;
        pptx_ct_a_video_file *a_video_file;
        pptx_ct_dsp_drawing *dsp_drawing;
        pptx_ct_dgm_color_transform *dgm_color_transform;
        pptx_ct_dgm_style_definition_header_lst *dgm_style_definition_header_lst;
        pptx_ct_dgm_color_transform_header *dgm_color_transform_header;
        pptx_ct_a_graphical_object *a_graphical_object;
        pptx_ct_p_slide_layout *p_slide_layout;
        pptx_ct_a_picture *a_picture;
        pptx_ct_dgm_rel_ids *dgm_rel_ids;
        pptx_ct_p_comment_author_list *p_comment_author_list;
        pptx_ct_a_blip *a_blip;
        pptx_ct_p_comment_list *p_comment_list;
        pptx_ct_p_tag_list *p_tag_list;
        pptx_ct_dsp_data_model_ext_block *dsp_data_model_ext_block;
        pptx_ct_dgm_style_definition *dgm_style_definition;
        pptx_ct_dgm_diagram_definition_header *dgm_diagram_definition_header;
        pptx_ct_p_presentation *p_presentation;
        pptx_ct_p_presentation_properties *p_presentation_properties;
        pptx_ct_dgm_diagram_definition_header_lst *dgm_diagram_definition_header_lst;
        pptx_ct_p_notes_master *p_notes_master;
        pptx_ct_a_empty_element *a_empty_element;
        pptx_ct_p_slide_sync_properties *p_slide_sync_properties;
        pptx_ct_a_table *a_table;
        pptx_ct_dgm_style_definition_header *dgm_style_definition_header;
        pptx_ct_a_base_styles_override *a_base_styles_override;
        pptx_ct_a_chart_space *a_chart_space;
    };
    pptx_any_type_id type_id;
    pptx_any *next;
};

pptx_any *pptx_any_new(xmlNode *node, int max_occurs);
void pptx_any_free(pptx_any *any);

#endif /* __PPTX_ANY_H__ */
