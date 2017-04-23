#ifndef __PPTX_CT_A_LINE_JOIN_ROUND_H__
#define __PPTX_CT_A_LINE_JOIN_ROUND_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_line_join_round_s pptx_ct_a_line_join_round;
pptx_ct_a_line_join_round *pptx_ct_a_line_join_round_new(xmlNode *node);
void pptx_ct_a_line_join_round_free(pptx_ct_a_line_join_round *obj);
int32_t pptx_ct_a_line_join_round_get_index(pptx_ct_a_line_join_round *obj);

#endif /* __PPTX_CT_A_LINE_JOIN_ROUND_H__ */
