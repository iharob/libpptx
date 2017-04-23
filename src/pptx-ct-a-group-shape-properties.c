#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-group-shape-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-group-transform-2d.h>
#include <private/pptx-ct-a-no-fill-properties.h>
#include <private/pptx-ct-a-solid-color-fill-properties.h>
#include <private/pptx-ct-a-gradient-fill-properties.h>
#include <private/pptx-ct-a-blip-fill-properties.h>
#include <private/pptx-ct-a-pattern-fill-properties.h>
#include <private/pptx-ct-a-group-fill-properties.h>
#include <private/pptx-ct-a-effect-list.h>
#include <private/pptx-ct-a-effect-container.h>
#include <private/pptx-ct-a-scene-3d.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-black-white-mode.h>

typedef struct pptx_ct_a_group_shape_properties_s {
    pptx_ct_a_group_transform_2d *xfrm;
    pptx_ct_a_no_fill_properties *fill_properties_no_fill;
    pptx_ct_a_solid_color_fill_properties *fill_properties_solid_fill;
    pptx_ct_a_gradient_fill_properties *fill_properties_grad_fill;
    pptx_ct_a_blip_fill_properties *fill_properties_blip_fill;
    pptx_ct_a_pattern_fill_properties *fill_properties_patt_fill;
    pptx_ct_a_group_fill_properties *fill_properties_grp_fill;
    pptx_ct_a_effect_list *effect_properties_effect_lst;
    pptx_ct_a_effect_container *effect_properties_effect_dag;
    pptx_ct_a_scene_3d *scene3d;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_black_white_mode_token_enum bw_mode;
    int32_t index;
} pptx_ct_a_group_shape_properties;

pptx_ct_a_group_shape_properties *
pptx_ct_a_group_shape_properties_new(xmlNode *node)
{
    pptx_ct_a_group_shape_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:xfrm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->xfrm = NULL;
        } else {
            obj->xfrm = pptx_ct_a_group_transform_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->xfrm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:noFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_no_fill = NULL;
        } else {
            obj->fill_properties_no_fill = pptx_ct_a_no_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_no_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:solidFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_solid_fill = NULL;
        } else {
            obj->fill_properties_solid_fill = pptx_ct_a_solid_color_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_solid_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gradFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_grad_fill = NULL;
        } else {
            obj->fill_properties_grad_fill = pptx_ct_a_gradient_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grad_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blipFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_blip_fill = NULL;
        } else {
            obj->fill_properties_blip_fill = pptx_ct_a_blip_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_blip_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pattFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_patt_fill = NULL;
        } else {
            obj->fill_properties_patt_fill = pptx_ct_a_pattern_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_patt_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_properties_grp_fill = NULL;
        } else {
            obj->fill_properties_grp_fill = pptx_ct_a_group_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grp_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_lst = NULL;
        } else {
            obj->effect_properties_effect_lst = pptx_ct_a_effect_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectDag");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_properties_effect_dag = NULL;
        } else {
            obj->effect_properties_effect_dag = pptx_ct_a_effect_container_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_properties_effect_dag = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:scene3d");
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
    obj->bw_mode = pptx_get_st_black_white_mode(node, (const xmlChar *) "bwMode");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_group_transform_2d *
pptx_ct_a_group_shape_properties_get_xfrm(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->xfrm;
}

pptx_ct_a_no_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_no_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_no_fill;
}

pptx_ct_a_solid_color_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_solid_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_solid_fill;
}

pptx_ct_a_gradient_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_grad_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_grad_fill;
}

pptx_ct_a_blip_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_blip_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_blip_fill;
}

pptx_ct_a_pattern_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_patt_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_patt_fill;
}

pptx_ct_a_group_fill_properties *
pptx_ct_a_group_shape_properties_get_fill_properties_grp_fill(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->fill_properties_grp_fill;
}

pptx_ct_a_effect_list *
pptx_ct_a_group_shape_properties_get_effect_properties_effect_lst(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->effect_properties_effect_lst;
}

pptx_ct_a_effect_container *
pptx_ct_a_group_shape_properties_get_effect_properties_effect_dag(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->effect_properties_effect_dag;
}

pptx_ct_a_scene_3d *
pptx_ct_a_group_shape_properties_get_scene3d(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->scene3d;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_group_shape_properties_get_ext_lst(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->ext_lst;
}

pptx_st_black_white_mode_token_enum 
pptx_ct_a_group_shape_properties_get_bw_mode(const pptx_ct_a_group_shape_properties *const obj)
{
    return obj->bw_mode;
}

int32_t
pptx_ct_a_group_shape_properties_get_index(pptx_ct_a_group_shape_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_group_shape_properties_free(pptx_ct_a_group_shape_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_group_transform_2d_free(obj->xfrm);
    pptx_ct_a_no_fill_properties_free(obj->fill_properties_no_fill);
    pptx_ct_a_solid_color_fill_properties_free(obj->fill_properties_solid_fill);
    pptx_ct_a_gradient_fill_properties_free(obj->fill_properties_grad_fill);
    pptx_ct_a_blip_fill_properties_free(obj->fill_properties_blip_fill);
    pptx_ct_a_pattern_fill_properties_free(obj->fill_properties_patt_fill);
    pptx_ct_a_group_fill_properties_free(obj->fill_properties_grp_fill);
    pptx_ct_a_effect_list_free(obj->effect_properties_effect_lst);
    pptx_ct_a_effect_container_free(obj->effect_properties_effect_dag);
    pptx_ct_a_scene_3d_free(obj->scene3d);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}