#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-dpt.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-marker.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-picture-options.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_dpt_s {
    pptx_uint idx;
    pptx_bool invert_if_negative;
    pptx_ct_a_marker *marker;
    pptx_bool bubble_3d;
    pptx_uint explosion;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_picture_options *picture_options;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_dpt;

pptx_ct_a_dpt *
pptx_ct_a_dpt_new(xmlNode *node)
{
    pptx_ct_a_dpt *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->idx = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:idx");
    obj->invert_if_negative = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:invertIfNegative");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:marker");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->marker = NULL;
        } else {
            obj->marker = pptx_ct_a_marker_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->marker = NULL;
    }
    obj->bubble_3d = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:bubble3D");
    obj->explosion = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:explosion");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pictureOptions");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->picture_options = NULL;
        } else {
            obj->picture_options = pptx_ct_a_picture_options_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->picture_options = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_dpt_get_idx(const pptx_ct_a_dpt *const obj)
{
    return obj->idx;
}

pptx_bool 
pptx_ct_a_dpt_get_invert_if_negative(const pptx_ct_a_dpt *const obj)
{
    return obj->invert_if_negative;
}

pptx_ct_a_marker *
pptx_ct_a_dpt_get_marker(const pptx_ct_a_dpt *const obj)
{
    return obj->marker;
}

pptx_bool 
pptx_ct_a_dpt_get_bubble_3d(const pptx_ct_a_dpt *const obj)
{
    return obj->bubble_3d;
}

pptx_uint 
pptx_ct_a_dpt_get_explosion(const pptx_ct_a_dpt *const obj)
{
    return obj->explosion;
}

pptx_ct_a_shape_properties *
pptx_ct_a_dpt_get_sp_pr(const pptx_ct_a_dpt *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_picture_options *
pptx_ct_a_dpt_get_picture_options(const pptx_ct_a_dpt *const obj)
{
    return obj->picture_options;
}

pptx_ct_a_extension_list *
pptx_ct_a_dpt_get_ext_lst(const pptx_ct_a_dpt *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_dpt_get_index(pptx_ct_a_dpt *obj)
{
    return obj->index;
}

void
pptx_ct_a_dpt_free(pptx_ct_a_dpt *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_marker_free(obj->marker);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_picture_options_free(obj->picture_options);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}