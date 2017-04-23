#ifndef __PPTX_CT_A_LVL_H__
#define __PPTX_CT_A_LVL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_str_val_s pptx_ct_a_str_val;

typedef struct pptx_ct_a_lvl_s pptx_ct_a_lvl;
pptx_ct_a_lvl *pptx_ct_a_lvl_new(xmlNode *node);
void pptx_ct_a_lvl_free(pptx_ct_a_lvl *obj);
pptx_ct_a_str_val **pptx_ct_a_lvl_get_pt(const pptx_ct_a_lvl *const obj);
int32_t pptx_ct_a_lvl_get_index(pptx_ct_a_lvl *obj);

#endif /* __PPTX_CT_A_LVL_H__ */
