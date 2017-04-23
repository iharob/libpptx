#ifndef __PPTX_CT_A_TEXT_BULLET_SIZE_POINT_H__
#define __PPTX_CT_A_TEXT_BULLET_SIZE_POINT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_text_bullet_size_point_s pptx_ct_a_text_bullet_size_point;
pptx_ct_a_text_bullet_size_point *pptx_ct_a_text_bullet_size_point_new(xmlNode *node);
void pptx_ct_a_text_bullet_size_point_free(pptx_ct_a_text_bullet_size_point *obj);
pptx_int pptx_ct_a_text_bullet_size_point_get_val(const pptx_ct_a_text_bullet_size_point *const obj);
int32_t pptx_ct_a_text_bullet_size_point_get_index(pptx_ct_a_text_bullet_size_point *obj);

#endif /* __PPTX_CT_A_TEXT_BULLET_SIZE_POINT_H__ */
