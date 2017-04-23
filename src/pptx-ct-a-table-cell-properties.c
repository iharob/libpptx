#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-cell-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-properties.h>
#include <private/pptx-ct-a-cell-3d.h>
#include <private/pptx-ct-a-no-fill-properties.h>
#include <private/pptx-ct-a-solid-color-fill-properties.h>
#include <private/pptx-ct-a-gradient-fill-properties.h>
#include <private/pptx-ct-a-blip-fill-properties.h>
#include <private/pptx-ct-a-pattern-fill-properties.h>
#include <private/pptx-ct-a-group-fill-properties.h>
#include <private/pptx-ct-a-headers.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-text-vertical-type.h>
#include <private/pptx-st-text-anchoring-type.h>
#include <private/pptx-st-text-horz-overflow-type.h>

typedef struct pptx_ct_a_table_cell_properties_s {
    pptx_ct_a_line_properties *ln_l;
    pptx_ct_a_line_properties *ln_r;
    pptx_ct_a_line_properties *ln_t;
    pptx_ct_a_line_properties *ln_b;
    pptx_ct_a_line_properties *ln_tl_to_br;
    pptx_ct_a_line_properties *ln_bl_to_tr;
    pptx_ct_a_cell_3d *cell_3d;
    pptx_ct_a_no_fill_properties *fill_properties_no_fill;
    pptx_ct_a_solid_color_fill_properties *fill_properties_solid_fill;
    pptx_ct_a_gradient_fill_properties *fill_properties_grad_fill;
    pptx_ct_a_blip_fill_properties *fill_properties_blip_fill;
    pptx_ct_a_pattern_fill_properties *fill_properties_patt_fill;
    pptx_ct_a_group_fill_properties *fill_properties_grp_fill;
    pptx_ct_a_headers *headers;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string mar_l;
    pptx_string mar_r;
    pptx_string mar_t;
    pptx_string mar_b;
    pptx_st_text_vertical_type_token_enum vert;
    pptx_st_text_anchoring_type_token_enum anchor;
    pptx_bool anchor_ctr;
    pptx_st_text_horz_overflow_type_token_enum horz_overflow;
    int32_t index;
} pptx_ct_a_table_cell_properties;

pptx_ct_a_table_cell_properties *
pptx_ct_a_table_cell_properties_new(xmlNode *node)
{
    pptx_ct_a_table_cell_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnL");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_l = NULL;
        } else {
            obj->ln_l = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_l = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnR");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_r = NULL;
        } else {
            obj->ln_r = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_r = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnT");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_t = NULL;
        } else {
            obj->ln_t = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_t = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnB");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_b = NULL;
        } else {
            obj->ln_b = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_b = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnTlToBr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_tl_to_br = NULL;
        } else {
            obj->ln_tl_to_br = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_tl_to_br = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnBlToTr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_bl_to_tr = NULL;
        } else {
            obj->ln_bl_to_tr = pptx_ct_a_line_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_bl_to_tr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cell3D");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cell_3d = NULL;
        } else {
            obj->cell_3d = pptx_ct_a_cell_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cell_3d = NULL;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:headers");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->headers = NULL;
        } else {
            obj->headers = pptx_ct_a_headers_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->headers = NULL;
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
    obj->mar_l = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "marL");
    obj->mar_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "marR");
    obj->mar_t = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "marT");
    obj->mar_b = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "marB");
    obj->vert = pptx_get_st_text_vertical_type(node, (const xmlChar *) "vert");
    obj->anchor = pptx_get_st_text_anchoring_type(node, (const xmlChar *) "anchor");
    obj->anchor_ctr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "anchorCtr");
    obj->horz_overflow = pptx_get_st_text_horz_overflow_type(node, (const xmlChar *) "horzOverflow");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_l(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_l;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_r(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_r;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_t(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_t;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_b(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_b;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_tl_to_br(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_tl_to_br;
}

pptx_ct_a_line_properties *
pptx_ct_a_table_cell_properties_get_ln_bl_to_tr(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ln_bl_to_tr;
}

pptx_ct_a_cell_3d *
pptx_ct_a_table_cell_properties_get_cell_3d(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->cell_3d;
}

pptx_ct_a_no_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_no_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_no_fill;
}

pptx_ct_a_solid_color_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_solid_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_solid_fill;
}

pptx_ct_a_gradient_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_grad_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_grad_fill;
}

pptx_ct_a_blip_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_blip_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_blip_fill;
}

pptx_ct_a_pattern_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_patt_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_patt_fill;
}

pptx_ct_a_group_fill_properties *
pptx_ct_a_table_cell_properties_get_fill_properties_grp_fill(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->fill_properties_grp_fill;
}

pptx_ct_a_headers *
pptx_ct_a_table_cell_properties_get_headers(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->headers;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_cell_properties_get_ext_lst(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_table_cell_properties_get_mar_l(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->mar_l;
}

pptx_string 
pptx_ct_a_table_cell_properties_get_mar_r(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->mar_r;
}

pptx_string 
pptx_ct_a_table_cell_properties_get_mar_t(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->mar_t;
}

pptx_string 
pptx_ct_a_table_cell_properties_get_mar_b(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->mar_b;
}

pptx_st_text_vertical_type_token_enum 
pptx_ct_a_table_cell_properties_get_vert(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->vert;
}

pptx_st_text_anchoring_type_token_enum 
pptx_ct_a_table_cell_properties_get_anchor(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->anchor;
}

pptx_bool 
pptx_ct_a_table_cell_properties_get_anchor_ctr(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->anchor_ctr;
}

pptx_st_text_horz_overflow_type_token_enum 
pptx_ct_a_table_cell_properties_get_horz_overflow(const pptx_ct_a_table_cell_properties *const obj)
{
    return obj->horz_overflow;
}

int32_t
pptx_ct_a_table_cell_properties_get_index(pptx_ct_a_table_cell_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_cell_properties_free(pptx_ct_a_table_cell_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_line_properties_free(obj->ln_l);
    pptx_ct_a_line_properties_free(obj->ln_r);
    pptx_ct_a_line_properties_free(obj->ln_t);
    pptx_ct_a_line_properties_free(obj->ln_b);
    pptx_ct_a_line_properties_free(obj->ln_tl_to_br);
    pptx_ct_a_line_properties_free(obj->ln_bl_to_tr);
    pptx_ct_a_cell_3d_free(obj->cell_3d);
    pptx_ct_a_no_fill_properties_free(obj->fill_properties_no_fill);
    pptx_ct_a_solid_color_fill_properties_free(obj->fill_properties_solid_fill);
    pptx_ct_a_gradient_fill_properties_free(obj->fill_properties_grad_fill);
    pptx_ct_a_blip_fill_properties_free(obj->fill_properties_blip_fill);
    pptx_ct_a_pattern_fill_properties_free(obj->fill_properties_patt_fill);
    pptx_ct_a_group_fill_properties_free(obj->fill_properties_grp_fill);
    pptx_ct_a_headers_free(obj->headers);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->mar_l);
    xmlFree(obj->mar_r);
    xmlFree(obj->mar_t);
    xmlFree(obj->mar_b);
    free(obj);
}