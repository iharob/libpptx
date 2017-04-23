#ifndef __PPTX_CT_A_LINE_JOIN_MITER_PROPERTIES_H__
#define __PPTX_CT_A_LINE_JOIN_MITER_PROPERTIES_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_line_join_miter_properties_s pptx_ct_a_line_join_miter_properties;
pptx_ct_a_line_join_miter_properties *pptx_ct_a_line_join_miter_properties_new(xmlNode *node);
void pptx_ct_a_line_join_miter_properties_free(pptx_ct_a_line_join_miter_properties *obj);
pptx_string pptx_ct_a_line_join_miter_properties_get_lim(const pptx_ct_a_line_join_miter_properties *const obj);
int32_t pptx_ct_a_line_join_miter_properties_get_index(pptx_ct_a_line_join_miter_properties *obj);

#endif /* __PPTX_CT_A_LINE_JOIN_MITER_PROPERTIES_H__ */
