#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-clipboard-style-sheet.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-base-styles.h>
#include <private/pptx-ct-a-color-mapping.h>

typedef struct pptx_ct_a_clipboard_style_sheet_s {
    pptx_ct_a_base_styles *theme_elements;
    pptx_ct_a_color_mapping *clr_map;
    int32_t index;
} pptx_ct_a_clipboard_style_sheet;

pptx_ct_a_clipboard_style_sheet *
pptx_ct_a_clipboard_style_sheet_new(xmlNode *node)
{
    pptx_ct_a_clipboard_style_sheet *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:themeElements");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->theme_elements = NULL;
        } else {
            obj->theme_elements = pptx_ct_a_base_styles_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->theme_elements = NULL;
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

pptx_ct_a_base_styles *
pptx_ct_a_clipboard_style_sheet_get_theme_elements(const pptx_ct_a_clipboard_style_sheet *const obj)
{
    return obj->theme_elements;
}

pptx_ct_a_color_mapping *
pptx_ct_a_clipboard_style_sheet_get_clr_map(const pptx_ct_a_clipboard_style_sheet *const obj)
{
    return obj->clr_map;
}

int32_t
pptx_ct_a_clipboard_style_sheet_get_index(pptx_ct_a_clipboard_style_sheet *obj)
{
    return obj->index;
}

void
pptx_ct_a_clipboard_style_sheet_free(pptx_ct_a_clipboard_style_sheet *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_base_styles_free(obj->theme_elements);
    pptx_ct_a_color_mapping_free(obj->clr_map);
    free(obj);
}