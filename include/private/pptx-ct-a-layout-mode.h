#ifndef __PPTX_CT_A_LAYOUT_MODE_H__
#define __PPTX_CT_A_LAYOUT_MODE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_layout_mode_text_enum pptx_st_layout_mode_text_enum;

typedef struct pptx_ct_a_layout_mode_s pptx_ct_a_layout_mode;
pptx_ct_a_layout_mode *pptx_ct_a_layout_mode_new(xmlNode *node);
void pptx_ct_a_layout_mode_free(pptx_ct_a_layout_mode *obj);
pptx_st_layout_mode_text_enum pptx_ct_a_layout_mode_get_val(const pptx_ct_a_layout_mode *const obj);
int32_t pptx_ct_a_layout_mode_get_index(pptx_ct_a_layout_mode *obj);

#endif /* __PPTX_CT_A_LAYOUT_MODE_H__ */
