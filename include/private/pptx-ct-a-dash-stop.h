#ifndef __PPTX_CT_A_DASH_STOP_H__
#define __PPTX_CT_A_DASH_STOP_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_dash_stop_s pptx_ct_a_dash_stop;
pptx_ct_a_dash_stop *pptx_ct_a_dash_stop_new(xmlNode *node);
void pptx_ct_a_dash_stop_free(pptx_ct_a_dash_stop *obj);
pptx_string pptx_ct_a_dash_stop_get_d(const pptx_ct_a_dash_stop *const obj);
pptx_string pptx_ct_a_dash_stop_get_sp(const pptx_ct_a_dash_stop *const obj);
int32_t pptx_ct_a_dash_stop_get_index(pptx_ct_a_dash_stop *obj);

#endif /* __PPTX_CT_A_DASH_STOP_H__ */
