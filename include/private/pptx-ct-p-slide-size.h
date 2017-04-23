#ifndef __PPTX_CT_P_SLIDE_SIZE_H__
#define __PPTX_CT_P_SLIDE_SIZE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_slide_size_type_token_enum pptx_st_slide_size_type_token_enum;

typedef struct pptx_ct_p_slide_size_s pptx_ct_p_slide_size;
pptx_ct_p_slide_size *pptx_ct_p_slide_size_new(xmlNode *node);
void pptx_ct_p_slide_size_free(pptx_ct_p_slide_size *obj);
pptx_int pptx_ct_p_slide_size_get_cx(const pptx_ct_p_slide_size *const obj);
pptx_int pptx_ct_p_slide_size_get_cy(const pptx_ct_p_slide_size *const obj);
pptx_st_slide_size_type_token_enum pptx_ct_p_slide_size_get_type(const pptx_ct_p_slide_size *const obj);
int32_t pptx_ct_p_slide_size_get_index(pptx_ct_p_slide_size *obj);

#endif /* __PPTX_CT_P_SLIDE_SIZE_H__ */
