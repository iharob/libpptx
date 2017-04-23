#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-background-style.h>
#include <private/pptx-ct-a-table-part-style.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_table_style_s {
    pptx_ct_a_table_background_style *tbl_bg;
    pptx_ct_a_table_part_style *whole_tbl;
    pptx_ct_a_table_part_style *band1_h;
    pptx_ct_a_table_part_style *band2_h;
    pptx_ct_a_table_part_style *band1_v;
    pptx_ct_a_table_part_style *band2_v;
    pptx_ct_a_table_part_style *last_col;
    pptx_ct_a_table_part_style *first_col;
    pptx_ct_a_table_part_style *last_row;
    pptx_ct_a_table_part_style *se_cell;
    pptx_ct_a_table_part_style *sw_cell;
    pptx_ct_a_table_part_style *first_row;
    pptx_ct_a_table_part_style *ne_cell;
    pptx_ct_a_table_part_style *nw_cell;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string style_id;
    pptx_string style_name;
    int32_t index;
} pptx_ct_a_table_style;

pptx_ct_a_table_style *
pptx_ct_a_table_style_new(xmlNode *node)
{
    pptx_ct_a_table_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tblBg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tbl_bg = NULL;
        } else {
            obj->tbl_bg = pptx_ct_a_table_background_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tbl_bg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:wholeTbl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->whole_tbl = NULL;
        } else {
            obj->whole_tbl = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->whole_tbl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:band1H");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->band1_h = NULL;
        } else {
            obj->band1_h = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->band1_h = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:band2H");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->band2_h = NULL;
        } else {
            obj->band2_h = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->band2_h = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:band1V");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->band1_v = NULL;
        } else {
            obj->band1_v = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->band1_v = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:band2V");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->band2_v = NULL;
        } else {
            obj->band2_v = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->band2_v = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lastCol");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->last_col = NULL;
        } else {
            obj->last_col = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->last_col = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:firstCol");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->first_col = NULL;
        } else {
            obj->first_col = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->first_col = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lastRow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->last_row = NULL;
        } else {
            obj->last_row = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->last_row = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:seCell");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->se_cell = NULL;
        } else {
            obj->se_cell = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->se_cell = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:swCell");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sw_cell = NULL;
        } else {
            obj->sw_cell = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sw_cell = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:firstRow");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->first_row = NULL;
        } else {
            obj->first_row = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->first_row = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:neCell");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ne_cell = NULL;
        } else {
            obj->ne_cell = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ne_cell = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:nwCell");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nw_cell = NULL;
        } else {
            obj->nw_cell = pptx_ct_a_table_part_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nw_cell = NULL;
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
    obj->style_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "styleId");
    obj->style_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "styleName");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_background_style *
pptx_ct_a_table_style_get_tbl_bg(const pptx_ct_a_table_style *const obj)
{
    return obj->tbl_bg;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_whole_tbl(const pptx_ct_a_table_style *const obj)
{
    return obj->whole_tbl;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_band1_h(const pptx_ct_a_table_style *const obj)
{
    return obj->band1_h;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_band2_h(const pptx_ct_a_table_style *const obj)
{
    return obj->band2_h;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_band1_v(const pptx_ct_a_table_style *const obj)
{
    return obj->band1_v;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_band2_v(const pptx_ct_a_table_style *const obj)
{
    return obj->band2_v;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_last_col(const pptx_ct_a_table_style *const obj)
{
    return obj->last_col;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_first_col(const pptx_ct_a_table_style *const obj)
{
    return obj->first_col;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_last_row(const pptx_ct_a_table_style *const obj)
{
    return obj->last_row;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_se_cell(const pptx_ct_a_table_style *const obj)
{
    return obj->se_cell;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_sw_cell(const pptx_ct_a_table_style *const obj)
{
    return obj->sw_cell;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_first_row(const pptx_ct_a_table_style *const obj)
{
    return obj->first_row;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_ne_cell(const pptx_ct_a_table_style *const obj)
{
    return obj->ne_cell;
}

pptx_ct_a_table_part_style *
pptx_ct_a_table_style_get_nw_cell(const pptx_ct_a_table_style *const obj)
{
    return obj->nw_cell;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_style_get_ext_lst(const pptx_ct_a_table_style *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_table_style_get_style_id(const pptx_ct_a_table_style *const obj)
{
    return obj->style_id;
}

pptx_string 
pptx_ct_a_table_style_get_style_name(const pptx_ct_a_table_style *const obj)
{
    return obj->style_name;
}

int32_t
pptx_ct_a_table_style_get_index(pptx_ct_a_table_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_style_free(pptx_ct_a_table_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_table_background_style_free(obj->tbl_bg);
    pptx_ct_a_table_part_style_free(obj->whole_tbl);
    pptx_ct_a_table_part_style_free(obj->band1_h);
    pptx_ct_a_table_part_style_free(obj->band2_h);
    pptx_ct_a_table_part_style_free(obj->band1_v);
    pptx_ct_a_table_part_style_free(obj->band2_v);
    pptx_ct_a_table_part_style_free(obj->last_col);
    pptx_ct_a_table_part_style_free(obj->first_col);
    pptx_ct_a_table_part_style_free(obj->last_row);
    pptx_ct_a_table_part_style_free(obj->se_cell);
    pptx_ct_a_table_part_style_free(obj->sw_cell);
    pptx_ct_a_table_part_style_free(obj->first_row);
    pptx_ct_a_table_part_style_free(obj->ne_cell);
    pptx_ct_a_table_part_style_free(obj->nw_cell);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->style_id);
    xmlFree(obj->style_name);
    free(obj);
}