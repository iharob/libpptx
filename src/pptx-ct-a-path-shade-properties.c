#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-shade-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-relative-rect.h>
#include <private/pptx-st-path-shade-type.h>

typedef struct pptx_ct_a_path_shade_properties_s {
    pptx_ct_a_relative_rect *fill_to_rect;
    pptx_st_path_shade_type_token_enum path;
    int32_t index;
} pptx_ct_a_path_shade_properties;

pptx_ct_a_path_shade_properties *
pptx_ct_a_path_shade_properties_new(xmlNode *node)
{
    pptx_ct_a_path_shade_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fillToRect");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fill_to_rect = NULL;
        } else {
            obj->fill_to_rect = pptx_ct_a_relative_rect_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_to_rect = NULL;
    }
    obj->path = pptx_get_st_path_shade_type(node, (const xmlChar *) "path");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_relative_rect *
pptx_ct_a_path_shade_properties_get_fill_to_rect(const pptx_ct_a_path_shade_properties *const obj)
{
    return obj->fill_to_rect;
}

pptx_st_path_shade_type_token_enum 
pptx_ct_a_path_shade_properties_get_path(const pptx_ct_a_path_shade_properties *const obj)
{
    return obj->path;
}

int32_t
pptx_ct_a_path_shade_properties_get_index(pptx_ct_a_path_shade_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_shade_properties_free(pptx_ct_a_path_shade_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_relative_rect_free(obj->fill_to_rect);
    free(obj);
}