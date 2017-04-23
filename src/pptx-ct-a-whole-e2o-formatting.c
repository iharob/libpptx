#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-whole-e2o-formatting.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-properties.h>
#include <private/pptx-ct-a-effect-list.h>
#include <private/pptx-ct-a-effect-container.h>

typedef struct pptx_ct_a_whole_e2o_formatting_s {
    pptx_ct_a_line_properties *ln;
    pptx_ct_a_effect_list *effect_properties_effect_lst;
    pptx_ct_a_effect_container *effect_properties_effect_dag;
    int32_t index;
} pptx_ct_a_whole_e2o_formatting;

pptx_ct_a_whole_e2o_formatting *
pptx_ct_a_whole_e2o_formatting_new(xmlNode *node)
{
    pptx_ct_a_whole_e2o_formatting *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ln");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln = NULL;
        } else {
            obj->ln = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_lst = NULL;
        } else {
            obj->effect_properties_effect_lst = pptx_ct_a_effect_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectDag");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_dag = NULL;
        } else {
            obj->effect_properties_effect_dag = pptx_ct_a_effect_container_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_dag = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_line_properties *
pptx_ct_a_whole_e2o_formatting_get_ln(const pptx_ct_a_whole_e2o_formatting *const obj)
{
    return obj->ln;
}

pptx_ct_a_effect_list *
pptx_ct_a_whole_e2o_formatting_get_effect_properties_effect_lst(const pptx_ct_a_whole_e2o_formatting *const obj)
{
    return obj->effect_properties_effect_lst;
}

pptx_ct_a_effect_container *
pptx_ct_a_whole_e2o_formatting_get_effect_properties_effect_dag(const pptx_ct_a_whole_e2o_formatting *const obj)
{
    return obj->effect_properties_effect_dag;
}

int32_t
pptx_ct_a_whole_e2o_formatting_get_index(pptx_ct_a_whole_e2o_formatting *obj)
{
    return obj->index;
}

void
pptx_ct_a_whole_e2o_formatting_free(pptx_ct_a_whole_e2o_formatting *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_line_properties_free(obj->ln);
    pptx_ct_a_effect_list_free(obj->effect_properties_effect_lst);
    pptx_ct_a_effect_container_free(obj->effect_properties_effect_dag);
    free(obj);
}