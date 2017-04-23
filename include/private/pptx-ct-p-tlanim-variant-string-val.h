#ifndef __PPTX_CT_P_TLANIM_VARIANT_STRING_VAL_H__
#define __PPTX_CT_P_TLANIM_VARIANT_STRING_VAL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_tlanim_variant_string_val_s pptx_ct_p_tlanim_variant_string_val;
pptx_ct_p_tlanim_variant_string_val *pptx_ct_p_tlanim_variant_string_val_new(xmlNode *node);
void pptx_ct_p_tlanim_variant_string_val_free(pptx_ct_p_tlanim_variant_string_val *obj);
pptx_string pptx_ct_p_tlanim_variant_string_val_get_val(const pptx_ct_p_tlanim_variant_string_val *const obj);
int32_t pptx_ct_p_tlanim_variant_string_val_get_index(pptx_ct_p_tlanim_variant_string_val *obj);

#endif /* __PPTX_CT_P_TLANIM_VARIANT_STRING_VAL_H__ */
