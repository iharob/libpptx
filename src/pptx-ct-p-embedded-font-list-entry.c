#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-embedded-font-list-entry.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-font.h>
#include <private/pptx-ct-p-embedded-font-data-id.h>

typedef struct pptx_ct_p_embedded_font_list_entry_s {
    pptx_ct_a_text_font *font;
    pptx_ct_p_embedded_font_data_id *regular;
    pptx_ct_p_embedded_font_data_id *bold;
    pptx_ct_p_embedded_font_data_id *italic;
    pptx_ct_p_embedded_font_data_id *bold_italic;
    int32_t index;
} pptx_ct_p_embedded_font_list_entry;

pptx_ct_p_embedded_font_list_entry *
pptx_ct_p_embedded_font_list_entry_new(xmlNode *node)
{
    pptx_ct_p_embedded_font_list_entry *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:font");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->font = NULL;
        } else {
            obj->font = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->font = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:regular");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->regular = NULL;
        } else {
            obj->regular = pptx_ct_p_embedded_font_data_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->regular = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bold");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bold = NULL;
        } else {
            obj->bold = pptx_ct_p_embedded_font_data_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bold = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:italic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->italic = NULL;
        } else {
            obj->italic = pptx_ct_p_embedded_font_data_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->italic = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:boldItalic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bold_italic = NULL;
        } else {
            obj->bold_italic = pptx_ct_p_embedded_font_data_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bold_italic = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_font *
pptx_ct_p_embedded_font_list_entry_get_font(const pptx_ct_p_embedded_font_list_entry *const obj)
{
    return obj->font;
}

pptx_ct_p_embedded_font_data_id *
pptx_ct_p_embedded_font_list_entry_get_regular(const pptx_ct_p_embedded_font_list_entry *const obj)
{
    return obj->regular;
}

pptx_ct_p_embedded_font_data_id *
pptx_ct_p_embedded_font_list_entry_get_bold(const pptx_ct_p_embedded_font_list_entry *const obj)
{
    return obj->bold;
}

pptx_ct_p_embedded_font_data_id *
pptx_ct_p_embedded_font_list_entry_get_italic(const pptx_ct_p_embedded_font_list_entry *const obj)
{
    return obj->italic;
}

pptx_ct_p_embedded_font_data_id *
pptx_ct_p_embedded_font_list_entry_get_bold_italic(const pptx_ct_p_embedded_font_list_entry *const obj)
{
    return obj->bold_italic;
}

int32_t
pptx_ct_p_embedded_font_list_entry_get_index(pptx_ct_p_embedded_font_list_entry *obj)
{
    return obj->index;
}

void
pptx_ct_p_embedded_font_list_entry_free(pptx_ct_p_embedded_font_list_entry *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_font_free(obj->font);
    pptx_ct_p_embedded_font_data_id_free(obj->regular);
    pptx_ct_p_embedded_font_data_id_free(obj->bold);
    pptx_ct_p_embedded_font_data_id_free(obj->italic);
    pptx_ct_p_embedded_font_data_id_free(obj->bold_italic);
    free(obj);
}