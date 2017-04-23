#ifndef __PPTX_ST_PRESET_SHADOW_VAL_H__
#define __PPTX_ST_PRESET_SHADOW_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_preset_shadow_val_token_enum {
    ST_PRESET_SHADOW_VAL_SHDW3,
    ST_PRESET_SHADOW_VAL_SHDW2,
    ST_PRESET_SHADOW_VAL_SHDW1,
    ST_PRESET_SHADOW_VAL_SHDW10,
    ST_PRESET_SHADOW_VAL_SHDW7,
    ST_PRESET_SHADOW_VAL_SHDW6,
    ST_PRESET_SHADOW_VAL_SHDW5,
    ST_PRESET_SHADOW_VAL_SHDW4,
    ST_PRESET_SHADOW_VAL_NIL,
    ST_PRESET_SHADOW_VAL_SHDW12,
    ST_PRESET_SHADOW_VAL_SHDW9,
    ST_PRESET_SHADOW_VAL_SHDW8,
    ST_PRESET_SHADOW_VAL_SHDW11,
    ST_PRESET_SHADOW_VAL_SHDW13,
    ST_PRESET_SHADOW_VAL_SHDW18,
    ST_PRESET_SHADOW_VAL_SHDW19,
    ST_PRESET_SHADOW_VAL_SHDW17,
    ST_PRESET_SHADOW_VAL_SHDW20,
    ST_PRESET_SHADOW_VAL_SHDW16,
    ST_PRESET_SHADOW_VAL_SHDW14,
    ST_PRESET_SHADOW_VAL_SHDW15
} pptx_st_preset_shadow_val_token_enum;

pptx_st_preset_shadow_val_token_enum pptx_get_st_preset_shadow_val(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PRESET_SHADOW_VAL_H__ */
