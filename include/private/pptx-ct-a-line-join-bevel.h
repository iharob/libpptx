#ifndef __PPTX_CT_A_LINE_JOIN_BEVEL_H__
#define __PPTX_CT_A_LINE_JOIN_BEVEL_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_line_join_bevel_s pptx_ct_a_line_join_bevel;
pptx_ct_a_line_join_bevel *pptx_ct_a_line_join_bevel_new(xmlNode *node);
void pptx_ct_a_line_join_bevel_free(pptx_ct_a_line_join_bevel *obj);
int32_t pptx_ct_a_line_join_bevel_get_index(pptx_ct_a_line_join_bevel *obj);

#endif /* __PPTX_CT_A_LINE_JOIN_BEVEL_H__ */
