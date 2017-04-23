#ifndef __PPTX_CT_P_TAG_LIST_H__
#define __PPTX_CT_P_TAG_LIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_string_tag_s pptx_ct_p_string_tag;

typedef struct pptx_ct_p_tag_list_s pptx_ct_p_tag_list;
pptx_ct_p_tag_list *pptx_ct_p_tag_list_new(xmlNode *node);
void pptx_ct_p_tag_list_free(pptx_ct_p_tag_list *obj);
pptx_ct_p_string_tag **pptx_ct_p_tag_list_get_tag(const pptx_ct_p_tag_list *const obj);
int32_t pptx_ct_p_tag_list_get_index(pptx_ct_p_tag_list *obj);

#endif /* __PPTX_CT_P_TAG_LIST_H__ */
