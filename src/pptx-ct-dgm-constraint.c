#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-constraint.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-constraint-type.h>
#include <private/pptx-st-constraint-relationship.h>
#include <private/pptx-st-element-type.h>
#include <private/pptx-st-bool-operator.h>

typedef struct pptx_ct_dgm_constraint_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_constraint_type_token_enum type;
    pptx_st_constraint_relationship_token_enum _for;
    pptx_string for_name;
    pptx_st_element_type_token_enum pt_type;
    pptx_st_constraint_type_token_enum ref_type;
    pptx_st_constraint_relationship_token_enum ref_for;
    pptx_string ref_for_name;
    pptx_st_element_type_token_enum ref_pt_type;
    pptx_st_bool_operator_token_enum op;
    pptx_double val;
    pptx_double fact;
    int32_t index;
} pptx_ct_dgm_constraint;

pptx_ct_dgm_constraint *
pptx_ct_dgm_constraint_new(xmlNode *node)
{
    pptx_ct_dgm_constraint *obj;
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
    obj->type = pptx_get_st_constraint_type(node, (const xmlChar *) "type");
    obj->_for = pptx_get_st_constraint_relationship(node, (const xmlChar *) "for");
    obj->for_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "forName");
    obj->pt_type = pptx_get_st_element_type(node, (const xmlChar *) "ptType");
    obj->ref_type = pptx_get_st_constraint_type(node, (const xmlChar *) "refType");
    obj->ref_for = pptx_get_st_constraint_relationship(node, (const xmlChar *) "refFor");
    obj->ref_for_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "refForName");
    obj->ref_pt_type = pptx_get_st_element_type(node, (const xmlChar *) "refPtType");
    obj->op = pptx_get_st_bool_operator(node, (const xmlChar *) "op");
    obj->val = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "val");
    obj->fact = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "fact");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_constraint_get_ext_lst(const pptx_ct_dgm_constraint *const obj)
{
    return obj->ext_lst;
}

pptx_st_constraint_type_token_enum 
pptx_ct_dgm_constraint_get_type(const pptx_ct_dgm_constraint *const obj)
{
    return obj->type;
}

pptx_st_constraint_relationship_token_enum 
pptx_ct_dgm_constraint_get__for(const pptx_ct_dgm_constraint *const obj)
{
    return obj->_for;
}

pptx_string 
pptx_ct_dgm_constraint_get_for_name(const pptx_ct_dgm_constraint *const obj)
{
    return obj->for_name;
}

pptx_st_element_type_token_enum 
pptx_ct_dgm_constraint_get_pt_type(const pptx_ct_dgm_constraint *const obj)
{
    return obj->pt_type;
}

pptx_st_constraint_type_token_enum 
pptx_ct_dgm_constraint_get_ref_type(const pptx_ct_dgm_constraint *const obj)
{
    return obj->ref_type;
}

pptx_st_constraint_relationship_token_enum 
pptx_ct_dgm_constraint_get_ref_for(const pptx_ct_dgm_constraint *const obj)
{
    return obj->ref_for;
}

pptx_string 
pptx_ct_dgm_constraint_get_ref_for_name(const pptx_ct_dgm_constraint *const obj)
{
    return obj->ref_for_name;
}

pptx_st_element_type_token_enum 
pptx_ct_dgm_constraint_get_ref_pt_type(const pptx_ct_dgm_constraint *const obj)
{
    return obj->ref_pt_type;
}

pptx_st_bool_operator_token_enum 
pptx_ct_dgm_constraint_get_op(const pptx_ct_dgm_constraint *const obj)
{
    return obj->op;
}

pptx_double 
pptx_ct_dgm_constraint_get_val(const pptx_ct_dgm_constraint *const obj)
{
    return obj->val;
}

pptx_double 
pptx_ct_dgm_constraint_get_fact(const pptx_ct_dgm_constraint *const obj)
{
    return obj->fact;
}

int32_t
pptx_ct_dgm_constraint_get_index(pptx_ct_dgm_constraint *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_constraint_free(pptx_ct_dgm_constraint *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->for_name);
    xmlFree(obj->ref_for_name);
    free(obj);
}