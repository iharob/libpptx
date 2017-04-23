#ifndef __PPTX_CT_A_PATH_2DARC_TO_H__
#define __PPTX_CT_A_PATH_2DARC_TO_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_path_2darc_to_s pptx_ct_a_path_2darc_to;
pptx_ct_a_path_2darc_to *pptx_ct_a_path_2darc_to_new(xmlNode *node);
void pptx_ct_a_path_2darc_to_free(pptx_ct_a_path_2darc_to *obj);
pptx_string pptx_ct_a_path_2darc_to_get_w_r(const pptx_ct_a_path_2darc_to *const obj);
pptx_string pptx_ct_a_path_2darc_to_get_h_r(const pptx_ct_a_path_2darc_to *const obj);
pptx_string pptx_ct_a_path_2darc_to_get_st_ang(const pptx_ct_a_path_2darc_to *const obj);
pptx_string pptx_ct_a_path_2darc_to_get_sw_ang(const pptx_ct_a_path_2darc_to *const obj);
int32_t pptx_ct_a_path_2darc_to_get_index(pptx_ct_a_path_2darc_to *obj);

#endif /* __PPTX_CT_A_PATH_2DARC_TO_H__ */
