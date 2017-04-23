#ifndef __PPTX_CT_A_BEVEL_H__
#define __PPTX_CT_A_BEVEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_bevel_preset_type_token_enum pptx_st_bevel_preset_type_token_enum;

typedef struct pptx_ct_a_bevel_s pptx_ct_a_bevel;
pptx_ct_a_bevel *pptx_ct_a_bevel_new(xmlNode *node);
void pptx_ct_a_bevel_free(pptx_ct_a_bevel *obj);
pptx_long pptx_ct_a_bevel_get_w(const pptx_ct_a_bevel *const obj);
pptx_long pptx_ct_a_bevel_get_h(const pptx_ct_a_bevel *const obj);
pptx_st_bevel_preset_type_token_enum pptx_ct_a_bevel_get_prst(const pptx_ct_a_bevel *const obj);
int32_t pptx_ct_a_bevel_get_index(pptx_ct_a_bevel *obj);

#endif /* __PPTX_CT_A_BEVEL_H__ */
