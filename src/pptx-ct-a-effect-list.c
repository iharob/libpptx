#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-effect-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-blur-effect.h>
#include <private/pptx-ct-a-fill-overlay-effect.h>
#include <private/pptx-ct-a-glow-effect.h>
#include <private/pptx-ct-a-inner-shadow-effect.h>
#include <private/pptx-ct-a-outer-shadow-effect.h>
#include <private/pptx-ct-a-preset-shadow-effect.h>
#include <private/pptx-ct-a-reflection-effect.h>
#include <private/pptx-ct-a-soft-edges-effect.h>

typedef struct pptx_ct_a_effect_list_s {
    pptx_ct_a_blur_effect *blur;
    pptx_ct_a_fill_overlay_effect *fill_overlay;
    pptx_ct_a_glow_effect *glow;
    pptx_ct_a_inner_shadow_effect *inner_shdw;
    pptx_ct_a_outer_shadow_effect *outer_shdw;
    pptx_ct_a_preset_shadow_effect *prst_shdw;
    pptx_ct_a_reflection_effect *reflection;
    pptx_ct_a_soft_edges_effect *soft_edge;
    int32_t index;
} pptx_ct_a_effect_list;

pptx_ct_a_effect_list *
pptx_ct_a_effect_list_new(xmlNode *node)
{
    pptx_ct_a_effect_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blur");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->blur = NULL;
        } else {
            obj->blur = pptx_ct_a_blur_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->blur = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillOverlay");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_overlay = NULL;
        } else {
            obj->fill_overlay = pptx_ct_a_fill_overlay_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_overlay = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:glow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->glow = NULL;
        } else {
            obj->glow = pptx_ct_a_glow_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->glow = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:innerShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->inner_shdw = NULL;
        } else {
            obj->inner_shdw = pptx_ct_a_inner_shadow_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->inner_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:outerShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->outer_shdw = NULL;
        } else {
            obj->outer_shdw = pptx_ct_a_outer_shadow_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->outer_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->prst_shdw = NULL;
        } else {
            obj->prst_shdw = pptx_ct_a_preset_shadow_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->prst_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:reflection");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->reflection = NULL;
        } else {
            obj->reflection = pptx_ct_a_reflection_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->reflection = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:softEdge");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->soft_edge = NULL;
        } else {
            obj->soft_edge = pptx_ct_a_soft_edges_effect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->soft_edge = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_blur_effect *
pptx_ct_a_effect_list_get_blur(const pptx_ct_a_effect_list *const obj)
{
    return obj->blur;
}

pptx_ct_a_fill_overlay_effect *
pptx_ct_a_effect_list_get_fill_overlay(const pptx_ct_a_effect_list *const obj)
{
    return obj->fill_overlay;
}

pptx_ct_a_glow_effect *
pptx_ct_a_effect_list_get_glow(const pptx_ct_a_effect_list *const obj)
{
    return obj->glow;
}

pptx_ct_a_inner_shadow_effect *
pptx_ct_a_effect_list_get_inner_shdw(const pptx_ct_a_effect_list *const obj)
{
    return obj->inner_shdw;
}

pptx_ct_a_outer_shadow_effect *
pptx_ct_a_effect_list_get_outer_shdw(const pptx_ct_a_effect_list *const obj)
{
    return obj->outer_shdw;
}

pptx_ct_a_preset_shadow_effect *
pptx_ct_a_effect_list_get_prst_shdw(const pptx_ct_a_effect_list *const obj)
{
    return obj->prst_shdw;
}

pptx_ct_a_reflection_effect *
pptx_ct_a_effect_list_get_reflection(const pptx_ct_a_effect_list *const obj)
{
    return obj->reflection;
}

pptx_ct_a_soft_edges_effect *
pptx_ct_a_effect_list_get_soft_edge(const pptx_ct_a_effect_list *const obj)
{
    return obj->soft_edge;
}

int32_t
pptx_ct_a_effect_list_get_index(pptx_ct_a_effect_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_effect_list_free(pptx_ct_a_effect_list *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_blur_effect_free(obj->blur);
    pptx_ct_a_fill_overlay_effect_free(obj->fill_overlay);
    pptx_ct_a_glow_effect_free(obj->glow);
    pptx_ct_a_inner_shadow_effect_free(obj->inner_shdw);
    pptx_ct_a_outer_shadow_effect_free(obj->outer_shdw);
    pptx_ct_a_preset_shadow_effect_free(obj->prst_shdw);
    pptx_ct_a_reflection_effect_free(obj->reflection);
    pptx_ct_a_soft_edges_effect_free(obj->soft_edge);
    free(obj);
}