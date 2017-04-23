#ifndef __PPTX_CT_CDR_MARKER_H__
#define __PPTX_CT_CDR_MARKER_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_cdr_marker_s pptx_ct_cdr_marker;
pptx_ct_cdr_marker *pptx_ct_cdr_marker_new(xmlNode *node);
void pptx_ct_cdr_marker_free(pptx_ct_cdr_marker *obj);
pptx_double pptx_ct_cdr_marker_get_x(const pptx_ct_cdr_marker *const obj);
pptx_double pptx_ct_cdr_marker_get_y(const pptx_ct_cdr_marker *const obj);
int32_t pptx_ct_cdr_marker_get_index(pptx_ct_cdr_marker *obj);

#endif /* __PPTX_CT_CDR_MARKER_H__ */
