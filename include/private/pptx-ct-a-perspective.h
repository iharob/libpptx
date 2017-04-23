#ifndef __PPTX_CT_A_PERSPECTIVE_H__
#define __PPTX_CT_A_PERSPECTIVE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_perspective_s pptx_ct_a_perspective;
pptx_ct_a_perspective *pptx_ct_a_perspective_new(xmlNode *node);
void pptx_ct_a_perspective_free(pptx_ct_a_perspective *obj);
pptx_byte pptx_ct_a_perspective_get_val(const pptx_ct_a_perspective *const obj);
int32_t pptx_ct_a_perspective_get_index(pptx_ct_a_perspective *obj);

#endif /* __PPTX_CT_A_PERSPECTIVE_H__ */
