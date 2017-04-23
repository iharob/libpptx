#ifndef __PPTX_CT_A_OF_PIE_TYPE_H__
#define __PPTX_CT_A_OF_PIE_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_of_pie_type_text_enum pptx_st_of_pie_type_text_enum;

typedef struct pptx_ct_a_of_pie_type_s pptx_ct_a_of_pie_type;
pptx_ct_a_of_pie_type *pptx_ct_a_of_pie_type_new(xmlNode *node);
void pptx_ct_a_of_pie_type_free(pptx_ct_a_of_pie_type *obj);
pptx_st_of_pie_type_text_enum pptx_ct_a_of_pie_type_get_val(const pptx_ct_a_of_pie_type *const obj);
int32_t pptx_ct_a_of_pie_type_get_index(pptx_ct_a_of_pie_type *obj);

#endif /* __PPTX_CT_A_OF_PIE_TYPE_H__ */
