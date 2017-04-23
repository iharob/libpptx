#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-tile-info-properties.h>
/* Imported internal stuff */
#include <private/pptx-st-tile-flip-mode.h>
#include <private/pptx-st-rect-alignment.h>

typedef struct pptx_ct_a_tile_info_properties_s {
    pptx_string tx;
    pptx_string ty;
    pptx_string sx;
    pptx_string sy;
    pptx_st_tile_flip_mode_token_enum flip;
    pptx_st_rect_alignment_token_enum algn;
    int32_t index;
} pptx_ct_a_tile_info_properties;

pptx_ct_a_tile_info_properties *
pptx_ct_a_tile_info_properties_new(xmlNode *node)
{
    pptx_ct_a_tile_info_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->tx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tx");
    obj->ty = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ty");
    obj->sx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sx");
    obj->sy = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sy");
    obj->flip = pptx_get_st_tile_flip_mode(node, (const xmlChar *) "flip");
    obj->algn = pptx_get_st_rect_alignment(node, (const xmlChar *) "algn");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_tile_info_properties_get_tx(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->tx;
}

pptx_string 
pptx_ct_a_tile_info_properties_get_ty(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->ty;
}

pptx_string 
pptx_ct_a_tile_info_properties_get_sx(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->sx;
}

pptx_string 
pptx_ct_a_tile_info_properties_get_sy(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->sy;
}

pptx_st_tile_flip_mode_token_enum 
pptx_ct_a_tile_info_properties_get_flip(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->flip;
}

pptx_st_rect_alignment_token_enum 
pptx_ct_a_tile_info_properties_get_algn(const pptx_ct_a_tile_info_properties *const obj)
{
    return obj->algn;
}

int32_t
pptx_ct_a_tile_info_properties_get_index(pptx_ct_a_tile_info_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_tile_info_properties_free(pptx_ct_a_tile_info_properties *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->tx);
    xmlFree(obj->ty);
    xmlFree(obj->sx);
    xmlFree(obj->sy);
    free(obj);
}