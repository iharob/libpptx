#ifndef __PPTX_ST_CRYPT_PROV_H__
#define __PPTX_ST_CRYPT_PROV_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_crypt_prov_text_enum {
    ST_CRYPT_PROV_RSA_AES,
    ST_CRYPT_PROV_NIL,
    ST_CRYPT_PROV_RSA_FULL,
    ST_CRYPT_PROV_CUSTOM
} pptx_st_crypt_prov_text_enum;

pptx_st_crypt_prov_text_enum pptx_get_st_crypt_prov(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_CRYPT_PROV_H__ */
