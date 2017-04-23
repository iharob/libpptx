#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-effect-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-effect-list.h>
#include <private/pptx-ct-a-effect-container.h>

typedef struct pptx_ct_a_effect_properties_s {
    pptx_ct_a_effect_list *effect_properties_effect_lst;
    pptx_ct_a_effect_container *effect_properties_effect_dag;
    int32_t index;
} pptx_ct_a_effect_properties;

pptx_ct_a_effect_properties *
pptx_ct_a_effect_properties_new(xmlNode *node)
{
    pptx_ct_a_effect_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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

pptx_ct_a_effect_list *
pptx_ct_a_effect_properties_get_effect_properties_effect_lst(const pptx_ct_a_effect_properties *const obj)
{
    return obj->effect_properties_effect_lst;
}

pptx_ct_a_effect_container *
pptx_ct_a_effect_properties_get_effect_properties_effect_dag(const pptx_ct_a_effect_properties *const obj)
{
    return obj->effect_properties_effect_dag;
}

int32_t
pptx_ct_a_effect_properties_get_index(pptx_ct_a_effect_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_effect_properties_free(pptx_ct_a_effect_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_effect_list_free(obj->effect_properties_effect_lst);
    pptx_ct_a_effect_container_free(obj->effect_properties_effect_dag);
    free(obj);
}