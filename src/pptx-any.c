#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-any.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-slide.h>
#include <private/pptx-ct-p-ole-object.h>
#include <private/pptx-ct-p-handout-master.h>
#include <private/pptx-ct-dgm-diagram-definition.h>
#include <private/pptx-ct-p-slide-master.h>
#include <private/pptx-ct-p-view-properties.h>
#include <private/pptx-ct-dgm-color-transform-header-lst.h>
#include <private/pptx-ct-a-rel-id.h>
#include <private/pptx-ct-a-table-style-list.h>
#include <private/pptx-ct-p-notes-slide.h>
#include <private/pptx-ct-a-office-style-sheet.h>
#include <private/pptx-ct-dgm-data-model.h>
#include <private/pptx-ct-a-video-file.h>
#include <private/pptx-ct-dsp-drawing.h>
#include <private/pptx-ct-dgm-color-transform.h>
#include <private/pptx-ct-dgm-style-definition-header-lst.h>
#include <private/pptx-ct-dgm-color-transform-header.h>
#include <private/pptx-ct-a-graphical-object.h>
#include <private/pptx-ct-p-slide-layout.h>
#include <private/pptx-ct-a-picture.h>
#include <private/pptx-ct-dgm-rel-ids.h>
#include <private/pptx-ct-p-comment-author-list.h>
#include <private/pptx-ct-a-blip.h>
#include <private/pptx-ct-p-comment-list.h>
#include <private/pptx-ct-p-tag-list.h>
#include <private/pptx-ct-dsp-data-model-ext-block.h>
#include <private/pptx-ct-dgm-style-definition.h>
#include <private/pptx-ct-dgm-diagram-definition-header.h>
#include <private/pptx-ct-p-presentation.h>
#include <private/pptx-ct-p-presentation-properties.h>
#include <private/pptx-ct-dgm-diagram-definition-header-lst.h>
#include <private/pptx-ct-p-notes-master.h>
#include <private/pptx-ct-a-empty-element.h>
#include <private/pptx-ct-p-slide-sync-properties.h>
#include <private/pptx-ct-a-table.h>
#include <private/pptx-ct-dgm-style-definition-header.h>
#include <private/pptx-ct-a-base-styles-override.h>
#include <private/pptx-ct-a-chart-space.h>

struct map {
    const char *name;
    pptx_any_type_id id;
};

static const struct map types[] = {
    {"a:blip", PPTX_ANY_CT_A_BLIP},
    {"a:chart", PPTX_ANY_CT_A_REL_ID},
    {"a:chartSpace", PPTX_ANY_CT_A_CHART_SPACE},
    {"a:graphic", PPTX_ANY_CT_A_GRAPHICAL_OBJECT},
    {"a:pic", PPTX_ANY_CT_A_PICTURE},
    {"a:tbl", PPTX_ANY_CT_A_TABLE},
    {"a:tblStyleLst", PPTX_ANY_CT_A_TABLE_STYLE_LIST},
    {"a:theme", PPTX_ANY_CT_A_OFFICE_STYLE_SHEET},
    {"a:themeManager", PPTX_ANY_CT_A_EMPTY_ELEMENT},
    {"a:themeOverride", PPTX_ANY_CT_A_BASE_STYLES_OVERRIDE},
    {"a:videoFile", PPTX_ANY_CT_A_VIDEO_FILE},
    {"dgm:colorsDef", PPTX_ANY_CT_DGM_COLOR_TRANSFORM},
    {"dgm:colorsDefHdr", PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER},
    {"dgm:colorsDefHdrLst", PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER_LST},
    {"dgm:dataModel", PPTX_ANY_CT_DGM_DATA_MODEL},
    {"dgm:layoutDef", PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION},
    {"dgm:layoutDefHdr", PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER},
    {"dgm:layoutDefHdrLst", PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER_LST},
    {"dgm:relIds", PPTX_ANY_CT_DGM_REL_IDS},
    {"dgm:styleDef", PPTX_ANY_CT_DGM_STYLE_DEFINITION},
    {"dgm:styleDefHdr", PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER},
    {"dgm:styleDefHdrLst", PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER_LST},
    {"dsp:dataModelExt", PPTX_ANY_CT_DSP_DATA_MODEL_EXT_BLOCK},
    {"dsp:drawing", PPTX_ANY_CT_DSP_DRAWING},
    {"p:cmAuthorLst", PPTX_ANY_CT_P_COMMENT_AUTHOR_LIST},
    {"p:cmLst", PPTX_ANY_CT_P_COMMENT_LIST},
    {"p:handoutMaster", PPTX_ANY_CT_P_HANDOUT_MASTER},
    {"p:notes", PPTX_ANY_CT_P_NOTES_SLIDE},
    {"p:notesMaster", PPTX_ANY_CT_P_NOTES_MASTER},
    {"p:oleObj", PPTX_ANY_CT_P_OLE_OBJECT},
    {"p:presentation", PPTX_ANY_CT_P_PRESENTATION},
    {"p:presentationPr", PPTX_ANY_CT_P_PRESENTATION_PROPERTIES},
    {"p:sld", PPTX_ANY_CT_P_SLIDE},
    {"p:sldLayout", PPTX_ANY_CT_P_SLIDE_LAYOUT},
    {"p:sldMaster", PPTX_ANY_CT_P_SLIDE_MASTER},
    {"p:sldSyncPr", PPTX_ANY_CT_P_SLIDE_SYNC_PROPERTIES},
    {"p:tagLst", PPTX_ANY_CT_P_TAG_LIST},
    {"p:viewPr", PPTX_ANY_CT_P_VIEW_PROPERTIES}
};

