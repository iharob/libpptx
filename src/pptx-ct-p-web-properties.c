#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-web-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-web-screen-size.h>
#include <private/pptx-st-web-color-type.h>

typedef struct pptx_ct_p_web_properties_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool show_animation;
    pptx_bool resize_graphics;
    pptx_bool allow_png;
    pptx_bool rely_on_vml;
    pptx_bool organize_in_folders;
    pptx_bool use_long_filenames;
    pptx_st_web_screen_size_token_enum img_sz;
    pptx_string encoding;
    pptx_st_web_color_type_token_enum clr;
    int32_t index;
} pptx_ct_p_web_properties;

pptx_ct_p_web_properties *
pptx_ct_p_web_properties_new(xmlNode *node)
{
    pptx_ct_p_web_properties *obj;
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
    obj->show_animation = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showAnimation");
    obj->resize_graphics = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "resizeGraphics");
    obj->allow_png = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "allowPng");
    obj->rely_on_vml = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "relyOnVml");
    obj->organize_in_folders = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "organizeInFolders");
    obj->use_long_filenames = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useLongFilenames");
    obj->img_sz = pptx_get_st_web_screen_size(node, (const xmlChar *) "imgSz");
    obj->encoding = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "encoding");
    obj->clr = pptx_get_st_web_color_type(node, (const xmlChar *) "clr");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_web_properties_get_ext_lst(const pptx_ct_p_web_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_web_properties_get_show_animation(const pptx_ct_p_web_properties *const obj)
{
    return obj->show_animation;
}

pptx_bool 
pptx_ct_p_web_properties_get_resize_graphics(const pptx_ct_p_web_properties *const obj)
{
    return obj->resize_graphics;
}

pptx_bool 
pptx_ct_p_web_properties_get_allow_png(const pptx_ct_p_web_properties *const obj)
{
    return obj->allow_png;
}

pptx_bool 
pptx_ct_p_web_properties_get_rely_on_vml(const pptx_ct_p_web_properties *const obj)
{
    return obj->rely_on_vml;
}

pptx_bool 
pptx_ct_p_web_properties_get_organize_in_folders(const pptx_ct_p_web_properties *const obj)
{
    return obj->organize_in_folders;
}

pptx_bool 
pptx_ct_p_web_properties_get_use_long_filenames(const pptx_ct_p_web_properties *const obj)
{
    return obj->use_long_filenames;
}

pptx_st_web_screen_size_token_enum 
pptx_ct_p_web_properties_get_img_sz(const pptx_ct_p_web_properties *const obj)
{
    return obj->img_sz;
}

pptx_string 
pptx_ct_p_web_properties_get_encoding(const pptx_ct_p_web_properties *const obj)
{
    return obj->encoding;
}

pptx_st_web_color_type_token_enum 
pptx_ct_p_web_properties_get_clr(const pptx_ct_p_web_properties *const obj)
{
    return obj->clr;
}

int32_t
pptx_ct_p_web_properties_get_index(pptx_ct_p_web_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_web_properties_free(pptx_ct_p_web_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    xmlFree(obj->encoding);
    free(obj);
}