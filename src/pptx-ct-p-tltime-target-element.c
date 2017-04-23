#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-target-element.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-a-embedded-wavaudio-file.h>
#include <private/pptx-ct-p-tlshape-target-element.h>
#include <private/pptx-ct-p-tlsub-shape-id.h>

typedef struct pptx_ct_p_tltime_target_element_s {
    pptx_ct_p_empty *sld_tgt;
    pptx_ct_a_embedded_wavaudio_file *snd_tgt;
    pptx_ct_p_tlshape_target_element *sp_tgt;
    pptx_ct_p_tlsub_shape_id *ink_tgt;
    int32_t index;
} pptx_ct_p_tltime_target_element;

pptx_ct_p_tltime_target_element *
pptx_ct_p_tltime_target_element_new(xmlNode *node)
{
    pptx_ct_p_tltime_target_element *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldTgt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sld_tgt = NULL;
        } else {
            obj->sld_tgt = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_tgt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sndTgt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->snd_tgt = NULL;
        } else {
            obj->snd_tgt = pptx_ct_a_embedded_wavaudio_file_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->snd_tgt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:spTgt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_tgt = NULL;
        } else {
            obj->sp_tgt = pptx_ct_p_tlshape_target_element_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_tgt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:inkTgt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ink_tgt = NULL;
        } else {
            obj->ink_tgt = pptx_ct_p_tlsub_shape_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ink_tgt = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_empty *
pptx_ct_p_tltime_target_element_get_sld_tgt(const pptx_ct_p_tltime_target_element *const obj)
{
    return obj->sld_tgt;
}

pptx_ct_a_embedded_wavaudio_file *
pptx_ct_p_tltime_target_element_get_snd_tgt(const pptx_ct_p_tltime_target_element *const obj)
{
    return obj->snd_tgt;
}

pptx_ct_p_tlshape_target_element *
pptx_ct_p_tltime_target_element_get_sp_tgt(const pptx_ct_p_tltime_target_element *const obj)
{
    return obj->sp_tgt;
}

pptx_ct_p_tlsub_shape_id *
pptx_ct_p_tltime_target_element_get_ink_tgt(const pptx_ct_p_tltime_target_element *const obj)
{
    return obj->ink_tgt;
}

int32_t
pptx_ct_p_tltime_target_element_get_index(pptx_ct_p_tltime_target_element *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_target_element_free(pptx_ct_p_tltime_target_element *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_empty_free(obj->sld_tgt);
    pptx_ct_a_embedded_wavaudio_file_free(obj->snd_tgt);
    pptx_ct_p_tlshape_target_element_free(obj->sp_tgt);
    pptx_ct_p_tlsub_shape_id_free(obj->ink_tgt);
    free(obj);
}