#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-cdr-graphic-frame-non-visual.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-non-visual-drawing-props.h>
#include <private/pptx-ct-a-non-visual-graphic-frame-properties.h>

typedef struct pptx_ct_cdr_graphic_frame_non_visual_s {
    pptx_ct_a_non_visual_drawing_props *c_nv_pr;
    pptx_ct_a_non_visual_graphic_frame_properties *c_nv_graphic_frame_pr;
    int32_t index;
} pptx_ct_cdr_graphic_frame_non_visual;

pptx_ct_cdr_graphic_frame_non_visual *
pptx_ct_cdr_graphic_frame_non_visual_new(xmlNode *node)
{
    pptx_ct_cdr_graphic_frame_non_visual *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:cNvPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_nv_pr = NULL;
        } else {
            obj->c_nv_pr = pptx_ct_a_non_visual_drawing_props_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_nv_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:cNvGraphicFramePr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_nv_graphic_frame_pr = NULL;
        } else {
            obj->c_nv_graphic_frame_pr = pptx_ct_a_non_visual_graphic_frame_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_nv_graphic_frame_pr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_non_visual_drawing_props *
pptx_ct_cdr_graphic_frame_non_visual_get_c_nv_pr(const pptx_ct_cdr_graphic_frame_non_visual *const obj)
{
    return obj->c_nv_pr;
}

pptx_ct_a_non_visual_graphic_frame_properties *
pptx_ct_cdr_graphic_frame_non_visual_get_c_nv_graphic_frame_pr(const pptx_ct_cdr_graphic_frame_non_visual *const obj)
{
    return obj->c_nv_graphic_frame_pr;
}

int32_t
pptx_ct_cdr_graphic_frame_non_visual_get_index(pptx_ct_cdr_graphic_frame_non_visual *obj)
{
    return obj->index;
}

void
pptx_ct_cdr_graphic_frame_non_visual_free(pptx_ct_cdr_graphic_frame_non_visual *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_non_visual_drawing_props_free(obj->c_nv_pr);
    pptx_ct_a_non_visual_graphic_frame_properties_free(obj->c_nv_graphic_frame_pr);
    free(obj);
}