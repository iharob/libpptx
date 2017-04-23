#ifndef __PPTX_CT_A_PATH_2D_H__
#define __PPTX_CT_A_PATH_2D_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_path_2dclose_s pptx_ct_a_path_2dclose;
typedef struct pptx_ct_a_path_2dmove_to_s pptx_ct_a_path_2dmove_to;
typedef struct pptx_ct_a_path_2dline_to_s pptx_ct_a_path_2dline_to;
typedef struct pptx_ct_a_path_2darc_to_s pptx_ct_a_path_2darc_to;
typedef struct pptx_ct_a_path_2dquad_bezier_to_s pptx_ct_a_path_2dquad_bezier_to;
typedef struct pptx_ct_a_path_2dcubic_bezier_to_s pptx_ct_a_path_2dcubic_bezier_to;
typedef enum pptx_st_path_fill_mode_token_enum pptx_st_path_fill_mode_token_enum;

typedef struct pptx_ct_a_path_2d_s pptx_ct_a_path_2d;
pptx_ct_a_path_2d *pptx_ct_a_path_2d_new(xmlNode *node);
void pptx_ct_a_path_2d_free(pptx_ct_a_path_2d *obj);
pptx_ct_a_path_2dclose **pptx_ct_a_path_2d_get_close(const pptx_ct_a_path_2d *const obj);
pptx_ct_a_path_2dmove_to **pptx_ct_a_path_2d_get_move_to(const pptx_ct_a_path_2d *const obj);
pptx_ct_a_path_2dline_to **pptx_ct_a_path_2d_get_ln_to(const pptx_ct_a_path_2d *const obj);
pptx_ct_a_path_2darc_to **pptx_ct_a_path_2d_get_arc_to(const pptx_ct_a_path_2d *const obj);
pptx_ct_a_path_2dquad_bezier_to **pptx_ct_a_path_2d_get_quad_bez_to(const pptx_ct_a_path_2d *const obj);
pptx_ct_a_path_2dcubic_bezier_to **pptx_ct_a_path_2d_get_cubic_bez_to(const pptx_ct_a_path_2d *const obj);
pptx_long pptx_ct_a_path_2d_get_w(const pptx_ct_a_path_2d *const obj);
pptx_long pptx_ct_a_path_2d_get_h(const pptx_ct_a_path_2d *const obj);
pptx_st_path_fill_mode_token_enum pptx_ct_a_path_2d_get_fill(const pptx_ct_a_path_2d *const obj);
pptx_bool pptx_ct_a_path_2d_get_stroke(const pptx_ct_a_path_2d *const obj);
pptx_bool pptx_ct_a_path_2d_get_extrusion_ok(const pptx_ct_a_path_2d *const obj);
int32_t pptx_ct_a_path_2d_get_index(pptx_ct_a_path_2d *obj);

#endif /* __PPTX_CT_A_PATH_2D_H__ */
