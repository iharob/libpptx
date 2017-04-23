#ifndef __PPTX_ST_PT_TYPE_H__
#define __PPTX_ST_PT_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_pt_type_token_enum {
    ST_PT_TYPE_NODE,
    ST_PT_TYPE_NIL,
    ST_PT_TYPE_DOC,
    ST_PT_TYPE_SIB_TRANS,
    ST_PT_TYPE_ASST,
    ST_PT_TYPE_PAR_TRANS,
    ST_PT_TYPE_PRES
} pptx_st_pt_type_token_enum;

pptx_st_pt_type_token_enum pptx_get_st_pt_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_PT_TYPE_H__ */
