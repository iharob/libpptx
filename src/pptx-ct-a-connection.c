#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-connection.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_connection_s {
    pptx_uint id;
    pptx_uint idx;
    int32_t index;
} pptx_ct_a_connection;

pptx_ct_a_connection *
pptx_ct_a_connection_new(xmlNode *node)
{
    pptx_ct_a_connection *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->idx = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "idx");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_connection_get_id(const pptx_ct_a_connection *const obj)
{
    return obj->id;
}

pptx_uint 
pptx_ct_a_connection_get_idx(const pptx_ct_a_connection *const obj)
{
    return obj->idx;
}

int32_t
pptx_ct_a_connection_get_index(pptx_ct_a_connection *obj)
{
    return obj->index;
}

void
pptx_ct_a_connection_free(pptx_ct_a_connection *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}