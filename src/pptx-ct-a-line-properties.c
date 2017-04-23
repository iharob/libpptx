#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-no-fill-properties.h>
#include <private/pptx-ct-a-solid-color-fill-properties.h>
#include <private/pptx-ct-a-gradient-fill-properties.h>
#include <private/pptx-ct-a-pattern-fill-properties.h>
#include <private/pptx-ct-a-preset-line-dash-properties.h>
#include <private/pptx-ct-a-dash-stop-list.h>
#include <private/pptx-ct-a-line-join-round.h>
#include <private/pptx-ct-a-line-join-bevel.h>
#include <private/pptx-ct-a-line-join-miter-properties.h>
#include <private/pptx-ct-a-line-end-properties.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-line-cap.h>
#include <private/pptx-st-compound-line.h>
#include <private/pptx-st-pen-alignment.h>

typedef struct pptx_ct_a_line_properties_s {
    pptx_ct_a_no_fill_properties *line_fill_properties_no_fill;
    pptx_ct_a_solid_color_fill_properties *line_fill_properties_solid_fill;
    pptx_ct_a_gradient_fill_properties *line_fill_properties_grad_fill;
    pptx_ct_a_pattern_fill_properties *line_fill_properties_patt_fill;
    pptx_ct_a_preset_line_dash_properties *line_dash_properties_prst_dash;
    pptx_ct_a_dash_stop_list *line_dash_properties_cust_dash;
    pptx_ct_a_line_join_round *line_join_properties_round;
    pptx_ct_a_line_join_bevel *line_join_properties_bevel;
    pptx_ct_a_line_join_miter_properties *line_join_properties_miter;
    pptx_ct_a_line_end_properties *head_end;
    pptx_ct_a_line_end_properties *tail_end;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_int w;
    pptx_st_line_cap_token_enum cap;
    pptx_st_compound_line_token_enum cmpd;
    pptx_st_pen_alignment_token_enum algn;
    int32_t index;
} pptx_ct_a_line_properties;

