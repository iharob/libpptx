#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-numeric-rule.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-constraint-type.h>
#include <private/pptx-st-constraint-relationship.h>
#include <private/pptx-st-element-type.h>

typedef struct pptx_ct_dgm_numeric_rule_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_constraint_type_token_enum type;
    pptx_st_constraint_relationship_token_enum _for;
    pptx_string for_name;
    pptx_st_element_type_token_enum pt_type;
    pptx_double val;
    pptx_double fact;
    pptx_double max;
    int32_t index;
} pptx_ct_dgm_numeric_rule;

pptx_ct_dgm_numeric_rule *
pptx_ct_dgm_numeric_rule_new(xmlNode *node)
{
    pptx_ct_dgm_numeric_rule *obj;
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
    obj->val = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "val");
    obj->fact = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "fact");
    obj->max = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "max");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_numeric_rule_get_ext_lst(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->ext_lst;
}

pptx_st_constraint_type_token_enum 
pptx_ct_dgm_numeric_rule_get_type(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->type;
}

pptx_st_constraint_relationship_token_enum 
pptx_ct_dgm_numeric_rule_get__for(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->_for;
}

pptx_string 
pptx_ct_dgm_numeric_rule_get_for_name(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->for_name;
}

pptx_st_element_type_token_enum 
pptx_ct_dgm_numeric_rule_get_pt_type(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->pt_type;
}

pptx_double 
pptx_ct_dgm_numeric_rule_get_val(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->val;
}

pptx_double 
pptx_ct_dgm_numeric_rule_get_fact(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->fact;
}

pptx_double 
pptx_ct_dgm_numeric_rule_get_max(const pptx_ct_dgm_numeric_rule *const obj)
{
    return obj->max;
}

int32_t
pptx_ct_dgm_numeric_rule_get_index(pptx_ct_dgm_numeric_rule *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_numeric_rule_free(pptx_ct_dgm_numeric_rule *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->for_name);
    free(obj);
}