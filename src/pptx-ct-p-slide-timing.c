#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-timing.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-time-node-list.h>
#include <private/pptx-ct-p-build-list.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_slide_timing_s {
    pptx_ct_p_time_node_list *tn_lst;
    pptx_ct_p_build_list *bld_lst;
    pptx_ct_p_extension_list_modify *ext_lst;
    int32_t index;
} pptx_ct_p_slide_timing;

pptx_ct_p_slide_timing *
pptx_ct_p_slide_timing_new(xmlNode *node)
{
    pptx_ct_p_slide_timing *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tn_lst = NULL;
        } else {
            obj->tn_lst = pptx_ct_p_time_node_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tn_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bld_lst = NULL;
        } else {
            obj->bld_lst = pptx_ct_p_build_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_lst = NULL;
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

pptx_ct_p_time_node_list *
pptx_ct_p_slide_timing_get_tn_lst(const pptx_ct_p_slide_timing *const obj)
{
    return obj->tn_lst;
}

pptx_ct_p_build_list *
pptx_ct_p_slide_timing_get_bld_lst(const pptx_ct_p_slide_timing *const obj)
{
    return obj->bld_lst;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_slide_timing_get_ext_lst(const pptx_ct_p_slide_timing *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_p_slide_timing_get_index(pptx_ct_p_slide_timing *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_timing_free(pptx_ct_p_slide_timing *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_time_node_list_free(obj->tn_lst);
    pptx_ct_p_build_list_free(obj->bld_lst);
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}