pptx_ct_a_line_properties *
pptx_ct_a_line_properties_new(xmlNode *node)
{
    pptx_ct_a_line_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:noFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_fill_properties_no_fill = NULL;
        } else {
            obj->line_fill_properties_no_fill = pptx_ct_a_no_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_fill_properties_no_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:solidFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_fill_properties_solid_fill = NULL;
        } else {
            obj->line_fill_properties_solid_fill = pptx_ct_a_solid_color_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_fill_properties_solid_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gradFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_fill_properties_grad_fill = NULL;
        } else {
            obj->line_fill_properties_grad_fill = pptx_ct_a_gradient_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_fill_properties_grad_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pattFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_fill_properties_patt_fill = NULL;
        } else {
            obj->line_fill_properties_patt_fill = pptx_ct_a_pattern_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_fill_properties_patt_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstDash");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_dash_properties_prst_dash = NULL;
        } else {
            obj->line_dash_properties_prst_dash = pptx_ct_a_preset_line_dash_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_dash_properties_prst_dash = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:custDash");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_dash_properties_cust_dash = NULL;
        } else {
            obj->line_dash_properties_cust_dash = pptx_ct_a_dash_stop_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_dash_properties_cust_dash = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:round");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_join_properties_round = NULL;
        } else {
            obj->line_join_properties_round = pptx_ct_a_line_join_round_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_join_properties_round = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_join_properties_bevel = NULL;
        } else {
            obj->line_join_properties_bevel = pptx_ct_a_line_join_bevel_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_join_properties_bevel = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:miter");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->line_join_properties_miter = NULL;
        } else {
            obj->line_join_properties_miter = pptx_ct_a_line_join_miter_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->line_join_properties_miter = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:headEnd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->head_end = NULL;
        } else {
            obj->head_end = pptx_ct_a_line_end_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->head_end = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tailEnd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tail_end = NULL;
        } else {
            obj->tail_end = pptx_ct_a_line_end_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tail_end = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->w = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "w");
    obj->cap = pptx_get_st_line_cap(node, (const xmlChar *) "cap");
    obj->cmpd = pptx_get_st_compound_line(node, (const xmlChar *) "cmpd");
    obj->algn = pptx_get_st_pen_alignment(node, (const xmlChar *) "algn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_no_fill_properties *
pptx_ct_a_line_properties_get_line_fill_properties_no_fill(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_fill_properties_no_fill;
}

pptx_ct_a_solid_color_fill_properties *
pptx_ct_a_line_properties_get_line_fill_properties_solid_fill(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_fill_properties_solid_fill;
}

pptx_ct_a_gradient_fill_properties *
pptx_ct_a_line_properties_get_line_fill_properties_grad_fill(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_fill_properties_grad_fill;
}

pptx_ct_a_pattern_fill_properties *
pptx_ct_a_line_properties_get_line_fill_properties_patt_fill(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_fill_properties_patt_fill;
}

pptx_ct_a_preset_line_dash_properties *
pptx_ct_a_line_properties_get_line_dash_properties_prst_dash(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_dash_properties_prst_dash;
}

pptx_ct_a_dash_stop_list *
pptx_ct_a_line_properties_get_line_dash_properties_cust_dash(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_dash_properties_cust_dash;
}

pptx_ct_a_line_join_round *
pptx_ct_a_line_properties_get_line_join_properties_round(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_join_properties_round;
}

pptx_ct_a_line_join_bevel *
pptx_ct_a_line_properties_get_line_join_properties_bevel(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_join_properties_bevel;
}

pptx_ct_a_line_join_miter_properties *
pptx_ct_a_line_properties_get_line_join_properties_miter(const pptx_ct_a_line_properties *const obj)
{
    return obj->line_join_properties_miter;
}

pptx_ct_a_line_end_properties *
pptx_ct_a_line_properties_get_head_end(const pptx_ct_a_line_properties *const obj)
{
    return obj->head_end;
}

pptx_ct_a_line_end_properties *
pptx_ct_a_line_properties_get_tail_end(const pptx_ct_a_line_properties *const obj)
{
    return obj->tail_end;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_line_properties_get_ext_lst(const pptx_ct_a_line_properties *const obj)
{
    return obj->ext_lst;
}

pptx_int 
pptx_ct_a_line_properties_get_w(const pptx_ct_a_line_properties *const obj)
{
    return obj->w;
}

pptx_st_line_cap_token_enum 
pptx_ct_a_line_properties_get_cap(const pptx_ct_a_line_properties *const obj)
{
    return obj->cap;
}

pptx_st_compound_line_token_enum 
pptx_ct_a_line_properties_get_cmpd(const pptx_ct_a_line_properties *const obj)
{
    return obj->cmpd;
}

pptx_st_pen_alignment_token_enum 
pptx_ct_a_line_properties_get_algn(const pptx_ct_a_line_properties *const obj)
{
    return obj->algn;
}

int32_t
pptx_ct_a_line_properties_get_index(pptx_ct_a_line_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_properties_free(pptx_ct_a_line_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_no_fill_properties_free(obj->line_fill_properties_no_fill);
    pptx_ct_a_solid_color_fill_properties_free(obj->line_fill_properties_solid_fill);
    pptx_ct_a_gradient_fill_properties_free(obj->line_fill_properties_grad_fill);
    pptx_ct_a_pattern_fill_properties_free(obj->line_fill_properties_patt_fill);
    pptx_ct_a_preset_line_dash_properties_free(obj->line_dash_properties_prst_dash);
    pptx_ct_a_dash_stop_list_free(obj->line_dash_properties_cust_dash);
    pptx_ct_a_line_join_round_free(obj->line_join_properties_round);
    pptx_ct_a_line_join_bevel_free(obj->line_join_properties_bevel);
    pptx_ct_a_line_join_miter_properties_free(obj->line_join_properties_miter);
    pptx_ct_a_line_end_properties_free(obj->head_end);
    pptx_ct_a_line_end_properties_free(obj->tail_end);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}