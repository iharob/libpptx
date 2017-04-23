#ifndef __PPTX_CT_A_PICTURE_FORMAT_H__
#define __PPTX_CT_A_PICTURE_FORMAT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_picture_format_text_enum pptx_st_picture_format_text_enum;

typedef struct pptx_ct_a_picture_format_s pptx_ct_a_picture_format;
pptx_ct_a_picture_format *pptx_ct_a_picture_format_new(xmlNode *node);
void pptx_ct_a_picture_format_free(pptx_ct_a_picture_format *obj);
pptx_st_picture_format_text_enum pptx_ct_a_picture_format_get_val(const pptx_ct_a_picture_format *const obj);
int32_t pptx_ct_a_picture_format_get_index(pptx_ct_a_picture_format *obj);

#endif /* __PPTX_CT_A_PICTURE_FORMAT_H__ */
