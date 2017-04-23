#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-disp-units.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-built-in-unit.h>
#include <private/pptx-ct-a-disp-units-lbl.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_disp_units_s {
    pptx_ct_a_double *cust_unit;
    pptx_ct_a_built_in_unit *built_in_unit;
    pptx_ct_a_disp_units_lbl *disp_units_lbl;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_disp_units;

pptx_ct_a_disp_units *
pptx_ct_a_disp_units_new(xmlNode *node)
{
    pptx_ct_a_disp_units *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:custUnit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_unit = NULL;
        } else {
            obj->cust_unit = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_unit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:builtInUnit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->built_in_unit = NULL;
        } else {
            obj->built_in_unit = pptx_ct_a_built_in_unit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->built_in_unit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dispUnitsLbl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->disp_units_lbl = NULL;
        } else {
            obj->disp_units_lbl = pptx_ct_a_disp_units_lbl_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->disp_units_lbl = NULL;
    }

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

pptx_ct_a_double *
pptx_ct_a_disp_units_get_cust_unit(const pptx_ct_a_disp_units *const obj)
{
    return obj->cust_unit;
}

pptx_ct_a_built_in_unit *
pptx_ct_a_disp_units_get_built_in_unit(const pptx_ct_a_disp_units *const obj)
{
    return obj->built_in_unit;
}

pptx_ct_a_disp_units_lbl *
pptx_ct_a_disp_units_get_disp_units_lbl(const pptx_ct_a_disp_units *const obj)
{
    return obj->disp_units_lbl;
}

pptx_ct_a_extension_list *
pptx_ct_a_disp_units_get_ext_lst(const pptx_ct_a_disp_units *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_disp_units_get_index(pptx_ct_a_disp_units *obj)
{
    return obj->index;
}

void
pptx_ct_a_disp_units_free(pptx_ct_a_disp_units *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_double_free(obj->cust_unit);
    pptx_ct_a_built_in_unit_free(obj->built_in_unit);
    pptx_ct_a_disp_units_lbl_free(obj->disp_units_lbl);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}