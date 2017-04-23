#ifndef __PPTX_CT_A_LINE_END_PROPERTIES_H__
#define __PPTX_CT_A_LINE_END_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_line_end_type_token_enum pptx_st_line_end_type_token_enum;
typedef enum pptx_st_line_end_width_token_enum pptx_st_line_end_width_token_enum;
typedef enum pptx_st_line_end_length_token_enum pptx_st_line_end_length_token_enum;

typedef struct pptx_ct_a_line_end_properties_s pptx_ct_a_line_end_properties;
pptx_ct_a_line_end_properties *pptx_ct_a_line_end_properties_new(xmlNode *node);
void pptx_ct_a_line_end_properties_free(pptx_ct_a_line_end_properties *obj);
pptx_st_line_end_type_token_enum pptx_ct_a_line_end_properties_get_type(const pptx_ct_a_line_end_properties *const obj);
pptx_st_line_end_width_token_enum pptx_ct_a_line_end_properties_get_w(const pptx_ct_a_line_end_properties *const obj);
pptx_st_line_end_length_token_enum pptx_ct_a_line_end_properties_get_len(const pptx_ct_a_line_end_properties *const obj);
int32_t pptx_ct_a_line_end_properties_get_index(pptx_ct_a_line_end_properties *obj);

#endif /* __PPTX_CT_A_LINE_END_PROPERTIES_H__ */
