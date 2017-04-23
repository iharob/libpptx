#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-scale-2d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-ratio.h>

typedef struct pptx_ct_a_scale_2d_s {
    pptx_ct_a_ratio *sx;
    pptx_ct_a_ratio *sy;
    int32_t index;
} pptx_ct_a_scale_2d;

pptx_ct_a_scale_2d *
pptx_ct_a_scale_2d_new(xmlNode *node)
{
    pptx_ct_a_scale_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sx = NULL;
        } else {
            obj->sx = pptx_ct_a_ratio_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sy");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sy = NULL;
        } else {
            obj->sy = pptx_ct_a_ratio_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sy = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_ratio *
pptx_ct_a_scale_2d_get_sx(const pptx_ct_a_scale_2d *const obj)
{
    return obj->sx;
}

pptx_ct_a_ratio *
pptx_ct_a_scale_2d_get_sy(const pptx_ct_a_scale_2d *const obj)
{
    return obj->sy;
}

int32_t
pptx_ct_a_scale_2d_get_index(pptx_ct_a_scale_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_scale_2d_free(pptx_ct_a_scale_2d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_ratio_free(obj->sx);
    pptx_ct_a_ratio_free(obj->sy);
    free(obj);
}