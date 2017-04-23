#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-audio-cdtime.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_audio_cdtime_s {
    pptx_byte track;
    pptx_uint time;
    int32_t index;
} pptx_ct_a_audio_cdtime;

pptx_ct_a_audio_cdtime *
pptx_ct_a_audio_cdtime_new(xmlNode *node)
{
    pptx_ct_a_audio_cdtime *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->track = pptx_xml_get_attribute_as_byte(node, (const xmlChar *) "track");
    obj->time = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "time");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_byte 
pptx_ct_a_audio_cdtime_get_track(const pptx_ct_a_audio_cdtime *const obj)
{
    return obj->track;
}

pptx_uint 
pptx_ct_a_audio_cdtime_get_time(const pptx_ct_a_audio_cdtime *const obj)
{
    return obj->time;
}

int32_t
pptx_ct_a_audio_cdtime_get_index(pptx_ct_a_audio_cdtime *obj)
{
    return obj->index;
}

void
pptx_ct_a_audio_cdtime_free(pptx_ct_a_audio_cdtime *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}