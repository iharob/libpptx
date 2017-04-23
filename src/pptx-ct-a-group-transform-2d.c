#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-group-transform-2d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-point-2d.h>
#include <private/pptx-ct-a-positive-size-2d.h>

typedef struct pptx_ct_a_group_transform_2d_s {
    pptx_ct_a_point_2d *off;
    pptx_ct_a_positive_size_2d *ext;
    pptx_ct_a_point_2d *ch_off;
    pptx_ct_a_positive_size_2d *ch_ext;
    pptx_int rot;
    pptx_bool flip_h;
    pptx_bool flip_v;
    int32_t index;
} pptx_ct_a_group_transform_2d;

pptx_ct_a_group_transform_2d *
pptx_ct_a_group_transform_2d_new(xmlNode *node)
{
    pptx_ct_a_group_transform_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:off");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->off = NULL;
        } else {
            obj->off = pptx_ct_a_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ext");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext = NULL;
        } else {
            obj->ext = pptx_ct_a_positive_size_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:chOff");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ch_off = NULL;
        } else {
            obj->ch_off = pptx_ct_a_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ch_off = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:chExt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ch_ext = NULL;
        } else {
            obj->ch_ext = pptx_ct_a_positive_size_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ch_ext = NULL;
    }
    obj->rot = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "rot");
    obj->flip_h = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "flipH");
    obj->flip_v = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "flipV");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_point_2d *
pptx_ct_a_group_transform_2d_get_off(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->off;
}

pptx_ct_a_positive_size_2d *
pptx_ct_a_group_transform_2d_get_ext(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->ext;
}

pptx_ct_a_point_2d *
pptx_ct_a_group_transform_2d_get_ch_off(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->ch_off;
}

pptx_ct_a_positive_size_2d *
pptx_ct_a_group_transform_2d_get_ch_ext(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->ch_ext;
}

pptx_int 
pptx_ct_a_group_transform_2d_get_rot(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->rot;
}

pptx_bool 
pptx_ct_a_group_transform_2d_get_flip_h(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->flip_h;
}

pptx_bool 
pptx_ct_a_group_transform_2d_get_flip_v(const pptx_ct_a_group_transform_2d *const obj)
{
    return obj->flip_v;
}

int32_t
pptx_ct_a_group_transform_2d_get_index(pptx_ct_a_group_transform_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_group_transform_2d_free(pptx_ct_a_group_transform_2d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_point_2d_free(obj->off);
    pptx_ct_a_positive_size_2d_free(obj->ext);
    pptx_ct_a_point_2d_free(obj->ch_off);
    pptx_ct_a_positive_size_2d_free(obj->ch_ext);
    free(obj);
}