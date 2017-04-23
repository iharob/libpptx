#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-themeable-line-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-properties.h>
#include <private/pptx-ct-a-style-matrix-reference.h>

typedef struct pptx_ct_a_themeable_line_style_s {
    pptx_ct_a_line_properties *ln;
    pptx_ct_a_style_matrix_reference *ln_ref;
    int32_t index;
} pptx_ct_a_themeable_line_style;

pptx_ct_a_themeable_line_style *
pptx_ct_a_themeable_line_style_new(xmlNode *node)
{
    pptx_ct_a_themeable_line_style *obj;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_line_properties *
pptx_ct_a_themeable_line_style_get_ln(const pptx_ct_a_themeable_line_style *const obj)
{
    return obj->ln;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_themeable_line_style_get_ln_ref(const pptx_ct_a_themeable_line_style *const obj)
{
    return obj->ln_ref;
}

int32_t
pptx_ct_a_themeable_line_style_get_index(pptx_ct_a_themeable_line_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_themeable_line_style_free(pptx_ct_a_themeable_line_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_line_properties_free(obj->ln);
    pptx_ct_a_style_matrix_reference_free(obj->ln_ref);
    free(obj);
}