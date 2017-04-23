#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-application-non-visual-drawing-props.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-placeholder.h>
#include <private/pptx-ct-a-audio-cd.h>
#include <private/pptx-ct-a-embedded-wavaudio-file.h>
#include <private/pptx-ct-a-audio-file.h>
#include <private/pptx-ct-a-video-file.h>
#include <private/pptx-ct-a-quick-time-file.h>
#include <private/pptx-ct-p-customer-data-list.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_application_non_visual_drawing_props_s {
    pptx_ct_p_placeholder *ph;
    pptx_ct_a_audio_cd *media_audio_cd;
    pptx_ct_a_embedded_wavaudio_file *media_wav_audio_file;
    pptx_ct_a_audio_file *media_audio_file;
    pptx_ct_a_video_file *media_video_file;
    pptx_ct_a_quick_time_file *media_quick_time_file;
    pptx_ct_p_customer_data_list *cust_data_lst;
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool is_photo;
    pptx_bool user_drawn;
    int32_t index;
} pptx_ct_p_application_non_visual_drawing_props;

pptx_ct_p_application_non_visual_drawing_props *
pptx_ct_p_application_non_visual_drawing_props_new(xmlNode *node)
{
    pptx_ct_p_application_non_visual_drawing_props *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:ph");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ph = NULL;
        } else {
            obj->ph = pptx_ct_p_placeholder_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ph = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:audioCd");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->media_audio_cd = NULL;
        } else {
            obj->media_audio_cd = pptx_ct_a_audio_cd_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->media_audio_cd = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:wavAudioFile");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->media_wav_audio_file = NULL;
        } else {
            obj->media_wav_audio_file = pptx_ct_a_embedded_wavaudio_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->media_wav_audio_file = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:audioFile");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->media_audio_file = NULL;
        } else {
            obj->media_audio_file = pptx_ct_a_audio_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->media_audio_file = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:videoFile");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->media_video_file = NULL;
        } else {
            obj->media_video_file = pptx_ct_a_video_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->media_video_file = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:quickTimeFile");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->media_quick_time_file = NULL;
        } else {
            obj->media_quick_time_file = pptx_ct_a_quick_time_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->media_quick_time_file = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custDataLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_data_lst = NULL;
        } else {
            obj->cust_data_lst = pptx_ct_p_customer_data_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_data_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->is_photo = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "isPhoto");
    obj->user_drawn = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "userDrawn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_placeholder *
pptx_ct_p_application_non_visual_drawing_props_get_ph(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->ph;
}

pptx_ct_a_audio_cd *
pptx_ct_p_application_non_visual_drawing_props_get_media_audio_cd(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->media_audio_cd;
}

pptx_ct_a_embedded_wavaudio_file *
pptx_ct_p_application_non_visual_drawing_props_get_media_wav_audio_file(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->media_wav_audio_file;
}

pptx_ct_a_audio_file *
pptx_ct_p_application_non_visual_drawing_props_get_media_audio_file(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->media_audio_file;
}

pptx_ct_a_video_file *
pptx_ct_p_application_non_visual_drawing_props_get_media_video_file(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->media_video_file;
}

pptx_ct_a_quick_time_file *
pptx_ct_p_application_non_visual_drawing_props_get_media_quick_time_file(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->media_quick_time_file;
}

pptx_ct_p_customer_data_list *
pptx_ct_p_application_non_visual_drawing_props_get_cust_data_lst(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->cust_data_lst;
}

pptx_ct_p_extension_list *
pptx_ct_p_application_non_visual_drawing_props_get_ext_lst(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_application_non_visual_drawing_props_get_is_photo(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->is_photo;
}

pptx_bool 
pptx_ct_p_application_non_visual_drawing_props_get_user_drawn(const pptx_ct_p_application_non_visual_drawing_props *const obj)
{
    return obj->user_drawn;
}

int32_t
pptx_ct_p_application_non_visual_drawing_props_get_index(pptx_ct_p_application_non_visual_drawing_props *obj)
{
    return obj->index;
}

void
pptx_ct_p_application_non_visual_drawing_props_free(pptx_ct_p_application_non_visual_drawing_props *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_placeholder_free(obj->ph);
    pptx_ct_a_audio_cd_free(obj->media_audio_cd);
    pptx_ct_a_embedded_wavaudio_file_free(obj->media_wav_audio_file);
    pptx_ct_a_audio_file_free(obj->media_audio_file);
    pptx_ct_a_video_file_free(obj->media_video_file);
    pptx_ct_a_quick_time_file_free(obj->media_quick_time_file);
    pptx_ct_p_customer_data_list_free(obj->cust_data_lst);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}