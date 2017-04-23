#ifndef __PPTX_CT_P_COMMENT_H__
#define __PPTX_CT_P_COMMENT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_point_2d_s pptx_ct_a_point_2d;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;

typedef struct pptx_ct_p_comment_s pptx_ct_p_comment;
pptx_ct_p_comment *pptx_ct_p_comment_new(xmlNode *node);
void pptx_ct_p_comment_free(pptx_ct_p_comment *obj);
pptx_ct_a_point_2d *pptx_ct_p_comment_get_pos(const pptx_ct_p_comment *const obj);
pptx_string pptx_ct_p_comment_get_text(const pptx_ct_p_comment *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_comment_get_ext_lst(const pptx_ct_p_comment *const obj);
pptx_uint pptx_ct_p_comment_get_author_id(const pptx_ct_p_comment *const obj);
pptx_string pptx_ct_p_comment_get_dt(const pptx_ct_p_comment *const obj);
pptx_uint pptx_ct_p_comment_get_idx(const pptx_ct_p_comment *const obj);
int32_t pptx_ct_p_comment_get_index(pptx_ct_p_comment *obj);

#endif /* __PPTX_CT_P_COMMENT_H__ */
