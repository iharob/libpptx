#ifndef __PPTX_CT_A_PIVOT_FMTS_H__
#define __PPTX_CT_A_PIVOT_FMTS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_pivot_fmt_s pptx_ct_a_pivot_fmt;

typedef struct pptx_ct_a_pivot_fmts_s pptx_ct_a_pivot_fmts;
pptx_ct_a_pivot_fmts *pptx_ct_a_pivot_fmts_new(xmlNode *node);
void pptx_ct_a_pivot_fmts_free(pptx_ct_a_pivot_fmts *obj);
pptx_ct_a_pivot_fmt **pptx_ct_a_pivot_fmts_get_pivot_fmt(const pptx_ct_a_pivot_fmts *const obj);
int32_t pptx_ct_a_pivot_fmts_get_index(pptx_ct_a_pivot_fmts *obj);

#endif /* __PPTX_CT_A_PIVOT_FMTS_H__ */
