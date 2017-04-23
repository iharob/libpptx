#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-val-ax.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-scaling.h>
#include <private/pptx-ct-a-ax-pos.h>
#include <private/pptx-ct-a-chart-lines.h>
#include <private/pptx-ct-a-title.h>
#include <private/pptx-ct-a-num-fmt.h>
#include <private/pptx-ct-a-tick-mark.h>
#include <private/pptx-ct-a-tick-lbl-pos.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-crosses.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-cross-between.h>
#include <private/pptx-ct-a-axis-unit.h>
#include <private/pptx-ct-a-disp-units.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_val_ax_s {
    pptx_uint ax_shared_ax_id;
    pptx_ct_a_scaling *ax_shared_scaling;
    pptx_bool ax_shared_delete;
    pptx_ct_a_ax_pos *ax_shared_ax_pos;
    pptx_ct_a_chart_lines *ax_shared_major_gridlines;
    pptx_ct_a_chart_lines *ax_shared_minor_gridlines;
    pptx_ct_a_title *ax_shared_title;
    pptx_ct_a_num_fmt *ax_shared_num_fmt;
    pptx_ct_a_tick_mark *ax_shared_major_tick_mark;
    pptx_ct_a_tick_mark *ax_shared_minor_tick_mark;
    pptx_ct_a_tick_lbl_pos *ax_shared_tick_lbl_pos;
    pptx_ct_a_shape_properties *ax_shared_sp_pr;
    pptx_ct_a_text_body *ax_shared_tx_pr;
    pptx_uint ax_shared_cross_ax;
    pptx_ct_a_crosses *crosses;
    pptx_ct_a_double *crosses_at;
    pptx_ct_a_cross_between *cross_between;
    pptx_ct_a_axis_unit *major_unit;
    pptx_ct_a_axis_unit *minor_unit;
    pptx_ct_a_disp_units *disp_units;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_val_ax;

pptx_ct_a_val_ax *
pptx_ct_a_val_ax_new(xmlNode *node)
{
    pptx_ct_a_val_ax *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->ax_shared_ax_id = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:axId");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scaling");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_scaling = NULL;
        } else {
            obj->ax_shared_scaling = pptx_ct_a_scaling_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_scaling = NULL;
    }
    obj->ax_shared_delete = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:delete");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:axPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_ax_pos = NULL;
        } else {
            obj->ax_shared_ax_pos = pptx_ct_a_ax_pos_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_ax_pos = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:majorGridlines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_major_gridlines = NULL;
        } else {
            obj->ax_shared_major_gridlines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_major_gridlines = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:minorGridlines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_minor_gridlines = NULL;
        } else {
            obj->ax_shared_minor_gridlines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_minor_gridlines = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:title");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_title = NULL;
        } else {
            obj->ax_shared_title = pptx_ct_a_title_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_title = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:numFmt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_num_fmt = NULL;
        } else {
            obj->ax_shared_num_fmt = pptx_ct_a_num_fmt_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_num_fmt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:majorTickMark");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_major_tick_mark = NULL;
        } else {
            obj->ax_shared_major_tick_mark = pptx_ct_a_tick_mark_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_major_tick_mark = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:minorTickMark");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_minor_tick_mark = NULL;
        } else {
            obj->ax_shared_minor_tick_mark = pptx_ct_a_tick_mark_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_minor_tick_mark = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tickLblPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_tick_lbl_pos = NULL;
        } else {
            obj->ax_shared_tick_lbl_pos = pptx_ct_a_tick_lbl_pos_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_tick_lbl_pos = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_sp_pr = NULL;
        } else {
            obj->ax_shared_sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ax_shared_tx_pr = NULL;
        } else {
            obj->ax_shared_tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ax_shared_tx_pr = NULL;
    }
    obj->ax_shared_cross_ax = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:crossAx");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:crosses");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->crosses = NULL;
        } else {
            obj->crosses = pptx_ct_a_crosses_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->crosses = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:crossesAt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->crosses_at = NULL;
        } else {
            obj->crosses_at = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->crosses_at = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:crossBetween");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cross_between = NULL;
        } else {
            obj->cross_between = pptx_ct_a_cross_between_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cross_between = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:majorUnit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->major_unit = NULL;
        } else {
            obj->major_unit = pptx_ct_a_axis_unit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->major_unit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:minorUnit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->minor_unit = NULL;
        } else {
            obj->minor_unit = pptx_ct_a_axis_unit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->minor_unit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dispUnits");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->disp_units = NULL;
        } else {
            obj->disp_units = pptx_ct_a_disp_units_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->disp_units = NULL;
    }

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

