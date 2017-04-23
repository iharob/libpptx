#ifndef __PPTX_CT_P_SMART_TAGS_H__
#define __PPTX_CT_P_SMART_TAGS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_smart_tags_s pptx_ct_p_smart_tags;
pptx_ct_p_smart_tags *pptx_ct_p_smart_tags_new(xmlNode *node);
void pptx_ct_p_smart_tags_free(pptx_ct_p_smart_tags *obj);
pptx_string pptx_ct_p_smart_tags_get_r_id(const pptx_ct_p_smart_tags *const obj);
int32_t pptx_ct_p_smart_tags_get_index(pptx_ct_p_smart_tags *obj);

#endif /* __PPTX_CT_P_SMART_TAGS_H__ */
