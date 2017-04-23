#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-chart-space.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-language-id.h>
#include <private/pptx-ct-a-style.h>
#include <private/pptx-ct-a-color-mapping.h>
#include <private/pptx-ct-a-pivot-source.h>
#include <private/pptx-ct-a-protection.h>
#include <private/pptx-ct-a-chart.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-external-data.h>
#include <private/pptx-ct-a-print-settings.h>
#include <private/pptx-ct-a-rel-id.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_chart_space_s {
    pptx_bool date1904;
    pptx_ct_a_text_language_id *lang;
    pptx_bool rounded_corners;
    pptx_ct_a_style *style;
    pptx_ct_a_color_mapping *clr_map_ovr;
    pptx_ct_a_pivot_source *pivot_source;
    pptx_ct_a_protection *protection;
    pptx_ct_a_chart *chart;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *tx_pr;
    pptx_ct_a_external_data *external_data;
    pptx_ct_a_print_settings *print_settings;
    pptx_ct_a_rel_id *user_shapes;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_chart_space;

pptx_ct_a_chart_space *
pptx_ct_a_chart_space_new(xmlNode *node)
{
    pptx_ct_a_chart_space *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->date1904 = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:date1904");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lang");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lang = NULL;
        } else {
            obj->lang = pptx_ct_a_text_language_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lang = NULL;
    }
    obj->rounded_corners = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:roundedCorners");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:style");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->style = NULL;
        } else {
            obj->style = pptx_ct_a_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrMapOvr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_map_ovr = NULL;
        } else {
            obj->clr_map_ovr = pptx_ct_a_color_mapping_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_map_ovr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pivotSource");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pivot_source = NULL;
        } else {
            obj->pivot_source = pptx_ct_a_pivot_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pivot_source = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:protection");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->protection = NULL;
        } else {
            obj->protection = pptx_ct_a_protection_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->protection = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:chart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->chart = NULL;
        } else {
            obj->chart = pptx_ct_a_chart_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_pr = NULL;
        } else {
            obj->tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:externalData");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->external_data = NULL;
        } else {
            obj->external_data = pptx_ct_a_external_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->external_data = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:printSettings");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->print_settings = NULL;
        } else {
            obj->print_settings = pptx_ct_a_print_settings_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->print_settings = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:userShapes");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->user_shapes = NULL;
        } else {
            obj->user_shapes = pptx_ct_a_rel_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->user_shapes = NULL;
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

pptx_bool 
pptx_ct_a_chart_space_get_date1904(const pptx_ct_a_chart_space *const obj)
{
    return obj->date1904;
}

pptx_ct_a_text_language_id *
pptx_ct_a_chart_space_get_lang(const pptx_ct_a_chart_space *const obj)
{
    return obj->lang;
}

pptx_bool 
pptx_ct_a_chart_space_get_rounded_corners(const pptx_ct_a_chart_space *const obj)
{
    return obj->rounded_corners;
}

pptx_ct_a_style *
pptx_ct_a_chart_space_get_style(const pptx_ct_a_chart_space *const obj)
{
    return obj->style;
}

pptx_ct_a_color_mapping *
pptx_ct_a_chart_space_get_clr_map_ovr(const pptx_ct_a_chart_space *const obj)
{
    return obj->clr_map_ovr;
}

pptx_ct_a_pivot_source *
pptx_ct_a_chart_space_get_pivot_source(const pptx_ct_a_chart_space *const obj)
{
    return obj->pivot_source;
}

pptx_ct_a_protection *
pptx_ct_a_chart_space_get_protection(const pptx_ct_a_chart_space *const obj)
{
    return obj->protection;
}

pptx_ct_a_chart *
pptx_ct_a_chart_space_get_chart(const pptx_ct_a_chart_space *const obj)
{
    return obj->chart;
}

pptx_ct_a_shape_properties *
pptx_ct_a_chart_space_get_sp_pr(const pptx_ct_a_chart_space *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_chart_space_get_tx_pr(const pptx_ct_a_chart_space *const obj)
{
    return obj->tx_pr;
}

pptx_ct_a_external_data *
pptx_ct_a_chart_space_get_external_data(const pptx_ct_a_chart_space *const obj)
{
    return obj->external_data;
}

pptx_ct_a_print_settings *
pptx_ct_a_chart_space_get_print_settings(const pptx_ct_a_chart_space *const obj)
{
    return obj->print_settings;
}

pptx_ct_a_rel_id *
pptx_ct_a_chart_space_get_user_shapes(const pptx_ct_a_chart_space *const obj)
{
    return obj->user_shapes;
}

pptx_ct_a_extension_list *
pptx_ct_a_chart_space_get_ext_lst(const pptx_ct_a_chart_space *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_chart_space_get_index(pptx_ct_a_chart_space *obj)
{
    return obj->index;
}

void
pptx_ct_a_chart_space_free(pptx_ct_a_chart_space *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_language_id_free(obj->lang);
    pptx_ct_a_style_free(obj->style);
    pptx_ct_a_color_mapping_free(obj->clr_map_ovr);
    pptx_ct_a_pivot_source_free(obj->pivot_source);
    pptx_ct_a_protection_free(obj->protection);
    pptx_ct_a_chart_free(obj->chart);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->tx_pr);
    pptx_ct_a_external_data_free(obj->external_data);
    pptx_ct_a_print_settings_free(obj->print_settings);
    pptx_ct_a_rel_id_free(obj->user_shapes);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}