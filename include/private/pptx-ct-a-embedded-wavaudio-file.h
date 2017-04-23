#ifndef __PPTX_CT_A_EMBEDDED_WAVAUDIO_FILE_H__
#define __PPTX_CT_A_EMBEDDED_WAVAUDIO_FILE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_a_embedded_wavaudio_file_s pptx_ct_a_embedded_wavaudio_file;
pptx_ct_a_embedded_wavaudio_file *pptx_ct_a_embedded_wavaudio_file_new(xmlNode *node);
void pptx_ct_a_embedded_wavaudio_file_free(pptx_ct_a_embedded_wavaudio_file *obj);
pptx_string pptx_ct_a_embedded_wavaudio_file_get_embed(const pptx_ct_a_embedded_wavaudio_file *const obj);
pptx_string pptx_ct_a_embedded_wavaudio_file_get_name(const pptx_ct_a_embedded_wavaudio_file *const obj);
int32_t pptx_ct_a_embedded_wavaudio_file_get_index(pptx_ct_a_embedded_wavaudio_file *obj);

#endif /* __PPTX_CT_A_EMBEDDED_WAVAUDIO_FILE_H__ */
