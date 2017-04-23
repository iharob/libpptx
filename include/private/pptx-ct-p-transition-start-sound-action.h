#ifndef __PPTX_CT_P_TRANSITION_START_SOUND_ACTION_H__
#define __PPTX_CT_P_TRANSITION_START_SOUND_ACTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_embedded_wavaudio_file_s pptx_ct_a_embedded_wavaudio_file;

typedef struct pptx_ct_p_transition_start_sound_action_s pptx_ct_p_transition_start_sound_action;
pptx_ct_p_transition_start_sound_action *pptx_ct_p_transition_start_sound_action_new(xmlNode *node);
void pptx_ct_p_transition_start_sound_action_free(pptx_ct_p_transition_start_sound_action *obj);
pptx_ct_a_embedded_wavaudio_file *pptx_ct_p_transition_start_sound_action_get_snd(const pptx_ct_p_transition_start_sound_action *const obj);
pptx_bool pptx_ct_p_transition_start_sound_action_get_loop(const pptx_ct_p_transition_start_sound_action *const obj);
int32_t pptx_ct_p_transition_start_sound_action_get_index(pptx_ct_p_transition_start_sound_action *obj);

#endif /* __PPTX_CT_P_TRANSITION_START_SOUND_ACTION_H__ */
