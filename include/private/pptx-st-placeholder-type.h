#ifndef __PPTX_ST_PLACEHOLDER_TYPE_H__
#define __PPTX_ST_PLACEHOLDER_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_placeholder_type_token_enum {
    ST_PLACEHOLDER_TYPE_BODY,
    ST_PLACEHOLDER_TYPE_FTR,
    ST_PLACEHOLDER_TYPE_SUB_TITLE,
    ST_PLACEHOLDER_TYPE_CTR_TITLE,
    ST_PLACEHOLDER_TYPE_CLIP_ART,
    ST_PLACEHOLDER_TYPE_TITLE,
    ST_PLACEHOLDER_TYPE_NIL,
    ST_PLACEHOLDER_TYPE_MEDIA,
    ST_PLACEHOLDER_TYPE_PIC,
    ST_PLACEHOLDER_TYPE_CHART,
    ST_PLACEHOLDER_TYPE_SLD_IMG,
    ST_PLACEHOLDER_TYPE_DGM,
    ST_PLACEHOLDER_TYPE_SLD_NUM,
    ST_PLACEHOLDER_TYPE_TBL,
    ST_PLACEHOLDER_TYPE_OBJ,
    ST_PLACEHOLDER_TYPE_DT,
    ST_PLACEHOLDER_TYPE_HDR
} pptx_st_placeholder_type_token_enum;

pptx_st_placeholder_type_token_enum pptx_get_st_placeholder_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PLACEHOLDER_TYPE_H__ */
