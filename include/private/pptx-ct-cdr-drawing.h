#ifndef __PPTX_CT_CDR_DRAWING_H__
#define __PPTX_CT_CDR_DRAWING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_cdr_rel_size_anchor_s pptx_ct_cdr_rel_size_anchor;
typedef struct pptx_ct_cdr_abs_size_anchor_s pptx_ct_cdr_abs_size_anchor;

typedef struct pptx_ct_cdr_drawing_s pptx_ct_cdr_drawing;
pptx_ct_cdr_drawing *pptx_ct_cdr_drawing_new(xmlNode *node);
void pptx_ct_cdr_drawing_free(pptx_ct_cdr_drawing *obj);
pptx_ct_cdr_rel_size_anchor **pptx_ct_cdr_drawing_get_anchor_rel_size_anchor(const pptx_ct_cdr_drawing *const obj);
pptx_ct_cdr_abs_size_anchor **pptx_ct_cdr_drawing_get_anchor_abs_size_anchor(const pptx_ct_cdr_drawing *const obj);
int32_t pptx_ct_cdr_drawing_get_index(pptx_ct_cdr_drawing *obj);

#endif /* __PPTX_CT_CDR_DRAWING_H__ */
