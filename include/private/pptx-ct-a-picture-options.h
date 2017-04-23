#ifndef __PPTX_CT_A_PICTURE_OPTIONS_H__
#define __PPTX_CT_A_PICTURE_OPTIONS_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_picture_format_s pptx_ct_a_picture_format;
typedef struct pptx_ct_a_picture_stack_unit_s pptx_ct_a_picture_stack_unit;

typedef struct pptx_ct_a_picture_options_s pptx_ct_a_picture_options;
pptx_ct_a_picture_options *pptx_ct_a_picture_options_new(xmlNode *node);
void pptx_ct_a_picture_options_free(pptx_ct_a_picture_options *obj);
pptx_bool pptx_ct_a_picture_options_get_apply_to_front(const pptx_ct_a_picture_options *const obj);
pptx_bool pptx_ct_a_picture_options_get_apply_to_sides(const pptx_ct_a_picture_options *const obj);
pptx_bool pptx_ct_a_picture_options_get_apply_to_end(const pptx_ct_a_picture_options *const obj);
pptx_ct_a_picture_format *pptx_ct_a_picture_options_get_picture_format(const pptx_ct_a_picture_options *const obj);
pptx_ct_a_picture_stack_unit *pptx_ct_a_picture_options_get_picture_stack_unit(const pptx_ct_a_picture_options *const obj);
int32_t pptx_ct_a_picture_options_get_index(pptx_ct_a_picture_options *obj);

#endif /* __PPTX_CT_A_PICTURE_OPTIONS_H__ */
