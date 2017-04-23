#ifndef __PPTX_CT_P_GUIDE_H__
#define __PPTX_CT_P_GUIDE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_direction_token_enum pptx_st_direction_token_enum;

typedef struct pptx_ct_p_guide_s pptx_ct_p_guide;
pptx_ct_p_guide *pptx_ct_p_guide_new(xmlNode *node);
void pptx_ct_p_guide_free(pptx_ct_p_guide *obj);
pptx_st_direction_token_enum pptx_ct_p_guide_get_orient(const pptx_ct_p_guide *const obj);
pptx_string pptx_ct_p_guide_get_pos(const pptx_ct_p_guide *const obj);
int32_t pptx_ct_p_guide_get_index(pptx_ct_p_guide *obj);

#endif /* __PPTX_CT_P_GUIDE_H__ */
