#ifndef __PPTX_CT_A_ORIENTATION_H__
#define __PPTX_CT_A_ORIENTATION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_orientation_text_enum pptx_st_orientation_text_enum;

typedef struct pptx_ct_a_orientation_s pptx_ct_a_orientation;
pptx_ct_a_orientation *pptx_ct_a_orientation_new(xmlNode *node);
void pptx_ct_a_orientation_free(pptx_ct_a_orientation *obj);
pptx_st_orientation_text_enum pptx_ct_a_orientation_get_val(const pptx_ct_a_orientation *const obj);
int32_t pptx_ct_a_orientation_get_index(pptx_ct_a_orientation *obj);

#endif /* __PPTX_CT_A_ORIENTATION_H__ */
