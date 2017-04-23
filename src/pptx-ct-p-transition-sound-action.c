#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-transition-sound-action.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-transition-start-sound-action.h>
#include <private/pptx-ct-p-empty.h>

typedef struct pptx_ct_p_transition_sound_action_s {
    pptx_ct_p_transition_start_sound_action *st_snd;
    pptx_ct_p_empty *end_snd;
    int32_t index;
} pptx_ct_p_transition_sound_action;

pptx_ct_p_transition_sound_action *
pptx_ct_p_transition_sound_action_new(xmlNode *node)
{
    pptx_ct_p_transition_sound_action *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:stSnd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->st_snd = NULL;
        } else {
            obj->st_snd = pptx_ct_p_transition_start_sound_action_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->st_snd = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:endSnd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end_snd = NULL;
        } else {
            obj->end_snd = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end_snd = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_transition_start_sound_action *
pptx_ct_p_transition_sound_action_get_st_snd(const pptx_ct_p_transition_sound_action *const obj)
{
    return obj->st_snd;
}

pptx_ct_p_empty *
pptx_ct_p_transition_sound_action_get_end_snd(const pptx_ct_p_transition_sound_action *const obj)
{
    return obj->end_snd;
}

int32_t
pptx_ct_p_transition_sound_action_get_index(pptx_ct_p_transition_sound_action *obj)
{
    return obj->index;
}

void
pptx_ct_p_transition_sound_action_free(pptx_ct_p_transition_sound_action *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_transition_start_sound_action_free(obj->st_snd);
    pptx_ct_p_empty_free(obj->end_snd);
    free(obj);
}