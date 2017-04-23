#ifndef __PPTX_CT_A_GRAPHICAL_OBJECT_H__
#define __PPTX_CT_A_GRAPHICAL_OBJECT_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_graphical_object_data_s pptx_ct_a_graphical_object_data;

typedef struct pptx_ct_a_graphical_object_s pptx_ct_a_graphical_object;
pptx_ct_a_graphical_object *pptx_ct_a_graphical_object_new(xmlNode *node);
void pptx_ct_a_graphical_object_free(pptx_ct_a_graphical_object *obj);
pptx_ct_a_graphical_object_data *pptx_ct_a_graphical_object_get_graphic_data(const pptx_ct_a_graphical_object *const obj);
int32_t pptx_ct_a_graphical_object_get_index(pptx_ct_a_graphical_object *obj);

#endif /* __PPTX_CT_A_GRAPHICAL_OBJECT_H__ */
