#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-adj-lst.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-shape-type.h>

typedef struct pptx_ct_dgm_shape_s {
    pptx_ct_dgm_adj_lst *adj_lst;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_double rot;
    pptx_st_shape_type_token_enum type;
    pptx_string blip;
    pptx_int z_order_off;
    pptx_bool hide_geom;
    pptx_bool lk_tx_entry;
    pptx_bool blip_phldr;
    int32_t index;
} pptx_ct_dgm_shape;

pptx_ct_dgm_shape *
pptx_ct_dgm_shape_new(xmlNode *node)
{
    pptx_ct_dgm_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:adjLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->adj_lst = NULL;
        } else {
            obj->adj_lst = pptx_ct_dgm_adj_lst_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->adj_lst = NULL;
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
    obj->rot = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "rot");
    obj->type = pptx_get_st_shape_type(node, (const xmlChar *) "type");
    obj->blip = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:blip");
    obj->z_order_off = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "zOrderOff");
    obj->hide_geom = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hideGeom");
    obj->lk_tx_entry = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "lkTxEntry");
    obj->blip_phldr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "blipPhldr");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_adj_lst *
pptx_ct_dgm_shape_get_adj_lst(const pptx_ct_dgm_shape *const obj)
{
    return obj->adj_lst;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_shape_get_ext_lst(const pptx_ct_dgm_shape *const obj)
{
    return obj->ext_lst;
}

pptx_double 
pptx_ct_dgm_shape_get_rot(const pptx_ct_dgm_shape *const obj)
{
    return obj->rot;
}

pptx_st_shape_type_token_enum 
pptx_ct_dgm_shape_get_type(const pptx_ct_dgm_shape *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_dgm_shape_get_blip(const pptx_ct_dgm_shape *const obj)
{
    return obj->blip;
}

pptx_int 
pptx_ct_dgm_shape_get_z_order_off(const pptx_ct_dgm_shape *const obj)
{
    return obj->z_order_off;
}

pptx_bool 
pptx_ct_dgm_shape_get_hide_geom(const pptx_ct_dgm_shape *const obj)
{
    return obj->hide_geom;
}

pptx_bool 
pptx_ct_dgm_shape_get_lk_tx_entry(const pptx_ct_dgm_shape *const obj)
{
    return obj->lk_tx_entry;
}

pptx_bool 
pptx_ct_dgm_shape_get_blip_phldr(const pptx_ct_dgm_shape *const obj)
{
    return obj->blip_phldr;
}

int32_t
pptx_ct_dgm_shape_get_index(pptx_ct_dgm_shape *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_shape_free(pptx_ct_dgm_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_adj_lst_free(obj->adj_lst);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->blip);
    free(obj);
}