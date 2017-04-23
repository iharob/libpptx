#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-blip.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-alpha-bi-level-effect.h>
#include <private/pptx-ct-a-alpha-ceiling-effect.h>
#include <private/pptx-ct-a-alpha-floor-effect.h>
#include <private/pptx-ct-a-alpha-inverse-effect.h>
#include <private/pptx-ct-a-alpha-modulate-effect.h>
#include <private/pptx-ct-a-alpha-modulate-fixed-effect.h>
#include <private/pptx-ct-a-alpha-replace-effect.h>
#include <private/pptx-ct-a-bi-level-effect.h>
#include <private/pptx-ct-a-blur-effect.h>
#include <private/pptx-ct-a-color-change-effect.h>
#include <private/pptx-ct-a-color-replace-effect.h>
#include <private/pptx-ct-a-duotone-effect.h>
#include <private/pptx-ct-a-fill-overlay-effect.h>
#include <private/pptx-ct-a-grayscale-effect.h>
#include <private/pptx-ct-a-hsleffect.h>
#include <private/pptx-ct-a-luminance-effect.h>
#include <private/pptx-ct-a-tint-effect.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-blip-compression.h>

typedef struct pptx_ct_a_blip_s {
    pptx_ct_a_alpha_bi_level_effect **alpha_bi_level;
    pptx_ct_a_alpha_ceiling_effect **alpha_ceiling;
    pptx_ct_a_alpha_floor_effect **alpha_floor;
    pptx_ct_a_alpha_inverse_effect **alpha_inv;
    pptx_ct_a_alpha_modulate_effect **alpha_mod;
    pptx_ct_a_alpha_modulate_fixed_effect **alpha_mod_fix;
    pptx_ct_a_alpha_replace_effect **alpha_repl;
    pptx_ct_a_bi_level_effect **bi_level;
    pptx_ct_a_blur_effect **blur;
    pptx_ct_a_color_change_effect **clr_change;
    pptx_ct_a_color_replace_effect **clr_repl;
    pptx_ct_a_duotone_effect **duotone;
    pptx_ct_a_fill_overlay_effect **fill_overlay;
    pptx_ct_a_grayscale_effect **grayscl;
    pptx_ct_a_hsleffect **hsl;
    pptx_ct_a_luminance_effect **lum;
    pptx_ct_a_tint_effect **tint;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string embed;
    pptx_string link;
    pptx_st_blip_compression_token_enum cstate;
    int32_t index;
} pptx_ct_a_blip;

