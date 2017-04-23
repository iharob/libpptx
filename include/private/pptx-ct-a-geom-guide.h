#ifndef __PPTX_CT_A_GEOM_GUIDE_H__
#define __PPTX_CT_A_GEOM_GUIDE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_geom_guide_s pptx_ct_a_geom_guide;
pptx_ct_a_geom_guide *pptx_ct_a_geom_guide_new(xmlNode *node);
void pptx_ct_a_geom_guide_free(pptx_ct_a_geom_guide *obj);
pptx_string pptx_ct_a_geom_guide_get_name(const pptx_ct_a_geom_guide *const obj);
pptx_string pptx_ct_a_geom_guide_get_fmla(const pptx_ct_a_geom_guide *const obj);
int32_t pptx_ct_a_geom_guide_get_index(pptx_ct_a_geom_guide *obj);

#endif /* __PPTX_CT_A_GEOM_GUIDE_H__ */
