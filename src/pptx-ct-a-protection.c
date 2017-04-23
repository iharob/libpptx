#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-protection.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_protection_s {
    pptx_bool chart_object;
    pptx_bool data;
    pptx_bool formatting;
    pptx_bool selection;
    pptx_bool user_interface;
    int32_t index;
} pptx_ct_a_protection;

pptx_ct_a_protection *
pptx_ct_a_protection_new(xmlNode *node)
{
    pptx_ct_a_protection *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->chart_object = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:chartObject");
    obj->data = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:data");
    obj->formatting = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:formatting");
    obj->selection = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:selection");
    obj->user_interface = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:userInterface");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_a_protection_get_chart_object(const pptx_ct_a_protection *const obj)
{
    return obj->chart_object;
}

pptx_bool 
pptx_ct_a_protection_get_data(const pptx_ct_a_protection *const obj)
{
    return obj->data;
}

pptx_bool 
pptx_ct_a_protection_get_formatting(const pptx_ct_a_protection *const obj)
{
    return obj->formatting;
}

pptx_bool 
pptx_ct_a_protection_get_selection(const pptx_ct_a_protection *const obj)
{
    return obj->selection;
}

pptx_bool 
pptx_ct_a_protection_get_user_interface(const pptx_ct_a_protection *const obj)
{
    return obj->user_interface;
}

int32_t
pptx_ct_a_protection_get_index(pptx_ct_a_protection *obj)
{
    return obj->index;
}

void
pptx_ct_a_protection_free(pptx_ct_a_protection *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}