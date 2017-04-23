#ifndef __PPTX_CT_A_TEXT_AUTONUMBER_BULLET_H__
#define __PPTX_CT_A_TEXT_AUTONUMBER_BULLET_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_text_autonumber_scheme_token_enum pptx_st_text_autonumber_scheme_token_enum;

typedef struct pptx_ct_a_text_autonumber_bullet_s pptx_ct_a_text_autonumber_bullet;
pptx_ct_a_text_autonumber_bullet *pptx_ct_a_text_autonumber_bullet_new(xmlNode *node);
void pptx_ct_a_text_autonumber_bullet_free(pptx_ct_a_text_autonumber_bullet *obj);
pptx_st_text_autonumber_scheme_token_enum pptx_ct_a_text_autonumber_bullet_get_type(const pptx_ct_a_text_autonumber_bullet *const obj);
pptx_int pptx_ct_a_text_autonumber_bullet_get_start_at(const pptx_ct_a_text_autonumber_bullet *const obj);
int32_t pptx_ct_a_text_autonumber_bullet_get_index(pptx_ct_a_text_autonumber_bullet *obj);

#endif /* __PPTX_CT_A_TEXT_AUTONUMBER_BULLET_H__ */
