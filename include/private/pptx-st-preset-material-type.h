#ifndef __PPTX_ST_PRESET_MATERIAL_TYPE_H__
#define __PPTX_ST_PRESET_MATERIAL_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_preset_material_type_token_enum {
    ST_PRESET_MATERIAL_TYPE_FLAT,
    ST_PRESET_MATERIAL_TYPE_TRANSLUCENT_POWDER,
    ST_PRESET_MATERIAL_TYPE_NIL,
    ST_PRESET_MATERIAL_TYPE_SOFT_EDGE,
    ST_PRESET_MATERIAL_TYPE_CLEAR,
    ST_PRESET_MATERIAL_TYPE_METAL,
    ST_PRESET_MATERIAL_TYPE_DK_EDGE,
    ST_PRESET_MATERIAL_TYPE_LEGACY_WIREFRAME,
    ST_PRESET_MATERIAL_TYPE_PLASTIC,
    ST_PRESET_MATERIAL_TYPE_MATTE,
    ST_PRESET_MATERIAL_TYPE_LEGACY_METAL,
    ST_PRESET_MATERIAL_TYPE_LEGACY_PLASTIC,
    ST_PRESET_MATERIAL_TYPE_WARM_MATTE,
    ST_PRESET_MATERIAL_TYPE_SOFTMETAL,
    ST_PRESET_MATERIAL_TYPE_LEGACY_MATTE,
    ST_PRESET_MATERIAL_TYPE_POWDER
} pptx_st_preset_material_type_token_enum;

pptx_st_preset_material_type_token_enum pptx_get_st_preset_material_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PRESET_MATERIAL_TYPE_H__ */
