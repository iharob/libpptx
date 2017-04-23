#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-flat-text.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_flat_text_s {
    pptx_string z;
    int32_t index;
} pptx_ct_a_flat_text;

pptx_ct_a_flat_text *
pptx_ct_a_flat_text_new(xmlNode *node)
{
    pptx_ct_a_flat_text *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->z = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "z");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_flat_text_get_z(const pptx_ct_a_flat_text *const obj)
{
    return obj->z;
}

int32_t
pptx_ct_a_flat_text_get_index(pptx_ct_a_flat_text *obj)
{
    return obj->index;
}

void
pptx_ct_a_flat_text_free(pptx_ct_a_flat_text *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->z);
    free(obj);
}