#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-effect-container.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-effect-container.h>
#include <private/pptx-ct-a-effect-reference.h>
#include <private/pptx-ct-a-alpha-bi-level-effect.h>
#include <private/pptx-ct-a-alpha-ceiling-effect.h>
#include <private/pptx-ct-a-alpha-floor-effect.h>
#include <private/pptx-ct-a-alpha-inverse-effect.h>
#include <private/pptx-ct-a-alpha-modulate-effect.h>
#include <private/pptx-ct-a-alpha-modulate-fixed-effect.h>
#include <private/pptx-ct-a-alpha-outset-effect.h>
#include <private/pptx-ct-a-alpha-replace-effect.h>
#include <private/pptx-ct-a-bi-level-effect.h>
#include <private/pptx-ct-a-blend-effect.h>
#include <private/pptx-ct-a-blur-effect.h>
#include <private/pptx-ct-a-color-change-effect.h>
#include <private/pptx-ct-a-color-replace-effect.h>
#include <private/pptx-ct-a-duotone-effect.h>
#include <private/pptx-ct-a-fill-effect.h>
#include <private/pptx-ct-a-fill-overlay-effect.h>
#include <private/pptx-ct-a-glow-effect.h>
#include <private/pptx-ct-a-grayscale-effect.h>
#include <private/pptx-ct-a-hsleffect.h>
#include <private/pptx-ct-a-inner-shadow-effect.h>
#include <private/pptx-ct-a-luminance-effect.h>
#include <private/pptx-ct-a-outer-shadow-effect.h>
#include <private/pptx-ct-a-preset-shadow-effect.h>
#include <private/pptx-ct-a-reflection-effect.h>
#include <private/pptx-ct-a-relative-offset-effect.h>
#include <private/pptx-ct-a-soft-edges-effect.h>
#include <private/pptx-ct-a-tint-effect.h>
#include <private/pptx-ct-a-transform-effect.h>
#include <private/pptx-st-effect-container-type.h>

typedef struct pptx_ct_a_effect_container_s {
    pptx_ct_a_effect_container **effect_cont;
    pptx_ct_a_effect_reference **effect_effect;
    pptx_ct_a_alpha_bi_level_effect **effect_alpha_bi_level;
    pptx_ct_a_alpha_ceiling_effect **effect_alpha_ceiling;
    pptx_ct_a_alpha_floor_effect **effect_alpha_floor;
    pptx_ct_a_alpha_inverse_effect **effect_alpha_inv;
    pptx_ct_a_alpha_modulate_effect **effect_alpha_mod;
    pptx_ct_a_alpha_modulate_fixed_effect **effect_alpha_mod_fix;
    pptx_ct_a_alpha_outset_effect **effect_alpha_outset;
    pptx_ct_a_alpha_replace_effect **effect_alpha_repl;
    pptx_ct_a_bi_level_effect **effect_bi_level;
    pptx_ct_a_blend_effect **effect_blend;
    pptx_ct_a_blur_effect **effect_blur;
    pptx_ct_a_color_change_effect **effect_clr_change;
    pptx_ct_a_color_replace_effect **effect_clr_repl;
    pptx_ct_a_duotone_effect **effect_duotone;
    pptx_ct_a_fill_effect **effect_fill;
    pptx_ct_a_fill_overlay_effect **effect_fill_overlay;
    pptx_ct_a_glow_effect **effect_glow;
    pptx_ct_a_grayscale_effect **effect_grayscl;
    pptx_ct_a_hsleffect **effect_hsl;
    pptx_ct_a_inner_shadow_effect **effect_inner_shdw;
    pptx_ct_a_luminance_effect **effect_lum;
    pptx_ct_a_outer_shadow_effect **effect_outer_shdw;
    pptx_ct_a_preset_shadow_effect **effect_prst_shdw;
    pptx_ct_a_reflection_effect **effect_reflection;
    pptx_ct_a_relative_offset_effect **effect_rel_off;
    pptx_ct_a_soft_edges_effect **effect_soft_edge;
    pptx_ct_a_tint_effect **effect_tint;
    pptx_ct_a_transform_effect **effect_xfrm;
    pptx_st_effect_container_type_token_enum type;
    pptx_string name;
    int32_t index;
} pptx_ct_a_effect_container;

