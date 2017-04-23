#ifndef __PPTX_CT_A_BAR_GROUPING_H__
#define __PPTX_CT_A_BAR_GROUPING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bar_grouping_text_enum pptx_st_bar_grouping_text_enum;

typedef struct pptx_ct_a_bar_grouping_s pptx_ct_a_bar_grouping;
pptx_ct_a_bar_grouping *pptx_ct_a_bar_grouping_new(xmlNode *node);
void pptx_ct_a_bar_grouping_free(pptx_ct_a_bar_grouping *obj);
pptx_st_bar_grouping_text_enum pptx_ct_a_bar_grouping_get_val(const pptx_ct_a_bar_grouping *const obj);
int32_t pptx_ct_a_bar_grouping_get_index(pptx_ct_a_bar_grouping *obj);

#endif /* __PPTX_CT_A_BAR_GROUPING_H__ */
