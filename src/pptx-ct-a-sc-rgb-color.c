#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-sc-rgb-color.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-positive-fixed-percentage.h>
#include <private/pptx-ct-a-complement-transform.h>
#include <private/pptx-ct-a-inverse-transform.h>
#include <private/pptx-ct-a-grayscale-transform.h>
#include <private/pptx-ct-a-fixed-percentage.h>
#include <private/pptx-ct-a-positive-percentage.h>
#include <private/pptx-ct-a-positive-fixed-angle.h>
#include <private/pptx-ct-a-angle.h>
#include <private/pptx-ct-a-percentage.h>
#include <private/pptx-ct-a-gamma-transform.h>
#include <private/pptx-ct-a-inverse-gamma-transform.h>

typedef struct pptx_ct_a_sc_rgb_color_s {
    pptx_ct_a_positive_fixed_percentage **color_transform_tint;
    pptx_ct_a_positive_fixed_percentage **color_transform_shade;
    pptx_ct_a_complement_transform **color_transform_comp;
    pptx_ct_a_inverse_transform **color_transform_inv;
    pptx_ct_a_grayscale_transform **color_transform_gray;
    pptx_ct_a_positive_fixed_percentage **color_transform_alpha;
    pptx_ct_a_fixed_percentage **color_transform_alpha_off;
    pptx_ct_a_positive_percentage **color_transform_alpha_mod;
    pptx_ct_a_positive_fixed_angle **color_transform_hue;
    pptx_ct_a_angle **color_transform_hue_off;
    pptx_ct_a_positive_percentage **color_transform_hue_mod;
    pptx_ct_a_percentage **color_transform_sat;
    pptx_ct_a_percentage **color_transform_sat_off;
    pptx_ct_a_percentage **color_transform_sat_mod;
    pptx_ct_a_percentage **color_transform_lum;
    pptx_ct_a_percentage **color_transform_lum_off;
    pptx_ct_a_percentage **color_transform_lum_mod;
    pptx_ct_a_percentage **color_transform_red;
    pptx_ct_a_percentage **color_transform_red_off;
    pptx_ct_a_percentage **color_transform_red_mod;
    pptx_ct_a_percentage **color_transform_green;
    pptx_ct_a_percentage **color_transform_green_off;
    pptx_ct_a_percentage **color_transform_green_mod;
    pptx_ct_a_percentage **color_transform_blue;
    pptx_ct_a_percentage **color_transform_blue_off;
    pptx_ct_a_percentage **color_transform_blue_mod;
    pptx_ct_a_gamma_transform **color_transform_gamma;
    pptx_ct_a_inverse_gamma_transform **color_transform_inv_gamma;
    pptx_string r;
    pptx_string g;
    pptx_string b;
    int32_t index;
} pptx_ct_a_sc_rgb_color;

