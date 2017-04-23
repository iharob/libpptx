#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-category.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_category_s {
    pptx_string type;
    pptx_uint pri;
    int32_t index;
} pptx_ct_dgm_category;

pptx_ct_dgm_category *
pptx_ct_dgm_category_new(xmlNode *node)
{
    pptx_ct_dgm_category *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->type = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "type");
    obj->pri = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "pri");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_dgm_category_get_type(const pptx_ct_dgm_category *const obj)
{
    return obj->type;
}

pptx_uint 
pptx_ct_dgm_category_get_pri(const pptx_ct_dgm_category *const obj)
{
    return obj->pri;
}

int32_t
pptx_ct_dgm_category_get_index(pptx_ct_dgm_category *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_category_free(pptx_ct_dgm_category *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->type);
    free(obj);
}