int
compare(const void *const A, const void *const B)
{
    const struct map *MAP_A = A;
    const struct map *MAP_B = B;
    
    return strcmp(MAP_A->name, MAP_B->name);
}

static pptx_any *
pptx_any_new_item(xmlNode *node)
{
    struct map *found;
    char *name;
    struct map key;
    pptx_any *item;
    name = pptx_xml_get_prefixed_name(node);
    if (name == NULL)
        goto error;
    key.name = name;
    // Perform a binary search
    found = bsearch(&key, types, sizeof types / sizeof *types, sizeof *types, compare);
    // Check if we found it, if we didn't then it means that
    // it's an application specific object and we don't care
    // about it.
    if (found == NULL)
        goto error;
    // Allocate and create the actual `any' type object, this is a single link list
    // that could be empty (head node  == NULL).
    item = malloc(sizeof *item);
    if (item == NULL)
        goto error;
    // For each type that is considered a `any' type candidate
    // we need to select the one that matched and populate it's
    // union member here
    item->type_id = found->id; 
    switch (item->type_id) {
    case PPTX_ANY_CT_P_SLIDE:
        item->p_slide = pptx_ct_p_slide_new(node);
        break;
    case PPTX_ANY_CT_P_OLE_OBJECT:
        item->p_ole_object = pptx_ct_p_ole_object_new(node);
        break;
    case PPTX_ANY_CT_P_HANDOUT_MASTER:
        item->p_handout_master = pptx_ct_p_handout_master_new(node);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION:
        item->dgm_diagram_definition = pptx_ct_dgm_diagram_definition_new(node);
        break;
    case PPTX_ANY_CT_P_SLIDE_MASTER:
        item->p_slide_master = pptx_ct_p_slide_master_new(node);
        break;
    case PPTX_ANY_CT_P_VIEW_PROPERTIES:
        item->p_view_properties = pptx_ct_p_view_properties_new(node);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER_LST:
        item->dgm_color_transform_header_lst = pptx_ct_dgm_color_transform_header_lst_new(node);
        break;
    case PPTX_ANY_CT_A_REL_ID:
        item->a_rel_id = pptx_ct_a_rel_id_new(node);
        break;
    case PPTX_ANY_CT_A_TABLE_STYLE_LIST:
        item->a_table_style_list = pptx_ct_a_table_style_list_new(node);
        break;
    case PPTX_ANY_CT_P_NOTES_SLIDE:
        item->p_notes_slide = pptx_ct_p_notes_slide_new(node);
        break;
    case PPTX_ANY_CT_A_OFFICE_STYLE_SHEET:
        item->a_office_style_sheet = pptx_ct_a_office_style_sheet_new(node);
        break;
    case PPTX_ANY_CT_DGM_DATA_MODEL:
        item->dgm_data_model = pptx_ct_dgm_data_model_new(node);
        break;
    case PPTX_ANY_CT_A_VIDEO_FILE:
        item->a_video_file = pptx_ct_a_video_file_new(node);
        break;
    case PPTX_ANY_CT_DSP_DRAWING:
        item->dsp_drawing = pptx_ct_dsp_drawing_new(node);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM:
        item->dgm_color_transform = pptx_ct_dgm_color_transform_new(node);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER_LST:
        item->dgm_style_definition_header_lst = pptx_ct_dgm_style_definition_header_lst_new(node);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER:
        item->dgm_color_transform_header = pptx_ct_dgm_color_transform_header_new(node);
        break;
    case PPTX_ANY_CT_A_GRAPHICAL_OBJECT:
        item->a_graphical_object = pptx_ct_a_graphical_object_new(node);
        break;
    case PPTX_ANY_CT_P_SLIDE_LAYOUT:
        item->p_slide_layout = pptx_ct_p_slide_layout_new(node);
        break;
    case PPTX_ANY_CT_A_PICTURE:
        item->a_picture = pptx_ct_a_picture_new(node);
        break;
    case PPTX_ANY_CT_DGM_REL_IDS:
        item->dgm_rel_ids = pptx_ct_dgm_rel_ids_new(node);
        break;
    case PPTX_ANY_CT_P_COMMENT_AUTHOR_LIST:
        item->p_comment_author_list = pptx_ct_p_comment_author_list_new(node);
        break;
    case PPTX_ANY_CT_A_BLIP:
        item->a_blip = pptx_ct_a_blip_new(node);
        break;
    case PPTX_ANY_CT_P_COMMENT_LIST:
        item->p_comment_list = pptx_ct_p_comment_list_new(node);
        break;
    case PPTX_ANY_CT_P_TAG_LIST:
        item->p_tag_list = pptx_ct_p_tag_list_new(node);
        break;
    case PPTX_ANY_CT_DSP_DATA_MODEL_EXT_BLOCK:
        item->dsp_data_model_ext_block = pptx_ct_dsp_data_model_ext_block_new(node);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION:
        item->dgm_style_definition = pptx_ct_dgm_style_definition_new(node);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER:
        item->dgm_diagram_definition_header = pptx_ct_dgm_diagram_definition_header_new(node);
        break;
    case PPTX_ANY_CT_P_PRESENTATION:
        item->p_presentation = pptx_ct_p_presentation_new(node);
        break;
    case PPTX_ANY_CT_P_PRESENTATION_PROPERTIES:
        item->p_presentation_properties = pptx_ct_p_presentation_properties_new(node);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER_LST:
        item->dgm_diagram_definition_header_lst = pptx_ct_dgm_diagram_definition_header_lst_new(node);
        break;
    case PPTX_ANY_CT_P_NOTES_MASTER:
        item->p_notes_master = pptx_ct_p_notes_master_new(node);
        break;
    case PPTX_ANY_CT_A_EMPTY_ELEMENT:
        item->a_empty_element = pptx_ct_a_empty_element_new(node);
        break;
    case PPTX_ANY_CT_P_SLIDE_SYNC_PROPERTIES:
        item->p_slide_sync_properties = pptx_ct_p_slide_sync_properties_new(node);
        break;
    case PPTX_ANY_CT_A_TABLE:
        item->a_table = pptx_ct_a_table_new(node);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER:
        item->dgm_style_definition_header = pptx_ct_dgm_style_definition_header_new(node);
        break;
    case PPTX_ANY_CT_A_BASE_STYLES_OVERRIDE:
        item->a_base_styles_override = pptx_ct_a_base_styles_override_new(node);
        break;
    case PPTX_ANY_CT_A_CHART_SPACE:
        item->a_chart_space = pptx_ct_a_chart_space_new(node);
        break;
    }
    item->next = NULL;
    // Release temporary memory
    free(name);
    // Return the list node
    return item;
error:
    // Cleanup and return `NULL' because something bad
    // happened
    free(name);
    return NULL;
}

