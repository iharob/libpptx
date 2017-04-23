#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-shape-3d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-bevel.h>
#include <private/pptx-ct-a-color.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-preset-material-type.h>

typedef struct pptx_ct_a_shape_3d_s {
    pptx_ct_a_bevel *bevel_t;
    pptx_ct_a_bevel *bevel_b;
    pptx_ct_a_color *extrusion_clr;
    pptx_ct_a_color *contour_clr;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string z;
    pptx_long extrusion_h;
    pptx_long contour_w;
    pptx_st_preset_material_type_token_enum prst_material;
    int32_t index;
} pptx_ct_a_shape_3d;

pptx_ct_a_shape_3d *
pptx_ct_a_shape_3d_new(xmlNode *node)
{
    pptx_ct_a_shape_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bevelT");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bevel_t = NULL;
        } else {
            obj->bevel_t = pptx_ct_a_bevel_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bevel_t = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bevelB");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bevel_b = NULL;
        } else {
            obj->bevel_b = pptx_ct_a_bevel_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bevel_b = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extrusionClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->extrusion_clr = NULL;
        } else {
            obj->extrusion_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->extrusion_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:contourClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->contour_clr = NULL;
        } else {
            obj->contour_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->contour_clr = NULL;
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
    obj->z = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "z");
    obj->extrusion_h = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "extrusionH");
    obj->contour_w = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "contourW");
    obj->prst_material = pptx_get_st_preset_material_type(node, (const xmlChar *) "prstMaterial");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_bevel *
pptx_ct_a_shape_3d_get_bevel_t(const pptx_ct_a_shape_3d *const obj)
{
    return obj->bevel_t;
}

pptx_ct_a_bevel *
pptx_ct_a_shape_3d_get_bevel_b(const pptx_ct_a_shape_3d *const obj)
{
    return obj->bevel_b;
}

pptx_ct_a_color *
pptx_ct_a_shape_3d_get_extrusion_clr(const pptx_ct_a_shape_3d *const obj)
{
    return obj->extrusion_clr;
}

pptx_ct_a_color *
pptx_ct_a_shape_3d_get_contour_clr(const pptx_ct_a_shape_3d *const obj)
{
    return obj->contour_clr;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_shape_3d_get_ext_lst(const pptx_ct_a_shape_3d *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_shape_3d_get_z(const pptx_ct_a_shape_3d *const obj)
{
    return obj->z;
}

pptx_long 
pptx_ct_a_shape_3d_get_extrusion_h(const pptx_ct_a_shape_3d *const obj)
{
    return obj->extrusion_h;
}

pptx_long 
pptx_ct_a_shape_3d_get_contour_w(const pptx_ct_a_shape_3d *const obj)
{
    return obj->contour_w;
}

pptx_st_preset_material_type_token_enum 
pptx_ct_a_shape_3d_get_prst_material(const pptx_ct_a_shape_3d *const obj)
{
    return obj->prst_material;
}

int32_t
pptx_ct_a_shape_3d_get_index(pptx_ct_a_shape_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_shape_3d_free(pptx_ct_a_shape_3d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_bevel_free(obj->bevel_t);
    pptx_ct_a_bevel_free(obj->bevel_b);
    pptx_ct_a_color_free(obj->extrusion_clr);
    pptx_ct_a_color_free(obj->contour_clr);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->z);
    free(obj);
}