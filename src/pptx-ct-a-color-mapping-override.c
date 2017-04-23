#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-mapping-override.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-empty-element.h>
#include <private/pptx-ct-a-color-mapping.h>

typedef struct pptx_ct_a_color_mapping_override_s {
    pptx_ct_a_empty_element *master_clr_mapping;
    pptx_ct_a_color_mapping *override_clr_mapping;
    int32_t index;
} pptx_ct_a_color_mapping_override;

pptx_ct_a_color_mapping_override *
pptx_ct_a_color_mapping_override_new(xmlNode *node)
{
    pptx_ct_a_color_mapping_override *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:masterClrMapping");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->master_clr_mapping = NULL;
        } else {
            obj->master_clr_mapping = pptx_ct_a_empty_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->master_clr_mapping = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:overrideClrMapping");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->override_clr_mapping = NULL;
        } else {
            obj->override_clr_mapping = pptx_ct_a_color_mapping_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->override_clr_mapping = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_empty_element *
pptx_ct_a_color_mapping_override_get_master_clr_mapping(const pptx_ct_a_color_mapping_override *const obj)
{
    return obj->master_clr_mapping;
}

pptx_ct_a_color_mapping *
pptx_ct_a_color_mapping_override_get_override_clr_mapping(const pptx_ct_a_color_mapping_override *const obj)
{
    return obj->override_clr_mapping;
}

int32_t
pptx_ct_a_color_mapping_override_get_index(pptx_ct_a_color_mapping_override *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_mapping_override_free(pptx_ct_a_color_mapping_override *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_empty_element_free(obj->master_clr_mapping);
    pptx_ct_a_color_mapping_free(obj->override_clr_mapping);
    free(obj);
}