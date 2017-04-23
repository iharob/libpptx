#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-normal-view-portion.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_normal_view_portion_s {
    pptx_string sz;
    pptx_bool auto_adjust;
    int32_t index;
} pptx_ct_p_normal_view_portion;

pptx_ct_p_normal_view_portion *
pptx_ct_p_normal_view_portion_new(xmlNode *node)
{
    pptx_ct_p_normal_view_portion *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->sz = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sz");
    obj->auto_adjust = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "autoAdjust");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_normal_view_portion_get_sz(const pptx_ct_p_normal_view_portion *const obj)
{
    return obj->sz;
}

pptx_bool 
pptx_ct_p_normal_view_portion_get_auto_adjust(const pptx_ct_p_normal_view_portion *const obj)
{
    return obj->auto_adjust;
}

int32_t
pptx_ct_p_normal_view_portion_get_index(pptx_ct_p_normal_view_portion *obj)
{
    return obj->index;
}

void
pptx_ct_p_normal_view_portion_free(pptx_ct_p_normal_view_portion *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->sz);
    free(obj);
}