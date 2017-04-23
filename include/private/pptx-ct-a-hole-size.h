#ifndef __PPTX_CT_A_HOLE_SIZE_H__
#define __PPTX_CT_A_HOLE_SIZE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_hole_size_s pptx_ct_a_hole_size;
pptx_ct_a_hole_size *pptx_ct_a_hole_size_new(xmlNode *node);
void pptx_ct_a_hole_size_free(pptx_ct_a_hole_size *obj);
pptx_string pptx_ct_a_hole_size_get_val(const pptx_ct_a_hole_size *const obj);
int32_t pptx_ct_a_hole_size_get_index(pptx_ct_a_hole_size *obj);

#endif /* __PPTX_CT_A_HOLE_SIZE_H__ */
