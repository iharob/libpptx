#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-extension.h>
/* Imported internal stuff */
#include <private/pptx-any.h>

typedef struct pptx_ct_a_extension_s {
    pptx_any *items;
    pptx_string uri;
    int32_t index;
} pptx_ct_a_extension;

pptx_ct_a_extension *
pptx_ct_a_extension_new(xmlNode *node)
{
    pptx_ct_a_extension *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->items = pptx_any_new(node, 1);
    obj->uri = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "uri");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_any *
pptx_ct_a_extension_get_items(const pptx_ct_a_extension *const obj)
{
    return obj->items;
}

pptx_string 
pptx_ct_a_extension_get_uri(const pptx_ct_a_extension *const obj)
{
    return obj->uri;
}

int32_t
pptx_ct_a_extension_get_index(pptx_ct_a_extension *obj)
{
    return obj->index;
}

void
pptx_ct_a_extension_free(pptx_ct_a_extension *obj)
{
    if (obj == NULL)
        return;
    pptx_any_free(obj->items);
    xmlFree(obj->uri);
    free(obj);
}