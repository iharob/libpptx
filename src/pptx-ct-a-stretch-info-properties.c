#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-stretch-info-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-relative-rect.h>

typedef struct pptx_ct_a_stretch_info_properties_s {
    pptx_ct_a_relative_rect *fill_rect;
    int32_t index;
} pptx_ct_a_stretch_info_properties;

pptx_ct_a_stretch_info_properties *
pptx_ct_a_stretch_info_properties_new(xmlNode *node)
{
    pptx_ct_a_stretch_info_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillRect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_rect = NULL;
        } else {
            obj->fill_rect = pptx_ct_a_relative_rect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_rect = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_relative_rect *
pptx_ct_a_stretch_info_properties_get_fill_rect(const pptx_ct_a_stretch_info_properties *const obj)
{
    return obj->fill_rect;
}

int32_t
pptx_ct_a_stretch_info_properties_get_index(pptx_ct_a_stretch_info_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_stretch_info_properties_free(pptx_ct_a_stretch_info_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_relative_rect_free(obj->fill_rect);
    free(obj);
}