pptx_ct_a_blip *
pptx_ct_a_blip_new(xmlNode *node)
{
    pptx_ct_a_blip *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaBiLevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_bi_level = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_bi_level);
            if (obj->alpha_bi_level != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_bi_level;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_bi_level_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_bi_level);
                    obj->alpha_bi_level = NULL;
                } else {
                    obj->alpha_bi_level[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_bi_level = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_bi_level = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaCeiling");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_ceiling = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_ceiling);
            if (obj->alpha_ceiling != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_ceiling;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_ceiling_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_ceiling);
                    obj->alpha_ceiling = NULL;
                } else {
                    obj->alpha_ceiling[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_ceiling = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_ceiling = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaFloor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_floor = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_floor);
            if (obj->alpha_floor != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_floor;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_floor_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_floor);
                    obj->alpha_floor = NULL;
                } else {
                    obj->alpha_floor[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_floor = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_floor = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaInv");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_inv = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_inv);
            if (obj->alpha_inv != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_inv;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_inverse_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_inv);
                    obj->alpha_inv = NULL;
                } else {
                    obj->alpha_inv[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_inv = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_inv = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_mod);
            if (obj->alpha_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_modulate_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_mod);
                    obj->alpha_mod = NULL;
                } else {
                    obj->alpha_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaModFix");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_mod_fix = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_mod_fix);
            if (obj->alpha_mod_fix != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_mod_fix;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_modulate_fixed_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_mod_fix);
                    obj->alpha_mod_fix = NULL;
                } else {
                    obj->alpha_mod_fix[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_mod_fix = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_mod_fix = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaRepl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alpha_repl = malloc((nodes->nodeNr + 1) * sizeof *obj->alpha_repl);
            if (obj->alpha_repl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alpha_repl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_alpha_replace_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alpha_repl);
                    obj->alpha_repl = NULL;
                } else {
                    obj->alpha_repl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alpha_repl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alpha_repl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:biLevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bi_level = malloc((nodes->nodeNr + 1) * sizeof *obj->bi_level);
            if (obj->bi_level != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bi_level;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_bi_level_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->bi_level);
                    obj->bi_level = NULL;
                } else {
                    obj->bi_level[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bi_level = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bi_level = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blur");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->blur = malloc((nodes->nodeNr + 1) * sizeof *obj->blur);
            if (obj->blur != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->blur;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_blur_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->blur);
                    obj->blur = NULL;
                } else {
                    obj->blur[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->blur = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->blur = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrChange");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->clr_change = malloc((nodes->nodeNr + 1) * sizeof *obj->clr_change);
            if (obj->clr_change != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->clr_change;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_color_change_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->clr_change);
                    obj->clr_change = NULL;
                } else {
                    obj->clr_change[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->clr_change = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_change = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrRepl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->clr_repl = malloc((nodes->nodeNr + 1) * sizeof *obj->clr_repl);
            if (obj->clr_repl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->clr_repl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_color_replace_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->clr_repl);
                    obj->clr_repl = NULL;
                } else {
                    obj->clr_repl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->clr_repl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_repl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:duotone");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->duotone = malloc((nodes->nodeNr + 1) * sizeof *obj->duotone);
            if (obj->duotone != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->duotone;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_duotone_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->duotone);
                    obj->duotone = NULL;
                } else {
                    obj->duotone[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->duotone = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->duotone = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillOverlay");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_overlay = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_overlay);
            if (obj->fill_overlay != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_overlay;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_fill_overlay_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->fill_overlay);
                    obj->fill_overlay = NULL;
                } else {
                    obj->fill_overlay[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_overlay = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_overlay = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grayscl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->grayscl = malloc((nodes->nodeNr + 1) * sizeof *obj->grayscl);
            if (obj->grayscl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->grayscl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_grayscale_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->grayscl);
                    obj->grayscl = NULL;
                } else {
                    obj->grayscl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->grayscl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grayscl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hsl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->hsl = malloc((nodes->nodeNr + 1) * sizeof *obj->hsl);
            if (obj->hsl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->hsl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_hsleffect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->hsl);
                    obj->hsl = NULL;
                } else {
                    obj->hsl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->hsl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hsl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lum");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->lum = malloc((nodes->nodeNr + 1) * sizeof *obj->lum);
            if (obj->lum != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->lum;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_luminance_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->lum);
                    obj->lum = NULL;
                } else {
                    obj->lum[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->lum = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lum = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tint");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tint = malloc((nodes->nodeNr + 1) * sizeof *obj->tint);
            if (obj->tint != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tint;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_tint_effect_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tint);
                    obj->tint = NULL;
                } else {
                    obj->tint[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tint = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tint = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->embed = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:embed");
    obj->link = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:link");
    obj->cstate = pptx_get_st_blip_compression(node, (const xmlChar *) "cstate");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_alpha_bi_level_effect **
pptx_ct_a_blip_get_alpha_bi_level(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_bi_level;
}

pptx_ct_a_alpha_ceiling_effect **
pptx_ct_a_blip_get_alpha_ceiling(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_ceiling;
}

pptx_ct_a_alpha_floor_effect **
pptx_ct_a_blip_get_alpha_floor(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_floor;
}

pptx_ct_a_alpha_inverse_effect **
pptx_ct_a_blip_get_alpha_inv(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_inv;
}

pptx_ct_a_alpha_modulate_effect **
pptx_ct_a_blip_get_alpha_mod(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_mod;
}

pptx_ct_a_alpha_modulate_fixed_effect **
pptx_ct_a_blip_get_alpha_mod_fix(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_mod_fix;
}

pptx_ct_a_alpha_replace_effect **
pptx_ct_a_blip_get_alpha_repl(const pptx_ct_a_blip *const obj)
{
    return obj->alpha_repl;
}

pptx_ct_a_bi_level_effect **
pptx_ct_a_blip_get_bi_level(const pptx_ct_a_blip *const obj)
{
    return obj->bi_level;
}

pptx_ct_a_blur_effect **
pptx_ct_a_blip_get_blur(const pptx_ct_a_blip *const obj)
{
    return obj->blur;
}

pptx_ct_a_color_change_effect **
pptx_ct_a_blip_get_clr_change(const pptx_ct_a_blip *const obj)
{
    return obj->clr_change;
}

pptx_ct_a_color_replace_effect **
pptx_ct_a_blip_get_clr_repl(const pptx_ct_a_blip *const obj)
{
    return obj->clr_repl;
}

pptx_ct_a_duotone_effect **
pptx_ct_a_blip_get_duotone(const pptx_ct_a_blip *const obj)
{
    return obj->duotone;
}

pptx_ct_a_fill_overlay_effect **
pptx_ct_a_blip_get_fill_overlay(const pptx_ct_a_blip *const obj)
{
    return obj->fill_overlay;
}

pptx_ct_a_grayscale_effect **
pptx_ct_a_blip_get_grayscl(const pptx_ct_a_blip *const obj)
{
    return obj->grayscl;
}

pptx_ct_a_hsleffect **
pptx_ct_a_blip_get_hsl(const pptx_ct_a_blip *const obj)
{
    return obj->hsl;
}

pptx_ct_a_luminance_effect **
pptx_ct_a_blip_get_lum(const pptx_ct_a_blip *const obj)
{
    return obj->lum;
}

pptx_ct_a_tint_effect **
pptx_ct_a_blip_get_tint(const pptx_ct_a_blip *const obj)
{
    return obj->tint;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_blip_get_ext_lst(const pptx_ct_a_blip *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_blip_get_embed(const pptx_ct_a_blip *const obj)
{
    return obj->embed;
}

pptx_string 
pptx_ct_a_blip_get_link(const pptx_ct_a_blip *const obj)
{
    return obj->link;
}

pptx_st_blip_compression_token_enum 
pptx_ct_a_blip_get_cstate(const pptx_ct_a_blip *const obj)
{
    return obj->cstate;
}

int32_t
pptx_ct_a_blip_get_index(pptx_ct_a_blip *obj)
{
    return obj->index;
}

void
pptx_ct_a_blip_free(pptx_ct_a_blip *obj)
{
    if (obj == NULL)
        return;
    if (obj->alpha_bi_level != NULL) {
        for (int i = 0; obj->alpha_bi_level[i] != NULL; ++i) {
            pptx_ct_a_alpha_bi_level_effect_free(obj->alpha_bi_level[i]);
        }
        free(obj->alpha_bi_level);
    }

    if (obj->alpha_ceiling != NULL) {
        for (int i = 0; obj->alpha_ceiling[i] != NULL; ++i) {
            pptx_ct_a_alpha_ceiling_effect_free(obj->alpha_ceiling[i]);
        }
        free(obj->alpha_ceiling);
    }

    if (obj->alpha_floor != NULL) {
        for (int i = 0; obj->alpha_floor[i] != NULL; ++i) {
            pptx_ct_a_alpha_floor_effect_free(obj->alpha_floor[i]);
        }
        free(obj->alpha_floor);
    }

    if (obj->alpha_inv != NULL) {
        for (int i = 0; obj->alpha_inv[i] != NULL; ++i) {
            pptx_ct_a_alpha_inverse_effect_free(obj->alpha_inv[i]);
        }
        free(obj->alpha_inv);
    }

    if (obj->alpha_mod != NULL) {
        for (int i = 0; obj->alpha_mod[i] != NULL; ++i) {
            pptx_ct_a_alpha_modulate_effect_free(obj->alpha_mod[i]);
        }
        free(obj->alpha_mod);
    }

    if (obj->alpha_mod_fix != NULL) {
        for (int i = 0; obj->alpha_mod_fix[i] != NULL; ++i) {
            pptx_ct_a_alpha_modulate_fixed_effect_free(obj->alpha_mod_fix[i]);
        }
        free(obj->alpha_mod_fix);
    }

    if (obj->alpha_repl != NULL) {
        for (int i = 0; obj->alpha_repl[i] != NULL; ++i) {
            pptx_ct_a_alpha_replace_effect_free(obj->alpha_repl[i]);
        }
        free(obj->alpha_repl);
    }

    if (obj->bi_level != NULL) {
        for (int i = 0; obj->bi_level[i] != NULL; ++i) {
            pptx_ct_a_bi_level_effect_free(obj->bi_level[i]);
        }
        free(obj->bi_level);
    }

    if (obj->blur != NULL) {
        for (int i = 0; obj->blur[i] != NULL; ++i) {
            pptx_ct_a_blur_effect_free(obj->blur[i]);
        }
        free(obj->blur);
    }

    if (obj->clr_change != NULL) {
        for (int i = 0; obj->clr_change[i] != NULL; ++i) {
            pptx_ct_a_color_change_effect_free(obj->clr_change[i]);
        }
        free(obj->clr_change);
    }

    if (obj->clr_repl != NULL) {
        for (int i = 0; obj->clr_repl[i] != NULL; ++i) {
            pptx_ct_a_color_replace_effect_free(obj->clr_repl[i]);
        }
        free(obj->clr_repl);
    }

    if (obj->duotone != NULL) {
        for (int i = 0; obj->duotone[i] != NULL; ++i) {
            pptx_ct_a_duotone_effect_free(obj->duotone[i]);
        }
        free(obj->duotone);
    }

    if (obj->fill_overlay != NULL) {
        for (int i = 0; obj->fill_overlay[i] != NULL; ++i) {
            pptx_ct_a_fill_overlay_effect_free(obj->fill_overlay[i]);
        }
        free(obj->fill_overlay);
    }

    if (obj->grayscl != NULL) {
        for (int i = 0; obj->grayscl[i] != NULL; ++i) {
            pptx_ct_a_grayscale_effect_free(obj->grayscl[i]);
        }
        free(obj->grayscl);
    }

    if (obj->hsl != NULL) {
        for (int i = 0; obj->hsl[i] != NULL; ++i) {
            pptx_ct_a_hsleffect_free(obj->hsl[i]);
        }
        free(obj->hsl);
    }

    if (obj->lum != NULL) {
        for (int i = 0; obj->lum[i] != NULL; ++i) {
            pptx_ct_a_luminance_effect_free(obj->lum[i]);
        }
        free(obj->lum);
    }

    if (obj->tint != NULL) {
        for (int i = 0; obj->tint[i] != NULL; ++i) {
            pptx_ct_a_tint_effect_free(obj->tint[i]);
        }
        free(obj->tint);
    }

    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->embed);
    xmlFree(obj->link);
    free(obj);
}