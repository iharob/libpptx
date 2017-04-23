#ifndef __PPTX_ST_DGM_BUILD_STEP_H__
#define __PPTX_ST_DGM_BUILD_STEP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_dgm_build_step_token_enum {
    ST_DGM_BUILD_STEP_SP,
    ST_DGM_BUILD_STEP_NIL,
    ST_DGM_BUILD_STEP_BG
} pptx_st_dgm_build_step_token_enum;

pptx_st_dgm_build_step_token_enum pptx_get_st_dgm_build_step(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_DGM_BUILD_STEP_H__ */
