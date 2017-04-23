#ifndef __PPTX_CT_A_BAND_FMT_H__
#define __PPTX_CT_A_BAND_FMT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;

typedef struct pptx_ct_a_band_fmt_s pptx_ct_a_band_fmt;
pptx_ct_a_band_fmt *pptx_ct_a_band_fmt_new(xmlNode *node);
void pptx_ct_a_band_fmt_free(pptx_ct_a_band_fmt *obj);
pptx_uint pptx_ct_a_band_fmt_get_idx(const pptx_ct_a_band_fmt *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_band_fmt_get_sp_pr(const pptx_ct_a_band_fmt *const obj);
int32_t pptx_ct_a_band_fmt_get_index(pptx_ct_a_band_fmt *obj);

#endif /* __PPTX_CT_A_BAND_FMT_H__ */
