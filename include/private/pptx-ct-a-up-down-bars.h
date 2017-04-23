#ifndef __PPTX_CT_A_UP_DOWN_BARS_H__
#define __PPTX_CT_A_UP_DOWN_BARS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_gap_amount_s pptx_ct_a_gap_amount;
typedef struct pptx_ct_a_up_down_bar_s pptx_ct_a_up_down_bar;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_up_down_bars_s pptx_ct_a_up_down_bars;
pptx_ct_a_up_down_bars *pptx_ct_a_up_down_bars_new(xmlNode *node);
void pptx_ct_a_up_down_bars_free(pptx_ct_a_up_down_bars *obj);
pptx_ct_a_gap_amount *pptx_ct_a_up_down_bars_get_gap_width(const pptx_ct_a_up_down_bars *const obj);
pptx_ct_a_up_down_bar *pptx_ct_a_up_down_bars_get_up_bars(const pptx_ct_a_up_down_bars *const obj);
pptx_ct_a_up_down_bar *pptx_ct_a_up_down_bars_get_down_bars(const pptx_ct_a_up_down_bars *const obj);
pptx_ct_a_extension_list *pptx_ct_a_up_down_bars_get_ext_lst(const pptx_ct_a_up_down_bars *const obj);
int32_t pptx_ct_a_up_down_bars_get_index(pptx_ct_a_up_down_bars *obj);

#endif /* __PPTX_CT_A_UP_DOWN_BARS_H__ */
