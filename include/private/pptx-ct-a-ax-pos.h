#ifndef __PPTX_CT_A_AX_POS_H__
#define __PPTX_CT_A_AX_POS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_ax_pos_text_enum pptx_st_ax_pos_text_enum;

typedef struct pptx_ct_a_ax_pos_s pptx_ct_a_ax_pos;
pptx_ct_a_ax_pos *pptx_ct_a_ax_pos_new(xmlNode *node);
void pptx_ct_a_ax_pos_free(pptx_ct_a_ax_pos *obj);
pptx_st_ax_pos_text_enum pptx_ct_a_ax_pos_get_val(const pptx_ct_a_ax_pos *const obj);
int32_t pptx_ct_a_ax_pos_get_index(pptx_ct_a_ax_pos *obj);

#endif /* __PPTX_CT_A_AX_POS_H__ */
