#ifndef __PPTX_CT_A_GVML_CONNECTOR_H__
#define __PPTX_CT_A_GVML_CONNECTOR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_gvml_connector_non_visual_s pptx_ct_a_gvml_connector_non_visual;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_shape_style_s pptx_ct_a_shape_style;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_gvml_connector_s pptx_ct_a_gvml_connector;
pptx_ct_a_gvml_connector *pptx_ct_a_gvml_connector_new(xmlNode *node);
void pptx_ct_a_gvml_connector_free(pptx_ct_a_gvml_connector *obj);
pptx_ct_a_gvml_connector_non_visual *pptx_ct_a_gvml_connector_get_nv_cxn_sp_pr(const pptx_ct_a_gvml_connector *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_gvml_connector_get_sp_pr(const pptx_ct_a_gvml_connector *const obj);
pptx_ct_a_shape_style *pptx_ct_a_gvml_connector_get_style(const pptx_ct_a_gvml_connector *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_gvml_connector_get_ext_lst(const pptx_ct_a_gvml_connector *const obj);
int32_t pptx_ct_a_gvml_connector_get_index(pptx_ct_a_gvml_connector *obj);

#endif /* __PPTX_CT_A_GVML_CONNECTOR_H__ */
