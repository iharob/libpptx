#ifndef __PPTX_CT_A_CONNECTOR_LOCKING_H__
#define __PPTX_CT_A_CONNECTOR_LOCKING_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_connector_locking_s pptx_ct_a_connector_locking;
pptx_ct_a_connector_locking *pptx_ct_a_connector_locking_new(xmlNode *node);
void pptx_ct_a_connector_locking_free(pptx_ct_a_connector_locking *obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_connector_locking_get_ext_lst(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_grp(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_select(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_rot(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_change_aspect(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_move(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_resize(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_edit_points(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_adjust_handles(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_change_arrowheads(const pptx_ct_a_connector_locking *const obj);
pptx_bool pptx_ct_a_connector_locking_get_no_change_shape_type(const pptx_ct_a_connector_locking *const obj);
int32_t pptx_ct_a_connector_locking_get_index(pptx_ct_a_connector_locking *obj);

#endif /* __PPTX_CT_A_CONNECTOR_LOCKING_H__ */
