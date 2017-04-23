#ifndef __PPTX_CT_A_NUM_FMT_H__
#define __PPTX_CT_A_NUM_FMT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_num_fmt_s pptx_ct_a_num_fmt;
pptx_ct_a_num_fmt *pptx_ct_a_num_fmt_new(xmlNode *node);
void pptx_ct_a_num_fmt_free(pptx_ct_a_num_fmt *obj);
pptx_string pptx_ct_a_num_fmt_get_format_code(const pptx_ct_a_num_fmt *const obj);
pptx_bool pptx_ct_a_num_fmt_get_source_linked(const pptx_ct_a_num_fmt *const obj);
int32_t pptx_ct_a_num_fmt_get_index(pptx_ct_a_num_fmt *obj);

#endif /* __PPTX_CT_A_NUM_FMT_H__ */
