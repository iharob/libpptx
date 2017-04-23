#ifndef __PPTX_CT_A_TIME_UNIT_H__
#define __PPTX_CT_A_TIME_UNIT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_time_unit_text_enum pptx_st_time_unit_text_enum;

typedef struct pptx_ct_a_time_unit_s pptx_ct_a_time_unit;
pptx_ct_a_time_unit *pptx_ct_a_time_unit_new(xmlNode *node);
void pptx_ct_a_time_unit_free(pptx_ct_a_time_unit *obj);
pptx_st_time_unit_text_enum pptx_ct_a_time_unit_get_val(const pptx_ct_a_time_unit *const obj);
int32_t pptx_ct_a_time_unit_get_index(pptx_ct_a_time_unit *obj);

#endif /* __PPTX_CT_A_TIME_UNIT_H__ */
