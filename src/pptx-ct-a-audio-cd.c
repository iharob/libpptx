#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-audio-cd.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-audio-cdtime.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_audio_cd_s {
    pptx_ct_a_audio_cdtime *st;
    pptx_ct_a_audio_cdtime *end;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_audio_cd;

pptx_ct_a_audio_cd *
pptx_ct_a_audio_cd_new(xmlNode *node)
{
    pptx_ct_a_audio_cd *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:st");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->st = NULL;
        } else {
            obj->st = pptx_ct_a_audio_cdtime_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->st = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:end");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end = NULL;
        } else {
            obj->end = pptx_ct_a_audio_cdtime_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end = NULL;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_audio_cdtime *
pptx_ct_a_audio_cd_get_st(const pptx_ct_a_audio_cd *const obj)
{
    return obj->st;
}

pptx_ct_a_audio_cdtime *
pptx_ct_a_audio_cd_get_end(const pptx_ct_a_audio_cd *const obj)
{
    return obj->end;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_audio_cd_get_ext_lst(const pptx_ct_a_audio_cd *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_audio_cd_get_index(pptx_ct_a_audio_cd *obj)
{
    return obj->index;
}

void
pptx_ct_a_audio_cd_free(pptx_ct_a_audio_cd *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_audio_cdtime_free(obj->st);
    pptx_ct_a_audio_cdtime_free(obj->end);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}