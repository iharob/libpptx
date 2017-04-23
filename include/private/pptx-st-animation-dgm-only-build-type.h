#ifndef __PPTX_ST_ANIMATION_DGM_ONLY_BUILD_TYPE_H__
#define __PPTX_ST_ANIMATION_DGM_ONLY_BUILD_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_animation_dgm_only_build_type_token_enum {
    ST_ANIMATION_DGM_ONLY_BUILD_TYPE_LVL_AT_ONCE,
    ST_ANIMATION_DGM_ONLY_BUILD_TYPE_LVL_ONE,
    ST_ANIMATION_DGM_ONLY_BUILD_TYPE_NIL,
    ST_ANIMATION_DGM_ONLY_BUILD_TYPE_ONE
} pptx_st_animation_dgm_only_build_type_token_enum;

pptx_st_animation_dgm_only_build_type_token_enum pptx_get_st_animation_dgm_only_build_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ANIMATION_DGM_ONLY_BUILD_TYPE_H__ */
