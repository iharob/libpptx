#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-view-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-normal-view-properties.h>
#include <private/pptx-ct-p-slide-view-properties.h>
#include <private/pptx-ct-p-outline-view-properties.h>
#include <private/pptx-ct-p-notes-text-view-properties.h>
#include <private/pptx-ct-p-slide-sorter-view-properties.h>
#include <private/pptx-ct-p-notes-view-properties.h>
#include <private/pptx-ct-a-positive-size-2d.h>
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-view-type.h>

typedef struct pptx_ct_p_view_properties_s {
    pptx_ct_p_normal_view_properties *normal_view_pr;
    pptx_ct_p_slide_view_properties *slide_view_pr;
    pptx_ct_p_outline_view_properties *outline_view_pr;
    pptx_ct_p_notes_text_view_properties *notes_text_view_pr;
    pptx_ct_p_slide_sorter_view_properties *sorter_view_pr;
    pptx_ct_p_notes_view_properties *notes_view_pr;
    pptx_ct_a_positive_size_2d *grid_spacing;
    pptx_ct_p_extension_list *ext_lst;
    pptx_st_view_type_token_enum last_view;
    pptx_bool show_comments;
    int32_t index;
} pptx_ct_p_view_properties;

pptx_ct_p_view_properties *
pptx_ct_p_view_properties_new(xmlNode *node)
{
    pptx_ct_p_view_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:normalViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->normal_view_pr = NULL;
        } else {
            obj->normal_view_pr = pptx_ct_p_normal_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->normal_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:slideViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->slide_view_pr = NULL;
        } else {
            obj->slide_view_pr = pptx_ct_p_slide_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->slide_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:outlineViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->outline_view_pr = NULL;
        } else {
            obj->outline_view_pr = pptx_ct_p_outline_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->outline_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesTextViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_text_view_pr = NULL;
        } else {
            obj->notes_text_view_pr = pptx_ct_p_notes_text_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_text_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sorterViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sorter_view_pr = NULL;
        } else {
            obj->sorter_view_pr = pptx_ct_p_slide_sorter_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sorter_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesViewPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_view_pr = NULL;
        } else {
            obj->notes_view_pr = pptx_ct_p_notes_view_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_view_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:gridSpacing");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->grid_spacing = NULL;
        } else {
            obj->grid_spacing = pptx_ct_a_positive_size_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grid_spacing = NULL;
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
    obj->last_view = pptx_get_st_view_type(node, (const xmlChar *) "lastView");
    obj->show_comments = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showComments");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_normal_view_properties *
pptx_ct_p_view_properties_get_normal_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->normal_view_pr;
}

pptx_ct_p_slide_view_properties *
pptx_ct_p_view_properties_get_slide_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->slide_view_pr;
}

pptx_ct_p_outline_view_properties *
pptx_ct_p_view_properties_get_outline_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->outline_view_pr;
}

pptx_ct_p_notes_text_view_properties *
pptx_ct_p_view_properties_get_notes_text_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->notes_text_view_pr;
}

pptx_ct_p_slide_sorter_view_properties *
pptx_ct_p_view_properties_get_sorter_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->sorter_view_pr;
}

pptx_ct_p_notes_view_properties *
pptx_ct_p_view_properties_get_notes_view_pr(const pptx_ct_p_view_properties *const obj)
{
    return obj->notes_view_pr;
}

pptx_ct_a_positive_size_2d *
pptx_ct_p_view_properties_get_grid_spacing(const pptx_ct_p_view_properties *const obj)
{
    return obj->grid_spacing;
}

pptx_ct_p_extension_list *
pptx_ct_p_view_properties_get_ext_lst(const pptx_ct_p_view_properties *const obj)
{
    return obj->ext_lst;
}

pptx_st_view_type_token_enum 
pptx_ct_p_view_properties_get_last_view(const pptx_ct_p_view_properties *const obj)
{
    return obj->last_view;
}

pptx_bool 
pptx_ct_p_view_properties_get_show_comments(const pptx_ct_p_view_properties *const obj)
{
    return obj->show_comments;
}

int32_t
pptx_ct_p_view_properties_get_index(pptx_ct_p_view_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_view_properties_free(pptx_ct_p_view_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_normal_view_properties_free(obj->normal_view_pr);
    pptx_ct_p_slide_view_properties_free(obj->slide_view_pr);
    pptx_ct_p_outline_view_properties_free(obj->outline_view_pr);
    pptx_ct_p_notes_text_view_properties_free(obj->notes_text_view_pr);
    pptx_ct_p_slide_sorter_view_properties_free(obj->sorter_view_pr);
    pptx_ct_p_notes_view_properties_free(obj->notes_view_pr);
    pptx_ct_a_positive_size_2d_free(obj->grid_spacing);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}