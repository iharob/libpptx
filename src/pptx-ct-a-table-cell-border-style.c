#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-cell-border-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-themeable-line-style.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_table_cell_border_style_s {
    pptx_ct_a_themeable_line_style *left;
    pptx_ct_a_themeable_line_style *right;
    pptx_ct_a_themeable_line_style *top;
    pptx_ct_a_themeable_line_style *bottom;
    pptx_ct_a_themeable_line_style *inside_h;
    pptx_ct_a_themeable_line_style *inside_v;
    pptx_ct_a_themeable_line_style *tl2br;
    pptx_ct_a_themeable_line_style *tr2bl;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_table_cell_border_style;

pptx_ct_a_table_cell_border_style *
pptx_ct_a_table_cell_border_style_new(xmlNode *node)
{
    pptx_ct_a_table_cell_border_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:left");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->left = NULL;
        } else {
            obj->left = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->left = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:right");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->right = NULL;
        } else {
            obj->right = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->right = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:top");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->top = NULL;
        } else {
            obj->top = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->top = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bottom");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bottom = NULL;
        } else {
            obj->bottom = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bottom = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:insideH");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->inside_h = NULL;
        } else {
            obj->inside_h = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->inside_h = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:insideV");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->inside_v = NULL;
        } else {
            obj->inside_v = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->inside_v = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tl2br");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tl2br = NULL;
        } else {
            obj->tl2br = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tl2br = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tr2bl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tr2bl = NULL;
        } else {
            obj->tr2bl = pptx_ct_a_themeable_line_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tr2bl = NULL;
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

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_left(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->left;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_right(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->right;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_top(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->top;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_bottom(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->bottom;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_inside_h(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->inside_h;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_inside_v(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->inside_v;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_tl2br(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->tl2br;
}

pptx_ct_a_themeable_line_style *
pptx_ct_a_table_cell_border_style_get_tr2bl(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->tr2bl;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_table_cell_border_style_get_ext_lst(const pptx_ct_a_table_cell_border_style *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_table_cell_border_style_get_index(pptx_ct_a_table_cell_border_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_cell_border_style_free(pptx_ct_a_table_cell_border_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_themeable_line_style_free(obj->left);
    pptx_ct_a_themeable_line_style_free(obj->right);
    pptx_ct_a_themeable_line_style_free(obj->top);
    pptx_ct_a_themeable_line_style_free(obj->bottom);
    pptx_ct_a_themeable_line_style_free(obj->inside_h);
    pptx_ct_a_themeable_line_style_free(obj->inside_v);
    pptx_ct_a_themeable_line_style_free(obj->tl2br);
    pptx_ct_a_themeable_line_style_free(obj->tr2bl);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}