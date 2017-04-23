#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-custom-geometry-2d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-geom-guide-list.h>
#include <private/pptx-ct-a-adjust-handle-list.h>
#include <private/pptx-ct-a-connection-site-list.h>
#include <private/pptx-ct-a-geom-rect.h>
#include <private/pptx-ct-a-path-2dlist.h>

typedef struct pptx_ct_a_custom_geometry_2d_s {
    pptx_ct_a_geom_guide_list *av_lst;
    pptx_ct_a_geom_guide_list *gd_lst;
    pptx_ct_a_adjust_handle_list *ah_lst;
    pptx_ct_a_connection_site_list *cxn_lst;
    pptx_ct_a_geom_rect *rect;
    pptx_ct_a_path_2dlist *path_lst;
    int32_t index;
} pptx_ct_a_custom_geometry_2d;

pptx_ct_a_custom_geometry_2d *
pptx_ct_a_custom_geometry_2d_new(xmlNode *node)
{
    pptx_ct_a_custom_geometry_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:avLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->av_lst = NULL;
        } else {
            obj->av_lst = pptx_ct_a_geom_guide_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->av_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gdLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->gd_lst = NULL;
        } else {
            obj->gd_lst = pptx_ct_a_geom_guide_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->gd_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ahLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ah_lst = NULL;
        } else {
            obj->ah_lst = pptx_ct_a_adjust_handle_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ah_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cxnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cxn_lst = NULL;
        } else {
            obj->cxn_lst = pptx_ct_a_connection_site_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rect = NULL;
        } else {
            obj->rect = pptx_ct_a_geom_rect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rect = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pathLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->path_lst = NULL;
        } else {
            obj->path_lst = pptx_ct_a_path_2dlist_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->path_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_geom_guide_list *
pptx_ct_a_custom_geometry_2d_get_av_lst(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->av_lst;
}

pptx_ct_a_geom_guide_list *
pptx_ct_a_custom_geometry_2d_get_gd_lst(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->gd_lst;
}

pptx_ct_a_adjust_handle_list *
pptx_ct_a_custom_geometry_2d_get_ah_lst(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->ah_lst;
}

pptx_ct_a_connection_site_list *
pptx_ct_a_custom_geometry_2d_get_cxn_lst(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->cxn_lst;
}

pptx_ct_a_geom_rect *
pptx_ct_a_custom_geometry_2d_get_rect(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->rect;
}

pptx_ct_a_path_2dlist *
pptx_ct_a_custom_geometry_2d_get_path_lst(const pptx_ct_a_custom_geometry_2d *const obj)
{
    return obj->path_lst;
}

int32_t
pptx_ct_a_custom_geometry_2d_get_index(pptx_ct_a_custom_geometry_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_custom_geometry_2d_free(pptx_ct_a_custom_geometry_2d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_geom_guide_list_free(obj->av_lst);
    pptx_ct_a_geom_guide_list_free(obj->gd_lst);
    pptx_ct_a_adjust_handle_list_free(obj->ah_lst);
    pptx_ct_a_connection_site_list_free(obj->cxn_lst);
    pptx_ct_a_geom_rect_free(obj->rect);
    pptx_ct_a_path_2dlist_free(obj->path_lst);
    free(obj);
}