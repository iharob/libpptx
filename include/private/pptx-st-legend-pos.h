#ifndef __PPTX_ST_LEGEND_POS_H__
#define __PPTX_ST_LEGEND_POS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_legend_pos_text_enum {
    ST_LEGEND_POS_B,
    ST_LEGEND_POS_NIL,
    ST_LEGEND_POS_TR,
    ST_LEGEND_POS_L,
    ST_LEGEND_POS_R,
    ST_LEGEND_POS_T
} pptx_st_legend_pos_text_enum;

pptx_st_legend_pos_text_enum pptx_get_st_legend_pos(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_LEGEND_POS_H__ */
