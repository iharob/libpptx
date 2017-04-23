#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlshape-target-element.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-p-tlsub-shape-id.h>
#include <private/pptx-ct-p-tlole-chart-target-element.h>
#include <private/pptx-ct-p-tltext-target-element.h>
#include <private/pptx-ct-a-animation-element-choice.h>

typedef struct pptx_ct_p_tlshape_target_element_s {
    pptx_ct_p_empty *bg;
    pptx_ct_p_tlsub_shape_id *sub_sp;
    pptx_ct_p_tlole_chart_target_element *ole_chart_el;
    pptx_ct_p_tltext_target_element *tx_el;
    pptx_ct_a_animation_element_choice *graphic_el;
    pptx_uint spid;
    int32_t index;
} pptx_ct_p_tlshape_target_element;

pptx_ct_p_tlshape_target_element *
pptx_ct_p_tlshape_target_element_new(xmlNode *node)
{
    pptx_ct_p_tlshape_target_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bg = NULL;
        } else {
            obj->bg = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:subSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sub_sp = NULL;
        } else {
            obj->sub_sp = pptx_ct_p_tlsub_shape_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sub_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:oleChartEl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ole_chart_el = NULL;
        } else {
            obj->ole_chart_el = pptx_ct_p_tlole_chart_target_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ole_chart_el = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:txEl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_el = NULL;
        } else {
            obj->tx_el = pptx_ct_p_tltext_target_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_el = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:graphicEl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->graphic_el = NULL;
        } else {
            obj->graphic_el = pptx_ct_a_animation_element_choice_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->graphic_el = NULL;
    }
    obj->spid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spid");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_empty *
pptx_ct_p_tlshape_target_element_get_bg(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->bg;
}

pptx_ct_p_tlsub_shape_id *
pptx_ct_p_tlshape_target_element_get_sub_sp(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->sub_sp;
}

pptx_ct_p_tlole_chart_target_element *
pptx_ct_p_tlshape_target_element_get_ole_chart_el(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->ole_chart_el;
}

pptx_ct_p_tltext_target_element *
pptx_ct_p_tlshape_target_element_get_tx_el(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->tx_el;
}

pptx_ct_a_animation_element_choice *
pptx_ct_p_tlshape_target_element_get_graphic_el(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->graphic_el;
}

pptx_uint 
pptx_ct_p_tlshape_target_element_get_spid(const pptx_ct_p_tlshape_target_element *const obj)
{
    return obj->spid;
}

int32_t
pptx_ct_p_tlshape_target_element_get_index(pptx_ct_p_tlshape_target_element *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlshape_target_element_free(pptx_ct_p_tlshape_target_element *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_empty_free(obj->bg);
    pptx_ct_p_tlsub_shape_id_free(obj->sub_sp);
    pptx_ct_p_tlole_chart_target_element_free(obj->ole_chart_el);
    pptx_ct_p_tltext_target_element_free(obj->tx_el);
    pptx_ct_a_animation_element_choice_free(obj->graphic_el);
    free(obj);
}