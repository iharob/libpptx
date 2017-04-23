#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-headers.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_headers_s {
    pptx_string header;
    int32_t index;
} pptx_ct_a_headers;

pptx_ct_a_headers *
pptx_ct_a_headers_new(xmlNode *node)
{
    pptx_ct_a_headers *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->header = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:header");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_headers_get_header(const pptx_ct_a_headers *const obj)
{
    return obj->header;
}

int32_t
pptx_ct_a_headers_get_index(pptx_ct_a_headers *obj)
{
    return obj->index;
}

void
pptx_ct_a_headers_free(pptx_ct_a_headers *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->header);
    free(obj);
}