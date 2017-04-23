#ifndef __PPTX_CT_A_COLOR_SCHEME_AND_MAPPING_H__
#define __PPTX_CT_A_COLOR_SCHEME_AND_MAPPING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_color_scheme_s pptx_ct_a_color_scheme;
typedef struct pptx_ct_a_color_mapping_s pptx_ct_a_color_mapping;

typedef struct pptx_ct_a_color_scheme_and_mapping_s pptx_ct_a_color_scheme_and_mapping;
pptx_ct_a_color_scheme_and_mapping *pptx_ct_a_color_scheme_and_mapping_new(xmlNode *node);
void pptx_ct_a_color_scheme_and_mapping_free(pptx_ct_a_color_scheme_and_mapping *obj);
pptx_ct_a_color_scheme *pptx_ct_a_color_scheme_and_mapping_get_clr_scheme(const pptx_ct_a_color_scheme_and_mapping *const obj);
pptx_ct_a_color_mapping *pptx_ct_a_color_scheme_and_mapping_get_clr_map(const pptx_ct_a_color_scheme_and_mapping *const obj);
int32_t pptx_ct_a_color_scheme_and_mapping_get_index(pptx_ct_a_color_scheme_and_mapping *obj);

#endif /* __PPTX_CT_A_COLOR_SCHEME_AND_MAPPING_H__ */
