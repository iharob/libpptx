#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-animation-element-choice.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-animation-dgm-element.h>
#include <private/pptx-ct-a-animation-chart-element.h>

typedef struct pptx_ct_a_animation_element_choice_s {
    pptx_ct_a_animation_dgm_element *dgm;
    pptx_ct_a_animation_chart_element *chart;
    int32_t index;
} pptx_ct_a_animation_element_choice;

pptx_ct_a_animation_element_choice *
pptx_ct_a_animation_element_choice_new(xmlNode *node)
{
    pptx_ct_a_animation_element_choice *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dgm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dgm = NULL;
        } else {
            obj->dgm = pptx_ct_a_animation_dgm_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dgm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:chart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->chart = NULL;
        } else {
            obj->chart = pptx_ct_a_animation_chart_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->chart = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_animation_dgm_element *
pptx_ct_a_animation_element_choice_get_dgm(const pptx_ct_a_animation_element_choice *const obj)
{
    return obj->dgm;
}

pptx_ct_a_animation_chart_element *
pptx_ct_a_animation_element_choice_get_chart(const pptx_ct_a_animation_element_choice *const obj)
{
    return obj->chart;
}

int32_t
pptx_ct_a_animation_element_choice_get_index(pptx_ct_a_animation_element_choice *obj)
{
    return obj->index;
}

void
pptx_ct_a_animation_element_choice_free(pptx_ct_a_animation_element_choice *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_animation_dgm_element_free(obj->dgm);
    pptx_ct_a_animation_chart_element_free(obj->chart);
    free(obj);
}