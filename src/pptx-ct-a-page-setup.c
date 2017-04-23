#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-page-setup.h>
/* Imported internal stuff */
#include <private/pptx-st-page-setup-orientation.h>

typedef struct pptx_ct_a_page_setup_s {
    pptx_uint paper_size;
    pptx_string paper_height;
    pptx_string paper_width;
    pptx_uint first_page_number;
    pptx_st_page_setup_orientation_text_enum orientation;
    pptx_bool black_and_white;
    pptx_bool draft;
    pptx_bool use_first_page_number;
    pptx_int horizontal_dpi;
    pptx_int vertical_dpi;
    pptx_uint copies;
    int32_t index;
} pptx_ct_a_page_setup;

pptx_ct_a_page_setup *
pptx_ct_a_page_setup_new(xmlNode *node)
{
    pptx_ct_a_page_setup *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->paper_size = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "paperSize");
    obj->paper_height = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "paperHeight");
    obj->paper_width = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "paperWidth");
    obj->first_page_number = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "firstPageNumber");
    obj->orientation = pptx_get_st_page_setup_orientation(node, (const xmlChar *) "orientation");
    obj->black_and_white = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "blackAndWhite");
    obj->draft = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "draft");
    obj->use_first_page_number = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useFirstPageNumber");
    obj->horizontal_dpi = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "horizontalDpi");
    obj->vertical_dpi = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "verticalDpi");
    obj->copies = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "copies");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_a_page_setup_get_paper_size(const pptx_ct_a_page_setup *const obj)
{
    return obj->paper_size;
}

pptx_string 
pptx_ct_a_page_setup_get_paper_height(const pptx_ct_a_page_setup *const obj)
{
    return obj->paper_height;
}

pptx_string 
pptx_ct_a_page_setup_get_paper_width(const pptx_ct_a_page_setup *const obj)
{
    return obj->paper_width;
}

pptx_uint 
pptx_ct_a_page_setup_get_first_page_number(const pptx_ct_a_page_setup *const obj)
{
    return obj->first_page_number;
}

pptx_st_page_setup_orientation_text_enum 
pptx_ct_a_page_setup_get_orientation(const pptx_ct_a_page_setup *const obj)
{
    return obj->orientation;
}

pptx_bool 
pptx_ct_a_page_setup_get_black_and_white(const pptx_ct_a_page_setup *const obj)
{
    return obj->black_and_white;
}

pptx_bool 
pptx_ct_a_page_setup_get_draft(const pptx_ct_a_page_setup *const obj)
{
    return obj->draft;
}

pptx_bool 
pptx_ct_a_page_setup_get_use_first_page_number(const pptx_ct_a_page_setup *const obj)
{
    return obj->use_first_page_number;
}

pptx_int 
pptx_ct_a_page_setup_get_horizontal_dpi(const pptx_ct_a_page_setup *const obj)
{
    return obj->horizontal_dpi;
}

pptx_int 
pptx_ct_a_page_setup_get_vertical_dpi(const pptx_ct_a_page_setup *const obj)
{
    return obj->vertical_dpi;
}

pptx_uint 
pptx_ct_a_page_setup_get_copies(const pptx_ct_a_page_setup *const obj)
{
    return obj->copies;
}

int32_t
pptx_ct_a_page_setup_get_index(pptx_ct_a_page_setup *obj)
{
    return obj->index;
}

void
pptx_ct_a_page_setup_free(pptx_ct_a_page_setup *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->paper_height);
    xmlFree(obj->paper_width);
    free(obj);
}