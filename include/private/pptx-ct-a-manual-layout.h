#ifndef __PPTX_CT_A_MANUAL_LAYOUT_H__
#define __PPTX_CT_A_MANUAL_LAYOUT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_layout_target_s pptx_ct_a_layout_target;
typedef struct pptx_ct_a_layout_mode_s pptx_ct_a_layout_mode;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_manual_layout_s pptx_ct_a_manual_layout;
pptx_ct_a_manual_layout *pptx_ct_a_manual_layout_new(xmlNode *node);
void pptx_ct_a_manual_layout_free(pptx_ct_a_manual_layout *obj);
pptx_ct_a_layout_target *pptx_ct_a_manual_layout_get_layout_target(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_layout_mode *pptx_ct_a_manual_layout_get_x_mode(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_layout_mode *pptx_ct_a_manual_layout_get_y_mode(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_layout_mode *pptx_ct_a_manual_layout_get_w_mode(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_layout_mode *pptx_ct_a_manual_layout_get_h_mode(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_double *pptx_ct_a_manual_layout_get_x(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_double *pptx_ct_a_manual_layout_get_y(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_double *pptx_ct_a_manual_layout_get_w(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_double *pptx_ct_a_manual_layout_get_h(const pptx_ct_a_manual_layout *const obj);
pptx_ct_a_extension_list *pptx_ct_a_manual_layout_get_ext_lst(const pptx_ct_a_manual_layout *const obj);
int32_t pptx_ct_a_manual_layout_get_index(pptx_ct_a_manual_layout *obj);

#endif /* __PPTX_CT_A_MANUAL_LAYOUT_H__ */
