#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-num-fmt.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_num_fmt_s {
    pptx_string format_code;
    pptx_bool source_linked;
    int32_t index;
} pptx_ct_a_num_fmt;

pptx_ct_a_num_fmt *
pptx_ct_a_num_fmt_new(xmlNode *node)
{
    pptx_ct_a_num_fmt *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->format_code = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "formatCode");
    obj->source_linked = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "sourceLinked");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_num_fmt_get_format_code(const pptx_ct_a_num_fmt *const obj)
{
    return obj->format_code;
}

pptx_bool 
pptx_ct_a_num_fmt_get_source_linked(const pptx_ct_a_num_fmt *const obj)
{
    return obj->source_linked;
}

int32_t
pptx_ct_a_num_fmt_get_index(pptx_ct_a_num_fmt *obj)
{
    return obj->index;
}

void
pptx_ct_a_num_fmt_free(pptx_ct_a_num_fmt *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->format_code);
    free(obj);
}