#ifndef __PPTX_CT_DGM_SHAPE_H__
#define __PPTX_CT_DGM_SHAPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_adj_lst_s pptx_ct_dgm_adj_lst;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;
typedef enum pptx_st_shape_type_token_enum pptx_st_shape_type_token_enum;

typedef struct pptx_ct_dgm_shape_s pptx_ct_dgm_shape;
pptx_ct_dgm_shape *pptx_ct_dgm_shape_new(xmlNode *node);
void pptx_ct_dgm_shape_free(pptx_ct_dgm_shape *obj);
pptx_ct_dgm_adj_lst *pptx_ct_dgm_shape_get_adj_lst(const pptx_ct_dgm_shape *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_dgm_shape_get_ext_lst(const pptx_ct_dgm_shape *const obj);
pptx_double pptx_ct_dgm_shape_get_rot(const pptx_ct_dgm_shape *const obj);
pptx_st_shape_type_token_enum pptx_ct_dgm_shape_get_type(const pptx_ct_dgm_shape *const obj);
pptx_string pptx_ct_dgm_shape_get_blip(const pptx_ct_dgm_shape *const obj);
pptx_int pptx_ct_dgm_shape_get_z_order_off(const pptx_ct_dgm_shape *const obj);
pptx_bool pptx_ct_dgm_shape_get_hide_geom(const pptx_ct_dgm_shape *const obj);
pptx_bool pptx_ct_dgm_shape_get_lk_tx_entry(const pptx_ct_dgm_shape *const obj);
pptx_bool pptx_ct_dgm_shape_get_blip_phldr(const pptx_ct_dgm_shape *const obj);
int32_t pptx_ct_dgm_shape_get_index(pptx_ct_dgm_shape *obj);

#endif /* __PPTX_CT_DGM_SHAPE_H__ */
