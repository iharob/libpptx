#ifndef __PPTX_CT_A_DISP_UNITS_H__
#define __PPTX_CT_A_DISP_UNITS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_built_in_unit_s pptx_ct_a_built_in_unit;
typedef struct pptx_ct_a_disp_units_lbl_s pptx_ct_a_disp_units_lbl;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_disp_units_s pptx_ct_a_disp_units;
pptx_ct_a_disp_units *pptx_ct_a_disp_units_new(xmlNode *node);
void pptx_ct_a_disp_units_free(pptx_ct_a_disp_units *obj);
pptx_ct_a_double *pptx_ct_a_disp_units_get_cust_unit(const pptx_ct_a_disp_units *const obj);
pptx_ct_a_built_in_unit *pptx_ct_a_disp_units_get_built_in_unit(const pptx_ct_a_disp_units *const obj);
pptx_ct_a_disp_units_lbl *pptx_ct_a_disp_units_get_disp_units_lbl(const pptx_ct_a_disp_units *const obj);
pptx_ct_a_extension_list *pptx_ct_a_disp_units_get_ext_lst(const pptx_ct_a_disp_units *const obj);
int32_t pptx_ct_a_disp_units_get_index(pptx_ct_a_disp_units *obj);

#endif /* __PPTX_CT_A_DISP_UNITS_H__ */
