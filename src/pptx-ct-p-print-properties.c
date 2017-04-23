#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-print-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-print-what.h>
#include <private/pptx-st-print-color-mode.h>

typedef struct pptx_ct_p_print_properties_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_st_print_what_token_enum prn_what;
    pptx_st_print_color_mode_token_enum clr_mode;
    pptx_bool hidden_slides;
    pptx_bool scale_to_fit_paper;
    pptx_bool frame_slides;
    int32_t index;
} pptx_ct_p_print_properties;

pptx_ct_p_print_properties *
pptx_ct_p_print_properties_new(xmlNode *node)
{
    pptx_ct_p_print_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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
    obj->prn_what = pptx_get_st_print_what(node, (const xmlChar *) "prnWhat");
    obj->clr_mode = pptx_get_st_print_color_mode(node, (const xmlChar *) "clrMode");
    obj->hidden_slides = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hiddenSlides");
    obj->scale_to_fit_paper = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "scaleToFitPaper");
    obj->frame_slides = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "frameSlides");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_print_properties_get_ext_lst(const pptx_ct_p_print_properties *const obj)
{
    return obj->ext_lst;
}

pptx_st_print_what_token_enum 
pptx_ct_p_print_properties_get_prn_what(const pptx_ct_p_print_properties *const obj)
{
    return obj->prn_what;
}

pptx_st_print_color_mode_token_enum 
pptx_ct_p_print_properties_get_clr_mode(const pptx_ct_p_print_properties *const obj)
{
    return obj->clr_mode;
}

pptx_bool 
pptx_ct_p_print_properties_get_hidden_slides(const pptx_ct_p_print_properties *const obj)
{
    return obj->hidden_slides;
}

pptx_bool 
pptx_ct_p_print_properties_get_scale_to_fit_paper(const pptx_ct_p_print_properties *const obj)
{
    return obj->scale_to_fit_paper;
}

pptx_bool 
pptx_ct_p_print_properties_get_frame_slides(const pptx_ct_p_print_properties *const obj)
{
    return obj->frame_slides;
}

int32_t
pptx_ct_p_print_properties_get_index(pptx_ct_p_print_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_print_properties_free(pptx_ct_p_print_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}