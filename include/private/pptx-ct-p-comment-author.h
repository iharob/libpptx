#ifndef __PPTX_CT_P_COMMENT_AUTHOR_H__
#define __PPTX_CT_P_COMMENT_AUTHOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_extension_list_s pptx_ct_p_extension_list;

typedef struct pptx_ct_p_comment_author_s pptx_ct_p_comment_author;
pptx_ct_p_comment_author *pptx_ct_p_comment_author_new(xmlNode *node);
void pptx_ct_p_comment_author_free(pptx_ct_p_comment_author *obj);
pptx_ct_p_extension_list *pptx_ct_p_comment_author_get_ext_lst(const pptx_ct_p_comment_author *const obj);
pptx_uint pptx_ct_p_comment_author_get_id(const pptx_ct_p_comment_author *const obj);
pptx_string pptx_ct_p_comment_author_get_name(const pptx_ct_p_comment_author *const obj);
pptx_string pptx_ct_p_comment_author_get_initials(const pptx_ct_p_comment_author *const obj);
pptx_uint pptx_ct_p_comment_author_get_last_idx(const pptx_ct_p_comment_author *const obj);
pptx_uint pptx_ct_p_comment_author_get_clr_idx(const pptx_ct_p_comment_author *const obj);
int32_t pptx_ct_p_comment_author_get_index(pptx_ct_p_comment_author *obj);

#endif /* __PPTX_CT_P_COMMENT_AUTHOR_H__ */
