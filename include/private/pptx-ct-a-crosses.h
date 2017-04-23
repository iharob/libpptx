#ifndef __PPTX_CT_A_CROSSES_H__
#define __PPTX_CT_A_CROSSES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_crosses_text_enum pptx_st_crosses_text_enum;

typedef struct pptx_ct_a_crosses_s pptx_ct_a_crosses;
pptx_ct_a_crosses *pptx_ct_a_crosses_new(xmlNode *node);
void pptx_ct_a_crosses_free(pptx_ct_a_crosses *obj);
pptx_st_crosses_text_enum pptx_ct_a_crosses_get_val(const pptx_ct_a_crosses *const obj);
int32_t pptx_ct_a_crosses_get_index(pptx_ct_a_crosses *obj);

#endif /* __PPTX_CT_A_CROSSES_H__ */
