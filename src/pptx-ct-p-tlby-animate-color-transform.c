#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlby-animate-color-transform.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlby-rgb-color-transform.h>
#include <private/pptx-ct-p-tlby-hsl-color-transform.h>

typedef struct pptx_ct_p_tlby_animate_color_transform_s {
    pptx_ct_p_tlby_rgb_color_transform *rgb;
    pptx_ct_p_tlby_hsl_color_transform *hsl;
    int32_t index;
} pptx_ct_p_tlby_animate_color_transform;

pptx_ct_p_tlby_animate_color_transform *
pptx_ct_p_tlby_animate_color_transform_new(xmlNode *node)
{
    pptx_ct_p_tlby_animate_color_transform *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:rgb");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rgb = NULL;
        } else {
            obj->rgb = pptx_ct_p_tlby_rgb_color_transform_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rgb = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:hsl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hsl = NULL;
        } else {
            obj->hsl = pptx_ct_p_tlby_hsl_color_transform_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hsl = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlby_rgb_color_transform *
pptx_ct_p_tlby_animate_color_transform_get_rgb(const pptx_ct_p_tlby_animate_color_transform *const obj)
{
    return obj->rgb;
}

pptx_ct_p_tlby_hsl_color_transform *
pptx_ct_p_tlby_animate_color_transform_get_hsl(const pptx_ct_p_tlby_animate_color_transform *const obj)
{
    return obj->hsl;
}

int32_t
pptx_ct_p_tlby_animate_color_transform_get_index(pptx_ct_p_tlby_animate_color_transform *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlby_animate_color_transform_free(pptx_ct_p_tlby_animate_color_transform *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlby_rgb_color_transform_free(obj->rgb);
    pptx_ct_p_tlby_hsl_color_transform_free(obj->hsl);
    free(obj);
}