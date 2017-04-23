#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-style-label.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-scene-3d.h>
#include <private/pptx-ct-a-shape-3d.h>
#include <private/pptx-ct-dgm-text-props.h>
#include <private/pptx-ct-a-shape-style.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_dgm_style_label_s {
    pptx_ct_a_scene_3d *scene3d;
    pptx_ct_a_shape_3d *sp3d;
    pptx_ct_dgm_text_props *tx_pr;
    pptx_ct_a_shape_style *style;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_dgm_style_label;

pptx_ct_dgm_style_label *
pptx_ct_dgm_style_label_new(xmlNode *node)
{
    pptx_ct_dgm_style_label *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:scene3d");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->scene3d = NULL;
        } else {
            obj->scene3d = pptx_ct_a_scene_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->scene3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:sp3d");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp3d = NULL;
        } else {
            obj->sp3d = pptx_ct_a_shape_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_pr = NULL;
        } else {
            obj->tx_pr = pptx_ct_dgm_text_props_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:style");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->style = NULL;
        } else {
            obj->style = pptx_ct_a_shape_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:extLst");
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
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_scene_3d *
pptx_ct_dgm_style_label_get_scene3d(const pptx_ct_dgm_style_label *const obj)
{
    return obj->scene3d;
}

pptx_ct_a_shape_3d *
pptx_ct_dgm_style_label_get_sp3d(const pptx_ct_dgm_style_label *const obj)
{
    return obj->sp3d;
}

pptx_ct_dgm_text_props *
pptx_ct_dgm_style_label_get_tx_pr(const pptx_ct_dgm_style_label *const obj)
{
    return obj->tx_pr;
}

pptx_ct_a_shape_style *
pptx_ct_dgm_style_label_get_style(const pptx_ct_dgm_style_label *const obj)
{
    return obj->style;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_style_label_get_ext_lst(const pptx_ct_dgm_style_label *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_style_label_get_name(const pptx_ct_dgm_style_label *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_dgm_style_label_get_index(pptx_ct_dgm_style_label *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_style_label_free(pptx_ct_dgm_style_label *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_scene_3d_free(obj->scene3d);
    pptx_ct_a_shape_3d_free(obj->sp3d);
    pptx_ct_dgm_text_props_free(obj->tx_pr);
    pptx_ct_a_shape_style_free(obj->style);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}