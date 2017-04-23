#ifndef __PPTX_CT_P_EMPTY_H__
#define __PPTX_CT_P_EMPTY_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_empty_s pptx_ct_p_empty;
pptx_ct_p_empty *pptx_ct_p_empty_new(xmlNode *node);
void pptx_ct_p_empty_free(pptx_ct_p_empty *obj);
int32_t pptx_ct_p_empty_get_index(pptx_ct_p_empty *obj);

#endif /* __PPTX_CT_P_EMPTY_H__ */
