#ifndef __PPTX_CT_A_CHART_H__
#define __PPTX_CT_A_CHART_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_title_s pptx_ct_a_title;
typedef struct pptx_ct_a_pivot_fmts_s pptx_ct_a_pivot_fmts;
typedef struct pptx_ct_a_view_3d_s pptx_ct_a_view_3d;
typedef struct pptx_ct_a_surface_s pptx_ct_a_surface;
typedef struct pptx_ct_a_plot_area_s pptx_ct_a_plot_area;
typedef struct pptx_ct_a_legend_s pptx_ct_a_legend;
typedef struct pptx_ct_a_disp_blanks_as_s pptx_ct_a_disp_blanks_as;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_chart_s pptx_ct_a_chart;
pptx_ct_a_chart *pptx_ct_a_chart_new(xmlNode *node);
void pptx_ct_a_chart_free(pptx_ct_a_chart *obj);
pptx_ct_a_title *pptx_ct_a_chart_get_title(const pptx_ct_a_chart *const obj);
pptx_bool pptx_ct_a_chart_get_auto_title_deleted(const pptx_ct_a_chart *const obj);
pptx_ct_a_pivot_fmts *pptx_ct_a_chart_get_pivot_fmts(const pptx_ct_a_chart *const obj);
pptx_ct_a_view_3d *pptx_ct_a_chart_get_view_3d(const pptx_ct_a_chart *const obj);
pptx_ct_a_surface *pptx_ct_a_chart_get_floor(const pptx_ct_a_chart *const obj);
pptx_ct_a_surface *pptx_ct_a_chart_get_side_wall(const pptx_ct_a_chart *const obj);
pptx_ct_a_surface *pptx_ct_a_chart_get_back_wall(const pptx_ct_a_chart *const obj);
pptx_ct_a_plot_area *pptx_ct_a_chart_get_plot_area(const pptx_ct_a_chart *const obj);
pptx_ct_a_legend *pptx_ct_a_chart_get_legend(const pptx_ct_a_chart *const obj);
pptx_bool pptx_ct_a_chart_get_plot_vis_only(const pptx_ct_a_chart *const obj);
pptx_ct_a_disp_blanks_as *pptx_ct_a_chart_get_disp_blanks_as(const pptx_ct_a_chart *const obj);
pptx_bool pptx_ct_a_chart_get_show_dlbls_over_max(const pptx_ct_a_chart *const obj);
pptx_ct_a_extension_list *pptx_ct_a_chart_get_ext_lst(const pptx_ct_a_chart *const obj);
int32_t pptx_ct_a_chart_get_index(pptx_ct_a_chart *obj);

#endif /* __PPTX_CT_A_CHART_H__ */
