#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-dlbl.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-layout.h>
#include <private/pptx-ct-a-tx.h>
#include <private/pptx-ct-a-num-fmt.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-dlbl-pos.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_dlbl_s {
    pptx_uint idx;
    pptx_bool delete;
    pptx_ct_a_layout *group_dlbl_layout;
    pptx_ct_a_tx *group_dlbl_tx;
    pptx_ct_a_num_fmt *dlbl_shared_num_fmt;
    pptx_ct_a_shape_properties *dlbl_shared_sp_pr;
    pptx_ct_a_text_body *dlbl_shared_tx_pr;
    pptx_ct_a_dlbl_pos *dlbl_shared_d_lbl_pos;
    pptx_bool dlbl_shared_show_legend_key;
    pptx_bool dlbl_shared_show_val;
    pptx_bool dlbl_shared_show_cat_name;
    pptx_bool dlbl_shared_show_ser_name;
    pptx_bool dlbl_shared_show_percent;
    pptx_bool dlbl_shared_show_bubble_size;
    pptx_string dlbl_shared_separator;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_dlbl;

pptx_ct_a_dlbl *
pptx_ct_a_dlbl_new(xmlNode *node)
{
    pptx_ct_a_dlbl *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->idx = pptx_xml_get_content_as_uint(node, (const xmlChar *) "a:idx");
    obj->delete = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:delete");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:layout");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->group_dlbl_layout = NULL;
        } else {
            obj->group_dlbl_layout = pptx_ct_a_layout_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->group_dlbl_layout = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->group_dlbl_tx = NULL;
        } else {
            obj->group_dlbl_tx = pptx_ct_a_tx_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->group_dlbl_tx = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:numFmt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_num_fmt = NULL;
        } else {
            obj->dlbl_shared_num_fmt = pptx_ct_a_num_fmt_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_num_fmt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_sp_pr = NULL;
        } else {
            obj->dlbl_shared_sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_tx_pr = NULL;
        } else {
            obj->dlbl_shared_tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_tx_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLblPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_d_lbl_pos = NULL;
        } else {
            obj->dlbl_shared_d_lbl_pos = pptx_ct_a_dlbl_pos_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_d_lbl_pos = NULL;
    }
    obj->dlbl_shared_show_legend_key = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showLegendKey");
    obj->dlbl_shared_show_val = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showVal");
    obj->dlbl_shared_show_cat_name = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showCatName");
    obj->dlbl_shared_show_ser_name = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showSerName");
    obj->dlbl_shared_show_percent = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showPercent");
    obj->dlbl_shared_show_bubble_size = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showBubbleSize");
    obj->dlbl_shared_separator = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:separator");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_dlbl_get_idx(const pptx_ct_a_dlbl *const obj)
{
    return obj->idx;
}

pptx_bool 
pptx_ct_a_dlbl_get_delete(const pptx_ct_a_dlbl *const obj)
{
    return obj->delete;
}

pptx_ct_a_layout *
pptx_ct_a_dlbl_get_group_dlbl_layout(const pptx_ct_a_dlbl *const obj)
{
    return obj->group_dlbl_layout;
}

pptx_ct_a_tx *
pptx_ct_a_dlbl_get_group_dlbl_tx(const pptx_ct_a_dlbl *const obj)
{
    return obj->group_dlbl_tx;
}

pptx_ct_a_num_fmt *
pptx_ct_a_dlbl_get_dlbl_shared_num_fmt(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_num_fmt;
}

pptx_ct_a_shape_properties *
pptx_ct_a_dlbl_get_dlbl_shared_sp_pr(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_dlbl_get_dlbl_shared_tx_pr(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_tx_pr;
}

pptx_ct_a_dlbl_pos *
pptx_ct_a_dlbl_get_dlbl_shared_d_lbl_pos(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_d_lbl_pos;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_legend_key(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_legend_key;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_val(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_val;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_cat_name(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_cat_name;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_ser_name(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_ser_name;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_percent(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_percent;
}

pptx_bool 
pptx_ct_a_dlbl_get_dlbl_shared_show_bubble_size(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_show_bubble_size;
}

pptx_string 
pptx_ct_a_dlbl_get_dlbl_shared_separator(const pptx_ct_a_dlbl *const obj)
{
    return obj->dlbl_shared_separator;
}

pptx_ct_a_extension_list *
pptx_ct_a_dlbl_get_ext_lst(const pptx_ct_a_dlbl *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_dlbl_get_index(pptx_ct_a_dlbl *obj)
{
    return obj->index;
}

void
pptx_ct_a_dlbl_free(pptx_ct_a_dlbl *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_layout_free(obj->group_dlbl_layout);
    pptx_ct_a_tx_free(obj->group_dlbl_tx);
    pptx_ct_a_num_fmt_free(obj->dlbl_shared_num_fmt);
    pptx_ct_a_shape_properties_free(obj->dlbl_shared_sp_pr);
    pptx_ct_a_text_body_free(obj->dlbl_shared_tx_pr);
    pptx_ct_a_dlbl_pos_free(obj->dlbl_shared_d_lbl_pos);
    xmlFree(obj->dlbl_shared_separator);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}