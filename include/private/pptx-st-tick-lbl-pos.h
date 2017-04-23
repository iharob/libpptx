#ifndef __PPTX_ST_TICK_LBL_POS_H__
#define __PPTX_ST_TICK_LBL_POS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tick_lbl_pos_text_enum {
    ST_TICK_LBL_POS_HIGH,
    ST_TICK_LBL_POS_NIL,
    ST_TICK_LBL_POS_NONE,
    ST_TICK_LBL_POS_LOW,
    ST_TICK_LBL_POS_NEXT_TO
} pptx_st_tick_lbl_pos_text_enum;

pptx_st_tick_lbl_pos_text_enum pptx_get_st_tick_lbl_pos(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TICK_LBL_POS_H__ */
