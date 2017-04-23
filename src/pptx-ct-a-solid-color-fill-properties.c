#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-solid-color-fill-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sc-rgb-color.h>
#include <private/pptx-ct-a-srgb-color.h>
#include <private/pptx-ct-a-hsl-color.h>
#include <private/pptx-ct-a-system-color.h>
#include <private/pptx-ct-a-scheme-color.h>
#include <private/pptx-ct-a-preset-color.h>

typedef struct pptx_ct_a_solid_color_fill_properties_s {
    pptx_ct_a_sc_rgb_color *color_choice_scrgb_clr;
    pptx_ct_a_srgb_color *color_choice_srgb_clr;
    pptx_ct_a_hsl_color *color_choice_hsl_clr;
    pptx_ct_a_system_color *color_choice_sys_clr;
    pptx_ct_a_scheme_color *color_choice_scheme_clr;
    pptx_ct_a_preset_color *color_choice_prst_clr;
    int32_t index;
} pptx_ct_a_solid_color_fill_properties;

pptx_ct_a_solid_color_fill_properties *
pptx_ct_a_solid_color_fill_properties_new(xmlNode *node)
{
    pptx_ct_a_solid_color_fill_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scrgbClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_scrgb_clr = NULL;
        } else {
            obj->color_choice_scrgb_clr = pptx_ct_a_sc_rgb_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scrgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:srgbClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_srgb_clr = NULL;
        } else {
            obj->color_choice_srgb_clr = pptx_ct_a_srgb_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_srgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hslClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_hsl_clr = NULL;
        } else {
            obj->color_choice_hsl_clr = pptx_ct_a_hsl_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_hsl_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sysClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_sys_clr = NULL;
        } else {
            obj->color_choice_sys_clr = pptx_ct_a_system_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_sys_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:schemeClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_scheme_clr = NULL;
        } else {
            obj->color_choice_scheme_clr = pptx_ct_a_scheme_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scheme_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->color_choice_prst_clr = NULL;
        } else {
            obj->color_choice_prst_clr = pptx_ct_a_preset_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_prst_clr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sc_rgb_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_scrgb_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_scrgb_clr;
}

pptx_ct_a_srgb_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_srgb_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_srgb_clr;
}

pptx_ct_a_hsl_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_hsl_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_hsl_clr;
}

pptx_ct_a_system_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_sys_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_sys_clr;
}

pptx_ct_a_scheme_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_scheme_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_scheme_clr;
}

pptx_ct_a_preset_color *
pptx_ct_a_solid_color_fill_properties_get_color_choice_prst_clr(const pptx_ct_a_solid_color_fill_properties *const obj)
{
    return obj->color_choice_prst_clr;
}

int32_t
pptx_ct_a_solid_color_fill_properties_get_index(pptx_ct_a_solid_color_fill_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_solid_color_fill_properties_free(pptx_ct_a_solid_color_fill_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_sc_rgb_color_free(obj->color_choice_scrgb_clr);
    pptx_ct_a_srgb_color_free(obj->color_choice_srgb_clr);
    pptx_ct_a_hsl_color_free(obj->color_choice_hsl_clr);
    pptx_ct_a_system_color_free(obj->color_choice_sys_clr);
    pptx_ct_a_scheme_color_free(obj->color_choice_scheme_clr);
    pptx_ct_a_preset_color_free(obj->color_choice_prst_clr);
    free(obj);
}