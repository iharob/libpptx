#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-transition.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-orientation-transition.h>
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-p-eight-direction-transition.h>
#include <private/pptx-ct-p-optional-black-transition.h>
#include <private/pptx-ct-p-side-direction-transition.h>
#include <private/pptx-ct-p-split-transition.h>
#include <private/pptx-ct-p-corner-direction-transition.h>
#include <private/pptx-ct-p-wheel-transition.h>
#include <private/pptx-ct-p-in-out-transition.h>
#include <private/pptx-ct-p-transition-sound-action.h>
#include <private/pptx-ct-p-extension-list-modify.h>
#include <private/pptx-st-transition-speed.h>

typedef struct pptx_ct_p_slide_transition_s {
    pptx_ct_p_orientation_transition *blinds;
    pptx_ct_p_orientation_transition *checker;
    pptx_ct_p_empty *circle;
    pptx_ct_p_empty *dissolve;
    pptx_ct_p_orientation_transition *comb;
    pptx_ct_p_eight_direction_transition *cover;
    pptx_ct_p_optional_black_transition *cut;
    pptx_ct_p_empty *diamond;
    pptx_ct_p_optional_black_transition *fade;
    pptx_ct_p_empty *newsflash;
    pptx_ct_p_empty *plus;
    pptx_ct_p_eight_direction_transition *pull;
    pptx_ct_p_side_direction_transition *push;
    pptx_ct_p_empty *random;
    pptx_ct_p_orientation_transition *random_bar;
    pptx_ct_p_split_transition *split;
    pptx_ct_p_corner_direction_transition *strips;
    pptx_ct_p_empty *wedge;
    pptx_ct_p_wheel_transition *wheel;
    pptx_ct_p_side_direction_transition *wipe;
    pptx_ct_p_in_out_transition *zoom;
    pptx_ct_p_transition_sound_action *snd_ac;
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_st_transition_speed_token_enum spd;
    pptx_bool adv_click;
    pptx_uint adv_tm;
    int32_t index;
} pptx_ct_p_slide_transition;

pptx_ct_p_slide_transition *
pptx_ct_p_slide_transition_new(xmlNode *node)
{
    pptx_ct_p_slide_transition *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:blinds");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->blinds = NULL;
        } else {
            obj->blinds = pptx_ct_p_orientation_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->blinds = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:checker");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->checker = NULL;
        } else {
            obj->checker = pptx_ct_p_orientation_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->checker = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:circle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->circle = NULL;
        } else {
            obj->circle = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->circle = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:dissolve");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dissolve = NULL;
        } else {
            obj->dissolve = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dissolve = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:comb");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->comb = NULL;
        } else {
            obj->comb = pptx_ct_p_orientation_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->comb = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cover");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cover = NULL;
        } else {
            obj->cover = pptx_ct_p_eight_direction_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cover = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cut");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cut = NULL;
        } else {
            obj->cut = pptx_ct_p_optional_black_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cut = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:diamond");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->diamond = NULL;
        } else {
            obj->diamond = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->diamond = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:fade");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fade = NULL;
        } else {
            obj->fade = pptx_ct_p_optional_black_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fade = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:newsflash");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->newsflash = NULL;
        } else {
            obj->newsflash = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->newsflash = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:plus");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->plus = NULL;
        } else {
            obj->plus = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->plus = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pull");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pull = NULL;
        } else {
            obj->pull = pptx_ct_p_eight_direction_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pull = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:push");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->push = NULL;
        } else {
            obj->push = pptx_ct_p_side_direction_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->push = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:random");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->random = NULL;
        } else {
            obj->random = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->random = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:randomBar");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->random_bar = NULL;
        } else {
            obj->random_bar = pptx_ct_p_orientation_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->random_bar = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:split");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->split = NULL;
        } else {
            obj->split = pptx_ct_p_split_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->split = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:strips");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->strips = NULL;
        } else {
            obj->strips = pptx_ct_p_corner_direction_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->strips = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:wedge");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->wedge = NULL;
        } else {
            obj->wedge = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->wedge = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:wheel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->wheel = NULL;
        } else {
            obj->wheel = pptx_ct_p_wheel_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->wheel = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:wipe");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->wipe = NULL;
        } else {
            obj->wipe = pptx_ct_p_side_direction_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->wipe = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:zoom");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->zoom = NULL;
        } else {
            obj->zoom = pptx_ct_p_in_out_transition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->zoom = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sndAc");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->snd_ac = NULL;
        } else {
            obj->snd_ac = pptx_ct_p_transition_sound_action_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->snd_ac = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->spd = pptx_get_st_transition_speed(node, (const xmlChar *) "spd");
    obj->adv_click = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "advClick");
    obj->adv_tm = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "advTm");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_orientation_transition *
pptx_ct_p_slide_transition_get_blinds(const pptx_ct_p_slide_transition *const obj)
{
    return obj->blinds;
}

