#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-title.h>
#include <private/pptx-ct-a-pivot-fmts.h>
#include <private/pptx-ct-a-view-3d.h>
#include <private/pptx-ct-a-surface.h>
#include <private/pptx-ct-a-plot-area.h>
#include <private/pptx-ct-a-legend.h>
#include <private/pptx-ct-a-disp-blanks-as.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_chart_s {
    pptx_ct_a_title *title;
    pptx_bool auto_title_deleted;
    pptx_ct_a_pivot_fmts *pivot_fmts;
    pptx_ct_a_view_3d *view_3d;
    pptx_ct_a_surface *floor;
    pptx_ct_a_surface *side_wall;
    pptx_ct_a_surface *back_wall;
    pptx_ct_a_plot_area *plot_area;
    pptx_ct_a_legend *legend;
    pptx_bool plot_vis_only;
    pptx_ct_a_disp_blanks_as *disp_blanks_as;
    pptx_bool show_dlbls_over_max;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_chart;

pptx_ct_a_chart *
pptx_ct_a_chart_new(xmlNode *node)
{
    pptx_ct_a_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:title");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->title = NULL;
        } else {
            obj->title = pptx_ct_a_title_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->title = NULL;
    }
    obj->auto_title_deleted = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:autoTitleDeleted");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pivotFmts");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pivot_fmts = NULL;
        } else {
            obj->pivot_fmts = pptx_ct_a_pivot_fmts_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pivot_fmts = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:view3D");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->view_3d = NULL;
        } else {
            obj->view_3d = pptx_ct_a_view_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->view_3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:floor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->floor = NULL;
        } else {
            obj->floor = pptx_ct_a_surface_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->floor = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sideWall");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->side_wall = NULL;
        } else {
            obj->side_wall = pptx_ct_a_surface_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->side_wall = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:backWall");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->back_wall = NULL;
        } else {
            obj->back_wall = pptx_ct_a_surface_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->back_wall = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:plotArea");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->plot_area = NULL;
        } else {
            obj->plot_area = pptx_ct_a_plot_area_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->plot_area = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:legend");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->legend = NULL;
        } else {
            obj->legend = pptx_ct_a_legend_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->legend = NULL;
    }
    obj->plot_vis_only = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:plotVisOnly");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dispBlanksAs");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->disp_blanks_as = NULL;
        } else {
            obj->disp_blanks_as = pptx_ct_a_disp_blanks_as_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->disp_blanks_as = NULL;
    }
    obj->show_dlbls_over_max = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showDLblsOverMax");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_title *
pptx_ct_a_chart_get_title(const pptx_ct_a_chart *const obj)
{
    return obj->title;
}

pptx_bool 
pptx_ct_a_chart_get_auto_title_deleted(const pptx_ct_a_chart *const obj)
{
    return obj->auto_title_deleted;
}

pptx_ct_a_pivot_fmts *
pptx_ct_a_chart_get_pivot_fmts(const pptx_ct_a_chart *const obj)
{
    return obj->pivot_fmts;
}

pptx_ct_a_view_3d *
pptx_ct_a_chart_get_view_3d(const pptx_ct_a_chart *const obj)
{
    return obj->view_3d;
}

pptx_ct_a_surface *
pptx_ct_a_chart_get_floor(const pptx_ct_a_chart *const obj)
{
    return obj->floor;
}

pptx_ct_a_surface *
pptx_ct_a_chart_get_side_wall(const pptx_ct_a_chart *const obj)
{
    return obj->side_wall;
}

pptx_ct_a_surface *
pptx_ct_a_chart_get_back_wall(const pptx_ct_a_chart *const obj)
{
    return obj->back_wall;
}

pptx_ct_a_plot_area *
pptx_ct_a_chart_get_plot_area(const pptx_ct_a_chart *const obj)
{
    return obj->plot_area;
}

pptx_ct_a_legend *
pptx_ct_a_chart_get_legend(const pptx_ct_a_chart *const obj)
{
    return obj->legend;
}

pptx_bool 
pptx_ct_a_chart_get_plot_vis_only(const pptx_ct_a_chart *const obj)
{
    return obj->plot_vis_only;
}

pptx_ct_a_disp_blanks_as *
pptx_ct_a_chart_get_disp_blanks_as(const pptx_ct_a_chart *const obj)
{
    return obj->disp_blanks_as;
}

pptx_bool 
pptx_ct_a_chart_get_show_dlbls_over_max(const pptx_ct_a_chart *const obj)
{
    return obj->show_dlbls_over_max;
}

pptx_ct_a_extension_list *
pptx_ct_a_chart_get_ext_lst(const pptx_ct_a_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_chart_get_index(pptx_ct_a_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_chart_free(pptx_ct_a_chart *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_title_free(obj->title);
    pptx_ct_a_pivot_fmts_free(obj->pivot_fmts);
    pptx_ct_a_view_3d_free(obj->view_3d);
    pptx_ct_a_surface_free(obj->floor);
    pptx_ct_a_surface_free(obj->side_wall);
    pptx_ct_a_surface_free(obj->back_wall);
    pptx_ct_a_plot_area_free(obj->plot_area);
    pptx_ct_a_legend_free(obj->legend);
    pptx_ct_a_disp_blanks_as_free(obj->disp_blanks_as);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}