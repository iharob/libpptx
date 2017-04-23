#ifndef __PPTX_CT_A_DISP_BLANKS_AS_H__
#define __PPTX_CT_A_DISP_BLANKS_AS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_disp_blanks_as_text_enum pptx_st_disp_blanks_as_text_enum;

typedef struct pptx_ct_a_disp_blanks_as_s pptx_ct_a_disp_blanks_as;
pptx_ct_a_disp_blanks_as *pptx_ct_a_disp_blanks_as_new(xmlNode *node);
void pptx_ct_a_disp_blanks_as_free(pptx_ct_a_disp_blanks_as *obj);
pptx_st_disp_blanks_as_text_enum pptx_ct_a_disp_blanks_as_get_val(const pptx_ct_a_disp_blanks_as *const obj);
int32_t pptx_ct_a_disp_blanks_as_get_index(pptx_ct_a_disp_blanks_as *obj);

#endif /* __PPTX_CT_A_DISP_BLANKS_AS_H__ */
