#ifndef __PPTX_CT_A_SIZE_REPRESENTS_H__
#define __PPTX_CT_A_SIZE_REPRESENTS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_size_represents_text_enum pptx_st_size_represents_text_enum;

typedef struct pptx_ct_a_size_represents_s pptx_ct_a_size_represents;
pptx_ct_a_size_represents *pptx_ct_a_size_represents_new(xmlNode *node);
void pptx_ct_a_size_represents_free(pptx_ct_a_size_represents *obj);
pptx_st_size_represents_text_enum pptx_ct_a_size_represents_get_val(const pptx_ct_a_size_represents *const obj);
int32_t pptx_ct_a_size_represents_get_index(pptx_ct_a_size_represents *obj);

#endif /* __PPTX_CT_A_SIZE_REPRESENTS_H__ */
