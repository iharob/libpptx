#ifndef __PPTX_CT_A_HSL_COLOR_H__
#define __PPTX_CT_A_HSL_COLOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_positive_fixed_percentage_s pptx_ct_a_positive_fixed_percentage;
typedef struct pptx_ct_a_complement_transform_s pptx_ct_a_complement_transform;
typedef struct pptx_ct_a_inverse_transform_s pptx_ct_a_inverse_transform;
typedef struct pptx_ct_a_grayscale_transform_s pptx_ct_a_grayscale_transform;
typedef struct pptx_ct_a_fixed_percentage_s pptx_ct_a_fixed_percentage;
typedef struct pptx_ct_a_positive_percentage_s pptx_ct_a_positive_percentage;
typedef struct pptx_ct_a_positive_fixed_angle_s pptx_ct_a_positive_fixed_angle;
typedef struct pptx_ct_a_angle_s pptx_ct_a_angle;
typedef struct pptx_ct_a_percentage_s pptx_ct_a_percentage;
typedef struct pptx_ct_a_gamma_transform_s pptx_ct_a_gamma_transform;
typedef struct pptx_ct_a_inverse_gamma_transform_s pptx_ct_a_inverse_gamma_transform;

typedef struct pptx_ct_a_hsl_color_s pptx_ct_a_hsl_color;
pptx_ct_a_hsl_color *pptx_ct_a_hsl_color_new(xmlNode *node);
void pptx_ct_a_hsl_color_free(pptx_ct_a_hsl_color *obj);
pptx_ct_a_positive_fixed_percentage **pptx_ct_a_hsl_color_get_color_transform_tint(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_positive_fixed_percentage **pptx_ct_a_hsl_color_get_color_transform_shade(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_complement_transform **pptx_ct_a_hsl_color_get_color_transform_comp(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_inverse_transform **pptx_ct_a_hsl_color_get_color_transform_inv(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_grayscale_transform **pptx_ct_a_hsl_color_get_color_transform_gray(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_positive_fixed_percentage **pptx_ct_a_hsl_color_get_color_transform_alpha(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_fixed_percentage **pptx_ct_a_hsl_color_get_color_transform_alpha_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_positive_percentage **pptx_ct_a_hsl_color_get_color_transform_alpha_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_positive_fixed_angle **pptx_ct_a_hsl_color_get_color_transform_hue(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_angle **pptx_ct_a_hsl_color_get_color_transform_hue_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_positive_percentage **pptx_ct_a_hsl_color_get_color_transform_hue_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_sat(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_sat_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_sat_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_lum(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_lum_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_lum_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_red(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_red_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_red_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_green(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_green_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_green_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_blue(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_blue_off(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_percentage **pptx_ct_a_hsl_color_get_color_transform_blue_mod(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_gamma_transform **pptx_ct_a_hsl_color_get_color_transform_gamma(const pptx_ct_a_hsl_color *const obj);
pptx_ct_a_inverse_gamma_transform **pptx_ct_a_hsl_color_get_color_transform_inv_gamma(const pptx_ct_a_hsl_color *const obj);
pptx_int pptx_ct_a_hsl_color_get_hue(const pptx_ct_a_hsl_color *const obj);
pptx_string pptx_ct_a_hsl_color_get_sat(const pptx_ct_a_hsl_color *const obj);
pptx_string pptx_ct_a_hsl_color_get_lum(const pptx_ct_a_hsl_color *const obj);
int32_t pptx_ct_a_hsl_color_get_index(pptx_ct_a_hsl_color *obj);

#endif /* __PPTX_CT_A_HSL_COLOR_H__ */
