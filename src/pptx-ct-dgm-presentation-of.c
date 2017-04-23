#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-presentation-of.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-axis-type.h>
#include <private/pptx-st-element-type.h>

typedef struct pptx_ct_dgm_presentation_of_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_axis_type_token_enum axis;
    pptx_st_element_type_token_enum pt_type;
    pptx_bool hide_last_trans;
    pptx_int st;
    pptx_uint cnt;
    pptx_int step;
    int32_t index;
} pptx_ct_dgm_presentation_of;

pptx_ct_dgm_presentation_of *
pptx_ct_dgm_presentation_of_new(xmlNode *node)
{
    pptx_ct_dgm_presentation_of *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:extLst");
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
    obj->axis = pptx_get_st_axis_type(node, (const xmlChar *) "axis");
    obj->pt_type = pptx_get_st_element_type(node, (const xmlChar *) "ptType");
    obj->hide_last_trans = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hideLastTrans");
    obj->st = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "st");
    obj->cnt = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "cnt");
    obj->step = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "step");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_presentation_of_get_ext_lst(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->ext_lst;
}

pptx_st_axis_type_token_enum 
pptx_ct_dgm_presentation_of_get_axis(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->axis;
}

pptx_st_element_type_token_enum 
pptx_ct_dgm_presentation_of_get_pt_type(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->pt_type;
}

pptx_bool 
pptx_ct_dgm_presentation_of_get_hide_last_trans(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->hide_last_trans;
}

pptx_int 
pptx_ct_dgm_presentation_of_get_st(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->st;
}

pptx_uint 
pptx_ct_dgm_presentation_of_get_cnt(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->cnt;
}

pptx_int 
pptx_ct_dgm_presentation_of_get_step(const pptx_ct_dgm_presentation_of *const obj)
{
    return obj->step;
}

int32_t
pptx_ct_dgm_presentation_of_get_index(pptx_ct_dgm_presentation_of *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_presentation_of_free(pptx_ct_dgm_presentation_of *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}