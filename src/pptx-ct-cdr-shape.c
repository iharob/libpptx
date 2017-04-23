#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-cdr-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-cdr-shape-non-visual.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-shape-style.h>
#include <private/pptx-ct-a-text-body.h>

typedef struct pptx_ct_cdr_shape_s {
    pptx_ct_cdr_shape_non_visual *nv_sp_pr;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_shape_style *style;
    pptx_ct_a_text_body *tx_body;
    pptx_string macro;
    pptx_string textlink;
    pptx_bool f_locks_text;
    pptx_bool f_published;
    int32_t index;
} pptx_ct_cdr_shape;

pptx_ct_cdr_shape *
pptx_ct_cdr_shape_new(xmlNode *node)
{
    pptx_ct_cdr_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:nvSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_sp_pr = NULL;
        } else {
            obj->nv_sp_pr = pptx_ct_cdr_shape_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:style");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->style = NULL;
        } else {
            obj->style = pptx_ct_a_shape_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:txBody");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_body = NULL;
        } else {
            obj->tx_body = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_body = NULL;
    }
    obj->macro = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "macro");
    obj->textlink = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "textlink");
    obj->f_locks_text = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "fLocksText");
    obj->f_published = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "fPublished");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_cdr_shape_non_visual *
pptx_ct_cdr_shape_get_nv_sp_pr(const pptx_ct_cdr_shape *const obj)
{
    return obj->nv_sp_pr;
}

pptx_ct_a_shape_properties *
pptx_ct_cdr_shape_get_sp_pr(const pptx_ct_cdr_shape *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_shape_style *
pptx_ct_cdr_shape_get_style(const pptx_ct_cdr_shape *const obj)
{
    return obj->style;
}

pptx_ct_a_text_body *
pptx_ct_cdr_shape_get_tx_body(const pptx_ct_cdr_shape *const obj)
{
    return obj->tx_body;
}

pptx_string 
pptx_ct_cdr_shape_get_macro(const pptx_ct_cdr_shape *const obj)
{
    return obj->macro;
}

pptx_string 
pptx_ct_cdr_shape_get_textlink(const pptx_ct_cdr_shape *const obj)
{
    return obj->textlink;
}

pptx_bool 
pptx_ct_cdr_shape_get_f_locks_text(const pptx_ct_cdr_shape *const obj)
{
    return obj->f_locks_text;
}

pptx_bool 
pptx_ct_cdr_shape_get_f_published(const pptx_ct_cdr_shape *const obj)
{
    return obj->f_published;
}

int32_t
pptx_ct_cdr_shape_get_index(pptx_ct_cdr_shape *obj)
{
    return obj->index;
}

void
pptx_ct_cdr_shape_free(pptx_ct_cdr_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_cdr_shape_non_visual_free(obj->nv_sp_pr);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_shape_style_free(obj->style);
    pptx_ct_a_text_body_free(obj->tx_body);
    xmlFree(obj->macro);
    xmlFree(obj->textlink);
    free(obj);
}