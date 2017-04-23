#ifndef __PPTX_CT_P_TLANIM_VARIANT_H__
#define __PPTX_CT_P_TLANIM_VARIANT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_tlanim_variant_boolean_val_s pptx_ct_p_tlanim_variant_boolean_val;
typedef struct pptx_ct_p_tlanim_variant_integer_val_s pptx_ct_p_tlanim_variant_integer_val;
typedef struct pptx_ct_p_tlanim_variant_float_val_s pptx_ct_p_tlanim_variant_float_val;
typedef struct pptx_ct_p_tlanim_variant_string_val_s pptx_ct_p_tlanim_variant_string_val;
typedef struct pptx_ct_a_color_s pptx_ct_a_color;

typedef struct pptx_ct_p_tlanim_variant_s pptx_ct_p_tlanim_variant;
pptx_ct_p_tlanim_variant *pptx_ct_p_tlanim_variant_new(xmlNode *node);
void pptx_ct_p_tlanim_variant_free(pptx_ct_p_tlanim_variant *obj);
pptx_ct_p_tlanim_variant_boolean_val *pptx_ct_p_tlanim_variant_get_bool_val(const pptx_ct_p_tlanim_variant *const obj);
pptx_ct_p_tlanim_variant_integer_val *pptx_ct_p_tlanim_variant_get_int_val(const pptx_ct_p_tlanim_variant *const obj);
pptx_ct_p_tlanim_variant_float_val *pptx_ct_p_tlanim_variant_get_flt_val(const pptx_ct_p_tlanim_variant *const obj);
pptx_ct_p_tlanim_variant_string_val *pptx_ct_p_tlanim_variant_get_str_val(const pptx_ct_p_tlanim_variant *const obj);
pptx_ct_a_color *pptx_ct_p_tlanim_variant_get_clr_val(const pptx_ct_p_tlanim_variant *const obj);
int32_t pptx_ct_p_tlanim_variant_get_index(pptx_ct_p_tlanim_variant *obj);

#endif /* __PPTX_CT_P_TLANIM_VARIANT_H__ */
