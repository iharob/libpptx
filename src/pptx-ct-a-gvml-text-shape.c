#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-gvml-text-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-gvml-use-shape-rectangle.h>
#include <private/pptx-ct-a-transform-2d.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_gvml_text_shape_s {
    pptx_ct_a_text_body *tx_body;
    pptx_ct_a_gvml_use_shape_rectangle *use_sp_rect;
    pptx_ct_a_transform_2d *xfrm;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_gvml_text_shape;

pptx_ct_a_gvml_text_shape *
pptx_ct_a_gvml_text_shape_new(xmlNode *node)
{
    pptx_ct_a_gvml_text_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txBody");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_body = NULL;
        } else {
            obj->tx_body = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_body = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:useSpRect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->use_sp_rect = NULL;
        } else {
            obj->use_sp_rect = pptx_ct_a_gvml_use_shape_rectangle_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->use_sp_rect = NULL;
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

pptx_ct_a_text_body *
pptx_ct_a_gvml_text_shape_get_tx_body(const pptx_ct_a_gvml_text_shape *const obj)
{
    return obj->tx_body;
}

pptx_ct_a_gvml_use_shape_rectangle *
pptx_ct_a_gvml_text_shape_get_use_sp_rect(const pptx_ct_a_gvml_text_shape *const obj)
{
    return obj->use_sp_rect;
}

pptx_ct_a_transform_2d *
pptx_ct_a_gvml_text_shape_get_xfrm(const pptx_ct_a_gvml_text_shape *const obj)
{
    return obj->xfrm;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_gvml_text_shape_get_ext_lst(const pptx_ct_a_gvml_text_shape *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_gvml_text_shape_get_index(pptx_ct_a_gvml_text_shape *obj)
{
    return obj->index;
}

void
pptx_ct_a_gvml_text_shape_free(pptx_ct_a_gvml_text_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_body_free(obj->tx_body);
    pptx_ct_a_gvml_use_shape_rectangle_free(obj->use_sp_rect);
    pptx_ct_a_transform_2d_free(obj->xfrm);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}