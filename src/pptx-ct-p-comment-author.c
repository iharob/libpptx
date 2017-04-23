#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-comment-author.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_comment_author_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_uint id;
    pptx_string name;
    pptx_string initials;
    pptx_uint last_idx;
    pptx_uint clr_idx;
    int32_t index;
} pptx_ct_p_comment_author;

pptx_ct_p_comment_author *
pptx_ct_p_comment_author_new(xmlNode *node)
{
    pptx_ct_p_comment_author *obj;
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
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->initials = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "initials");
    obj->last_idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "lastIdx");
    obj->clr_idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "clrIdx");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_comment_author_get_ext_lst(const pptx_ct_p_comment_author *const obj)
{
    return obj->ext_lst;
}

pptx_uint 
pptx_ct_p_comment_author_get_id(const pptx_ct_p_comment_author *const obj)
{
    return obj->id;
}

pptx_string 
pptx_ct_p_comment_author_get_name(const pptx_ct_p_comment_author *const obj)
{
    return obj->name;
}

pptx_string 
pptx_ct_p_comment_author_get_initials(const pptx_ct_p_comment_author *const obj)
{
    return obj->initials;
}

pptx_uint 
pptx_ct_p_comment_author_get_last_idx(const pptx_ct_p_comment_author *const obj)
{
    return obj->last_idx;
}

pptx_uint 
pptx_ct_p_comment_author_get_clr_idx(const pptx_ct_p_comment_author *const obj)
{
    return obj->clr_idx;
}

int32_t
pptx_ct_p_comment_author_get_index(pptx_ct_p_comment_author *obj)
{
    return obj->index;
}

void
pptx_ct_p_comment_author_free(pptx_ct_p_comment_author *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    xmlFree(obj->initials);
    free(obj);
}