static void
pptx_any_data_free(pptx_any *item)
{
    if (item == NULL)
        return;
    switch (item->type_id) {
    case PPTX_ANY_CT_P_SLIDE:
        pptx_ct_p_slide_free(item->p_slide);
        break;
    case PPTX_ANY_CT_P_OLE_OBJECT:
        pptx_ct_p_ole_object_free(item->p_ole_object);
        break;
    case PPTX_ANY_CT_P_HANDOUT_MASTER:
        pptx_ct_p_handout_master_free(item->p_handout_master);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION:
        pptx_ct_dgm_diagram_definition_free(item->dgm_diagram_definition);
        break;
    case PPTX_ANY_CT_P_SLIDE_MASTER:
        pptx_ct_p_slide_master_free(item->p_slide_master);
        break;
    case PPTX_ANY_CT_P_VIEW_PROPERTIES:
        pptx_ct_p_view_properties_free(item->p_view_properties);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER_LST:
        pptx_ct_dgm_color_transform_header_lst_free(item->dgm_color_transform_header_lst);
        break;
    case PPTX_ANY_CT_A_REL_ID:
        pptx_ct_a_rel_id_free(item->a_rel_id);
        break;
    case PPTX_ANY_CT_A_TABLE_STYLE_LIST:
        pptx_ct_a_table_style_list_free(item->a_table_style_list);
        break;
    case PPTX_ANY_CT_P_NOTES_SLIDE:
        pptx_ct_p_notes_slide_free(item->p_notes_slide);
        break;
    case PPTX_ANY_CT_A_OFFICE_STYLE_SHEET:
        pptx_ct_a_office_style_sheet_free(item->a_office_style_sheet);
        break;
    case PPTX_ANY_CT_DGM_DATA_MODEL:
        pptx_ct_dgm_data_model_free(item->dgm_data_model);
        break;
    case PPTX_ANY_CT_A_VIDEO_FILE:
        pptx_ct_a_video_file_free(item->a_video_file);
        break;
    case PPTX_ANY_CT_DSP_DRAWING:
        pptx_ct_dsp_drawing_free(item->dsp_drawing);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM:
        pptx_ct_dgm_color_transform_free(item->dgm_color_transform);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER_LST:
        pptx_ct_dgm_style_definition_header_lst_free(item->dgm_style_definition_header_lst);
        break;
    case PPTX_ANY_CT_DGM_COLOR_TRANSFORM_HEADER:
        pptx_ct_dgm_color_transform_header_free(item->dgm_color_transform_header);
        break;
    case PPTX_ANY_CT_A_GRAPHICAL_OBJECT:
        pptx_ct_a_graphical_object_free(item->a_graphical_object);
        break;
    case PPTX_ANY_CT_P_SLIDE_LAYOUT:
        pptx_ct_p_slide_layout_free(item->p_slide_layout);
        break;
    case PPTX_ANY_CT_A_PICTURE:
        pptx_ct_a_picture_free(item->a_picture);
        break;
    case PPTX_ANY_CT_DGM_REL_IDS:
        pptx_ct_dgm_rel_ids_free(item->dgm_rel_ids);
        break;
    case PPTX_ANY_CT_P_COMMENT_AUTHOR_LIST:
        pptx_ct_p_comment_author_list_free(item->p_comment_author_list);
        break;
    case PPTX_ANY_CT_A_BLIP:
        pptx_ct_a_blip_free(item->a_blip);
        break;
    case PPTX_ANY_CT_P_COMMENT_LIST:
        pptx_ct_p_comment_list_free(item->p_comment_list);
        break;
    case PPTX_ANY_CT_P_TAG_LIST:
        pptx_ct_p_tag_list_free(item->p_tag_list);
        break;
    case PPTX_ANY_CT_DSP_DATA_MODEL_EXT_BLOCK:
        pptx_ct_dsp_data_model_ext_block_free(item->dsp_data_model_ext_block);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION:
        pptx_ct_dgm_style_definition_free(item->dgm_style_definition);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER:
        pptx_ct_dgm_diagram_definition_header_free(item->dgm_diagram_definition_header);
        break;
    case PPTX_ANY_CT_P_PRESENTATION:
        pptx_ct_p_presentation_free(item->p_presentation);
        break;
    case PPTX_ANY_CT_P_PRESENTATION_PROPERTIES:
        pptx_ct_p_presentation_properties_free(item->p_presentation_properties);
        break;
    case PPTX_ANY_CT_DGM_DIAGRAM_DEFINITION_HEADER_LST:
        pptx_ct_dgm_diagram_definition_header_lst_free(item->dgm_diagram_definition_header_lst);
        break;
    case PPTX_ANY_CT_P_NOTES_MASTER:
        pptx_ct_p_notes_master_free(item->p_notes_master);
        break;
    case PPTX_ANY_CT_A_EMPTY_ELEMENT:
        pptx_ct_a_empty_element_free(item->a_empty_element);
        break;
    case PPTX_ANY_CT_P_SLIDE_SYNC_PROPERTIES:
        pptx_ct_p_slide_sync_properties_free(item->p_slide_sync_properties);
        break;
    case PPTX_ANY_CT_A_TABLE:
        pptx_ct_a_table_free(item->a_table);
        break;
    case PPTX_ANY_CT_DGM_STYLE_DEFINITION_HEADER:
        pptx_ct_dgm_style_definition_header_free(item->dgm_style_definition_header);
        break;
    case PPTX_ANY_CT_A_BASE_STYLES_OVERRIDE:
        pptx_ct_a_base_styles_override_free(item->a_base_styles_override);
        break;
    case PPTX_ANY_CT_A_CHART_SPACE:
        pptx_ct_a_chart_space_free(item->a_chart_space);
        break;
    }
}

void
pptx_any_free(pptx_any *list)
{
    pptx_any *next;
    for (pptx_any *item = list; item != NULL; item = next) {
        // Store the next pointer
        next = item->next;
        // Call the data free function, selection
        // is performed per type id
        pptx_any_data_free(item);
        // Free the container object (the list node)
        free(item);
    }
}

pptx_any *
pptx_any_new(xmlNode *node, int max_occurs)
{
    pptx_any *list;
    list = NULL;
    for (xmlNode *next = node->children; next != NULL; next = next->next) {
        pptx_any *item;
        item = pptx_any_new_item(next);
        if (item == NULL)
            continue;
        item->next = list;
        list = item;
    }
    return list;
}
