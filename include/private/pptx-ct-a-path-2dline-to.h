#ifndef __PPTX_CT_A_PATH_2DLINE_TO_H__
#define __PPTX_CT_A_PATH_2DLINE_TO_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_adj_point_2d_s pptx_ct_a_adj_point_2d;

typedef struct pptx_ct_a_path_2dline_to_s pptx_ct_a_path_2dline_to;
pptx_ct_a_path_2dline_to *pptx_ct_a_path_2dline_to_new(xmlNode *node);
void pptx_ct_a_path_2dline_to_free(pptx_ct_a_path_2dline_to *obj);
pptx_ct_a_adj_point_2d *pptx_ct_a_path_2dline_to_get_pt(const pptx_ct_a_path_2dline_to *const obj);
int32_t pptx_ct_a_path_2dline_to_get_index(pptx_ct_a_path_2dline_to *obj);

#endif /* __PPTX_CT_A_PATH_2DLINE_TO_H__ */
