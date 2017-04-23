#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-sorter-view-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-common-view-properties.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_slide_sorter_view_properties_s {
    pptx_ct_p_common_view_properties *c_view_pr;
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool show_formatting;
    int32_t index;
} pptx_ct_p_slide_sorter_view_properties;

pptx_ct_p_slide_sorter_view_properties *
pptx_ct_p_slide_sorter_view_properties_new(xmlNode *node)
{
    pptx_ct_p_slide_sorter_view_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_view_pr = NULL;
        } else {
            obj->c_view_pr = pptx_ct_p_common_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_view_pr = NULL;
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
    obj->show_formatting = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showFormatting");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_common_view_properties *
pptx_ct_p_slide_sorter_view_properties_get_c_view_pr(const pptx_ct_p_slide_sorter_view_properties *const obj)
{
    return obj->c_view_pr;
}

pptx_ct_p_extension_list *
pptx_ct_p_slide_sorter_view_properties_get_ext_lst(const pptx_ct_p_slide_sorter_view_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_slide_sorter_view_properties_get_show_formatting(const pptx_ct_p_slide_sorter_view_properties *const obj)
{
    return obj->show_formatting;
}

int32_t
pptx_ct_p_slide_sorter_view_properties_get_index(pptx_ct_p_slide_sorter_view_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_sorter_view_properties_free(pptx_ct_p_slide_sorter_view_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_common_view_properties_free(obj->c_view_pr);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}