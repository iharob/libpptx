#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-trendline.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-trendline-type.h>
#include <private/pptx-ct-a-order.h>
#include <private/pptx-ct-a-period.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-trendline-lbl.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_trendline_s {
    pptx_string name;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_trendline_type *trendline_type;
    pptx_ct_a_order *order;
    pptx_ct_a_period *period;
    pptx_ct_a_double *forward;
    pptx_ct_a_double *backward;
    pptx_ct_a_double *intercept;
    pptx_bool disp_rsqr;
    pptx_bool disp_eq;
    pptx_ct_a_trendline_lbl *trendline_lbl;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_trendline;

pptx_ct_a_trendline *
pptx_ct_a_trendline_new(xmlNode *node)
{
    pptx_ct_a_trendline *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->name = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:name");

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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:trendlineType");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->trendline_type = NULL;
        } else {
            obj->trendline_type = pptx_ct_a_trendline_type_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->trendline_type = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:order");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->order = NULL;
        } else {
            obj->order = pptx_ct_a_order_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->order = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:period");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->period = NULL;
        } else {
            obj->period = pptx_ct_a_period_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->period = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:forward");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->forward = NULL;
        } else {
            obj->forward = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->forward = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:backward");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->backward = NULL;
        } else {
            obj->backward = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->backward = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:intercept");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->intercept = NULL;
        } else {
            obj->intercept = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->intercept = NULL;
    }
    obj->disp_rsqr = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:dispRSqr");
    obj->disp_eq = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:dispEq");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:trendlineLbl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->trendline_lbl = NULL;
        } else {
            obj->trendline_lbl = pptx_ct_a_trendline_lbl_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->trendline_lbl = NULL;
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

pptx_string 
pptx_ct_a_trendline_get_name(const pptx_ct_a_trendline *const obj)
{
    return obj->name;
}

pptx_ct_a_shape_properties *
pptx_ct_a_trendline_get_sp_pr(const pptx_ct_a_trendline *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_trendline_type *
pptx_ct_a_trendline_get_trendline_type(const pptx_ct_a_trendline *const obj)
{
    return obj->trendline_type;
}

pptx_ct_a_order *
pptx_ct_a_trendline_get_order(const pptx_ct_a_trendline *const obj)
{
    return obj->order;
}

pptx_ct_a_period *
pptx_ct_a_trendline_get_period(const pptx_ct_a_trendline *const obj)
{
    return obj->period;
}

pptx_ct_a_double *
pptx_ct_a_trendline_get_forward(const pptx_ct_a_trendline *const obj)
{
    return obj->forward;
}

pptx_ct_a_double *
pptx_ct_a_trendline_get_backward(const pptx_ct_a_trendline *const obj)
{
    return obj->backward;
}

pptx_ct_a_double *
pptx_ct_a_trendline_get_intercept(const pptx_ct_a_trendline *const obj)
{
    return obj->intercept;
}

pptx_bool 
pptx_ct_a_trendline_get_disp_rsqr(const pptx_ct_a_trendline *const obj)
{
    return obj->disp_rsqr;
}

pptx_bool 
pptx_ct_a_trendline_get_disp_eq(const pptx_ct_a_trendline *const obj)
{
    return obj->disp_eq;
}

pptx_ct_a_trendline_lbl *
pptx_ct_a_trendline_get_trendline_lbl(const pptx_ct_a_trendline *const obj)
{
    return obj->trendline_lbl;
}

pptx_ct_a_extension_list *
pptx_ct_a_trendline_get_ext_lst(const pptx_ct_a_trendline *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_trendline_get_index(pptx_ct_a_trendline *obj)
{
    return obj->index;
}

void
pptx_ct_a_trendline_free(pptx_ct_a_trendline *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->name);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_trendline_type_free(obj->trendline_type);
    pptx_ct_a_order_free(obj->order);
    pptx_ct_a_period_free(obj->period);
    pptx_ct_a_double_free(obj->forward);
    pptx_ct_a_double_free(obj->backward);
    pptx_ct_a_double_free(obj->intercept);
    pptx_ct_a_trendline_lbl_free(obj->trendline_lbl);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}