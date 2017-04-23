#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-placeholder.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list-modify.h>
#include <private/pptx-st-placeholder-type.h>
#include <private/pptx-st-direction.h>
#include <private/pptx-st-placeholder-size.h>

typedef struct pptx_ct_p_placeholder_s {
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_st_placeholder_type_token_enum type;
    pptx_st_direction_token_enum orient;
    pptx_st_placeholder_size_token_enum sz;
    pptx_uint idx;
    pptx_bool has_custom_prompt;
    int32_t index;
} pptx_ct_p_placeholder;

pptx_ct_p_placeholder *
pptx_ct_p_placeholder_new(xmlNode *node)
{
    pptx_ct_p_placeholder *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->type = pptx_get_st_placeholder_type(node, (const xmlChar *) "type");
    obj->orient = pptx_get_st_direction(node, (const xmlChar *) "orient");
    obj->sz = pptx_get_st_placeholder_size(node, (const xmlChar *) "sz");
    obj->idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "idx");
    obj->has_custom_prompt = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hasCustomPrompt");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_placeholder_get_ext_lst(const pptx_ct_p_placeholder *const obj)
{
    return obj->ext_lst;
}

pptx_st_placeholder_type_token_enum 
pptx_ct_p_placeholder_get_type(const pptx_ct_p_placeholder *const obj)
{
    return obj->type;
}

pptx_st_direction_token_enum 
pptx_ct_p_placeholder_get_orient(const pptx_ct_p_placeholder *const obj)
{
    return obj->orient;
}

pptx_st_placeholder_size_token_enum 
pptx_ct_p_placeholder_get_sz(const pptx_ct_p_placeholder *const obj)
{
    return obj->sz;
}

pptx_uint 
pptx_ct_p_placeholder_get_idx(const pptx_ct_p_placeholder *const obj)
{
    return obj->idx;
}

pptx_bool 
pptx_ct_p_placeholder_get_has_custom_prompt(const pptx_ct_p_placeholder *const obj)
{
    return obj->has_custom_prompt;
}

int32_t
pptx_ct_p_placeholder_get_index(pptx_ct_p_placeholder *obj)
{
    return obj->index;
}

void
pptx_ct_p_placeholder_free(pptx_ct_p_placeholder *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}