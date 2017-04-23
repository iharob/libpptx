#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-scheme-and-mapping.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color-scheme.h>
#include <private/pptx-ct-a-color-mapping.h>

typedef struct pptx_ct_a_color_scheme_and_mapping_s {
    pptx_ct_a_color_scheme *clr_scheme;
    pptx_ct_a_color_mapping *clr_map;
    int32_t index;
} pptx_ct_a_color_scheme_and_mapping;

pptx_ct_a_color_scheme_and_mapping *
pptx_ct_a_color_scheme_and_mapping_new(xmlNode *node)
{
    pptx_ct_a_color_scheme_and_mapping *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrScheme");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_scheme = NULL;
        } else {
            obj->clr_scheme = pptx_ct_a_color_scheme_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_scheme = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:clrMap");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_map = NULL;
        } else {
            obj->clr_map = pptx_ct_a_color_mapping_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_map = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color_scheme *
pptx_ct_a_color_scheme_and_mapping_get_clr_scheme(const pptx_ct_a_color_scheme_and_mapping *const obj)
{
    return obj->clr_scheme;
}

pptx_ct_a_color_mapping *
pptx_ct_a_color_scheme_and_mapping_get_clr_map(const pptx_ct_a_color_scheme_and_mapping *const obj)
{
    return obj->clr_map;
}

int32_t
pptx_ct_a_color_scheme_and_mapping_get_index(pptx_ct_a_color_scheme_and_mapping *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_scheme_and_mapping_free(pptx_ct_a_color_scheme_and_mapping *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_color_scheme_free(obj->clr_scheme);
    pptx_ct_a_color_mapping_free(obj->clr_map);
    free(obj);
}