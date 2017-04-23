#ifndef __PPTX_CT_A_TEXT_NO_BULLET_H__
#define __PPTX_CT_A_TEXT_NO_BULLET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_no_bullet_s pptx_ct_a_text_no_bullet;
pptx_ct_a_text_no_bullet *pptx_ct_a_text_no_bullet_new(xmlNode *node);
void pptx_ct_a_text_no_bullet_free(pptx_ct_a_text_no_bullet *obj);
int32_t pptx_ct_a_text_no_bullet_get_index(pptx_ct_a_text_no_bullet *obj);

#endif /* __PPTX_CT_A_TEXT_NO_BULLET_H__ */
