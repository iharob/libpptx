#ifndef __PPTX_CT_A_ADJ_POINT_2D_H__
#define __PPTX_CT_A_ADJ_POINT_2D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_adj_point_2d_s pptx_ct_a_adj_point_2d;
pptx_ct_a_adj_point_2d *pptx_ct_a_adj_point_2d_new(xmlNode *node);
void pptx_ct_a_adj_point_2d_free(pptx_ct_a_adj_point_2d *obj);
pptx_string pptx_ct_a_adj_point_2d_get_x(const pptx_ct_a_adj_point_2d *const obj);
pptx_string pptx_ct_a_adj_point_2d_get_y(const pptx_ct_a_adj_point_2d *const obj);
int32_t pptx_ct_a_adj_point_2d_get_index(pptx_ct_a_adj_point_2d *obj);

#endif /* __PPTX_CT_A_ADJ_POINT_2D_H__ */
