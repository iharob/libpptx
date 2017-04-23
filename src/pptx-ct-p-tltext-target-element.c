#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltext-target-element.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-index-range.h>

typedef struct pptx_ct_p_tltext_target_element_s {
    pptx_ct_p_index_range *char_rg;
    pptx_ct_p_index_range *p_rg;
    int32_t index;
} pptx_ct_p_tltext_target_element;

pptx_ct_p_tltext_target_element *
pptx_ct_p_tltext_target_element_new(xmlNode *node)
{
    pptx_ct_p_tltext_target_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:charRg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->char_rg = NULL;
        } else {
            obj->char_rg = pptx_ct_p_index_range_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->char_rg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pRg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->p_rg = NULL;
        } else {
            obj->p_rg = pptx_ct_p_index_range_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->p_rg = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_index_range *
pptx_ct_p_tltext_target_element_get_char_rg(const pptx_ct_p_tltext_target_element *const obj)
{
    return obj->char_rg;
}

pptx_ct_p_index_range *
pptx_ct_p_tltext_target_element_get_p_rg(const pptx_ct_p_tltext_target_element *const obj)
{
    return obj->p_rg;
}

int32_t
pptx_ct_p_tltext_target_element_get_index(pptx_ct_p_tltext_target_element *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltext_target_element_free(pptx_ct_p_tltext_target_element *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_index_range_free(obj->char_rg);
    pptx_ct_p_index_range_free(obj->p_rg);
    free(obj);
}