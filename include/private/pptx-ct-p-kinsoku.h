#ifndef __PPTX_CT_P_KINSOKU_H__
#define __PPTX_CT_P_KINSOKU_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_kinsoku_s pptx_ct_p_kinsoku;
pptx_ct_p_kinsoku *pptx_ct_p_kinsoku_new(xmlNode *node);
void pptx_ct_p_kinsoku_free(pptx_ct_p_kinsoku *obj);
pptx_string pptx_ct_p_kinsoku_get_lang(const pptx_ct_p_kinsoku *const obj);
pptx_string pptx_ct_p_kinsoku_get_inval_st_chars(const pptx_ct_p_kinsoku *const obj);
pptx_string pptx_ct_p_kinsoku_get_inval_end_chars(const pptx_ct_p_kinsoku *const obj);
int32_t pptx_ct_p_kinsoku_get_index(pptx_ct_p_kinsoku *obj);

#endif /* __PPTX_CT_P_KINSOKU_H__ */