pptx_ct_a_sc_rgb_color *
pptx_ct_a_sc_rgb_color_new(xmlNode *node)
{
    pptx_ct_a_sc_rgb_color *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tint");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_tint = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_tint);
            if (obj->color_transform_tint != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_tint;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_fixed_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_tint);
                    obj->color_transform_tint = NULL;
                } else {
                    obj->color_transform_tint[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_tint = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_tint = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:shade");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_shade = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_shade);
            if (obj->color_transform_shade != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_shade;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_fixed_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_shade);
                    obj->color_transform_shade = NULL;
                } else {
                    obj->color_transform_shade[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_shade = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_shade = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:comp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_comp = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_comp);
            if (obj->color_transform_comp != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_comp;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_complement_transform_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_comp);
                    obj->color_transform_comp = NULL;
                } else {
                    obj->color_transform_comp[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_comp = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_comp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:inv");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_inv = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_inv);
            if (obj->color_transform_inv != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_inv;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_inverse_transform_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_inv);
                    obj->color_transform_inv = NULL;
                } else {
                    obj->color_transform_inv[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_inv = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_inv = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gray");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_gray = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_gray);
            if (obj->color_transform_gray != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_gray;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_grayscale_transform_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_gray);
                    obj->color_transform_gray = NULL;
                } else {
                    obj->color_transform_gray[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_gray = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_gray = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alpha");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_alpha = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_alpha);
            if (obj->color_transform_alpha != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_alpha;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_fixed_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_alpha);
                    obj->color_transform_alpha = NULL;
                } else {
                    obj->color_transform_alpha[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_alpha = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_alpha = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_alpha_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_alpha_off);
            if (obj->color_transform_alpha_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_alpha_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_fixed_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_alpha_off);
                    obj->color_transform_alpha_off = NULL;
                } else {
                    obj->color_transform_alpha_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_alpha_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_alpha_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:alphaMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_alpha_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_alpha_mod);
            if (obj->color_transform_alpha_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_alpha_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_alpha_mod);
                    obj->color_transform_alpha_mod = NULL;
                } else {
                    obj->color_transform_alpha_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_alpha_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_alpha_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hue");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_hue = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_hue);
            if (obj->color_transform_hue != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_hue;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_fixed_angle_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_hue);
                    obj->color_transform_hue = NULL;
                } else {
                    obj->color_transform_hue[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_hue = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_hue = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hueOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_hue_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_hue_off);
            if (obj->color_transform_hue_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_hue_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_angle_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_hue_off);
                    obj->color_transform_hue_off = NULL;
                } else {
                    obj->color_transform_hue_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_hue_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_hue_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hueMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_hue_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_hue_mod);
            if (obj->color_transform_hue_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_hue_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_positive_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_hue_mod);
                    obj->color_transform_hue_mod = NULL;
                } else {
                    obj->color_transform_hue_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_hue_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_hue_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sat");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_sat = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_sat);
            if (obj->color_transform_sat != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_sat;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_sat);
                    obj->color_transform_sat = NULL;
                } else {
                    obj->color_transform_sat[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_sat = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_sat = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:satOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_sat_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_sat_off);
            if (obj->color_transform_sat_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_sat_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_sat_off);
                    obj->color_transform_sat_off = NULL;
                } else {
                    obj->color_transform_sat_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_sat_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_sat_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:satMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_sat_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_sat_mod);
            if (obj->color_transform_sat_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_sat_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_sat_mod);
                    obj->color_transform_sat_mod = NULL;
                } else {
                    obj->color_transform_sat_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_sat_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_sat_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lum");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_lum = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_lum);
            if (obj->color_transform_lum != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_lum;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_lum);
                    obj->color_transform_lum = NULL;
                } else {
                    obj->color_transform_lum[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_lum = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_lum = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lumOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_lum_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_lum_off);
            if (obj->color_transform_lum_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_lum_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_lum_off);
                    obj->color_transform_lum_off = NULL;
                } else {
                    obj->color_transform_lum_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_lum_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_lum_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lumMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_lum_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_lum_mod);
            if (obj->color_transform_lum_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_lum_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_lum_mod);
                    obj->color_transform_lum_mod = NULL;
                } else {
                    obj->color_transform_lum_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_lum_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_lum_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:red");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_red = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_red);
            if (obj->color_transform_red != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_red;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_red);
                    obj->color_transform_red = NULL;
                } else {
                    obj->color_transform_red[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_red = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_red = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:redOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_red_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_red_off);
            if (obj->color_transform_red_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_red_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_red_off);
                    obj->color_transform_red_off = NULL;
                } else {
                    obj->color_transform_red_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_red_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_red_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:redMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_red_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_red_mod);
            if (obj->color_transform_red_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_red_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_red_mod);
                    obj->color_transform_red_mod = NULL;
                } else {
                    obj->color_transform_red_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_red_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_red_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:green");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_green = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_green);
            if (obj->color_transform_green != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_green;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_green);
                    obj->color_transform_green = NULL;
                } else {
                    obj->color_transform_green[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_green = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_green = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:greenOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_green_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_green_off);
            if (obj->color_transform_green_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_green_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_green_off);
                    obj->color_transform_green_off = NULL;
                } else {
                    obj->color_transform_green_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_green_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_green_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:greenMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_green_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_green_mod);
            if (obj->color_transform_green_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_green_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_green_mod);
                    obj->color_transform_green_mod = NULL;
                } else {
                    obj->color_transform_green_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_green_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_green_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blue");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_blue = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_blue);
            if (obj->color_transform_blue != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_blue;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_blue);
                    obj->color_transform_blue = NULL;
                } else {
                    obj->color_transform_blue[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_blue = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_blue = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blueOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_blue_off = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_blue_off);
            if (obj->color_transform_blue_off != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_blue_off;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_blue_off);
                    obj->color_transform_blue_off = NULL;
                } else {
                    obj->color_transform_blue_off[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_blue_off = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_blue_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blueMod");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_blue_mod = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_blue_mod);
            if (obj->color_transform_blue_mod != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_blue_mod;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_percentage_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_blue_mod);
                    obj->color_transform_blue_mod = NULL;
                } else {
                    obj->color_transform_blue_mod[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_blue_mod = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_blue_mod = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gamma");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_gamma = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_gamma);
            if (obj->color_transform_gamma != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_gamma;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_gamma_transform_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_gamma);
                    obj->color_transform_gamma = NULL;
                } else {
                    obj->color_transform_gamma[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_gamma = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_gamma = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:invGamma");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->color_transform_inv_gamma = malloc((nodes->nodeNr + 1) * sizeof *obj->color_transform_inv_gamma);
            if (obj->color_transform_inv_gamma != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->color_transform_inv_gamma;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_inverse_gamma_transform_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->color_transform_inv_gamma);
                    obj->color_transform_inv_gamma = NULL;
                } else {
                    obj->color_transform_inv_gamma[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->color_transform_inv_gamma = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->color_transform_inv_gamma = NULL;
    }
    obj->r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r");
    obj->g = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "g");
    obj->b = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "b");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_positive_fixed_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_tint(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_tint;
}

pptx_ct_a_positive_fixed_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_shade(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_shade;
}

pptx_ct_a_complement_transform **
pptx_ct_a_sc_rgb_color_get_color_transform_comp(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_comp;
}

pptx_ct_a_inverse_transform **
pptx_ct_a_sc_rgb_color_get_color_transform_inv(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_inv;
}

pptx_ct_a_grayscale_transform **
pptx_ct_a_sc_rgb_color_get_color_transform_gray(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_gray;
}

pptx_ct_a_positive_fixed_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_alpha(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_alpha;
}

pptx_ct_a_fixed_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_alpha_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_alpha_off;
}

pptx_ct_a_positive_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_alpha_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_alpha_mod;
}

