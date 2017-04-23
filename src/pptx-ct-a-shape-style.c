#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-shape-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-style-matrix-reference.h>
#include <private/pptx-ct-a-font-reference.h>

typedef struct pptx_ct_a_shape_style_s {
    pptx_ct_a_style_matrix_reference *ln_ref;
    pptx_ct_a_style_matrix_reference *fill_ref;
    pptx_ct_a_style_matrix_reference *effect_ref;
    pptx_ct_a_font_reference *font_ref;
    int32_t index;
} pptx_ct_a_shape_style;

pptx_ct_a_shape_style *
pptx_ct_a_shape_style_new(xmlNode *node)
{
    pptx_ct_a_shape_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_ref = NULL;
        } else {
            obj->ln_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_ref = NULL;
        } else {
            obj->fill_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_ref = NULL;
        } else {
            obj->effect_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fontRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->font_ref = NULL;
        } else {
            obj->font_ref = pptx_ct_a_font_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->font_ref = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_shape_style_get_ln_ref(const pptx_ct_a_shape_style *const obj)
{
    return obj->ln_ref;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_shape_style_get_fill_ref(const pptx_ct_a_shape_style *const obj)
{
    return obj->fill_ref;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_shape_style_get_effect_ref(const pptx_ct_a_shape_style *const obj)
{
    return obj->effect_ref;
}

pptx_ct_a_font_reference *
pptx_ct_a_shape_style_get_font_ref(const pptx_ct_a_shape_style *const obj)
{
    return obj->font_ref;
}

int32_t
pptx_ct_a_shape_style_get_index(pptx_ct_a_shape_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_shape_style_free(pptx_ct_a_shape_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_style_matrix_reference_free(obj->ln_ref);
    pptx_ct_a_style_matrix_reference_free(obj->fill_ref);
    pptx_ct_a_style_matrix_reference_free(obj->effect_ref);
    pptx_ct_a_font_reference_free(obj->font_ref);
    free(obj);
}