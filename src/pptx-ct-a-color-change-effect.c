#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-change-effect.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color.h>

typedef struct pptx_ct_a_color_change_effect_s {
    pptx_ct_a_color *clr_from;
    pptx_ct_a_color *clr_to;
    pptx_bool use_a;
    int32_t index;
} pptx_ct_a_color_change_effect;

pptx_ct_a_color_change_effect *
pptx_ct_a_color_change_effect_new(xmlNode *node)
{
    pptx_ct_a_color_change_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrFrom");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_from = NULL;
        } else {
            obj->clr_from = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_from = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_to = NULL;
        } else {
            obj->clr_to = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_to = NULL;
    }
    obj->use_a = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useA");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color *
pptx_ct_a_color_change_effect_get_clr_from(const pptx_ct_a_color_change_effect *const obj)
{
    return obj->clr_from;
}

pptx_ct_a_color *
pptx_ct_a_color_change_effect_get_clr_to(const pptx_ct_a_color_change_effect *const obj)
{
    return obj->clr_to;
}

pptx_bool 
pptx_ct_a_color_change_effect_get_use_a(const pptx_ct_a_color_change_effect *const obj)
{
    return obj->use_a;
}

int32_t
pptx_ct_a_color_change_effect_get_index(pptx_ct_a_color_change_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_change_effect_free(pptx_ct_a_color_change_effect *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_color_free(obj->clr_from);
    pptx_ct_a_color_free(obj->clr_to);
    free(obj);
}