pptx_ct_p_orientation_transition *
pptx_ct_p_slide_transition_get_checker(const pptx_ct_p_slide_transition *const obj)
{
    return obj->checker;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_circle(const pptx_ct_p_slide_transition *const obj)
{
    return obj->circle;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_dissolve(const pptx_ct_p_slide_transition *const obj)
{
    return obj->dissolve;
}

pptx_ct_p_orientation_transition *
pptx_ct_p_slide_transition_get_comb(const pptx_ct_p_slide_transition *const obj)
{
    return obj->comb;
}

pptx_ct_p_eight_direction_transition *
pptx_ct_p_slide_transition_get_cover(const pptx_ct_p_slide_transition *const obj)
{
    return obj->cover;
}

pptx_ct_p_optional_black_transition *
pptx_ct_p_slide_transition_get_cut(const pptx_ct_p_slide_transition *const obj)
{
    return obj->cut;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_diamond(const pptx_ct_p_slide_transition *const obj)
{
    return obj->diamond;
}

pptx_ct_p_optional_black_transition *
pptx_ct_p_slide_transition_get_fade(const pptx_ct_p_slide_transition *const obj)
{
    return obj->fade;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_newsflash(const pptx_ct_p_slide_transition *const obj)
{
    return obj->newsflash;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_plus(const pptx_ct_p_slide_transition *const obj)
{
    return obj->plus;
}

pptx_ct_p_eight_direction_transition *
pptx_ct_p_slide_transition_get_pull(const pptx_ct_p_slide_transition *const obj)
{
    return obj->pull;
}

pptx_ct_p_side_direction_transition *
pptx_ct_p_slide_transition_get_push(const pptx_ct_p_slide_transition *const obj)
{
    return obj->push;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_random(const pptx_ct_p_slide_transition *const obj)
{
    return obj->random;
}

pptx_ct_p_orientation_transition *
pptx_ct_p_slide_transition_get_random_bar(const pptx_ct_p_slide_transition *const obj)
{
    return obj->random_bar;
}

pptx_ct_p_split_transition *
pptx_ct_p_slide_transition_get_split(const pptx_ct_p_slide_transition *const obj)
{
    return obj->split;
}

pptx_ct_p_corner_direction_transition *
pptx_ct_p_slide_transition_get_strips(const pptx_ct_p_slide_transition *const obj)
{
    return obj->strips;
}

pptx_ct_p_empty *
pptx_ct_p_slide_transition_get_wedge(const pptx_ct_p_slide_transition *const obj)
{
    return obj->wedge;
}

pptx_ct_p_wheel_transition *
pptx_ct_p_slide_transition_get_wheel(const pptx_ct_p_slide_transition *const obj)
{
    return obj->wheel;
}

pptx_ct_p_side_direction_transition *
pptx_ct_p_slide_transition_get_wipe(const pptx_ct_p_slide_transition *const obj)
{
    return obj->wipe;
}

pptx_ct_p_in_out_transition *
pptx_ct_p_slide_transition_get_zoom(const pptx_ct_p_slide_transition *const obj)
{
    return obj->zoom;
}

pptx_ct_p_transition_sound_action *
pptx_ct_p_slide_transition_get_snd_ac(const pptx_ct_p_slide_transition *const obj)
{
    return obj->snd_ac;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_slide_transition_get_ext_lst(const pptx_ct_p_slide_transition *const obj)
{
    return obj->ext_lst;
}

pptx_st_transition_speed_token_enum 
pptx_ct_p_slide_transition_get_spd(const pptx_ct_p_slide_transition *const obj)
{
    return obj->spd;
}

pptx_bool 
pptx_ct_p_slide_transition_get_adv_click(const pptx_ct_p_slide_transition *const obj)
{
    return obj->adv_click;
}

pptx_uint 
pptx_ct_p_slide_transition_get_adv_tm(const pptx_ct_p_slide_transition *const obj)
{
    return obj->adv_tm;
}

int32_t
pptx_ct_p_slide_transition_get_index(pptx_ct_p_slide_transition *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_transition_free(pptx_ct_p_slide_transition *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_orientation_transition_free(obj->blinds);
    pptx_ct_p_orientation_transition_free(obj->checker);
    pptx_ct_p_empty_free(obj->circle);
    pptx_ct_p_empty_free(obj->dissolve);
    pptx_ct_p_orientation_transition_free(obj->comb);
    pptx_ct_p_eight_direction_transition_free(obj->cover);
    pptx_ct_p_optional_black_transition_free(obj->cut);
    pptx_ct_p_empty_free(obj->diamond);
    pptx_ct_p_optional_black_transition_free(obj->fade);
    pptx_ct_p_empty_free(obj->newsflash);
    pptx_ct_p_empty_free(obj->plus);
    pptx_ct_p_eight_direction_transition_free(obj->pull);
    pptx_ct_p_side_direction_transition_free(obj->push);
    pptx_ct_p_empty_free(obj->random);
    pptx_ct_p_orientation_transition_free(obj->random_bar);
    pptx_ct_p_split_transition_free(obj->split);
    pptx_ct_p_corner_direction_transition_free(obj->strips);
    pptx_ct_p_empty_free(obj->wedge);
    pptx_ct_p_wheel_transition_free(obj->wheel);
    pptx_ct_p_side_direction_transition_free(obj->wipe);
    pptx_ct_p_in_out_transition_free(obj->zoom);
    pptx_ct_p_transition_sound_action_free(obj->snd_ac);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}