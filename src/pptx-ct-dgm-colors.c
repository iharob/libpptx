#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-colors.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sc-rgb-color.h>
#include <private/pptx-ct-a-srgb-color.h>
#include <private/pptx-ct-a-hsl-color.h>
#include <private/pptx-ct-a-system-color.h>
#include <private/pptx-ct-a-scheme-color.h>
#include <private/pptx-ct-a-preset-color.h>
#include <private/pptx-st-clr-app-method.h>
#include <private/pptx-st-hue-dir.h>

typedef struct pptx_ct_dgm_colors_s {
    pptx_ct_a_sc_rgb_color **color_choice_scrgb_clr;
    pptx_ct_a_srgb_color **color_choice_srgb_clr;
    pptx_ct_a_hsl_color **color_choice_hsl_clr;
    pptx_ct_a_system_color **color_choice_sys_clr;
    pptx_ct_a_scheme_color **color_choice_scheme_clr;
    pptx_ct_a_preset_color **color_choice_prst_clr;
    pptx_st_clr_app_method_token_enum meth;
    pptx_st_hue_dir_token_enum hue_dir;
    int32_t index;
} pptx_ct_dgm_colors;

pptx_ct_dgm_colors *
pptx_ct_dgm_colors_new(xmlNode *node)
{
    pptx_ct_dgm_colors *obj;
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
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_scrgb_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_scrgb_clr);
            if (obj->color_choice_scrgb_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_scrgb_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_sc_rgb_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_scrgb_clr);
                    obj->color_choice_scrgb_clr = NULL;
                } else {
                    obj->color_choice_scrgb_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_scrgb_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scrgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:srgbClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_srgb_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_srgb_clr);
            if (obj->color_choice_srgb_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_srgb_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_srgb_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_srgb_clr);
                    obj->color_choice_srgb_clr = NULL;
                } else {
                    obj->color_choice_srgb_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_srgb_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_srgb_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hslClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_hsl_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_hsl_clr);
            if (obj->color_choice_hsl_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_hsl_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_hsl_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_hsl_clr);
                    obj->color_choice_hsl_clr = NULL;
                } else {
                    obj->color_choice_hsl_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_hsl_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_hsl_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sysClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_sys_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_sys_clr);
            if (obj->color_choice_sys_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_sys_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_system_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_sys_clr);
                    obj->color_choice_sys_clr = NULL;
                } else {
                    obj->color_choice_sys_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_sys_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_sys_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:schemeClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_scheme_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_scheme_clr);
            if (obj->color_choice_scheme_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_scheme_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_scheme_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_scheme_clr);
                    obj->color_choice_scheme_clr = NULL;
                } else {
                    obj->color_choice_scheme_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_scheme_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_scheme_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_choice_prst_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->color_choice_prst_clr);
            if (obj->color_choice_prst_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_choice_prst_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_preset_color_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_choice_prst_clr);
                    obj->color_choice_prst_clr = NULL;
                } else {
                    obj->color_choice_prst_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_choice_prst_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_choice_prst_clr = NULL;
    }
    obj->meth = pptx_get_st_clr_app_method(node, (const xmlChar *) "meth");
    obj->hue_dir = pptx_get_st_hue_dir(node, (const xmlChar *) "hueDir");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sc_rgb_color **
pptx_ct_dgm_colors_get_color_choice_scrgb_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_scrgb_clr;
}

pptx_ct_a_srgb_color **
pptx_ct_dgm_colors_get_color_choice_srgb_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_srgb_clr;
}

pptx_ct_a_hsl_color **
pptx_ct_dgm_colors_get_color_choice_hsl_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_hsl_clr;
}

pptx_ct_a_system_color **
pptx_ct_dgm_colors_get_color_choice_sys_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_sys_clr;
}

pptx_ct_a_scheme_color **
pptx_ct_dgm_colors_get_color_choice_scheme_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_scheme_clr;
}

pptx_ct_a_preset_color **
pptx_ct_dgm_colors_get_color_choice_prst_clr(const pptx_ct_dgm_colors *const obj)
{
    return obj->color_choice_prst_clr;
}

pptx_st_clr_app_method_token_enum 
pptx_ct_dgm_colors_get_meth(const pptx_ct_dgm_colors *const obj)
{
    return obj->meth;
}

pptx_st_hue_dir_token_enum 
pptx_ct_dgm_colors_get_hue_dir(const pptx_ct_dgm_colors *const obj)
{
    return obj->hue_dir;
}

int32_t
pptx_ct_dgm_colors_get_index(pptx_ct_dgm_colors *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_colors_free(pptx_ct_dgm_colors *obj)
{
    if (obj == NULL)
        return;
    if (obj->color_choice_scrgb_clr != NULL) {
        for (int i = 0; obj->color_choice_scrgb_clr[i] != NULL; ++i) {
            pptx_ct_a_sc_rgb_color_free(obj->color_choice_scrgb_clr[i]);
        }
        free(obj->color_choice_scrgb_clr);
    }

    if (obj->color_choice_srgb_clr != NULL) {
        for (int i = 0; obj->color_choice_srgb_clr[i] != NULL; ++i) {
            pptx_ct_a_srgb_color_free(obj->color_choice_srgb_clr[i]);
        }
        free(obj->color_choice_srgb_clr);
    }

    if (obj->color_choice_hsl_clr != NULL) {
        for (int i = 0; obj->color_choice_hsl_clr[i] != NULL; ++i) {
            pptx_ct_a_hsl_color_free(obj->color_choice_hsl_clr[i]);
        }
        free(obj->color_choice_hsl_clr);
    }

    if (obj->color_choice_sys_clr != NULL) {
        for (int i = 0; obj->color_choice_sys_clr[i] != NULL; ++i) {
            pptx_ct_a_system_color_free(obj->color_choice_sys_clr[i]);
        }
        free(obj->color_choice_sys_clr);
    }

    if (obj->color_choice_scheme_clr != NULL) {
        for (int i = 0; obj->color_choice_scheme_clr[i] != NULL; ++i) {
            pptx_ct_a_scheme_color_free(obj->color_choice_scheme_clr[i]);
        }
        free(obj->color_choice_scheme_clr);
    }

    if (obj->color_choice_prst_clr != NULL) {
        for (int i = 0; obj->color_choice_prst_clr[i] != NULL; ++i) {
            pptx_ct_a_preset_color_free(obj->color_choice_prst_clr[i]);
        }
        free(obj->color_choice_prst_clr);
    }

    free(obj);
}