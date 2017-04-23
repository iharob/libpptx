#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-elem-prop-set.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-layout-variable-property-set.h>
#include <private/pptx-ct-a-shape-style.h>

typedef struct pptx_ct_dgm_elem_prop_set_s {
    pptx_ct_dgm_layout_variable_property_set *pres_layout_vars;
    pptx_ct_a_shape_style *style;
    pptx_string pres_assoc_id;
    pptx_string pres_name;
    pptx_string pres_style_lbl;
    pptx_int pres_style_idx;
    pptx_int pres_style_cnt;
    pptx_string lo_type_id;
    pptx_string lo_cat_id;
    pptx_string qs_type_id;
    pptx_string qs_cat_id;
    pptx_string cs_type_id;
    pptx_string cs_cat_id;
    pptx_bool coherent_3doff;
    pptx_string phldr_t;
    pptx_bool phldr;
    pptx_int cust_ang;
    pptx_bool cust_flip_vert;
    pptx_bool cust_flip_hor;
    pptx_int cust_sz_x;
    pptx_int cust_sz_y;
    pptx_int cust_scale_x;
    pptx_int cust_scale_y;
    pptx_bool cust_t;
    pptx_int cust_lin_fact_x;
    pptx_int cust_lin_fact_y;
    pptx_int cust_lin_fact_neighbor_x;
    pptx_int cust_lin_fact_neighbor_y;
    pptx_int cust_rad_scale_rad;
    pptx_int cust_rad_scale_inc;
    int32_t index;
} pptx_ct_dgm_elem_prop_set;

pptx_ct_dgm_elem_prop_set *
pptx_ct_dgm_elem_prop_set_new(xmlNode *node)
{
    pptx_ct_dgm_elem_prop_set *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:presLayoutVars");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pres_layout_vars = NULL;
        } else {
            obj->pres_layout_vars = pptx_ct_dgm_layout_variable_property_set_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pres_layout_vars = NULL;
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
    obj->pres_assoc_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "presAssocID");
    obj->pres_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "presName");
    obj->pres_style_lbl = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "presStyleLbl");
    obj->pres_style_idx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "presStyleIdx");
    obj->pres_style_cnt = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "presStyleCnt");
    obj->lo_type_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "loTypeId");
    obj->lo_cat_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "loCatId");
    obj->qs_type_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "qsTypeId");
    obj->qs_cat_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "qsCatId");
    obj->cs_type_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "csTypeId");
    obj->cs_cat_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "csCatId");
    obj->coherent_3doff = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "coherent3DOff");
    obj->phldr_t = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "phldrT");
    obj->phldr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "phldr");
    obj->cust_ang = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custAng");
    obj->cust_flip_vert = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "custFlipVert");
    obj->cust_flip_hor = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "custFlipHor");
    obj->cust_sz_x = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custSzX");
    obj->cust_sz_y = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custSzY");
    obj->cust_scale_x = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custScaleX");
    obj->cust_scale_y = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custScaleY");
    obj->cust_t = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "custT");
    obj->cust_lin_fact_x = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custLinFactX");
    obj->cust_lin_fact_y = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custLinFactY");
    obj->cust_lin_fact_neighbor_x = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custLinFactNeighborX");
    obj->cust_lin_fact_neighbor_y = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custLinFactNeighborY");
    obj->cust_rad_scale_rad = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custRadScaleRad");
    obj->cust_rad_scale_inc = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "custRadScaleInc");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_layout_variable_property_set *
pptx_ct_dgm_elem_prop_set_get_pres_layout_vars(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_layout_vars;
}

pptx_ct_a_shape_style *
pptx_ct_dgm_elem_prop_set_get_style(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->style;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_pres_assoc_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_assoc_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_pres_name(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_name;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_pres_style_lbl(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_style_lbl;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_pres_style_idx(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_style_idx;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_pres_style_cnt(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->pres_style_cnt;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_lo_type_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->lo_type_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_lo_cat_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->lo_cat_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_qs_type_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->qs_type_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_qs_cat_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->qs_cat_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_cs_type_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cs_type_id;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_cs_cat_id(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cs_cat_id;
}

pptx_bool 
pptx_ct_dgm_elem_prop_set_get_coherent_3doff(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->coherent_3doff;
}

pptx_string 
pptx_ct_dgm_elem_prop_set_get_phldr_t(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->phldr_t;
}

pptx_bool 
pptx_ct_dgm_elem_prop_set_get_phldr(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->phldr;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_ang(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_ang;
}

pptx_bool 
pptx_ct_dgm_elem_prop_set_get_cust_flip_vert(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_flip_vert;
}

pptx_bool 
pptx_ct_dgm_elem_prop_set_get_cust_flip_hor(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_flip_hor;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_sz_x(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_sz_x;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_sz_y(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_sz_y;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_scale_x(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_scale_x;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_scale_y(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_scale_y;
}

pptx_bool 
pptx_ct_dgm_elem_prop_set_get_cust_t(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_t;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_lin_fact_x(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_lin_fact_x;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_lin_fact_y(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_lin_fact_y;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_lin_fact_neighbor_x(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_lin_fact_neighbor_x;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_lin_fact_neighbor_y(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_lin_fact_neighbor_y;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_rad_scale_rad(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_rad_scale_rad;
}

pptx_int 
pptx_ct_dgm_elem_prop_set_get_cust_rad_scale_inc(const pptx_ct_dgm_elem_prop_set *const obj)
{
    return obj->cust_rad_scale_inc;
}

int32_t
pptx_ct_dgm_elem_prop_set_get_index(pptx_ct_dgm_elem_prop_set *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_elem_prop_set_free(pptx_ct_dgm_elem_prop_set *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_layout_variable_property_set_free(obj->pres_layout_vars);
    pptx_ct_a_shape_style_free(obj->style);
    xmlFree(obj->pres_assoc_id);
    xmlFree(obj->pres_name);
    xmlFree(obj->pres_style_lbl);
    xmlFree(obj->lo_type_id);
    xmlFree(obj->lo_cat_id);
    xmlFree(obj->qs_type_id);
    xmlFree(obj->qs_cat_id);
    xmlFree(obj->cs_type_id);
    xmlFree(obj->cs_cat_id);
    xmlFree(obj->phldr_t);
    free(obj);
}