#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-2darc-to.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_path_2darc_to_s {
    pptx_string w_r;
    pptx_string h_r;
    pptx_string st_ang;
    pptx_string sw_ang;
    int32_t index;
} pptx_ct_a_path_2darc_to;

pptx_ct_a_path_2darc_to *
pptx_ct_a_path_2darc_to_new(xmlNode *node)
{
    pptx_ct_a_path_2darc_to *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->w_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "wR");
    obj->h_r = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "hR");
    obj->st_ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "stAng");
    obj->sw_ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "swAng");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_path_2darc_to_get_w_r(const pptx_ct_a_path_2darc_to *const obj)
{
    return obj->w_r;
}

pptx_string 
pptx_ct_a_path_2darc_to_get_h_r(const pptx_ct_a_path_2darc_to *const obj)
{
    return obj->h_r;
}

pptx_string 
pptx_ct_a_path_2darc_to_get_st_ang(const pptx_ct_a_path_2darc_to *const obj)
{
    return obj->st_ang;
}

pptx_string 
pptx_ct_a_path_2darc_to_get_sw_ang(const pptx_ct_a_path_2darc_to *const obj)
{
    return obj->sw_ang;
}

int32_t
pptx_ct_a_path_2darc_to_get_index(pptx_ct_a_path_2darc_to *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_2darc_to_free(pptx_ct_a_path_2darc_to *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->w_r);
    xmlFree(obj->h_r);
    xmlFree(obj->st_ang);
    xmlFree(obj->sw_ang);
    free(obj);
}