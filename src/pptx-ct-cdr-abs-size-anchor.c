#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-cdr-abs-size-anchor.h>
/* Imported internal stuff */
#include <private/pptx-ct-cdr-marker.h>
#include <private/pptx-ct-a-positive-size-2d.h>
#include <private/pptx-ct-cdr-shape.h>
#include <private/pptx-ct-cdr-group-shape.h>
#include <private/pptx-ct-cdr-graphic-frame.h>
#include <private/pptx-ct-cdr-connector.h>
#include <private/pptx-ct-cdr-picture.h>

typedef struct pptx_ct_cdr_abs_size_anchor_s {
    pptx_ct_cdr_marker *from;
    pptx_ct_a_positive_size_2d *ext;
    pptx_ct_cdr_shape *sp;
    pptx_ct_cdr_group_shape *grp_sp;
    pptx_ct_cdr_graphic_frame *graphic_frame;
    pptx_ct_cdr_connector *cxn_sp;
    pptx_ct_cdr_picture *pic;
    int32_t index;
} pptx_ct_cdr_abs_size_anchor;

pptx_ct_cdr_abs_size_anchor *
pptx_ct_cdr_abs_size_anchor_new(xmlNode *node)
{
    pptx_ct_cdr_abs_size_anchor *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:from");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->from = NULL;
        } else {
            obj->from = pptx_ct_cdr_marker_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->from = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:ext");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:sp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp = NULL;
        } else {
            obj->sp = pptx_ct_cdr_shape_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:grpSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->grp_sp = NULL;
        } else {
            obj->grp_sp = pptx_ct_cdr_group_shape_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grp_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:graphicFrame");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->graphic_frame = NULL;
        } else {
            obj->graphic_frame = pptx_ct_cdr_graphic_frame_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->graphic_frame = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:cxnSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cxn_sp = NULL;
        } else {
            obj->cxn_sp = pptx_ct_cdr_connector_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:pic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pic = NULL;
        } else {
            obj->pic = pptx_ct_cdr_picture_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pic = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_cdr_marker *
pptx_ct_cdr_abs_size_anchor_get_from(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->from;
}

pptx_ct_a_positive_size_2d *
pptx_ct_cdr_abs_size_anchor_get_ext(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->ext;
}

pptx_ct_cdr_shape *
pptx_ct_cdr_abs_size_anchor_get_sp(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->sp;
}

pptx_ct_cdr_group_shape *
pptx_ct_cdr_abs_size_anchor_get_grp_sp(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->grp_sp;
}

pptx_ct_cdr_graphic_frame *
pptx_ct_cdr_abs_size_anchor_get_graphic_frame(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->graphic_frame;
}

pptx_ct_cdr_connector *
pptx_ct_cdr_abs_size_anchor_get_cxn_sp(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->cxn_sp;
}

pptx_ct_cdr_picture *
pptx_ct_cdr_abs_size_anchor_get_pic(const pptx_ct_cdr_abs_size_anchor *const obj)
{
    return obj->pic;
}

int32_t
pptx_ct_cdr_abs_size_anchor_get_index(pptx_ct_cdr_abs_size_anchor *obj)
{
    return obj->index;
}

void
pptx_ct_cdr_abs_size_anchor_free(pptx_ct_cdr_abs_size_anchor *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_cdr_marker_free(obj->from);
    pptx_ct_a_positive_size_2d_free(obj->ext);
    pptx_ct_cdr_shape_free(obj->sp);
    pptx_ct_cdr_group_shape_free(obj->grp_sp);
    pptx_ct_cdr_graphic_frame_free(obj->graphic_frame);
    pptx_ct_cdr_connector_free(obj->cxn_sp);
    pptx_ct_cdr_picture_free(obj->pic);
    free(obj);
}