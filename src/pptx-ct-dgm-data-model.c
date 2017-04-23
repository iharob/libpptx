#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-data-model.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-pt-list.h>
#include <private/pptx-ct-dgm-cxn-list.h>
#include <private/pptx-ct-a-background-formatting.h>
#include <private/pptx-ct-a-whole-e2o-formatting.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_dgm_data_model_s {
    pptx_ct_dgm_pt_list *pt_lst;
    pptx_ct_dgm_cxn_list *cxn_lst;
    pptx_ct_a_background_formatting *bg;
    pptx_ct_a_whole_e2o_formatting *whole;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_dgm_data_model;

pptx_ct_dgm_data_model *
pptx_ct_dgm_data_model_new(xmlNode *node)
{
    pptx_ct_dgm_data_model *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:ptLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pt_lst = NULL;
        } else {
            obj->pt_lst = pptx_ct_dgm_pt_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pt_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:cxnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cxn_lst = NULL;
        } else {
            obj->cxn_lst = pptx_ct_dgm_cxn_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:bg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bg = NULL;
        } else {
            obj->bg = pptx_ct_a_background_formatting_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:whole");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->whole = NULL;
        } else {
            obj->whole = pptx_ct_a_whole_e2o_formatting_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->whole = NULL;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_pt_list *
pptx_ct_dgm_data_model_get_pt_lst(const pptx_ct_dgm_data_model *const obj)
{
    return obj->pt_lst;
}

pptx_ct_dgm_cxn_list *
pptx_ct_dgm_data_model_get_cxn_lst(const pptx_ct_dgm_data_model *const obj)
{
    return obj->cxn_lst;
}

pptx_ct_a_background_formatting *
pptx_ct_dgm_data_model_get_bg(const pptx_ct_dgm_data_model *const obj)
{
    return obj->bg;
}

pptx_ct_a_whole_e2o_formatting *
pptx_ct_dgm_data_model_get_whole(const pptx_ct_dgm_data_model *const obj)
{
    return obj->whole;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_data_model_get_ext_lst(const pptx_ct_dgm_data_model *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_dgm_data_model_get_index(pptx_ct_dgm_data_model *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_data_model_free(pptx_ct_dgm_data_model *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_pt_list_free(obj->pt_lst);
    pptx_ct_dgm_cxn_list_free(obj->cxn_lst);
    pptx_ct_a_background_formatting_free(obj->bg);
    pptx_ct_a_whole_e2o_formatting_free(obj->whole);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}