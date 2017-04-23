#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-gradient-fill-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-gradient-stop-list.h>
#include <private/pptx-ct-a-linear-shade-properties.h>
#include <private/pptx-ct-a-path-shade-properties.h>
#include <private/pptx-ct-a-relative-rect.h>
#include <private/pptx-st-tile-flip-mode.h>

typedef struct pptx_ct_a_gradient_fill_properties_s {
    pptx_ct_a_gradient_stop_list *gs_lst;
    pptx_ct_a_linear_shade_properties *shade_properties_lin;
    pptx_ct_a_path_shade_properties *shade_properties_path;
    pptx_ct_a_relative_rect *tile_rect;
    pptx_st_tile_flip_mode_token_enum flip;
    pptx_bool rot_with_shape;
    int32_t index;
} pptx_ct_a_gradient_fill_properties;

pptx_ct_a_gradient_fill_properties *
pptx_ct_a_gradient_fill_properties_new(xmlNode *node)
{
    pptx_ct_a_gradient_fill_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gsLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->gs_lst = NULL;
        } else {
            obj->gs_lst = pptx_ct_a_gradient_stop_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->gs_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lin");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->shade_properties_lin = NULL;
        } else {
            obj->shade_properties_lin = pptx_ct_a_linear_shade_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->shade_properties_lin = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:path");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->shade_properties_path = NULL;
        } else {
            obj->shade_properties_path = pptx_ct_a_path_shade_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->shade_properties_path = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tileRect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tile_rect = NULL;
        } else {
            obj->tile_rect = pptx_ct_a_relative_rect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tile_rect = NULL;
    }
    obj->flip = pptx_get_st_tile_flip_mode(node, (const xmlChar *) "flip");
    obj->rot_with_shape = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rotWithShape");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_gradient_stop_list *
pptx_ct_a_gradient_fill_properties_get_gs_lst(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->gs_lst;
}

pptx_ct_a_linear_shade_properties *
pptx_ct_a_gradient_fill_properties_get_shade_properties_lin(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->shade_properties_lin;
}

pptx_ct_a_path_shade_properties *
pptx_ct_a_gradient_fill_properties_get_shade_properties_path(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->shade_properties_path;
}

pptx_ct_a_relative_rect *
pptx_ct_a_gradient_fill_properties_get_tile_rect(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->tile_rect;
}

pptx_st_tile_flip_mode_token_enum 
pptx_ct_a_gradient_fill_properties_get_flip(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->flip;
}

pptx_bool 
pptx_ct_a_gradient_fill_properties_get_rot_with_shape(const pptx_ct_a_gradient_fill_properties *const obj)
{
    return obj->rot_with_shape;
}

int32_t
pptx_ct_a_gradient_fill_properties_get_index(pptx_ct_a_gradient_fill_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_gradient_fill_properties_free(pptx_ct_a_gradient_fill_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_gradient_stop_list_free(obj->gs_lst);
    pptx_ct_a_linear_shade_properties_free(obj->shade_properties_lin);
    pptx_ct_a_path_shade_properties_free(obj->shade_properties_path);
    pptx_ct_a_relative_rect_free(obj->tile_rect);
    free(obj);
}