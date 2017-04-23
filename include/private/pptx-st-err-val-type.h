#ifndef __PPTX_ST_ERR_VAL_TYPE_H__
#define __PPTX_ST_ERR_VAL_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_err_val_type_text_enum {
    ST_ERR_VAL_TYPE_STD_ERR,
    ST_ERR_VAL_TYPE_CUST,
    ST_ERR_VAL_TYPE_NIL,
    ST_ERR_VAL_TYPE_FIXED_VAL,
    ST_ERR_VAL_TYPE_STD_DEV,
    ST_ERR_VAL_TYPE_PERCENTAGE
} pptx_st_err_val_type_text_enum;

pptx_st_err_val_type_text_enum pptx_get_st_err_val_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_ERR_VAL_TYPE_H__ */
