#ifndef __PPTX_CT_A_GEOM_RECT_H__
#define __PPTX_CT_A_GEOM_RECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_geom_rect_s pptx_ct_a_geom_rect;
pptx_ct_a_geom_rect *pptx_ct_a_geom_rect_new(xmlNode *node);
void pptx_ct_a_geom_rect_free(pptx_ct_a_geom_rect *obj);
pptx_string pptx_ct_a_geom_rect_get_l(const pptx_ct_a_geom_rect *const obj);
pptx_string pptx_ct_a_geom_rect_get_t(const pptx_ct_a_geom_rect *const obj);
pptx_string pptx_ct_a_geom_rect_get_r(const pptx_ct_a_geom_rect *const obj);
pptx_string pptx_ct_a_geom_rect_get_b(const pptx_ct_a_geom_rect *const obj);
int32_t pptx_ct_a_geom_rect_get_index(pptx_ct_a_geom_rect *obj);

#endif /* __PPTX_CT_A_GEOM_RECT_H__ */
