#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-custom-show.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-slide-relationship-list.h>
#include <private/pptx-ct-p-extension-list.h>

typedef struct pptx_ct_p_custom_show_s {
    pptx_ct_p_slide_relationship_list *sld_lst;
    pptx_ct_p_extension_list *ext_lst;
    pptx_string name;
    pptx_uint id;
    int32_t index;
} pptx_ct_p_custom_show;

pptx_ct_p_custom_show *
pptx_ct_p_custom_show_new(xmlNode *node)
{
    pptx_ct_p_custom_show *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sld_lst = NULL;
        } else {
            obj->sld_lst = pptx_ct_p_slide_relationship_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_lst = NULL;
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
    obj->id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "id");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_slide_relationship_list *
pptx_ct_p_custom_show_get_sld_lst(const pptx_ct_p_custom_show *const obj)
{
    return obj->sld_lst;
}

pptx_ct_p_extension_list *
pptx_ct_p_custom_show_get_ext_lst(const pptx_ct_p_custom_show *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_p_custom_show_get_name(const pptx_ct_p_custom_show *const obj)
{
    return obj->name;
}

pptx_uint 
pptx_ct_p_custom_show_get_id(const pptx_ct_p_custom_show *const obj)
{
    return obj->id;
}

int32_t
pptx_ct_p_custom_show_get_index(pptx_ct_p_custom_show *obj)
{
    return obj->index;
}

void
pptx_ct_p_custom_show_free(pptx_ct_p_custom_show *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_slide_relationship_list_free(obj->sld_lst);
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}