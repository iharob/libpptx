#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-duotone-effect.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sc-rgb-color.h>
#include <private/pptx-ct-a-srgb-color.h>
#include <private/pptx-ct-a-hsl-color.h>
#include <private/pptx-ct-a-system-color.h>
#include <private/pptx-ct-a-scheme-color.h>
#include <private/pptx-ct-a-preset-color.h>

typedef struct pptx_ct_a_duotone_effect_s {
    pptx_ct_a_sc_rgb_color **color_choice_scrgb_clr;
    pptx_ct_a_srgb_color **color_choice_srgb_clr;
    pptx_ct_a_hsl_color **color_choice_hsl_clr;
    pptx_ct_a_system_color **color_choice_sys_clr;
    pptx_ct_a_scheme_color **color_choice_scheme_clr;
    pptx_ct_a_preset_color **color_choice_prst_clr;
    int32_t index;
} pptx_ct_a_duotone_effect;

pptx_ct_a_duotone_effect *
pptx_ct_a_duotone_effect_new(xmlNode *node)
{
    pptx_ct_a_duotone_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sc_rgb_color **
pptx_ct_a_duotone_effect_get_color_choice_scrgb_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_scrgb_clr;
}

pptx_ct_a_srgb_color **
pptx_ct_a_duotone_effect_get_color_choice_srgb_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_srgb_clr;
}

pptx_ct_a_hsl_color **
pptx_ct_a_duotone_effect_get_color_choice_hsl_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_hsl_clr;
}

pptx_ct_a_system_color **
pptx_ct_a_duotone_effect_get_color_choice_sys_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_sys_clr;
}

pptx_ct_a_scheme_color **
pptx_ct_a_duotone_effect_get_color_choice_scheme_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_scheme_clr;
}

pptx_ct_a_preset_color **
pptx_ct_a_duotone_effect_get_color_choice_prst_clr(const pptx_ct_a_duotone_effect *const obj)
{
    return obj->color_choice_prst_clr;
}

int32_t
pptx_ct_a_duotone_effect_get_index(pptx_ct_a_duotone_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_duotone_effect_free(pptx_ct_a_duotone_effect *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}