#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-page-margins.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_page_margins_s {
    pptx_double l;
    pptx_double r;
    pptx_double t;
    pptx_double b;
    pptx_double header;
    pptx_double footer;
    int32_t index;
} pptx_ct_a_page_margins;

pptx_ct_a_page_margins *
pptx_ct_a_page_margins_new(xmlNode *node)
{
    pptx_ct_a_page_margins *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->l = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "l");
    obj->r = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "r");
    obj->t = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "t");
    obj->b = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "b");
    obj->header = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "header");
    obj->footer = pptx_xml_get_attribute_as_double(node, (const xmlChar *) "footer");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_double 
pptx_ct_a_page_margins_get_l(const pptx_ct_a_page_margins *const obj)
{
    return obj->l;
}

pptx_double 
pptx_ct_a_page_margins_get_r(const pptx_ct_a_page_margins *const obj)
{
    return obj->r;
}

pptx_double 
pptx_ct_a_page_margins_get_t(const pptx_ct_a_page_margins *const obj)
{
    return obj->t;
}

pptx_double 
pptx_ct_a_page_margins_get_b(const pptx_ct_a_page_margins *const obj)
{
    return obj->b;
}

pptx_double 
pptx_ct_a_page_margins_get_header(const pptx_ct_a_page_margins *const obj)
{
    return obj->header;
}

pptx_double 
pptx_ct_a_page_margins_get_footer(const pptx_ct_a_page_margins *const obj)
{
    return obj->footer;
}

int32_t
pptx_ct_a_page_margins_get_index(pptx_ct_a_page_margins *obj)
{
    return obj->index;
}

void
pptx_ct_a_page_margins_free(pptx_ct_a_page_margins *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}