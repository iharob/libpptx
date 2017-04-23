#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-string-tag.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_string_tag_s {
    pptx_string name;
    pptx_string val;
    int32_t index;
} pptx_ct_p_string_tag;

pptx_ct_p_string_tag *
pptx_ct_p_string_tag_new(xmlNode *node)
{
    pptx_ct_p_string_tag *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->val = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_string_tag_get_name(const pptx_ct_p_string_tag *const obj)
{
    return obj->name;
}

pptx_string 
pptx_ct_p_string_tag_get_val(const pptx_ct_p_string_tag *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_p_string_tag_get_index(pptx_ct_p_string_tag *obj)
{
    return obj->index;
}

void
pptx_ct_p_string_tag_free(pptx_ct_p_string_tag *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->name);
    xmlFree(obj->val);
    free(obj);
}