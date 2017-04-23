#ifndef __PPTX_CT_A_BAND_FMTS_H__
#define __PPTX_CT_A_BAND_FMTS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_band_fmt_s pptx_ct_a_band_fmt;

typedef struct pptx_ct_a_band_fmts_s pptx_ct_a_band_fmts;
pptx_ct_a_band_fmts *pptx_ct_a_band_fmts_new(xmlNode *node);
void pptx_ct_a_band_fmts_free(pptx_ct_a_band_fmts *obj);
pptx_ct_a_band_fmt **pptx_ct_a_band_fmts_get_band_fmt(const pptx_ct_a_band_fmts *const obj);
int32_t pptx_ct_a_band_fmts_get_index(pptx_ct_a_band_fmts *obj);

#endif /* __PPTX_CT_A_BAND_FMTS_H__ */
