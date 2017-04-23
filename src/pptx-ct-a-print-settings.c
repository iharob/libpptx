#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-print-settings.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-header-footer.h>
#include <private/pptx-ct-a-page-margins.h>
#include <private/pptx-ct-a-page-setup.h>
#include <private/pptx-ct-a-rel-id.h>

typedef struct pptx_ct_a_print_settings_s {
    pptx_ct_a_header_footer *header_footer;
    pptx_ct_a_page_margins *page_margins;
    pptx_ct_a_page_setup *page_setup;
    pptx_ct_a_rel_id *legacy_drawing_hf;
    int32_t index;
} pptx_ct_a_print_settings;

pptx_ct_a_print_settings *
pptx_ct_a_print_settings_new(xmlNode *node)
{
    pptx_ct_a_print_settings *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:headerFooter");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->header_footer = NULL;
        } else {
            obj->header_footer = pptx_ct_a_header_footer_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->header_footer = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pageMargins");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->page_margins = NULL;
        } else {
            obj->page_margins = pptx_ct_a_page_margins_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->page_margins = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pageSetup");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->page_setup = NULL;
        } else {
            obj->page_setup = pptx_ct_a_page_setup_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->page_setup = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:legacyDrawingHF");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->legacy_drawing_hf = NULL;
        } else {
            obj->legacy_drawing_hf = pptx_ct_a_rel_id_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->legacy_drawing_hf = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_header_footer *
pptx_ct_a_print_settings_get_header_footer(const pptx_ct_a_print_settings *const obj)
{
    return obj->header_footer;
}

pptx_ct_a_page_margins *
pptx_ct_a_print_settings_get_page_margins(const pptx_ct_a_print_settings *const obj)
{
    return obj->page_margins;
}

pptx_ct_a_page_setup *
pptx_ct_a_print_settings_get_page_setup(const pptx_ct_a_print_settings *const obj)
{
    return obj->page_setup;
}

pptx_ct_a_rel_id *
pptx_ct_a_print_settings_get_legacy_drawing_hf(const pptx_ct_a_print_settings *const obj)
{
    return obj->legacy_drawing_hf;
}

int32_t
pptx_ct_a_print_settings_get_index(pptx_ct_a_print_settings *obj)
{
    return obj->index;
}

void
pptx_ct_a_print_settings_free(pptx_ct_a_print_settings *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_header_footer_free(obj->header_footer);
    pptx_ct_a_page_margins_free(obj->page_margins);
    pptx_ct_a_page_setup_free(obj->page_setup);
    pptx_ct_a_rel_id_free(obj->legacy_drawing_hf);
    free(obj);
}