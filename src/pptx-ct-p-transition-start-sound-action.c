#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-transition-start-sound-action.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-embedded-wavaudio-file.h>

typedef struct pptx_ct_p_transition_start_sound_action_s {
    pptx_ct_a_embedded_wavaudio_file *snd;
    pptx_bool loop;
    int32_t index;
} pptx_ct_p_transition_start_sound_action;

pptx_ct_p_transition_start_sound_action *
pptx_ct_p_transition_start_sound_action_new(xmlNode *node)
{
    pptx_ct_p_transition_start_sound_action *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:snd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->snd = NULL;
        } else {
            obj->snd = pptx_ct_a_embedded_wavaudio_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->snd = NULL;
    }
    obj->loop = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "loop");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_embedded_wavaudio_file *
pptx_ct_p_transition_start_sound_action_get_snd(const pptx_ct_p_transition_start_sound_action *const obj)
{
    return obj->snd;
}

pptx_bool 
pptx_ct_p_transition_start_sound_action_get_loop(const pptx_ct_p_transition_start_sound_action *const obj)
{
    return obj->loop;
}

int32_t
pptx_ct_p_transition_start_sound_action_get_index(pptx_ct_p_transition_start_sound_action *obj)
{
    return obj->index;
}

void
pptx_ct_p_transition_start_sound_action_free(pptx_ct_p_transition_start_sound_action *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_embedded_wavaudio_file_free(obj->snd);
    free(obj);
}