#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-custom-show-id.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_custom_show_id_s {
    pptx_uint id;
    int32_t index;
} pptx_ct_p_custom_show_id;

pptx_ct_p_custom_show_id *
pptx_ct_p_custom_show_id_new(xmlNode *node)
{
    pptx_ct_p_custom_show_id *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_custom_show_id_get_id(const pptx_ct_p_custom_show_id *const obj)
{
    return obj->id;
}

int32_t
pptx_ct_p_custom_show_id_get_index(pptx_ct_p_custom_show_id *obj)
{
    return obj->index;
}

void
pptx_ct_p_custom_show_id_free(pptx_ct_p_custom_show_id *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}