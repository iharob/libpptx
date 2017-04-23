#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-background-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-fill-properties.h>
#include <private/pptx-ct-a-style-matrix-reference.h>
#include <private/pptx-ct-a-effect-properties.h>

typedef struct pptx_ct_a_table_background_style_s {
    pptx_ct_a_fill_properties *themeable_fill_style_fill;
    pptx_ct_a_style_matrix_reference *themeable_fill_style_fill_ref;
    pptx_ct_a_effect_properties *themeable_effect_style_effect;
    pptx_ct_a_style_matrix_reference *themeable_effect_style_effect_ref;
    int32_t index;
} pptx_ct_a_table_background_style;

pptx_ct_a_table_background_style *
pptx_ct_a_table_background_style_new(xmlNode *node)
{
    pptx_ct_a_table_background_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_fill_style_fill = NULL;
        } else {
            obj->themeable_fill_style_fill = pptx_ct_a_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_fill_style_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_fill_style_fill_ref = NULL;
        } else {
            obj->themeable_fill_style_fill_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_fill_style_fill_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_effect_style_effect = NULL;
        } else {
            obj->themeable_effect_style_effect = pptx_ct_a_effect_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_effect_style_effect = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_effect_style_effect_ref = NULL;
        } else {
            obj->themeable_effect_style_effect_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_effect_style_effect_ref = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_fill_properties *
pptx_ct_a_table_background_style_get_themeable_fill_style_fill(const pptx_ct_a_table_background_style *const obj)
{
    return obj->themeable_fill_style_fill;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_table_background_style_get_themeable_fill_style_fill_ref(const pptx_ct_a_table_background_style *const obj)
{
    return obj->themeable_fill_style_fill_ref;
}

pptx_ct_a_effect_properties *
pptx_ct_a_table_background_style_get_themeable_effect_style_effect(const pptx_ct_a_table_background_style *const obj)
{
    return obj->themeable_effect_style_effect;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_table_background_style_get_themeable_effect_style_effect_ref(const pptx_ct_a_table_background_style *const obj)
{
    return obj->themeable_effect_style_effect_ref;
}

int32_t
pptx_ct_a_table_background_style_get_index(pptx_ct_a_table_background_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_background_style_free(pptx_ct_a_table_background_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_fill_properties_free(obj->themeable_fill_style_fill);
    pptx_ct_a_style_matrix_reference_free(obj->themeable_fill_style_fill_ref);
    pptx_ct_a_effect_properties_free(obj->themeable_effect_style_effect);
    pptx_ct_a_style_matrix_reference_free(obj->themeable_effect_style_effect_ref);
    free(obj);
}