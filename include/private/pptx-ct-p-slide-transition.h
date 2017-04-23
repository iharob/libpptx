#ifndef __PPTX_CT_P_SLIDE_TRANSITION_H__
#define __PPTX_CT_P_SLIDE_TRANSITION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_p_orientation_transition_s pptx_ct_p_orientation_transition;
typedef struct pptx_ct_p_empty_s pptx_ct_p_empty;
typedef struct pptx_ct_p_eight_direction_transition_s pptx_ct_p_eight_direction_transition;
typedef struct pptx_ct_p_optional_black_transition_s pptx_ct_p_optional_black_transition;
typedef struct pptx_ct_p_side_direction_transition_s pptx_ct_p_side_direction_transition;
typedef struct pptx_ct_p_split_transition_s pptx_ct_p_split_transition;
typedef struct pptx_ct_p_corner_direction_transition_s pptx_ct_p_corner_direction_transition;
typedef struct pptx_ct_p_wheel_transition_s pptx_ct_p_wheel_transition;
typedef struct pptx_ct_p_in_out_transition_s pptx_ct_p_in_out_transition;
typedef struct pptx_ct_p_transition_sound_action_s pptx_ct_p_transition_sound_action;
typedef struct pptx_ct_p_extension_list_modify_s pptx_ct_p_extension_list_modify;
typedef enum pptx_st_transition_speed_token_enum pptx_st_transition_speed_token_enum;

typedef struct pptx_ct_p_slide_transition_s pptx_ct_p_slide_transition;
pptx_ct_p_slide_transition *pptx_ct_p_slide_transition_new(xmlNode *node);
void pptx_ct_p_slide_transition_free(pptx_ct_p_slide_transition *obj);
pptx_ct_p_orientation_transition *pptx_ct_p_slide_transition_get_blinds(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_orientation_transition *pptx_ct_p_slide_transition_get_checker(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_circle(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_dissolve(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_orientation_transition *pptx_ct_p_slide_transition_get_comb(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_eight_direction_transition *pptx_ct_p_slide_transition_get_cover(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_optional_black_transition *pptx_ct_p_slide_transition_get_cut(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_diamond(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_optional_black_transition *pptx_ct_p_slide_transition_get_fade(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_newsflash(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_plus(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_eight_direction_transition *pptx_ct_p_slide_transition_get_pull(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_side_direction_transition *pptx_ct_p_slide_transition_get_push(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_random(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_orientation_transition *pptx_ct_p_slide_transition_get_random_bar(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_split_transition *pptx_ct_p_slide_transition_get_split(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_corner_direction_transition *pptx_ct_p_slide_transition_get_strips(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_empty *pptx_ct_p_slide_transition_get_wedge(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_wheel_transition *pptx_ct_p_slide_transition_get_wheel(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_side_direction_transition *pptx_ct_p_slide_transition_get_wipe(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_in_out_transition *pptx_ct_p_slide_transition_get_zoom(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_transition_sound_action *pptx_ct_p_slide_transition_get_snd_ac(const pptx_ct_p_slide_transition *const obj);
pptx_ct_p_extension_list_modify *pptx_ct_p_slide_transition_get_ext_lst(const pptx_ct_p_slide_transition *const obj);
pptx_st_transition_speed_token_enum pptx_ct_p_slide_transition_get_spd(const pptx_ct_p_slide_transition *const obj);
pptx_bool pptx_ct_p_slide_transition_get_adv_click(const pptx_ct_p_slide_transition *const obj);
pptx_uint pptx_ct_p_slide_transition_get_adv_tm(const pptx_ct_p_slide_transition *const obj);
int32_t pptx_ct_p_slide_transition_get_index(pptx_ct_p_slide_transition *obj);

#endif /* __PPTX_CT_P_SLIDE_TRANSITION_H__ */
