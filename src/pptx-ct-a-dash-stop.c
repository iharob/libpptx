#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-dash-stop.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_dash_stop_s {
    pptx_string d;
    pptx_string sp;
    int32_t index;
} pptx_ct_a_dash_stop;

pptx_ct_a_dash_stop *
pptx_ct_a_dash_stop_new(xmlNode *node)
{
    pptx_ct_a_dash_stop *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->d = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "d");
    obj->sp = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sp");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_dash_stop_get_d(const pptx_ct_a_dash_stop *const obj)
{
    return obj->d;
}

pptx_string 
pptx_ct_a_dash_stop_get_sp(const pptx_ct_a_dash_stop *const obj)
{
    return obj->sp;
}

int32_t
pptx_ct_a_dash_stop_get_index(pptx_ct_a_dash_stop *obj)
{
    return obj->index;
}

void
pptx_ct_a_dash_stop_free(pptx_ct_a_dash_stop *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->d);
    xmlFree(obj->sp);
    free(obj);
}