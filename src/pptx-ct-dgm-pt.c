#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-pt.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-elem-prop-set.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-pt-type.h>

typedef struct pptx_ct_dgm_pt_s {
    pptx_ct_dgm_elem_prop_set *pr_set;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *t;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string model_id;
    pptx_st_pt_type_token_enum type;
    pptx_string cxn_id;
    int32_t index;
} pptx_ct_dgm_pt;

pptx_ct_dgm_pt *
pptx_ct_dgm_pt_new(xmlNode *node)
{
    pptx_ct_dgm_pt *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:prSet");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pr_set = NULL;
        } else {
            obj->pr_set = pptx_ct_dgm_elem_prop_set_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pr_set = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:t");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->t = NULL;
        } else {
            obj->t = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->t = NULL;
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
    obj->model_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "modelId");
    obj->type = pptx_get_st_pt_type(node, (const xmlChar *) "type");
    obj->cxn_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "cxnId");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_elem_prop_set *
pptx_ct_dgm_pt_get_pr_set(const pptx_ct_dgm_pt *const obj)
{
    return obj->pr_set;
}

pptx_ct_a_shape_properties *
pptx_ct_dgm_pt_get_sp_pr(const pptx_ct_dgm_pt *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_dgm_pt_get_t(const pptx_ct_dgm_pt *const obj)
{
    return obj->t;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_pt_get_ext_lst(const pptx_ct_dgm_pt *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_pt_get_model_id(const pptx_ct_dgm_pt *const obj)
{
    return obj->model_id;
}

pptx_st_pt_type_token_enum 
pptx_ct_dgm_pt_get_type(const pptx_ct_dgm_pt *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_dgm_pt_get_cxn_id(const pptx_ct_dgm_pt *const obj)
{
    return obj->cxn_id;
}

int32_t
pptx_ct_dgm_pt_get_index(pptx_ct_dgm_pt *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_pt_free(pptx_ct_dgm_pt *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_elem_prop_set_free(obj->pr_set);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->t);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->model_id);
    xmlFree(obj->cxn_id);
    free(obj);
}