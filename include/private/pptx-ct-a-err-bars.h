#ifndef __PPTX_CT_A_ERR_BARS_H__
#define __PPTX_CT_A_ERR_BARS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_err_dir_s pptx_ct_a_err_dir;
typedef struct pptx_ct_a_err_bar_type_s pptx_ct_a_err_bar_type;
typedef struct pptx_ct_a_err_val_type_s pptx_ct_a_err_val_type;
typedef struct pptx_ct_a_num_data_source_s pptx_ct_a_num_data_source;
typedef struct pptx_ct_a_double_s pptx_ct_a_double;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_err_bars_s pptx_ct_a_err_bars;
pptx_ct_a_err_bars *pptx_ct_a_err_bars_new(xmlNode *node);
void pptx_ct_a_err_bars_free(pptx_ct_a_err_bars *obj);
pptx_ct_a_err_dir *pptx_ct_a_err_bars_get_err_dir(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_err_bar_type *pptx_ct_a_err_bars_get_err_bar_type(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_err_val_type *pptx_ct_a_err_bars_get_err_val_type(const pptx_ct_a_err_bars *const obj);
pptx_bool pptx_ct_a_err_bars_get_no_end_cap(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_num_data_source *pptx_ct_a_err_bars_get_plus(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_num_data_source *pptx_ct_a_err_bars_get_minus(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_double *pptx_ct_a_err_bars_get_val(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_err_bars_get_sp_pr(const pptx_ct_a_err_bars *const obj);
pptx_ct_a_extension_list *pptx_ct_a_err_bars_get_ext_lst(const pptx_ct_a_err_bars *const obj);
int32_t pptx_ct_a_err_bars_get_index(pptx_ct_a_err_bars *obj);

#endif /* __PPTX_CT_A_ERR_BARS_H__ */
