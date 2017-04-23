#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-list-style.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-paragraph-properties.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_text_list_style_s {
    pptx_ct_a_text_paragraph_properties *def_ppr;
    pptx_ct_a_text_paragraph_properties *lvl1p_pr;
    pptx_ct_a_text_paragraph_properties *lvl2p_pr;
    pptx_ct_a_text_paragraph_properties *lvl3p_pr;
    pptx_ct_a_text_paragraph_properties *lvl4p_pr;
    pptx_ct_a_text_paragraph_properties *lvl5p_pr;
    pptx_ct_a_text_paragraph_properties *lvl6p_pr;
    pptx_ct_a_text_paragraph_properties *lvl7p_pr;
    pptx_ct_a_text_paragraph_properties *lvl8p_pr;
    pptx_ct_a_text_paragraph_properties *lvl9p_pr;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_text_list_style;

pptx_ct_a_text_list_style *
pptx_ct_a_text_list_style_new(xmlNode *node)
{
    pptx_ct_a_text_list_style *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:defPPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->def_ppr = NULL;
        } else {
            obj->def_ppr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->def_ppr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl1pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl1p_pr = NULL;
        } else {
            obj->lvl1p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl1p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl2pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl2p_pr = NULL;
        } else {
            obj->lvl2p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl2p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl3pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl3p_pr = NULL;
        } else {
            obj->lvl3p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl3p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl4pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl4p_pr = NULL;
        } else {
            obj->lvl4p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl4p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl5pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl5p_pr = NULL;
        } else {
            obj->lvl5p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl5p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl6pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl6p_pr = NULL;
        } else {
            obj->lvl6p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl6p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl7pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl7p_pr = NULL;
        } else {
            obj->lvl7p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl7p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl8pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl8p_pr = NULL;
        } else {
            obj->lvl8p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl8p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lvl9pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lvl9p_pr = NULL;
        } else {
            obj->lvl9p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lvl9p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_def_ppr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->def_ppr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl1p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl1p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl2p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl2p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl3p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl3p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl4p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl4p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl5p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl5p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl6p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl6p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl7p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl7p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl8p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl8p_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_list_style_get_lvl9p_pr(const pptx_ct_a_text_list_style *const obj)
{
    return obj->lvl9p_pr;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_text_list_style_get_ext_lst(const pptx_ct_a_text_list_style *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_text_list_style_get_index(pptx_ct_a_text_list_style *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_list_style_free(pptx_ct_a_text_list_style *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_paragraph_properties_free(obj->def_ppr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl1p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl2p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl3p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl4p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl5p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl6p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl7p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl8p_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->lvl9p_pr);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}