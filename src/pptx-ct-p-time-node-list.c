#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-time-node-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltime-node-parallel.h>
#include <private/pptx-ct-p-tltime-node-sequence.h>
#include <private/pptx-ct-p-tltime-node-exclusive.h>
#include <private/pptx-ct-p-tlanimate-behavior.h>
#include <private/pptx-ct-p-tlanimate-color-behavior.h>
#include <private/pptx-ct-p-tlanimate-effect-behavior.h>
#include <private/pptx-ct-p-tlanimate-motion-behavior.h>
#include <private/pptx-ct-p-tlanimate-rotation-behavior.h>
#include <private/pptx-ct-p-tlanimate-scale-behavior.h>
#include <private/pptx-ct-p-tlcommand-behavior.h>
#include <private/pptx-ct-p-tlset-behavior.h>
#include <private/pptx-ct-p-tlmedia-node-audio.h>
#include <private/pptx-ct-p-tlmedia-node-video.h>

typedef struct pptx_ct_p_time_node_list_s {
    pptx_ct_p_tltime_node_parallel **par;
    pptx_ct_p_tltime_node_sequence **seq;
    pptx_ct_p_tltime_node_exclusive **excl;
    pptx_ct_p_tlanimate_behavior **anim;
    pptx_ct_p_tlanimate_color_behavior **anim_clr;
    pptx_ct_p_tlanimate_effect_behavior **anim_effect;
    pptx_ct_p_tlanimate_motion_behavior **anim_motion;
    pptx_ct_p_tlanimate_rotation_behavior **anim_rot;
    pptx_ct_p_tlanimate_scale_behavior **anim_scale;
    pptx_ct_p_tlcommand_behavior **cmd;
    pptx_ct_p_tlset_behavior **set;
    pptx_ct_p_tlmedia_node_audio **audio;
    pptx_ct_p_tlmedia_node_video **video;
    int32_t index;
} pptx_ct_p_time_node_list;

