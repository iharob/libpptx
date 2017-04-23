#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-surface.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-thickness.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-picture-options.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_surface_s {
    pptx_ct_a_thickness *thickness;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_picture_options *picture_options;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_surface;

pptx_ct_a_surface *
pptx_ct_a_surface_new(xmlNode *node)
{
    pptx_ct_a_surface *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:thickness");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->thickness = NULL;
        } else {
            obj->thickness = pptx_ct_a_thickness_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->thickness = NULL;
    }

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

pptx_ct_a_thickness *
pptx_ct_a_surface_get_thickness(const pptx_ct_a_surface *const obj)
{
    return obj->thickness;
}

pptx_ct_a_shape_properties *
pptx_ct_a_surface_get_sp_pr(const pptx_ct_a_surface *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_picture_options *
pptx_ct_a_surface_get_picture_options(const pptx_ct_a_surface *const obj)
{
    return obj->picture_options;
}

pptx_ct_a_extension_list *
pptx_ct_a_surface_get_ext_lst(const pptx_ct_a_surface *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_surface_get_index(pptx_ct_a_surface *obj)
{
    return obj->index;
}

void
pptx_ct_a_surface_free(pptx_ct_a_surface *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_thickness_free(obj->thickness);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_picture_options_free(obj->picture_options);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}