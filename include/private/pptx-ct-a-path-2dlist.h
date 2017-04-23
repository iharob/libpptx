#ifndef __PPTX_CT_A_PATH_2DLIST_H__
#define __PPTX_CT_A_PATH_2DLIST_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_path_2d_s pptx_ct_a_path_2d;

typedef struct pptx_ct_a_path_2dlist_s pptx_ct_a_path_2dlist;
pptx_ct_a_path_2dlist *pptx_ct_a_path_2dlist_new(xmlNode *node);
void pptx_ct_a_path_2dlist_free(pptx_ct_a_path_2dlist *obj);
pptx_ct_a_path_2d **pptx_ct_a_path_2dlist_get_path(const pptx_ct_a_path_2dlist *const obj);
int32_t pptx_ct_a_path_2dlist_get_index(pptx_ct_a_path_2dlist *obj);

#endif /* __PPTX_CT_A_PATH_2DLIST_H__ */
