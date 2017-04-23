#ifndef __PPTX_CT_P_STRING_TAG_H__
#define __PPTX_CT_P_STRING_TAG_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_string_tag_s pptx_ct_p_string_tag;
pptx_ct_p_string_tag *pptx_ct_p_string_tag_new(xmlNode *node);
void pptx_ct_p_string_tag_free(pptx_ct_p_string_tag *obj);
pptx_string pptx_ct_p_string_tag_get_name(const pptx_ct_p_string_tag *const obj);
pptx_string pptx_ct_p_string_tag_get_val(const pptx_ct_p_string_tag *const obj);
int32_t pptx_ct_p_string_tag_get_index(pptx_ct_p_string_tag *obj);

#endif /* __PPTX_CT_P_STRING_TAG_H__ */
