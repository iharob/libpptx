#ifndef __PPTX_ST_DLBL_POS_H__
#define __PPTX_ST_DLBL_POS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_dlbl_pos_text_enum {
    ST_DLBL_POS_BEST_FIT,
    ST_DLBL_POS_IN_END,
    ST_DLBL_POS_B,
    ST_DLBL_POS_NIL,
    ST_DLBL_POS_CTR,
    ST_DLBL_POS_L,
    ST_DLBL_POS_IN_BASE,
    ST_DLBL_POS_R,
    ST_DLBL_POS_OUT_END,
    ST_DLBL_POS_T
} pptx_st_dlbl_pos_text_enum;

pptx_st_dlbl_pos_text_enum pptx_get_st_dlbl_pos(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_DLBL_POS_H__ */
