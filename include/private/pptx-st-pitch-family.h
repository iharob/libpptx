#ifndef __PPTX_ST_PITCH_FAMILY_H__
#define __PPTX_ST_PITCH_FAMILY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pitch_family_byte_enum {
    ST_PITCH_FAMILY_02,
    ST_PITCH_FAMILY_00,
    ST_PITCH_FAMILY_01,
    ST_PITCH_FAMILY_48,
    ST_PITCH_FAMILY_17,
    ST_PITCH_FAMILY_16,
    ST_PITCH_FAMILY_33,
    ST_PITCH_FAMILY_18,
    ST_PITCH_FAMILY_49,
    ST_PITCH_FAMILY_50,
    ST_PITCH_FAMILY_34,
    ST_PITCH_FAMILY_NIL,
    ST_PITCH_FAMILY_64,
    ST_PITCH_FAMILY_65,
    ST_PITCH_FAMILY_66,
    ST_PITCH_FAMILY_32,
    ST_PITCH_FAMILY_82,
    ST_PITCH_FAMILY_80,
    ST_PITCH_FAMILY_81
} pptx_st_pitch_family_byte_enum;

pptx_st_pitch_family_byte_enum pptx_get_st_pitch_family(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PITCH_FAMILY_H__ */
