#ifndef __PPTX_CT_DGM_STYLE_DEFINITION_HEADER_LST_H__
#define __PPTX_CT_DGM_STYLE_DEFINITION_HEADER_LST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_dgm_style_definition_header_s pptx_ct_dgm_style_definition_header;

typedef struct pptx_ct_dgm_style_definition_header_lst_s pptx_ct_dgm_style_definition_header_lst;
pptx_ct_dgm_style_definition_header_lst *pptx_ct_dgm_style_definition_header_lst_new(xmlNode *node);
void pptx_ct_dgm_style_definition_header_lst_free(pptx_ct_dgm_style_definition_header_lst *obj);
pptx_ct_dgm_style_definition_header **pptx_ct_dgm_style_definition_header_lst_get_style_def_hdr(const pptx_ct_dgm_style_definition_header_lst *const obj);
int32_t pptx_ct_dgm_style_definition_header_lst_get_index(pptx_ct_dgm_style_definition_header_lst *obj);

#endif /* __PPTX_CT_DGM_STYLE_DEFINITION_HEADER_LST_H__ */
