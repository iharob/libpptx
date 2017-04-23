#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-ctstyle-label.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-colors.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_dgm_ctstyle_label_s {
    pptx_ct_dgm_colors *fill_clr_lst;
    pptx_ct_dgm_colors *lin_clr_lst;
    pptx_ct_dgm_colors *effect_clr_lst;
    pptx_ct_dgm_colors *tx_lin_clr_lst;
    pptx_ct_dgm_colors *tx_fill_clr_lst;
    pptx_ct_dgm_colors *tx_effect_clr_lst;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_dgm_ctstyle_label;

pptx_ct_dgm_ctstyle_label *
pptx_ct_dgm_ctstyle_label_new(xmlNode *node)
{
    pptx_ct_dgm_ctstyle_label *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:fillClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_clr_lst = NULL;
        } else {
            obj->fill_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_clr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:linClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lin_clr_lst = NULL;
        } else {
            obj->lin_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lin_clr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:effectClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->effect_clr_lst = NULL;
        } else {
            obj->effect_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_clr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:txLinClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_lin_clr_lst = NULL;
        } else {
            obj->tx_lin_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_lin_clr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:txFillClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_fill_clr_lst = NULL;
        } else {
            obj->tx_fill_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_fill_clr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:txEffectClrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_effect_clr_lst = NULL;
        } else {
            obj->tx_effect_clr_lst = pptx_ct_dgm_colors_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_effect_clr_lst = NULL;
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
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_fill_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->fill_clr_lst;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_lin_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->lin_clr_lst;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_effect_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->effect_clr_lst;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_tx_lin_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->tx_lin_clr_lst;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_tx_fill_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->tx_fill_clr_lst;
}

pptx_ct_dgm_colors *
pptx_ct_dgm_ctstyle_label_get_tx_effect_clr_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->tx_effect_clr_lst;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_ctstyle_label_get_ext_lst(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_ctstyle_label_get_name(const pptx_ct_dgm_ctstyle_label *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_dgm_ctstyle_label_get_index(pptx_ct_dgm_ctstyle_label *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_ctstyle_label_free(pptx_ct_dgm_ctstyle_label *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_colors_free(obj->fill_clr_lst);
    pptx_ct_dgm_colors_free(obj->lin_clr_lst);
    pptx_ct_dgm_colors_free(obj->effect_clr_lst);
    pptx_ct_dgm_colors_free(obj->tx_lin_clr_lst);
    pptx_ct_dgm_colors_free(obj->tx_fill_clr_lst);
    pptx_ct_dgm_colors_free(obj->tx_effect_clr_lst);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}