#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-comment.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-point-2d.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_comment_s {
    pptx_ct_a_point_2d *pos;
    pptx_string text;
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_uint author_id;
    pptx_string dt;
    pptx_uint idx;
    int32_t index;
} pptx_ct_p_comment;

pptx_ct_p_comment *
pptx_ct_p_comment_new(xmlNode *node)
{
    pptx_ct_p_comment *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pos = NULL;
        } else {
            obj->pos = pptx_ct_a_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pos = NULL;
    }
    obj->text = pptx_xml_get_content_as_string(node, (const xmlChar *) "p:text");

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
    obj->author_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "authorId");
    obj->dt = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "dt");
    obj->idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "idx");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_point_2d *
pptx_ct_p_comment_get_pos(const pptx_ct_p_comment *const obj)
{
    return obj->pos;
}

pptx_string 
pptx_ct_p_comment_get_text(const pptx_ct_p_comment *const obj)
{
    return obj->text;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_comment_get_ext_lst(const pptx_ct_p_comment *const obj)
{
    return obj->ext_lst;
}

pptx_uint 
pptx_ct_p_comment_get_author_id(const pptx_ct_p_comment *const obj)
{
    return obj->author_id;
}

pptx_string 
pptx_ct_p_comment_get_dt(const pptx_ct_p_comment *const obj)
{
    return obj->dt;
}

pptx_uint 
pptx_ct_p_comment_get_idx(const pptx_ct_p_comment *const obj)
{
    return obj->idx;
}

int32_t
pptx_ct_p_comment_get_index(pptx_ct_p_comment *obj)
{
    return obj->index;
}

void
pptx_ct_p_comment_free(pptx_ct_p_comment *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_point_2d_free(obj->pos);
    xmlFree(obj->text);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    xmlFree(obj->dt);
    free(obj);
}