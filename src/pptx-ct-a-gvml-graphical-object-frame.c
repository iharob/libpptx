#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-gvml-graphical-object-frame.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-gvml-graphic-frame-non-visual.h>
#include <private/pptx-ct-a-graphical-object.h>
#include <private/pptx-ct-a-transform-2d.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_gvml_graphical_object_frame_s {
    pptx_ct_a_gvml_graphic_frame_non_visual *nv_graphic_frame_pr;
    pptx_ct_a_graphical_object *graphic;
    pptx_ct_a_transform_2d *xfrm;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_gvml_graphical_object_frame;

pptx_ct_a_gvml_graphical_object_frame *
pptx_ct_a_gvml_graphical_object_frame_new(xmlNode *node)
{
    pptx_ct_a_gvml_graphical_object_frame *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:nvGraphicFramePr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_graphic_frame_pr = NULL;
        } else {
            obj->nv_graphic_frame_pr = pptx_ct_a_gvml_graphic_frame_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_graphic_frame_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:graphic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->graphic = NULL;
        } else {
            obj->graphic = pptx_ct_a_graphical_object_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->graphic = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:xfrm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->xfrm = NULL;
        } else {
            obj->xfrm = pptx_ct_a_transform_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->xfrm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_gvml_graphic_frame_non_visual *
pptx_ct_a_gvml_graphical_object_frame_get_nv_graphic_frame_pr(const pptx_ct_a_gvml_graphical_object_frame *const obj)
{
    return obj->nv_graphic_frame_pr;
}

pptx_ct_a_graphical_object *
pptx_ct_a_gvml_graphical_object_frame_get_graphic(const pptx_ct_a_gvml_graphical_object_frame *const obj)
{
    return obj->graphic;
}

pptx_ct_a_transform_2d *
pptx_ct_a_gvml_graphical_object_frame_get_xfrm(const pptx_ct_a_gvml_graphical_object_frame *const obj)
{
    return obj->xfrm;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_gvml_graphical_object_frame_get_ext_lst(const pptx_ct_a_gvml_graphical_object_frame *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_gvml_graphical_object_frame_get_index(pptx_ct_a_gvml_graphical_object_frame *obj)
{
    return obj->index;
}

void
pptx_ct_a_gvml_graphical_object_frame_free(pptx_ct_a_gvml_graphical_object_frame *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_gvml_graphic_frame_non_visual_free(obj->nv_graphic_frame_pr);
    pptx_ct_a_graphical_object_free(obj->graphic);
    pptx_ct_a_transform_2d_free(obj->xfrm);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}