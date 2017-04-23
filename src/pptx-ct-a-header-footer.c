#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-header-footer.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_header_footer_s {
    pptx_string odd_header;
    pptx_string odd_footer;
    pptx_string even_header;
    pptx_string even_footer;
    pptx_string first_header;
    pptx_string first_footer;
    pptx_bool align_with_margins;
    pptx_bool different_odd_even;
    pptx_bool different_first;
    int32_t index;
} pptx_ct_a_header_footer;

pptx_ct_a_header_footer *
pptx_ct_a_header_footer_new(xmlNode *node)
{
    pptx_ct_a_header_footer *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->odd_header = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:oddHeader");
    obj->odd_footer = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:oddFooter");
    obj->even_header = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:evenHeader");
    obj->even_footer = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:evenFooter");
    obj->first_header = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:firstHeader");
    obj->first_footer = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:firstFooter");
    obj->align_with_margins = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "alignWithMargins");
    obj->different_odd_even = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "differentOddEven");
    obj->different_first = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "differentFirst");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_header_footer_get_odd_header(const pptx_ct_a_header_footer *const obj)
{
    return obj->odd_header;
}

pptx_string 
pptx_ct_a_header_footer_get_odd_footer(const pptx_ct_a_header_footer *const obj)
{
    return obj->odd_footer;
}

pptx_string 
pptx_ct_a_header_footer_get_even_header(const pptx_ct_a_header_footer *const obj)
{
    return obj->even_header;
}

pptx_string 
pptx_ct_a_header_footer_get_even_footer(const pptx_ct_a_header_footer *const obj)
{
    return obj->even_footer;
}

pptx_string 
pptx_ct_a_header_footer_get_first_header(const pptx_ct_a_header_footer *const obj)
{
    return obj->first_header;
}

pptx_string 
pptx_ct_a_header_footer_get_first_footer(const pptx_ct_a_header_footer *const obj)
{
    return obj->first_footer;
}

pptx_bool 
pptx_ct_a_header_footer_get_align_with_margins(const pptx_ct_a_header_footer *const obj)
{
    return obj->align_with_margins;
}

pptx_bool 
pptx_ct_a_header_footer_get_different_odd_even(const pptx_ct_a_header_footer *const obj)
{
    return obj->different_odd_even;
}

pptx_bool 
pptx_ct_a_header_footer_get_different_first(const pptx_ct_a_header_footer *const obj)
{
    return obj->different_first;
}

int32_t
pptx_ct_a_header_footer_get_index(pptx_ct_a_header_footer *obj)
{
    return obj->index;
}

void
pptx_ct_a_header_footer_free(pptx_ct_a_header_footer *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->odd_header);
    xmlFree(obj->odd_footer);
    xmlFree(obj->even_header);
    xmlFree(obj->even_footer);
    xmlFree(obj->first_header);
    xmlFree(obj->first_footer);
    free(obj);
}