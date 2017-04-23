#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-control.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-ct-p-picture.h>

typedef struct pptx_ct_p_control_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_ct_p_picture *pic;
    pptx_string spid;
    pptx_string name;
    pptx_bool show_as_icon;
    pptx_string r_id;
    pptx_int img_w;
    pptx_int img_h;
    int32_t index;
} pptx_ct_p_control;

pptx_ct_p_control *
pptx_ct_p_control_new(xmlNode *node)
{
    pptx_ct_p_control *obj;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pic = NULL;
        } else {
            obj->pic = pptx_ct_p_picture_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pic = NULL;
    }
    obj->spid = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "spid");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->show_as_icon = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showAsIcon");
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->img_w = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "imgW");
    obj->img_h = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "imgH");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_control_get_ext_lst(const pptx_ct_p_control *const obj)
{
    return obj->ext_lst;
}

pptx_ct_p_picture *
pptx_ct_p_control_get_pic(const pptx_ct_p_control *const obj)
{
    return obj->pic;
}

pptx_string 
pptx_ct_p_control_get_spid(const pptx_ct_p_control *const obj)
{
    return obj->spid;
}

pptx_string 
pptx_ct_p_control_get_name(const pptx_ct_p_control *const obj)
{
    return obj->name;
}

pptx_bool 
pptx_ct_p_control_get_show_as_icon(const pptx_ct_p_control *const obj)
{
    return obj->show_as_icon;
}

pptx_string 
pptx_ct_p_control_get_r_id(const pptx_ct_p_control *const obj)
{
    return obj->r_id;
}

pptx_int 
pptx_ct_p_control_get_img_w(const pptx_ct_p_control *const obj)
{
    return obj->img_w;
}

pptx_int 
pptx_ct_p_control_get_img_h(const pptx_ct_p_control *const obj)
{
    return obj->img_h;
}

int32_t
pptx_ct_p_control_get_index(pptx_ct_p_control *obj)
{
    return obj->index;
}

void
pptx_ct_p_control_free(pptx_ct_p_control *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    pptx_ct_p_picture_free(obj->pic);
    xmlFree(obj->spid);
    xmlFree(obj->name);
    xmlFree(obj->r_id);
    free(obj);
}