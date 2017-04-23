#ifndef __PPTX_CT_P_INDEX_RANGE_H__
#define __PPTX_CT_P_INDEX_RANGE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_index_range_s pptx_ct_p_index_range;
pptx_ct_p_index_range *pptx_ct_p_index_range_new(xmlNode *node);
void pptx_ct_p_index_range_free(pptx_ct_p_index_range *obj);
pptx_uint pptx_ct_p_index_range_get_st(const pptx_ct_p_index_range *const obj);
pptx_uint pptx_ct_p_index_range_get_end(const pptx_ct_p_index_range *const obj);
int32_t pptx_ct_p_index_range_get_index(pptx_ct_p_index_range *obj);

#endif /* __PPTX_CT_P_INDEX_RANGE_H__ */
