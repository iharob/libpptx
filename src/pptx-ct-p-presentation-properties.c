#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-presentation-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-html-publish-properties.h>
#include <private/pptx-ct-p-web-properties.h>
#include <private/pptx-ct-p-print-properties.h>
#include <private/pptx-ct-p-show-properties.h>
#include <private/pptx-ct-a-color-mru.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_presentation_properties_s {
    pptx_ct_p_html_publish_properties *html_pub_pr;
    pptx_ct_p_web_properties *web_pr;
    pptx_ct_p_print_properties *prn_pr;
    pptx_ct_p_show_properties *show_pr;
    pptx_ct_a_color_mru *clr_mru;
    pptx_ct_p_extension_list *ext_lst;
    int32_t index;
} pptx_ct_p_presentation_properties;

pptx_ct_p_presentation_properties *
pptx_ct_p_presentation_properties_new(xmlNode *node)
{
    pptx_ct_p_presentation_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:htmlPubPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->html_pub_pr = NULL;
        } else {
            obj->html_pub_pr = pptx_ct_p_html_publish_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->html_pub_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:webPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->web_pr = NULL;
        } else {
            obj->web_pr = pptx_ct_p_web_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->web_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:prnPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->prn_pr = NULL;
        } else {
            obj->prn_pr = pptx_ct_p_print_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->prn_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:showPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->show_pr = NULL;
        } else {
            obj->show_pr = pptx_ct_p_show_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->show_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:clrMru");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_mru = NULL;
        } else {
            obj->clr_mru = pptx_ct_a_color_mru_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_mru = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_html_publish_properties *
pptx_ct_p_presentation_properties_get_html_pub_pr(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->html_pub_pr;
}

pptx_ct_p_web_properties *
pptx_ct_p_presentation_properties_get_web_pr(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->web_pr;
}

pptx_ct_p_print_properties *
pptx_ct_p_presentation_properties_get_prn_pr(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->prn_pr;
}

pptx_ct_p_show_properties *
pptx_ct_p_presentation_properties_get_show_pr(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->show_pr;
}

pptx_ct_a_color_mru *
pptx_ct_p_presentation_properties_get_clr_mru(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->clr_mru;
}

pptx_ct_p_extension_list *
pptx_ct_p_presentation_properties_get_ext_lst(const pptx_ct_p_presentation_properties *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_p_presentation_properties_get_index(pptx_ct_p_presentation_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_presentation_properties_free(pptx_ct_p_presentation_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_html_publish_properties_free(obj->html_pub_pr);
    pptx_ct_p_web_properties_free(obj->web_pr);
    pptx_ct_p_print_properties_free(obj->prn_pr);
    pptx_ct_p_show_properties_free(obj->show_pr);
    pptx_ct_a_color_mru_free(obj->clr_mru);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}