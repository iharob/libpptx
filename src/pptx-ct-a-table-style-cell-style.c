#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-table-style-cell-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-table-cell-border-style.h>
#include <private/pptx-ct-a-fill-properties.h>
#include <private/pptx-ct-a-style-matrix-reference.h>
#include <private/pptx-ct-a-cell-3d.h>

typedef struct pptx_ct_a_table_style_cell_style_s {
    pptx_ct_a_table_cell_border_style *tc_bdr;
    pptx_ct_a_fill_properties *themeable_fill_style_fill;
    pptx_ct_a_style_matrix_reference *themeable_fill_style_fill_ref;
    pptx_ct_a_cell_3d *cell_3d;
    int32_t index;
} pptx_ct_a_table_style_cell_style;

pptx_ct_a_table_style_cell_style *
pptx_ct_a_table_style_cell_style_new(xmlNode *node)
{
    pptx_ct_a_table_style_cell_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:tcBdr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tc_bdr = NULL;
        } else {
            obj->tc_bdr = pptx_ct_a_table_cell_border_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tc_bdr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_fill_style_fill = NULL;
        } else {
            obj->themeable_fill_style_fill = pptx_ct_a_fill_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_fill_style_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->themeable_fill_style_fill_ref = NULL;
        } else {
            obj->themeable_fill_style_fill_ref = pptx_ct_a_style_matrix_reference_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->themeable_fill_style_fill_ref = NULL;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_table_cell_border_style *
pptx_ct_a_table_style_cell_style_get_tc_bdr(const pptx_ct_a_table_style_cell_style *const obj)
{
    return obj->tc_bdr;
}

pptx_ct_a_fill_properties *
pptx_ct_a_table_style_cell_style_get_themeable_fill_style_fill(const pptx_ct_a_table_style_cell_style *const obj)
{
    return obj->themeable_fill_style_fill;
}

pptx_ct_a_style_matrix_reference *
pptx_ct_a_table_style_cell_style_get_themeable_fill_style_fill_ref(const pptx_ct_a_table_style_cell_style *const obj)
{
    return obj->themeable_fill_style_fill_ref;
}

pptx_ct_a_cell_3d *
pptx_ct_a_table_style_cell_style_get_cell_3d(const pptx_ct_a_table_style_cell_style *const obj)
{
    return obj->cell_3d;
}

int32_t
pptx_ct_a_table_style_cell_style_get_index(pptx_ct_a_table_style_cell_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_table_style_cell_style_free(pptx_ct_a_table_style_cell_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_table_cell_border_style_free(obj->tc_bdr);
    pptx_ct_a_fill_properties_free(obj->themeable_fill_style_fill);
    pptx_ct_a_style_matrix_reference_free(obj->themeable_fill_style_fill_ref);
    pptx_ct_a_cell_3d_free(obj->cell_3d);
    free(obj);
}