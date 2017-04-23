#ifndef __PPTX_ST_AX_POS_H__
#define __PPTX_ST_AX_POS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_ax_pos_text_enum {
    ST_AX_POS_R,
    ST_AX_POS_B,
    ST_AX_POS_L,
    ST_AX_POS_NIL,
    ST_AX_POS_T
} pptx_st_ax_pos_text_enum;

pptx_st_ax_pos_text_enum pptx_get_st_ax_pos(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_AX_POS_H__ */
