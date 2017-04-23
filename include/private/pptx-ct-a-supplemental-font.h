#ifndef __PPTX_CT_A_SUPPLEMENTAL_FONT_H__
#define __PPTX_CT_A_SUPPLEMENTAL_FONT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_supplemental_font_s pptx_ct_a_supplemental_font;
pptx_ct_a_supplemental_font *pptx_ct_a_supplemental_font_new(xmlNode *node);
void pptx_ct_a_supplemental_font_free(pptx_ct_a_supplemental_font *obj);
pptx_string pptx_ct_a_supplemental_font_get_script(const pptx_ct_a_supplemental_font *const obj);
pptx_string pptx_ct_a_supplemental_font_get_typeface(const pptx_ct_a_supplemental_font *const obj);
int32_t pptx_ct_a_supplemental_font_get_index(pptx_ct_a_supplemental_font *obj);

#endif /* __PPTX_CT_A_SUPPLEMENTAL_FONT_H__ */
