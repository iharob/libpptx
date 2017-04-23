#ifndef __PPTX_CT_A_ADJUST_HANDLE_LIST_H__
#define __PPTX_CT_A_ADJUST_HANDLE_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_xyadjust_handle_s pptx_ct_a_xyadjust_handle;
typedef struct pptx_ct_a_polar_adjust_handle_s pptx_ct_a_polar_adjust_handle;

typedef struct pptx_ct_a_adjust_handle_list_s pptx_ct_a_adjust_handle_list;
pptx_ct_a_adjust_handle_list *pptx_ct_a_adjust_handle_list_new(xmlNode *node);
void pptx_ct_a_adjust_handle_list_free(pptx_ct_a_adjust_handle_list *obj);
pptx_ct_a_xyadjust_handle **pptx_ct_a_adjust_handle_list_get_ah_xy(const pptx_ct_a_adjust_handle_list *const obj);
pptx_ct_a_polar_adjust_handle **pptx_ct_a_adjust_handle_list_get_ah_polar(const pptx_ct_a_adjust_handle_list *const obj);
int32_t pptx_ct_a_adjust_handle_list_get_index(pptx_ct_a_adjust_handle_list *obj);

#endif /* __PPTX_CT_A_ADJUST_HANDLE_LIST_H__ */
