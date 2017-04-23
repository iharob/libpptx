#ifndef __PPTX_CT_DGM_TEXT_PROPS_H__
#define __PPTX_CT_DGM_TEXT_PROPS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_shape_3d_s pptx_ct_a_shape_3d;
typedef struct pptx_ct_a_flat_text_s pptx_ct_a_flat_text;

typedef struct pptx_ct_dgm_text_props_s pptx_ct_dgm_text_props;
pptx_ct_dgm_text_props *pptx_ct_dgm_text_props_new(xmlNode *node);
void pptx_ct_dgm_text_props_free(pptx_ct_dgm_text_props *obj);
pptx_ct_a_shape_3d *pptx_ct_dgm_text_props_get_text_3d_sp3d(const pptx_ct_dgm_text_props *const obj);
pptx_ct_a_flat_text *pptx_ct_dgm_text_props_get_text_3d_flat_tx(const pptx_ct_dgm_text_props *const obj);
int32_t pptx_ct_dgm_text_props_get_index(pptx_ct_dgm_text_props *obj);

#endif /* __PPTX_CT_DGM_TEXT_PROPS_H__ */
