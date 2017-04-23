#ifndef __PPTX_CT_A_PATH_2DCLOSE_H__
#define __PPTX_CT_A_PATH_2DCLOSE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_path_2dclose_s pptx_ct_a_path_2dclose;
pptx_ct_a_path_2dclose *pptx_ct_a_path_2dclose_new(xmlNode *node);
void pptx_ct_a_path_2dclose_free(pptx_ct_a_path_2dclose *obj);
int32_t pptx_ct_a_path_2dclose_get_index(pptx_ct_a_path_2dclose *obj);

#endif /* __PPTX_CT_A_PATH_2DCLOSE_H__ */
