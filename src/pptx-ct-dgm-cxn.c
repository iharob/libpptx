#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-cxn.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-cxn-type.h>

typedef struct pptx_ct_dgm_cxn_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string model_id;
    pptx_st_cxn_type_token_enum type;
    pptx_string src_id;
    pptx_string dest_id;
    pptx_uint src_ord;
    pptx_uint dest_ord;
    pptx_string par_trans_id;
    pptx_string sib_trans_id;
    pptx_string pres_id;
    int32_t index;
} pptx_ct_dgm_cxn;

pptx_ct_dgm_cxn *
pptx_ct_dgm_cxn_new(xmlNode *node)
{
    pptx_ct_dgm_cxn *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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
    obj->type = pptx_get_st_cxn_type(node, (const xmlChar *) "type");
    obj->src_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "srcId");
    obj->dest_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "destId");
    obj->src_ord = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "srcOrd");
    obj->dest_ord = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "destOrd");
    obj->par_trans_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "parTransId");
    obj->sib_trans_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sibTransId");
    obj->pres_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "presId");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_cxn_get_ext_lst(const pptx_ct_dgm_cxn *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_cxn_get_model_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->model_id;
}

pptx_st_cxn_type_token_enum 
pptx_ct_dgm_cxn_get_type(const pptx_ct_dgm_cxn *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_dgm_cxn_get_src_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->src_id;
}

pptx_string 
pptx_ct_dgm_cxn_get_dest_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->dest_id;
}

pptx_uint 
pptx_ct_dgm_cxn_get_src_ord(const pptx_ct_dgm_cxn *const obj)
{
    return obj->src_ord;
}

pptx_uint 
pptx_ct_dgm_cxn_get_dest_ord(const pptx_ct_dgm_cxn *const obj)
{
    return obj->dest_ord;
}

pptx_string 
pptx_ct_dgm_cxn_get_par_trans_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->par_trans_id;
}

pptx_string 
pptx_ct_dgm_cxn_get_sib_trans_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->sib_trans_id;
}

pptx_string 
pptx_ct_dgm_cxn_get_pres_id(const pptx_ct_dgm_cxn *const obj)
{
    return obj->pres_id;
}

int32_t
pptx_ct_dgm_cxn_get_index(pptx_ct_dgm_cxn *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_cxn_free(pptx_ct_dgm_cxn *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->model_id);
    xmlFree(obj->src_id);
    xmlFree(obj->dest_id);
    xmlFree(obj->par_trans_id);
    xmlFree(obj->sib_trans_id);
    xmlFree(obj->pres_id);
    free(obj);
}