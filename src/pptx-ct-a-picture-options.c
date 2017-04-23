#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-picture-options.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-picture-format.h>
#include <private/pptx-ct-a-picture-stack-unit.h>

typedef struct pptx_ct_a_picture_options_s {
    pptx_bool apply_to_front;
    pptx_bool apply_to_sides;
    pptx_bool apply_to_end;
    pptx_ct_a_picture_format *picture_format;
    pptx_ct_a_picture_stack_unit *picture_stack_unit;
    int32_t index;
} pptx_ct_a_picture_options;

pptx_ct_a_picture_options *
pptx_ct_a_picture_options_new(xmlNode *node)
{
    pptx_ct_a_picture_options *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->apply_to_front = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:applyToFront");
    obj->apply_to_sides = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:applyToSides");
    obj->apply_to_end = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:applyToEnd");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pictureFormat");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->picture_format = NULL;
        } else {
            obj->picture_format = pptx_ct_a_picture_format_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->picture_format = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pictureStackUnit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->picture_stack_unit = NULL;
        } else {
            obj->picture_stack_unit = pptx_ct_a_picture_stack_unit_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->picture_stack_unit = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_a_picture_options_get_apply_to_front(const pptx_ct_a_picture_options *const obj)
{
    return obj->apply_to_front;
}

pptx_bool 
pptx_ct_a_picture_options_get_apply_to_sides(const pptx_ct_a_picture_options *const obj)
{
    return obj->apply_to_sides;
}

pptx_bool 
pptx_ct_a_picture_options_get_apply_to_end(const pptx_ct_a_picture_options *const obj)
{
    return obj->apply_to_end;
}

pptx_ct_a_picture_format *
pptx_ct_a_picture_options_get_picture_format(const pptx_ct_a_picture_options *const obj)
{
    return obj->picture_format;
}

pptx_ct_a_picture_stack_unit *
pptx_ct_a_picture_options_get_picture_stack_unit(const pptx_ct_a_picture_options *const obj)
{
    return obj->picture_stack_unit;
}

int32_t
pptx_ct_a_picture_options_get_index(pptx_ct_a_picture_options *obj)
{
    return obj->index;
}

void
pptx_ct_a_picture_options_free(pptx_ct_a_picture_options *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_picture_format_free(obj->picture_format);
    pptx_ct_a_picture_stack_unit_free(obj->picture_stack_unit);
    free(obj);
}