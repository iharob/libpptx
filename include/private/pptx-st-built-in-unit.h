#ifndef __PPTX_ST_BUILT_IN_UNIT_H__
#define __PPTX_ST_BUILT_IN_UNIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_built_in_unit_text_enum {
    ST_BUILT_IN_UNIT_NIL,
    ST_BUILT_IN_UNIT_TEN_MILLIONS,
    ST_BUILT_IN_UNIT_TEN_THOUSANDS,
    ST_BUILT_IN_UNIT_HUNDREDS,
    ST_BUILT_IN_UNIT_HUNDRED_THOUSANDS,
    ST_BUILT_IN_UNIT_TRILLIONS,
    ST_BUILT_IN_UNIT_HUNDRED_MILLIONS,
    ST_BUILT_IN_UNIT_BILLIONS,
    ST_BUILT_IN_UNIT_THOUSANDS,
    ST_BUILT_IN_UNIT_MILLIONS
} pptx_st_built_in_unit_text_enum;

pptx_st_built_in_unit_text_enum pptx_get_st_built_in_unit(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_BUILT_IN_UNIT_H__ */
