#ifndef __PPTX_ST_LBL_ALGN_H__
#define __PPTX_ST_LBL_ALGN_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_lbl_algn_text_enum {
    ST_LBL_ALGN_NIL,
    ST_LBL_ALGN_R,
    ST_LBL_ALGN_L,
    ST_LBL_ALGN_CTR
} pptx_st_lbl_algn_text_enum;

pptx_st_lbl_algn_text_enum pptx_get_st_lbl_algn(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LBL_ALGN_H__ */
