#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-join-miter-properties.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_line_join_miter_properties_s {
    pptx_string lim;
    int32_t index;
} pptx_ct_a_line_join_miter_properties;

pptx_ct_a_line_join_miter_properties *
pptx_ct_a_line_join_miter_properties_new(xmlNode *node)
{
    pptx_ct_a_line_join_miter_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->lim = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lim");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_line_join_miter_properties_get_lim(const pptx_ct_a_line_join_miter_properties *const obj)
{
    return obj->lim;
}

int32_t
pptx_ct_a_line_join_miter_properties_get_index(pptx_ct_a_line_join_miter_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_join_miter_properties_free(pptx_ct_a_line_join_miter_properties *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->lim);
    free(obj);
}