pptx_ct_a_positive_fixed_angle **
pptx_ct_a_sc_rgb_color_get_color_transform_hue(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_hue;
}

pptx_ct_a_angle **
pptx_ct_a_sc_rgb_color_get_color_transform_hue_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_hue_off;
}

pptx_ct_a_positive_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_hue_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_hue_mod;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_sat(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_sat;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_sat_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_sat_off;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_sat_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_sat_mod;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_lum(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_lum;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_lum_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_lum_off;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_lum_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_lum_mod;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_red(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_red;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_red_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_red_off;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_red_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_red_mod;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_green(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_green;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_green_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_green_off;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_green_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_green_mod;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_blue(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_blue;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_blue_off(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_blue_off;
}

pptx_ct_a_percentage **
pptx_ct_a_sc_rgb_color_get_color_transform_blue_mod(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_blue_mod;
}

pptx_ct_a_gamma_transform **
pptx_ct_a_sc_rgb_color_get_color_transform_gamma(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_gamma;
}

pptx_ct_a_inverse_gamma_transform **
pptx_ct_a_sc_rgb_color_get_color_transform_inv_gamma(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->color_transform_inv_gamma;
}

pptx_string 
pptx_ct_a_sc_rgb_color_get_r(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->r;
}

pptx_string 
pptx_ct_a_sc_rgb_color_get_g(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->g;
}

pptx_string 
pptx_ct_a_sc_rgb_color_get_b(const pptx_ct_a_sc_rgb_color *const obj)
{
    return obj->b;
}

int32_t
pptx_ct_a_sc_rgb_color_get_index(pptx_ct_a_sc_rgb_color *obj)
{
    return obj->index;
}

void
pptx_ct_a_sc_rgb_color_free(pptx_ct_a_sc_rgb_color *obj)
{
    if (obj == NULL)
        return;
    if (obj->color_transform_tint != NULL) {
        for (int i = 0; obj->color_transform_tint[i] != NULL; ++i) {
            pptx_ct_a_positive_fixed_percentage_free(obj->color_transform_tint[i]);
        }
        free(obj->color_transform_tint);
    }

    if (obj->color_transform_shade != NULL) {
        for (int i = 0; obj->color_transform_shade[i] != NULL; ++i) {
            pptx_ct_a_positive_fixed_percentage_free(obj->color_transform_shade[i]);
        }
        free(obj->color_transform_shade);
    }

    if (obj->color_transform_comp != NULL) {
        for (int i = 0; obj->color_transform_comp[i] != NULL; ++i) {
            pptx_ct_a_complement_transform_free(obj->color_transform_comp[i]);
        }
        free(obj->color_transform_comp);
    }

    if (obj->color_transform_inv != NULL) {
        for (int i = 0; obj->color_transform_inv[i] != NULL; ++i) {
            pptx_ct_a_inverse_transform_free(obj->color_transform_inv[i]);
        }
        free(obj->color_transform_inv);
    }

    if (obj->color_transform_gray != NULL) {
        for (int i = 0; obj->color_transform_gray[i] != NULL; ++i) {
            pptx_ct_a_grayscale_transform_free(obj->color_transform_gray[i]);
        }
        free(obj->color_transform_gray);
    }

    if (obj->color_transform_alpha != NULL) {
        for (int i = 0; obj->color_transform_alpha[i] != NULL; ++i) {
            pptx_ct_a_positive_fixed_percentage_free(obj->color_transform_alpha[i]);
        }
        free(obj->color_transform_alpha);
    }

    if (obj->color_transform_alpha_off != NULL) {
        for (int i = 0; obj->color_transform_alpha_off[i] != NULL; ++i) {
            pptx_ct_a_fixed_percentage_free(obj->color_transform_alpha_off[i]);
        }
        free(obj->color_transform_alpha_off);
    }

    if (obj->color_transform_alpha_mod != NULL) {
        for (int i = 0; obj->color_transform_alpha_mod[i] != NULL; ++i) {
            pptx_ct_a_positive_percentage_free(obj->color_transform_alpha_mod[i]);
        }
        free(obj->color_transform_alpha_mod);
    }

    if (obj->color_transform_hue != NULL) {
        for (int i = 0; obj->color_transform_hue[i] != NULL; ++i) {
            pptx_ct_a_positive_fixed_angle_free(obj->color_transform_hue[i]);
        }
        free(obj->color_transform_hue);
    }

    if (obj->color_transform_hue_off != NULL) {
        for (int i = 0; obj->color_transform_hue_off[i] != NULL; ++i) {
            pptx_ct_a_angle_free(obj->color_transform_hue_off[i]);
        }
        free(obj->color_transform_hue_off);
    }

    if (obj->color_transform_hue_mod != NULL) {
        for (int i = 0; obj->color_transform_hue_mod[i] != NULL; ++i) {
            pptx_ct_a_positive_percentage_free(obj->color_transform_hue_mod[i]);
        }
        free(obj->color_transform_hue_mod);
    }

    if (obj->color_transform_sat != NULL) {
        for (int i = 0; obj->color_transform_sat[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_sat[i]);
        }
        free(obj->color_transform_sat);
    }

    if (obj->color_transform_sat_off != NULL) {
        for (int i = 0; obj->color_transform_sat_off[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_sat_off[i]);
        }
        free(obj->color_transform_sat_off);
    }

    if (obj->color_transform_sat_mod != NULL) {
        for (int i = 0; obj->color_transform_sat_mod[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_sat_mod[i]);
        }
        free(obj->color_transform_sat_mod);
    }

    if (obj->color_transform_lum != NULL) {
        for (int i = 0; obj->color_transform_lum[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_lum[i]);
        }
        free(obj->color_transform_lum);
    }

    if (obj->color_transform_lum_off != NULL) {
        for (int i = 0; obj->color_transform_lum_off[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_lum_off[i]);
        }
        free(obj->color_transform_lum_off);
    }

    if (obj->color_transform_lum_mod != NULL) {
        for (int i = 0; obj->color_transform_lum_mod[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_lum_mod[i]);
        }
        free(obj->color_transform_lum_mod);
    }

    if (obj->color_transform_red != NULL) {
        for (int i = 0; obj->color_transform_red[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_red[i]);
        }
        free(obj->color_transform_red);
    }

    if (obj->color_transform_red_off != NULL) {
        for (int i = 0; obj->color_transform_red_off[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_red_off[i]);
        }
        free(obj->color_transform_red_off);
    }

    if (obj->color_transform_red_mod != NULL) {
        for (int i = 0; obj->color_transform_red_mod[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_red_mod[i]);
        }
        free(obj->color_transform_red_mod);
    }

    if (obj->color_transform_green != NULL) {
        for (int i = 0; obj->color_transform_green[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_green[i]);
        }
        free(obj->color_transform_green);
    }

    if (obj->color_transform_green_off != NULL) {
        for (int i = 0; obj->color_transform_green_off[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_green_off[i]);
        }
        free(obj->color_transform_green_off);
    }

    if (obj->color_transform_green_mod != NULL) {
        for (int i = 0; obj->color_transform_green_mod[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_green_mod[i]);
        }
        free(obj->color_transform_green_mod);
    }

    if (obj->color_transform_blue != NULL) {
        for (int i = 0; obj->color_transform_blue[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_blue[i]);
        }
        free(obj->color_transform_blue);
    }

    if (obj->color_transform_blue_off != NULL) {
        for (int i = 0; obj->color_transform_blue_off[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_blue_off[i]);
        }
        free(obj->color_transform_blue_off);
    }

    if (obj->color_transform_blue_mod != NULL) {
        for (int i = 0; obj->color_transform_blue_mod[i] != NULL; ++i) {
            pptx_ct_a_percentage_free(obj->color_transform_blue_mod[i]);
        }
        free(obj->color_transform_blue_mod);
    }

    if (obj->color_transform_gamma != NULL) {
        for (int i = 0; obj->color_transform_gamma[i] != NULL; ++i) {
            pptx_ct_a_gamma_transform_free(obj->color_transform_gamma[i]);
        }
        free(obj->color_transform_gamma);
    }

    if (obj->color_transform_inv_gamma != NULL) {
        for (int i = 0; obj->color_transform_inv_gamma[i] != NULL; ++i) {
            pptx_ct_a_inverse_gamma_transform_free(obj->color_transform_inv_gamma[i]);
        }
        free(obj->color_transform_inv_gamma);
    }

    xmlFree(obj->r);
    xmlFree(obj->g);
    xmlFree(obj->b);
    free(obj);
}