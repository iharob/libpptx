#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-pattern-fill-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color.h>
#include <private/pptx-st-preset-pattern-val.h>

typedef struct pptx_ct_a_pattern_fill_properties_s {
    pptx_ct_a_color *fg_clr;
    pptx_ct_a_color *bg_clr;
    pptx_st_preset_pattern_val_token_enum prst;
    int32_t index;
} pptx_ct_a_pattern_fill_properties;

pptx_ct_a_pattern_fill_properties *
pptx_ct_a_pattern_fill_properties_new(xmlNode *node)
{
    pptx_ct_a_pattern_fill_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fgClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fg_clr = NULL;
        } else {
            obj->fg_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fg_clr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bgClr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bg_clr = NULL;
        } else {
            obj->bg_clr = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bg_clr = NULL;
    }
    obj->prst = pptx_get_st_preset_pattern_val(node, (const xmlChar *) "prst");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color *
pptx_ct_a_pattern_fill_properties_get_fg_clr(const pptx_ct_a_pattern_fill_properties *const obj)
{
    return obj->fg_clr;
}

pptx_ct_a_color *
pptx_ct_a_pattern_fill_properties_get_bg_clr(const pptx_ct_a_pattern_fill_properties *const obj)
{
    return obj->bg_clr;
}

pptx_st_preset_pattern_val_token_enum 
pptx_ct_a_pattern_fill_properties_get_prst(const pptx_ct_a_pattern_fill_properties *const obj)
{
    return obj->prst;
}

int32_t
pptx_ct_a_pattern_fill_properties_get_index(pptx_ct_a_pattern_fill_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_pattern_fill_properties_free(pptx_ct_a_pattern_fill_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_color_free(obj->fg_clr);
    pptx_ct_a_color_free(obj->bg_clr);
    free(obj);
}