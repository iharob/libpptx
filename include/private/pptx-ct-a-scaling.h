#ifndef __PPTX_CT_A_SCALING_H__
#define __PPTX_CT_A_SCALING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_log_base_s pptx_ct_a_log_base;
typedef struct pptx_ct_a_orientation_s pptx_ct_a_orientation;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_scaling_s pptx_ct_a_scaling;
pptx_ct_a_scaling *pptx_ct_a_scaling_new(xmlNode *node);
void pptx_ct_a_scaling_free(pptx_ct_a_scaling *obj);
pptx_ct_a_log_base *pptx_ct_a_scaling_get_log_base(const pptx_ct_a_scaling *const obj);
pptx_ct_a_orientation *pptx_ct_a_scaling_get_orientation(const pptx_ct_a_scaling *const obj);
pptx_ct_a_double *pptx_ct_a_scaling_get_max(const pptx_ct_a_scaling *const obj);
pptx_ct_a_double *pptx_ct_a_scaling_get_min(const pptx_ct_a_scaling *const obj);
pptx_ct_a_extension_list *pptx_ct_a_scaling_get_ext_lst(const pptx_ct_a_scaling *const obj);
int32_t pptx_ct_a_scaling_get_index(pptx_ct_a_scaling *obj);

#endif /* __PPTX_CT_A_SCALING_H__ */
