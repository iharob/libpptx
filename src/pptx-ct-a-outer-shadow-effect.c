#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-outer-shadow-effect.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sc-rgb-color.h>
#include <private/pptx-ct-a-srgb-color.h>
#include <private/pptx-ct-a-hsl-color.h>
#include <private/pptx-ct-a-system-color.h>
#include <private/pptx-ct-a-scheme-color.h>
#include <private/pptx-ct-a-preset-color.h>
#include <private/pptx-st-rect-alignment.h>

typedef struct pptx_ct_a_outer_shadow_effect_s {
    pptx_ct_a_sc_rgb_color *color_choice_scrgb_clr;
    pptx_ct_a_srgb_color *color_choice_srgb_clr;
    pptx_ct_a_hsl_color *color_choice_hsl_clr;
    pptx_ct_a_system_color *color_choice_sys_clr;
    pptx_ct_a_scheme_color *color_choice_scheme_clr;
    pptx_ct_a_preset_color *color_choice_prst_clr;
    pptx_long blur_rad;
    pptx_long dist;
    pptx_int dir;
    pptx_string sx;
    pptx_string sy;
    pptx_int kx;
    pptx_int ky;
    pptx_st_rect_alignment_token_enum algn;
    pptx_bool rot_with_shape;
    int32_t index;
} pptx_ct_a_outer_shadow_effect;

pptx_ct_a_outer_shadow_effect *
pptx_ct_a_outer_shadow_effect_new(xmlNode *node)
{
    pptx_ct_a_outer_shadow_effect *obj;
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
    obj->blur_rad = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "blurRad");
    obj->dist = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "dist");
    obj->dir = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "dir");
    obj->sx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sx");
    obj->sy = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sy");
    obj->kx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "kx");
    obj->ky = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "ky");
    obj->algn = pptx_get_st_rect_alignment(node, (const xmlChar *) "algn");
    obj->rot_with_shape = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rotWithShape");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sc_rgb_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_scrgb_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_scrgb_clr;
}

pptx_ct_a_srgb_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_srgb_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_srgb_clr;
}

pptx_ct_a_hsl_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_hsl_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_hsl_clr;
}

pptx_ct_a_system_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_sys_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_sys_clr;
}

pptx_ct_a_scheme_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_scheme_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_scheme_clr;
}

pptx_ct_a_preset_color *
pptx_ct_a_outer_shadow_effect_get_color_choice_prst_clr(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->color_choice_prst_clr;
}

pptx_long 
pptx_ct_a_outer_shadow_effect_get_blur_rad(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->blur_rad;
}

pptx_long 
pptx_ct_a_outer_shadow_effect_get_dist(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->dist;
}

pptx_int 
pptx_ct_a_outer_shadow_effect_get_dir(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->dir;
}

pptx_string 
pptx_ct_a_outer_shadow_effect_get_sx(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->sx;
}

pptx_string 
pptx_ct_a_outer_shadow_effect_get_sy(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->sy;
}

pptx_int 
pptx_ct_a_outer_shadow_effect_get_kx(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->kx;
}

pptx_int 
pptx_ct_a_outer_shadow_effect_get_ky(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->ky;
}

pptx_st_rect_alignment_token_enum 
pptx_ct_a_outer_shadow_effect_get_algn(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->algn;
}

pptx_bool 
pptx_ct_a_outer_shadow_effect_get_rot_with_shape(const pptx_ct_a_outer_shadow_effect *const obj)
{
    return obj->rot_with_shape;
}

int32_t
pptx_ct_a_outer_shadow_effect_get_index(pptx_ct_a_outer_shadow_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_outer_shadow_effect_free(pptx_ct_a_outer_shadow_effect *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_sc_rgb_color_free(obj->color_choice_scrgb_clr);
    pptx_ct_a_srgb_color_free(obj->color_choice_srgb_clr);
    pptx_ct_a_hsl_color_free(obj->color_choice_hsl_clr);
    pptx_ct_a_system_color_free(obj->color_choice_sys_clr);
    pptx_ct_a_scheme_color_free(obj->color_choice_scheme_clr);
    pptx_ct_a_preset_color_free(obj->color_choice_prst_clr);
    xmlFree(obj->sx);
    xmlFree(obj->sy);
    free(obj);
}