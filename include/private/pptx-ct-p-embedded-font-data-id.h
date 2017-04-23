#ifndef __PPTX_CT_P_EMBEDDED_FONT_DATA_ID_H__
#define __PPTX_CT_P_EMBEDDED_FONT_DATA_ID_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>


typedef struct pptx_ct_p_embedded_font_data_id_s pptx_ct_p_embedded_font_data_id;
pptx_ct_p_embedded_font_data_id *pptx_ct_p_embedded_font_data_id_new(xmlNode *node);
void pptx_ct_p_embedded_font_data_id_free(pptx_ct_p_embedded_font_data_id *obj);
pptx_string pptx_ct_p_embedded_font_data_id_get_r_id(const pptx_ct_p_embedded_font_data_id *const obj);
int32_t pptx_ct_p_embedded_font_data_id_get_index(pptx_ct_p_embedded_font_data_id *obj);

#endif /* __PPTX_CT_P_EMBEDDED_FONT_DATA_ID_H__ */
