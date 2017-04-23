#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-common-slide-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-background.h>
#include <private/pptx-ct-p-group-shape.h>
#include <private/pptx-ct-p-customer-data-list.h>
#include <private/pptx-ct-p-control-list.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_common_slide_data_s {
    pptx_ct_p_background *bg;
    pptx_ct_p_group_shape *sp_tree;
    pptx_ct_p_customer_data_list *cust_data_lst;
    pptx_ct_p_control_list *controls;
    pptx_ct_p_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_p_common_slide_data;

pptx_ct_p_common_slide_data *
pptx_ct_p_common_slide_data_new(xmlNode *node)
{
    pptx_ct_p_common_slide_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bg = NULL;
        } else {
            obj->bg = pptx_ct_p_background_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:spTree");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_tree = NULL;
        } else {
            obj->sp_tree = pptx_ct_p_group_shape_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_tree = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custDataLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cust_data_lst = NULL;
        } else {
            obj->cust_data_lst = pptx_ct_p_customer_data_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_data_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:controls");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->controls = NULL;
        } else {
            obj->controls = pptx_ct_p_control_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->controls = NULL;
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
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_background *
pptx_ct_p_common_slide_data_get_bg(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->bg;
}

pptx_ct_p_group_shape *
pptx_ct_p_common_slide_data_get_sp_tree(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->sp_tree;
}

pptx_ct_p_customer_data_list *
pptx_ct_p_common_slide_data_get_cust_data_lst(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->cust_data_lst;
}

pptx_ct_p_control_list *
pptx_ct_p_common_slide_data_get_controls(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->controls;
}

pptx_ct_p_extension_list *
pptx_ct_p_common_slide_data_get_ext_lst(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_p_common_slide_data_get_name(const pptx_ct_p_common_slide_data *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_p_common_slide_data_get_index(pptx_ct_p_common_slide_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_common_slide_data_free(pptx_ct_p_common_slide_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_background_free(obj->bg);
    pptx_ct_p_group_shape_free(obj->sp_tree);
    pptx_ct_p_customer_data_list_free(obj->cust_data_lst);
    pptx_ct_p_control_list_free(obj->controls);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}