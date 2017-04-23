#ifndef __PPTX_CT_P_TLANIM_VARIANT_FLOAT_VAL_H__
#define __PPTX_CT_P_TLANIM_VARIANT_FLOAT_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlanim_variant_float_val_s pptx_ct_p_tlanim_variant_float_val;
pptx_ct_p_tlanim_variant_float_val *pptx_ct_p_tlanim_variant_float_val_new(xmlNode *node);
void pptx_ct_p_tlanim_variant_float_val_free(pptx_ct_p_tlanim_variant_float_val *obj);
pptx_float pptx_ct_p_tlanim_variant_float_val_get_val(const pptx_ct_p_tlanim_variant_float_val *const obj);
int32_t pptx_ct_p_tlanim_variant_float_val_get_index(pptx_ct_p_tlanim_variant_float_val *obj);

#endif /* __PPTX_CT_P_TLANIM_VARIANT_FLOAT_VAL_H__ */
