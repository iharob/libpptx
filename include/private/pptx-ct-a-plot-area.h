#ifndef __PPTX_CT_A_PLOT_AREA_H__
#define __PPTX_CT_A_PLOT_AREA_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_layout_s pptx_ct_a_layout;
typedef struct pptx_ct_a_area_chart_s pptx_ct_a_area_chart;
typedef struct pptx_ct_a_area_3dchart_s pptx_ct_a_area_3dchart;
typedef struct pptx_ct_a_line_chart_s pptx_ct_a_line_chart;
typedef struct pptx_ct_a_line_3dchart_s pptx_ct_a_line_3dchart;
typedef struct pptx_ct_a_stock_chart_s pptx_ct_a_stock_chart;
typedef struct pptx_ct_a_radar_chart_s pptx_ct_a_radar_chart;
typedef struct pptx_ct_a_scatter_chart_s pptx_ct_a_scatter_chart;
typedef struct pptx_ct_a_pie_chart_s pptx_ct_a_pie_chart;
typedef struct pptx_ct_a_pie_3dchart_s pptx_ct_a_pie_3dchart;
typedef struct pptx_ct_a_doughnut_chart_s pptx_ct_a_doughnut_chart;
typedef struct pptx_ct_a_bar_chart_s pptx_ct_a_bar_chart;
typedef struct pptx_ct_a_bar_3dchart_s pptx_ct_a_bar_3dchart;
typedef struct pptx_ct_a_of_pie_chart_s pptx_ct_a_of_pie_chart;
typedef struct pptx_ct_a_surface_chart_s pptx_ct_a_surface_chart;
typedef struct pptx_ct_a_surface_3dchart_s pptx_ct_a_surface_3dchart;
typedef struct pptx_ct_a_bubble_chart_s pptx_ct_a_bubble_chart;
typedef struct pptx_ct_a_val_ax_s pptx_ct_a_val_ax;
typedef struct pptx_ct_a_cat_ax_s pptx_ct_a_cat_ax;
typedef struct pptx_ct_a_date_ax_s pptx_ct_a_date_ax;
typedef struct pptx_ct_a_ser_ax_s pptx_ct_a_ser_ax;
typedef struct pptx_ct_a_dtable_s pptx_ct_a_dtable;
typedef struct pptx_ct_a_shape_properties_s pptx_ct_a_shape_properties;
typedef struct pptx_ct_a_extension_list_s pptx_ct_a_extension_list;

typedef struct pptx_ct_a_plot_area_s pptx_ct_a_plot_area;
pptx_ct_a_plot_area *pptx_ct_a_plot_area_new(xmlNode *node);
void pptx_ct_a_plot_area_free(pptx_ct_a_plot_area *obj);
pptx_ct_a_layout *pptx_ct_a_plot_area_get_layout(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_area_chart **pptx_ct_a_plot_area_get_area_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_area_3dchart **pptx_ct_a_plot_area_get_area_3dchart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_line_chart **pptx_ct_a_plot_area_get_line_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_line_3dchart **pptx_ct_a_plot_area_get_line_3dchart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_stock_chart **pptx_ct_a_plot_area_get_stock_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_radar_chart **pptx_ct_a_plot_area_get_radar_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_scatter_chart **pptx_ct_a_plot_area_get_scatter_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_pie_chart **pptx_ct_a_plot_area_get_pie_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_pie_3dchart **pptx_ct_a_plot_area_get_pie_3dchart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_doughnut_chart **pptx_ct_a_plot_area_get_doughnut_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_bar_chart **pptx_ct_a_plot_area_get_bar_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_bar_3dchart **pptx_ct_a_plot_area_get_bar_3dchart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_of_pie_chart **pptx_ct_a_plot_area_get_of_pie_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_surface_chart **pptx_ct_a_plot_area_get_surface_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_surface_3dchart **pptx_ct_a_plot_area_get_surface_3dchart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_bubble_chart **pptx_ct_a_plot_area_get_bubble_chart(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_val_ax **pptx_ct_a_plot_area_get_val_ax(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_cat_ax **pptx_ct_a_plot_area_get_cat_ax(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_date_ax **pptx_ct_a_plot_area_get_date_ax(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_ser_ax **pptx_ct_a_plot_area_get_ser_ax(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_dtable *pptx_ct_a_plot_area_get_d_table(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_shape_properties *pptx_ct_a_plot_area_get_sp_pr(const pptx_ct_a_plot_area *const obj);
pptx_ct_a_extension_list *pptx_ct_a_plot_area_get_ext_lst(const pptx_ct_a_plot_area *const obj);
int32_t pptx_ct_a_plot_area_get_index(pptx_ct_a_plot_area *obj);

#endif /* __PPTX_CT_A_PLOT_AREA_H__ */