pptx_ct_a_effect_container *
pptx_ct_a_effect_container_new(xmlNode *node)
{
    pptx_ct_a_effect_container *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_cont = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_cont);
            if (obj->effect_cont != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_cont;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_effect_container_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_cont);
                    obj->effect_cont = NULL;
                } else {
                    obj->effect_cont[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_cont = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_cont = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_effect = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_effect);
            if (obj->effect_effect != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_effect;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_effect_reference_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_effect);
                    obj->effect_effect = NULL;
                } else {
                    obj->effect_effect[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_effect = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_effect = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaBiLevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_bi_level = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_bi_level);
            if (obj->effect_alpha_bi_level != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_bi_level;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_bi_level_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_bi_level);
                    obj->effect_alpha_bi_level = NULL;
                } else {
                    obj->effect_alpha_bi_level[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_bi_level = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_bi_level = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaCeiling");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_ceiling = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_ceiling);
            if (obj->effect_alpha_ceiling != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_ceiling;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_ceiling_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_ceiling);
                    obj->effect_alpha_ceiling = NULL;
                } else {
                    obj->effect_alpha_ceiling[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_ceiling = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_ceiling = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaFloor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_floor = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_floor);
            if (obj->effect_alpha_floor != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_floor;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_floor_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_floor);
                    obj->effect_alpha_floor = NULL;
                } else {
                    obj->effect_alpha_floor[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_floor = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_floor = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaInv");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_inv = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_inv);
            if (obj->effect_alpha_inv != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_inv;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_inverse_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_inv);
                    obj->effect_alpha_inv = NULL;
                } else {
                    obj->effect_alpha_inv[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_inv = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_inv = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_mod);
            if (obj->effect_alpha_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_modulate_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_mod);
                    obj->effect_alpha_mod = NULL;
                } else {
                    obj->effect_alpha_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaModFix");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_mod_fix = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_mod_fix);
            if (obj->effect_alpha_mod_fix != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_mod_fix;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_modulate_fixed_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_mod_fix);
                    obj->effect_alpha_mod_fix = NULL;
                } else {
                    obj->effect_alpha_mod_fix[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_mod_fix = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_mod_fix = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaOutset");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_outset = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_outset);
            if (obj->effect_alpha_outset != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_outset;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_outset_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_outset);
                    obj->effect_alpha_outset = NULL;
                } else {
                    obj->effect_alpha_outset[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_outset = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_outset = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaRepl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_alpha_repl = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_alpha_repl);
            if (obj->effect_alpha_repl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_alpha_repl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_replace_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_alpha_repl);
                    obj->effect_alpha_repl = NULL;
                } else {
                    obj->effect_alpha_repl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_alpha_repl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_alpha_repl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:biLevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_bi_level = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_bi_level);
            if (obj->effect_bi_level != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_bi_level;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_bi_level_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_bi_level);
                    obj->effect_bi_level = NULL;
                } else {
                    obj->effect_bi_level[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_bi_level = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_bi_level = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blend");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_blend = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_blend);
            if (obj->effect_blend != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_blend;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_blend_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_blend);
                    obj->effect_blend = NULL;
                } else {
                    obj->effect_blend[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_blend = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_blend = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blur");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_blur = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_blur);
            if (obj->effect_blur != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_blur;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_blur_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_blur);
                    obj->effect_blur = NULL;
                } else {
                    obj->effect_blur[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_blur = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_blur = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrChange");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_clr_change = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_clr_change);
            if (obj->effect_clr_change != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_clr_change;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_color_change_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_clr_change);
                    obj->effect_clr_change = NULL;
                } else {
                    obj->effect_clr_change[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_clr_change = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_clr_change = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrRepl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_clr_repl = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_clr_repl);
            if (obj->effect_clr_repl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_clr_repl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_color_replace_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_clr_repl);
                    obj->effect_clr_repl = NULL;
                } else {
                    obj->effect_clr_repl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_clr_repl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_clr_repl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:duotone");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_duotone = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_duotone);
            if (obj->effect_duotone != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_duotone;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_duotone_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_duotone);
                    obj->effect_duotone = NULL;
                } else {
                    obj->effect_duotone[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_duotone = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_duotone = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_fill);
            if (obj->effect_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_fill_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_fill);
                    obj->effect_fill = NULL;
                } else {
                    obj->effect_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillOverlay");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_fill_overlay = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_fill_overlay);
            if (obj->effect_fill_overlay != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_fill_overlay;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_fill_overlay_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_fill_overlay);
                    obj->effect_fill_overlay = NULL;
                } else {
                    obj->effect_fill_overlay[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_fill_overlay = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_fill_overlay = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:glow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_glow = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_glow);
            if (obj->effect_glow != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_glow;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_glow_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_glow);
                    obj->effect_glow = NULL;
                } else {
                    obj->effect_glow[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_glow = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_glow = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grayscl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_grayscl = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_grayscl);
            if (obj->effect_grayscl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_grayscl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_grayscale_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_grayscl);
                    obj->effect_grayscl = NULL;
                } else {
                    obj->effect_grayscl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_grayscl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_grayscl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hsl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_hsl = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_hsl);
            if (obj->effect_hsl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_hsl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_hsleffect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_hsl);
                    obj->effect_hsl = NULL;
                } else {
                    obj->effect_hsl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_hsl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_hsl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:innerShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_inner_shdw = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_inner_shdw);
            if (obj->effect_inner_shdw != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_inner_shdw;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_inner_shadow_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_inner_shdw);
                    obj->effect_inner_shdw = NULL;
                } else {
                    obj->effect_inner_shdw[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_inner_shdw = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_inner_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lum");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_lum = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_lum);
            if (obj->effect_lum != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_lum;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_luminance_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_lum);
                    obj->effect_lum = NULL;
                } else {
                    obj->effect_lum[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_lum = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_lum = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:outerShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_outer_shdw = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_outer_shdw);
            if (obj->effect_outer_shdw != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_outer_shdw;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_outer_shadow_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_outer_shdw);
                    obj->effect_outer_shdw = NULL;
                } else {
                    obj->effect_outer_shdw[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_outer_shdw = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_outer_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:prstShdw");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_prst_shdw = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_prst_shdw);
            if (obj->effect_prst_shdw != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_prst_shdw;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_preset_shadow_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_prst_shdw);
                    obj->effect_prst_shdw = NULL;
                } else {
                    obj->effect_prst_shdw[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_prst_shdw = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_prst_shdw = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:reflection");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_reflection = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_reflection);
            if (obj->effect_reflection != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_reflection;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_reflection_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_reflection);
                    obj->effect_reflection = NULL;
                } else {
                    obj->effect_reflection[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_reflection = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_reflection = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:relOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_rel_off = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_rel_off);
            if (obj->effect_rel_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_rel_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_relative_offset_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_rel_off);
                    obj->effect_rel_off = NULL;
                } else {
                    obj->effect_rel_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_rel_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_rel_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:softEdge");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_soft_edge = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_soft_edge);
            if (obj->effect_soft_edge != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_soft_edge;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_soft_edges_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_soft_edge);
                    obj->effect_soft_edge = NULL;
                } else {
                    obj->effect_soft_edge[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_soft_edge = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_soft_edge = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tint");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_tint = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_tint);
            if (obj->effect_tint != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_tint;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_tint_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_tint);
                    obj->effect_tint = NULL;
                } else {
                    obj->effect_tint[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_tint = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_tint = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:xfrm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_xfrm = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_xfrm);
            if (obj->effect_xfrm != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_xfrm;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_transform_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->effect_xfrm);
                    obj->effect_xfrm = NULL;
                } else {
                    obj->effect_xfrm[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_xfrm = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_xfrm = NULL;
    }
    obj->type = pptx_get_st_effect_container_type(node, (const xmlChar *) "type");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_effect_container **
pptx_ct_a_effect_container_get_effect_cont(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_cont;
}

pptx_ct_a_effect_reference **
pptx_ct_a_effect_container_get_effect_effect(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_effect;
}

pptx_ct_a_alpha_bi_level_effect **
pptx_ct_a_effect_container_get_effect_alpha_bi_level(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_bi_level;
}

pptx_ct_a_alpha_ceiling_effect **
pptx_ct_a_effect_container_get_effect_alpha_ceiling(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_ceiling;
}

pptx_ct_a_alpha_floor_effect **
pptx_ct_a_effect_container_get_effect_alpha_floor(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_floor;
}

pptx_ct_a_alpha_inverse_effect **
pptx_ct_a_effect_container_get_effect_alpha_inv(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_inv;
}

pptx_ct_a_alpha_modulate_effect **
pptx_ct_a_effect_container_get_effect_alpha_mod(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_mod;
}

pptx_ct_a_alpha_modulate_fixed_effect **
pptx_ct_a_effect_container_get_effect_alpha_mod_fix(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_mod_fix;
}

pptx_ct_a_alpha_outset_effect **
pptx_ct_a_effect_container_get_effect_alpha_outset(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_outset;
}

pptx_ct_a_alpha_replace_effect **
pptx_ct_a_effect_container_get_effect_alpha_repl(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_alpha_repl;
}

pptx_ct_a_bi_level_effect **
pptx_ct_a_effect_container_get_effect_bi_level(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_bi_level;
}

pptx_ct_a_blend_effect **
pptx_ct_a_effect_container_get_effect_blend(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_blend;
}

pptx_ct_a_blur_effect **
pptx_ct_a_effect_container_get_effect_blur(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_blur;
}

pptx_ct_a_color_change_effect **
pptx_ct_a_effect_container_get_effect_clr_change(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_clr_change;
}

pptx_ct_a_color_replace_effect **
pptx_ct_a_effect_container_get_effect_clr_repl(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_clr_repl;
}

pptx_ct_a_duotone_effect **
pptx_ct_a_effect_container_get_effect_duotone(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_duotone;
}

pptx_ct_a_fill_effect **
pptx_ct_a_effect_container_get_effect_fill(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_fill;
}

pptx_ct_a_fill_overlay_effect **
pptx_ct_a_effect_container_get_effect_fill_overlay(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_fill_overlay;
}

pptx_ct_a_glow_effect **
pptx_ct_a_effect_container_get_effect_glow(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_glow;
}

pptx_ct_a_grayscale_effect **
pptx_ct_a_effect_container_get_effect_grayscl(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_grayscl;
}

pptx_ct_a_hsleffect **
pptx_ct_a_effect_container_get_effect_hsl(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_hsl;
}

pptx_ct_a_inner_shadow_effect **
pptx_ct_a_effect_container_get_effect_inner_shdw(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_inner_shdw;
}

pptx_ct_a_luminance_effect **
pptx_ct_a_effect_container_get_effect_lum(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_lum;
}

pptx_ct_a_outer_shadow_effect **
pptx_ct_a_effect_container_get_effect_outer_shdw(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_outer_shdw;
}

pptx_ct_a_preset_shadow_effect **
pptx_ct_a_effect_container_get_effect_prst_shdw(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_prst_shdw;
}

pptx_ct_a_reflection_effect **
pptx_ct_a_effect_container_get_effect_reflection(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_reflection;
}

pptx_ct_a_relative_offset_effect **
pptx_ct_a_effect_container_get_effect_rel_off(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_rel_off;
}

pptx_ct_a_soft_edges_effect **
pptx_ct_a_effect_container_get_effect_soft_edge(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_soft_edge;
}

pptx_ct_a_tint_effect **
pptx_ct_a_effect_container_get_effect_tint(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_tint;
}

pptx_ct_a_transform_effect **
pptx_ct_a_effect_container_get_effect_xfrm(const pptx_ct_a_effect_container *const obj)
{
    return obj->effect_xfrm;
}

pptx_st_effect_container_type_token_enum 
pptx_ct_a_effect_container_get_type(const pptx_ct_a_effect_container *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_a_effect_container_get_name(const pptx_ct_a_effect_container *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_effect_container_get_index(pptx_ct_a_effect_container *obj)
{
    return obj->index;
}

void
pptx_ct_a_effect_container_free(pptx_ct_a_effect_container *obj)
{
    if (obj == NULL)
        return;
    if (obj->effect_cont != NULL) {
        for (int i = 0; obj->effect_cont[i] != NULL; ++i) {
            pptx_ct_a_effect_container_free(obj->effect_cont[i]);
        }
        free(obj->effect_cont);
    }

    if (obj->effect_effect != NULL) {
        for (int i = 0; obj->effect_effect[i] != NULL; ++i) {
            pptx_ct_a_effect_reference_free(obj->effect_effect[i]);
        }
        free(obj->effect_effect);
    }

    if (obj->effect_alpha_bi_level != NULL) {
        for (int i = 0; obj->effect_alpha_bi_level[i] != NULL; ++i) {
            pptx_ct_a_alpha_bi_level_effect_free(obj->effect_alpha_bi_level[i]);
        }
        free(obj->effect_alpha_bi_level);
    }

    if (obj->effect_alpha_ceiling != NULL) {
        for (int i = 0; obj->effect_alpha_ceiling[i] != NULL; ++i) {
            pptx_ct_a_alpha_ceiling_effect_free(obj->effect_alpha_ceiling[i]);
        }
        free(obj->effect_alpha_ceiling);
    }

    if (obj->effect_alpha_floor != NULL) {
        for (int i = 0; obj->effect_alpha_floor[i] != NULL; ++i) {
            pptx_ct_a_alpha_floor_effect_free(obj->effect_alpha_floor[i]);
        }
        free(obj->effect_alpha_floor);
    }

    if (obj->effect_alpha_inv != NULL) {
        for (int i = 0; obj->effect_alpha_inv[i] != NULL; ++i) {
            pptx_ct_a_alpha_inverse_effect_free(obj->effect_alpha_inv[i]);
        }
        free(obj->effect_alpha_inv);
    }

    if (obj->effect_alpha_mod != NULL) {
        for (int i = 0; obj->effect_alpha_mod[i] != NULL; ++i) {
            pptx_ct_a_alpha_modulate_effect_free(obj->effect_alpha_mod[i]);
        }
        free(obj->effect_alpha_mod);
    }

    if (obj->effect_alpha_mod_fix != NULL) {
        for (int i = 0; obj->effect_alpha_mod_fix[i] != NULL; ++i) {
            pptx_ct_a_alpha_modulate_fixed_effect_free(obj->effect_alpha_mod_fix[i]);
        }
        free(obj->effect_alpha_mod_fix);
    }

    if (obj->effect_alpha_outset != NULL) {
        for (int i = 0; obj->effect_alpha_outset[i] != NULL; ++i) {
            pptx_ct_a_alpha_outset_effect_free(obj->effect_alpha_outset[i]);
        }
        free(obj->effect_alpha_outset);
    }

    if (obj->effect_alpha_repl != NULL) {
        for (int i = 0; obj->effect_alpha_repl[i] != NULL; ++i) {
            pptx_ct_a_alpha_replace_effect_free(obj->effect_alpha_repl[i]);
        }
        free(obj->effect_alpha_repl);
    }

    if (obj->effect_bi_level != NULL) {
        for (int i = 0; obj->effect_bi_level[i] != NULL; ++i) {
            pptx_ct_a_bi_level_effect_free(obj->effect_bi_level[i]);
        }
        free(obj->effect_bi_level);
    }

    if (obj->effect_blend != NULL) {
        for (int i = 0; obj->effect_blend[i] != NULL; ++i) {
            pptx_ct_a_blend_effect_free(obj->effect_blend[i]);
        }
        free(obj->effect_blend);
    }

    if (obj->effect_blur != NULL) {
        for (int i = 0; obj->effect_blur[i] != NULL; ++i) {
            pptx_ct_a_blur_effect_free(obj->effect_blur[i]);
        }
        free(obj->effect_blur);
    }

    if (obj->effect_clr_change != NULL) {
        for (int i = 0; obj->effect_clr_change[i] != NULL; ++i) {
            pptx_ct_a_color_change_effect_free(obj->effect_clr_change[i]);
        }
        free(obj->effect_clr_change);
    }

    if (obj->effect_clr_repl != NULL) {
        for (int i = 0; obj->effect_clr_repl[i] != NULL; ++i) {
            pptx_ct_a_color_replace_effect_free(obj->effect_clr_repl[i]);
        }
        free(obj->effect_clr_repl);
    }

    if (obj->effect_duotone != NULL) {
        for (int i = 0; obj->effect_duotone[i] != NULL; ++i) {
            pptx_ct_a_duotone_effect_free(obj->effect_duotone[i]);
        }
        free(obj->effect_duotone);
    }

    if (obj->effect_fill != NULL) {
        for (int i = 0; obj->effect_fill[i] != NULL; ++i) {
            pptx_ct_a_fill_effect_free(obj->effect_fill[i]);
        }
        free(obj->effect_fill);
    }

    if (obj->effect_fill_overlay != NULL) {
        for (int i = 0; obj->effect_fill_overlay[i] != NULL; ++i) {
            pptx_ct_a_fill_overlay_effect_free(obj->effect_fill_overlay[i]);
        }
        free(obj->effect_fill_overlay);
    }

    if (obj->effect_glow != NULL) {
        for (int i = 0; obj->effect_glow[i] != NULL; ++i) {
            pptx_ct_a_glow_effect_free(obj->effect_glow[i]);
        }
        free(obj->effect_glow);
    }

    if (obj->effect_grayscl != NULL) {
        for (int i = 0; obj->effect_grayscl[i] != NULL; ++i) {
            pptx_ct_a_grayscale_effect_free(obj->effect_grayscl[i]);
        }
        free(obj->effect_grayscl);
    }

    if (obj->effect_hsl != NULL) {
        for (int i = 0; obj->effect_hsl[i] != NULL; ++i) {
            pptx_ct_a_hsleffect_free(obj->effect_hsl[i]);
        }
        free(obj->effect_hsl);
    }

    if (obj->effect_inner_shdw != NULL) {
        for (int i = 0; obj->effect_inner_shdw[i] != NULL; ++i) {
            pptx_ct_a_inner_shadow_effect_free(obj->effect_inner_shdw[i]);
        }
        free(obj->effect_inner_shdw);
    }

    if (obj->effect_lum != NULL) {
        for (int i = 0; obj->effect_lum[i] != NULL; ++i) {
            pptx_ct_a_luminance_effect_free(obj->effect_lum[i]);
        }
        free(obj->effect_lum);
    }

    if (obj->effect_outer_shdw != NULL) {
        for (int i = 0; obj->effect_outer_shdw[i] != NULL; ++i) {
            pptx_ct_a_outer_shadow_effect_free(obj->effect_outer_shdw[i]);
        }
        free(obj->effect_outer_shdw);
    }

    if (obj->effect_prst_shdw != NULL) {
        for (int i = 0; obj->effect_prst_shdw[i] != NULL; ++i) {
            pptx_ct_a_preset_shadow_effect_free(obj->effect_prst_shdw[i]);
        }
        free(obj->effect_prst_shdw);
    }

    if (obj->effect_reflection != NULL) {
        for (int i = 0; obj->effect_reflection[i] != NULL; ++i) {
            pptx_ct_a_reflection_effect_free(obj->effect_reflection[i]);
        }
        free(obj->effect_reflection);
    }

    if (obj->effect_rel_off != NULL) {
        for (int i = 0; obj->effect_rel_off[i] != NULL; ++i) {
            pptx_ct_a_relative_offset_effect_free(obj->effect_rel_off[i]);
        }
        free(obj->effect_rel_off);
    }

    if (obj->effect_soft_edge != NULL) {
        for (int i = 0; obj->effect_soft_edge[i] != NULL; ++i) {
            pptx_ct_a_soft_edges_effect_free(obj->effect_soft_edge[i]);
        }
        free(obj->effect_soft_edge);
    }

    if (obj->effect_tint != NULL) {
        for (int i = 0; obj->effect_tint[i] != NULL; ++i) {
            pptx_ct_a_tint_effect_free(obj->effect_tint[i]);
        }
        free(obj->effect_tint);
    }

    if (obj->effect_xfrm != NULL) {
        for (int i = 0; obj->effect_xfrm[i] != NULL; ++i) {
            pptx_ct_a_transform_effect_free(obj->effect_xfrm[i]);
        }
        free(obj->effect_xfrm);
    }

    xmlFree(obj->name);
    free(obj);
}