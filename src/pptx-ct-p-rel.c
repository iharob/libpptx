#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-rel.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_rel_s {
    pptx_string r_id;
    int32_t index;
} pptx_ct_p_rel;

pptx_ct_p_rel *
pptx_ct_p_rel_new(xmlNode *node)
{
    pptx_ct_p_rel *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_rel_get_r_id(const pptx_ct_p_rel *const obj)
{
    return obj->r_id;
}

int32_t
pptx_ct_p_rel_get_index(pptx_ct_p_rel *obj)
{
    return obj->index;
}

void
pptx_ct_p_rel_free(pptx_ct_p_rel *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->r_id);
    free(obj);
}