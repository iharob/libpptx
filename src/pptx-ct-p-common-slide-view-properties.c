#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-common-slide-view-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-common-view-properties.h>
#include <private/pptx-ct-p-guide-list.h>

typedef struct pptx_ct_p_common_slide_view_properties_s {
    pptx_ct_p_common_view_properties *c_view_pr;
    pptx_ct_p_guide_list *guide_lst;
    pptx_bool snap_to_grid;
    pptx_bool snap_to_objects;
    pptx_bool show_guides;
    int32_t index;
} pptx_ct_p_common_slide_view_properties;

pptx_ct_p_common_slide_view_properties *
pptx_ct_p_common_slide_view_properties_new(xmlNode *node)
{
    pptx_ct_p_common_slide_view_properties *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:guideLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->guide_lst = NULL;
        } else {
            obj->guide_lst = pptx_ct_p_guide_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->guide_lst = NULL;
    }
    obj->snap_to_grid = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "snapToGrid");
    obj->snap_to_objects = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "snapToObjects");
    obj->show_guides = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showGuides");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_common_view_properties *
pptx_ct_p_common_slide_view_properties_get_c_view_pr(const pptx_ct_p_common_slide_view_properties *const obj)
{
    return obj->c_view_pr;
}

pptx_ct_p_guide_list *
pptx_ct_p_common_slide_view_properties_get_guide_lst(const pptx_ct_p_common_slide_view_properties *const obj)
{
    return obj->guide_lst;
}

pptx_bool 
pptx_ct_p_common_slide_view_properties_get_snap_to_grid(const pptx_ct_p_common_slide_view_properties *const obj)
{
    return obj->snap_to_grid;
}

pptx_bool 
pptx_ct_p_common_slide_view_properties_get_snap_to_objects(const pptx_ct_p_common_slide_view_properties *const obj)
{
    return obj->snap_to_objects;
}

pptx_bool 
pptx_ct_p_common_slide_view_properties_get_show_guides(const pptx_ct_p_common_slide_view_properties *const obj)
{
    return obj->show_guides;
}

int32_t
pptx_ct_p_common_slide_view_properties_get_index(pptx_ct_p_common_slide_view_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_common_slide_view_properties_free(pptx_ct_p_common_slide_view_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_common_view_properties_free(obj->c_view_pr);
    pptx_ct_p_guide_list_free(obj->guide_lst);
    free(obj);
}