pptx_ct_p_time_node_list *
pptx_ct_p_time_node_list_new(xmlNode *node)
{
    pptx_ct_p_time_node_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:par");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->par = malloc((nodes->nodeNr + 1) * sizeof *obj->par);
            if (obj->par != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->par;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tltime_node_parallel_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->par);
                    obj->par = NULL;
                } else {
                    obj->par[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->par = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->par = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:seq");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->seq = malloc((nodes->nodeNr + 1) * sizeof *obj->seq);
            if (obj->seq != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->seq;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tltime_node_sequence_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->seq);
                    obj->seq = NULL;
                } else {
                    obj->seq[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->seq = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->seq = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:excl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->excl = malloc((nodes->nodeNr + 1) * sizeof *obj->excl);
            if (obj->excl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->excl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tltime_node_exclusive_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->excl);
                    obj->excl = NULL;
                } else {
                    obj->excl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->excl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->excl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:anim");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim = malloc((nodes->nodeNr + 1) * sizeof *obj->anim);
            if (obj->anim != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim);
                    obj->anim = NULL;
                } else {
                    obj->anim[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:animClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim_clr = malloc((nodes->nodeNr + 1) * sizeof *obj->anim_clr);
            if (obj->anim_clr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim_clr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_color_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim_clr);
                    obj->anim_clr = NULL;
                } else {
                    obj->anim_clr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim_clr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:animEffect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim_effect = malloc((nodes->nodeNr + 1) * sizeof *obj->anim_effect);
            if (obj->anim_effect != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim_effect;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_effect_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim_effect);
                    obj->anim_effect = NULL;
                } else {
                    obj->anim_effect[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim_effect = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_effect = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:animMotion");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim_motion = malloc((nodes->nodeNr + 1) * sizeof *obj->anim_motion);
            if (obj->anim_motion != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim_motion;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_motion_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim_motion);
                    obj->anim_motion = NULL;
                } else {
                    obj->anim_motion[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim_motion = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_motion = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:animRot");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim_rot = malloc((nodes->nodeNr + 1) * sizeof *obj->anim_rot);
            if (obj->anim_rot != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim_rot;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_rotation_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim_rot);
                    obj->anim_rot = NULL;
                } else {
                    obj->anim_rot[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim_rot = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_rot = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:animScale");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anim_scale = malloc((nodes->nodeNr + 1) * sizeof *obj->anim_scale);
            if (obj->anim_scale != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anim_scale;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlanimate_scale_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->anim_scale);
                    obj->anim_scale = NULL;
                } else {
                    obj->anim_scale[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anim_scale = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_scale = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cmd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cmd = malloc((nodes->nodeNr + 1) * sizeof *obj->cmd);
            if (obj->cmd != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cmd;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlcommand_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->cmd);
                    obj->cmd = NULL;
                } else {
                    obj->cmd[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cmd = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cmd = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:set");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->set = malloc((nodes->nodeNr + 1) * sizeof *obj->set);
            if (obj->set != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->set;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlset_behavior_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->set);
                    obj->set = NULL;
                } else {
                    obj->set[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->set = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->set = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:audio");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->audio = malloc((nodes->nodeNr + 1) * sizeof *obj->audio);
            if (obj->audio != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->audio;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlmedia_node_audio_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->audio);
                    obj->audio = NULL;
                } else {
                    obj->audio[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->audio = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->audio = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:video");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->video = malloc((nodes->nodeNr + 1) * sizeof *obj->video);
            if (obj->video != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->video;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlmedia_node_video_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->video);
                    obj->video = NULL;
                } else {
                    obj->video[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->video = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->video = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltime_node_parallel **
pptx_ct_p_time_node_list_get_par(const pptx_ct_p_time_node_list *const obj)
{
    return obj->par;
}

pptx_ct_p_tltime_node_sequence **
pptx_ct_p_time_node_list_get_seq(const pptx_ct_p_time_node_list *const obj)
{
    return obj->seq;
}

pptx_ct_p_tltime_node_exclusive **
pptx_ct_p_time_node_list_get_excl(const pptx_ct_p_time_node_list *const obj)
{
    return obj->excl;
}

pptx_ct_p_tlanimate_behavior **
pptx_ct_p_time_node_list_get_anim(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim;
}

pptx_ct_p_tlanimate_color_behavior **
pptx_ct_p_time_node_list_get_anim_clr(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim_clr;
}

pptx_ct_p_tlanimate_effect_behavior **
pptx_ct_p_time_node_list_get_anim_effect(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim_effect;
}

pptx_ct_p_tlanimate_motion_behavior **
pptx_ct_p_time_node_list_get_anim_motion(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim_motion;
}

pptx_ct_p_tlanimate_rotation_behavior **
pptx_ct_p_time_node_list_get_anim_rot(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim_rot;
}

pptx_ct_p_tlanimate_scale_behavior **
pptx_ct_p_time_node_list_get_anim_scale(const pptx_ct_p_time_node_list *const obj)
{
    return obj->anim_scale;
}

pptx_ct_p_tlcommand_behavior **
pptx_ct_p_time_node_list_get_cmd(const pptx_ct_p_time_node_list *const obj)
{
    return obj->cmd;
}

pptx_ct_p_tlset_behavior **
pptx_ct_p_time_node_list_get_set(const pptx_ct_p_time_node_list *const obj)
{
    return obj->set;
}

pptx_ct_p_tlmedia_node_audio **
pptx_ct_p_time_node_list_get_audio(const pptx_ct_p_time_node_list *const obj)
{
    return obj->audio;
}

pptx_ct_p_tlmedia_node_video **
pptx_ct_p_time_node_list_get_video(const pptx_ct_p_time_node_list *const obj)
{
    return obj->video;
}

int32_t
pptx_ct_p_time_node_list_get_index(pptx_ct_p_time_node_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_time_node_list_free(pptx_ct_p_time_node_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->par != NULL) {
        for (int i = 0; obj->par[i] != NULL; ++i) {
            pptx_ct_p_tltime_node_parallel_free(obj->par[i]);
        }
        free(obj->par);
    }

    if (obj->seq != NULL) {
        for (int i = 0; obj->seq[i] != NULL; ++i) {
            pptx_ct_p_tltime_node_sequence_free(obj->seq[i]);
        }
        free(obj->seq);
    }

    if (obj->excl != NULL) {
        for (int i = 0; obj->excl[i] != NULL; ++i) {
            pptx_ct_p_tltime_node_exclusive_free(obj->excl[i]);
        }
        free(obj->excl);
    }

    if (obj->anim != NULL) {
        for (int i = 0; obj->anim[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_behavior_free(obj->anim[i]);
        }
        free(obj->anim);
    }

    if (obj->anim_clr != NULL) {
        for (int i = 0; obj->anim_clr[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_color_behavior_free(obj->anim_clr[i]);
        }
        free(obj->anim_clr);
    }

    if (obj->anim_effect != NULL) {
        for (int i = 0; obj->anim_effect[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_effect_behavior_free(obj->anim_effect[i]);
        }
        free(obj->anim_effect);
    }

    if (obj->anim_motion != NULL) {
        for (int i = 0; obj->anim_motion[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_motion_behavior_free(obj->anim_motion[i]);
        }
        free(obj->anim_motion);
    }

    if (obj->anim_rot != NULL) {
        for (int i = 0; obj->anim_rot[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_rotation_behavior_free(obj->anim_rot[i]);
        }
        free(obj->anim_rot);
    }

    if (obj->anim_scale != NULL) {
        for (int i = 0; obj->anim_scale[i] != NULL; ++i) {
            pptx_ct_p_tlanimate_scale_behavior_free(obj->anim_scale[i]);
        }
        free(obj->anim_scale);
    }

    if (obj->cmd != NULL) {
        for (int i = 0; obj->cmd[i] != NULL; ++i) {
            pptx_ct_p_tlcommand_behavior_free(obj->cmd[i]);
        }
        free(obj->cmd);
    }

    if (obj->set != NULL) {
        for (int i = 0; obj->set[i] != NULL; ++i) {
            pptx_ct_p_tlset_behavior_free(obj->set[i]);
        }
        free(obj->set);
    }

    if (obj->audio != NULL) {
        for (int i = 0; obj->audio[i] != NULL; ++i) {
            pptx_ct_p_tlmedia_node_audio_free(obj->audio[i]);
        }
        free(obj->audio);
    }

    if (obj->video != NULL) {
        for (int i = 0; obj->video[i] != NULL; ++i) {
            pptx_ct_p_tlmedia_node_video_free(obj->video[i]);
        }
        free(obj->video);
    }

    free(obj);
}