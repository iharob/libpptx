#ifndef __PPTX_ST_ANIM_LVL_STR_H__
#define __PPTX_ST_ANIM_LVL_STR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_anim_lvl_str_token_enum {
    ST_ANIM_LVL_STR_LVL,
    ST_ANIM_LVL_STR_NONE,
    ST_ANIM_LVL_STR_NIL,
    ST_ANIM_LVL_STR_CTR
} pptx_st_anim_lvl_str_token_enum;

pptx_st_anim_lvl_str_token_enum pptx_get_st_anim_lvl_str(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ANIM_LVL_STR_H__ */
