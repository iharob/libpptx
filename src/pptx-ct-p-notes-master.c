#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-notes-master.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-common-slide-data.h>
#include <private/pptx-ct-a-color-mapping.h>
#include <private/pptx-ct-p-header-footer.h>
#include <private/pptx-ct-a-text-list-style.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_notes_master_s {
    pptx_ct_p_common_slide_data *c_sld;
    pptx_ct_a_color_mapping *top_level_slide_clr_map;
    pptx_ct_p_header_footer *hf;
    pptx_ct_a_text_list_style *notes_style;
    pptx_ct_p_extension_list_modify *ext_lst;
    int32_t index;
} pptx_ct_p_notes_master;

pptx_ct_p_notes_master *
pptx_ct_p_notes_master_new(xmlNode *node)
{
    pptx_ct_p_notes_master *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cSld");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_sld = NULL;
        } else {
            obj->c_sld = pptx_ct_p_common_slide_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_sld = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:clrMap");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->top_level_slide_clr_map = NULL;
        } else {
            obj->top_level_slide_clr_map = pptx_ct_a_color_mapping_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->top_level_slide_clr_map = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:hf");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hf = NULL;
        } else {
            obj->hf = pptx_ct_p_header_footer_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hf = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_style = NULL;
        } else {
            obj->notes_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_common_slide_data *
pptx_ct_p_notes_master_get_c_sld(const pptx_ct_p_notes_master *const obj)
{
    return obj->c_sld;
}

pptx_ct_a_color_mapping *
pptx_ct_p_notes_master_get_top_level_slide_clr_map(const pptx_ct_p_notes_master *const obj)
{
    return obj->top_level_slide_clr_map;
}

pptx_ct_p_header_footer *
pptx_ct_p_notes_master_get_hf(const pptx_ct_p_notes_master *const obj)
{
    return obj->hf;
}

pptx_ct_a_text_list_style *
pptx_ct_p_notes_master_get_notes_style(const pptx_ct_p_notes_master *const obj)
{
    return obj->notes_style;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_notes_master_get_ext_lst(const pptx_ct_p_notes_master *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_p_notes_master_get_index(pptx_ct_p_notes_master *obj)
{
    return obj->index;
}

void
pptx_ct_p_notes_master_free(pptx_ct_p_notes_master *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_common_slide_data_free(obj->c_sld);
    pptx_ct_a_color_mapping_free(obj->top_level_slide_clr_map);
    pptx_ct_p_header_footer_free(obj->hf);
    pptx_ct_a_text_list_style_free(obj->notes_style);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}