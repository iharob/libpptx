#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-background.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-background-properties.h>
#include <private/pptx-ct-a-style-matrix-reference.h>
#include <private/pptx-st-black-white-mode.h>

typedef struct pptx_ct_p_background_s {
    pptx_ct_p_background_properties *background_bg_pr;
    pptx_ct_a_style_matrix_reference *background_bg_ref;
    pptx_st_black_white_mode_token_enum bw_mode;
    int32_t index;
} pptx_ct_p_background;

pptx_ct_p_background *
pptx_ct_p_background_new(xmlNode *node)
{
    pptx_ct_p_background *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bgPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->background_bg_pr = NULL;
        } else {
            obj->background_bg_pr = pptx_ct_p_background_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->background_bg_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bgRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->background_bg_ref = NULL;
        } else {
            obj->background_bg_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->background_bg_ref = NULL;
    }
    obj->bw_mode = pptx_get_st_black_white_mode(node, (const xmlChar *) "bwMode");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_background_properties *
pptx_ct_p_background_get_background_bg_pr(const pptx_ct_p_background *const obj)
{
    return obj->background_bg_pr;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_p_background_get_background_bg_ref(const pptx_ct_p_background *const obj)
{
    return obj->background_bg_ref;
}

pptx_st_black_white_mode_token_enum 
pptx_ct_p_background_get_bw_mode(const pptx_ct_p_background *const obj)
{
    return obj->bw_mode;
}

int32_t
pptx_ct_p_background_get_index(pptx_ct_p_background *obj)
{
    return obj->index;
}

void
pptx_ct_p_background_free(pptx_ct_p_background *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_background_properties_free(obj->background_bg_pr);
    pptx_ct_a_style_matrix_reference_free(obj->background_bg_ref);
    free(obj);
}