pptx_uint 
pptx_ct_a_val_ax_get_ax_shared_ax_id(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_ax_id;
}

pptx_ct_a_scaling *
pptx_ct_a_val_ax_get_ax_shared_scaling(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_scaling;
}

pptx_bool 
pptx_ct_a_val_ax_get_ax_shared_delete(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_delete;
}

pptx_ct_a_ax_pos *
pptx_ct_a_val_ax_get_ax_shared_ax_pos(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_ax_pos;
}

pptx_ct_a_chart_lines *
pptx_ct_a_val_ax_get_ax_shared_major_gridlines(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_major_gridlines;
}

pptx_ct_a_chart_lines *
pptx_ct_a_val_ax_get_ax_shared_minor_gridlines(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_minor_gridlines;
}

pptx_ct_a_title *
pptx_ct_a_val_ax_get_ax_shared_title(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_title;
}

pptx_ct_a_num_fmt *
pptx_ct_a_val_ax_get_ax_shared_num_fmt(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_num_fmt;
}

pptx_ct_a_tick_mark *
pptx_ct_a_val_ax_get_ax_shared_major_tick_mark(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_major_tick_mark;
}

pptx_ct_a_tick_mark *
pptx_ct_a_val_ax_get_ax_shared_minor_tick_mark(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_minor_tick_mark;
}

pptx_ct_a_tick_lbl_pos *
pptx_ct_a_val_ax_get_ax_shared_tick_lbl_pos(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_tick_lbl_pos;
}

pptx_ct_a_shape_properties *
pptx_ct_a_val_ax_get_ax_shared_sp_pr(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_val_ax_get_ax_shared_tx_pr(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_tx_pr;
}

pptx_uint 
pptx_ct_a_val_ax_get_ax_shared_cross_ax(const pptx_ct_a_val_ax *const obj)
{
    return obj->ax_shared_cross_ax;
}

pptx_ct_a_crosses *
pptx_ct_a_val_ax_get_crosses(const pptx_ct_a_val_ax *const obj)
{
    return obj->crosses;
}

pptx_ct_a_double *
pptx_ct_a_val_ax_get_crosses_at(const pptx_ct_a_val_ax *const obj)
{
    return obj->crosses_at;
}

pptx_ct_a_cross_between *
pptx_ct_a_val_ax_get_cross_between(const pptx_ct_a_val_ax *const obj)
{
    return obj->cross_between;
}

pptx_ct_a_axis_unit *
pptx_ct_a_val_ax_get_major_unit(const pptx_ct_a_val_ax *const obj)
{
    return obj->major_unit;
}

pptx_ct_a_axis_unit *
pptx_ct_a_val_ax_get_minor_unit(const pptx_ct_a_val_ax *const obj)
{
    return obj->minor_unit;
}

pptx_ct_a_disp_units *
pptx_ct_a_val_ax_get_disp_units(const pptx_ct_a_val_ax *const obj)
{
    return obj->disp_units;
}

pptx_ct_a_extension_list *
pptx_ct_a_val_ax_get_ext_lst(const pptx_ct_a_val_ax *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_val_ax_get_index(pptx_ct_a_val_ax *obj)
{
    return obj->index;
}

void
pptx_ct_a_val_ax_free(pptx_ct_a_val_ax *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_scaling_free(obj->ax_shared_scaling);
    pptx_ct_a_ax_pos_free(obj->ax_shared_ax_pos);
    pptx_ct_a_chart_lines_free(obj->ax_shared_major_gridlines);
    pptx_ct_a_chart_lines_free(obj->ax_shared_minor_gridlines);
    pptx_ct_a_title_free(obj->ax_shared_title);
    pptx_ct_a_num_fmt_free(obj->ax_shared_num_fmt);
    pptx_ct_a_tick_mark_free(obj->ax_shared_major_tick_mark);
    pptx_ct_a_tick_mark_free(obj->ax_shared_minor_tick_mark);
    pptx_ct_a_tick_lbl_pos_free(obj->ax_shared_tick_lbl_pos);
    pptx_ct_a_shape_properties_free(obj->ax_shared_sp_pr);
    pptx_ct_a_text_body_free(obj->ax_shared_tx_pr);
    pptx_ct_a_crosses_free(obj->crosses);
    pptx_ct_a_double_free(obj->crosses_at);
    pptx_ct_a_cross_between_free(obj->cross_between);
    pptx_ct_a_axis_unit_free(obj->major_unit);
    pptx_ct_a_axis_unit_free(obj->minor_unit);
    pptx_ct_a_disp_units_free(obj->disp_units);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}