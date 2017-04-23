#ifndef __PPTX_ST_RADAR_STYLE_H__
#define __PPTX_ST_RADAR_STYLE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_radar_style_text_enum {
    ST_RADAR_STYLE_MARKER,
    ST_RADAR_STYLE_NIL,
    ST_RADAR_STYLE_FILLED,
    ST_RADAR_STYLE_STANDARD
} pptx_st_radar_style_text_enum;

pptx_st_radar_style_text_enum pptx_get_st_radar_style(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_RADAR_STYLE_H__ */
