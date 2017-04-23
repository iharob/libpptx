#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-blip-fill-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-blip.h>
#include <private/pptx-ct-a-relative-rect.h>
#include <private/pptx-ct-a-tile-info-properties.h>
#include <private/pptx-ct-a-stretch-info-properties.h>

typedef struct pptx_ct_a_blip_fill_properties_s {
    pptx_ct_a_blip *blip;
    pptx_ct_a_relative_rect *src_rect;
    pptx_ct_a_tile_info_properties *fill_mode_properties_tile;
    pptx_ct_a_stretch_info_properties *fill_mode_properties_stretch;
    pptx_uint dpi;
    pptx_bool rot_with_shape;
    int32_t index;
} pptx_ct_a_blip_fill_properties;

pptx_ct_a_blip_fill_properties *
pptx_ct_a_blip_fill_properties_new(xmlNode *node)
{
    pptx_ct_a_blip_fill_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blip");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->blip = NULL;
        } else {
            obj->blip = pptx_ct_a_blip_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->blip = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:srcRect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->src_rect = NULL;
        } else {
            obj->src_rect = pptx_ct_a_relative_rect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->src_rect = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tile");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_mode_properties_tile = NULL;
        } else {
            obj->fill_mode_properties_tile = pptx_ct_a_tile_info_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_mode_properties_tile = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:stretch");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_mode_properties_stretch = NULL;
        } else {
            obj->fill_mode_properties_stretch = pptx_ct_a_stretch_info_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_mode_properties_stretch = NULL;
    }
    obj->dpi = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "dpi");
    obj->rot_with_shape = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rotWithShape");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_blip *
pptx_ct_a_blip_fill_properties_get_blip(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->blip;
}

pptx_ct_a_relative_rect *
pptx_ct_a_blip_fill_properties_get_src_rect(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->src_rect;
}

pptx_ct_a_tile_info_properties *
pptx_ct_a_blip_fill_properties_get_fill_mode_properties_tile(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->fill_mode_properties_tile;
}

pptx_ct_a_stretch_info_properties *
pptx_ct_a_blip_fill_properties_get_fill_mode_properties_stretch(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->fill_mode_properties_stretch;
}

pptx_uint 
pptx_ct_a_blip_fill_properties_get_dpi(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->dpi;
}

pptx_bool 
pptx_ct_a_blip_fill_properties_get_rot_with_shape(const pptx_ct_a_blip_fill_properties *const obj)
{
    return obj->rot_with_shape;
}

int32_t
pptx_ct_a_blip_fill_properties_get_index(pptx_ct_a_blip_fill_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_blip_fill_properties_free(pptx_ct_a_blip_fill_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_blip_free(obj->blip);
    pptx_ct_a_relative_rect_free(obj->src_rect);
    pptx_ct_a_tile_info_properties_free(obj->fill_mode_properties_tile);
    pptx_ct_a_stretch_info_properties_free(obj->fill_mode_properties_stretch);
    free(obj);
}