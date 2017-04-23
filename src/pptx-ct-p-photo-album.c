#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-photo-album.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-photo-album-layout.h>
#include <private/pptx-st-photo-album-frame-shape.h>

typedef struct pptx_ct_p_photo_album_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_bool bw;
    pptx_bool show_captions;
    pptx_st_photo_album_layout_token_enum layout;
    pptx_st_photo_album_frame_shape_token_enum frame;
    int32_t index;
} pptx_ct_p_photo_album;

pptx_ct_p_photo_album *
pptx_ct_p_photo_album_new(xmlNode *node)
{
    pptx_ct_p_photo_album *obj;
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
    obj->bw = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "bw");
    obj->show_captions = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showCaptions");
    obj->layout = pptx_get_st_photo_album_layout(node, (const xmlChar *) "layout");
    obj->frame = pptx_get_st_photo_album_frame_shape(node, (const xmlChar *) "frame");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_photo_album_get_ext_lst(const pptx_ct_p_photo_album *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_photo_album_get_bw(const pptx_ct_p_photo_album *const obj)
{
    return obj->bw;
}

pptx_bool 
pptx_ct_p_photo_album_get_show_captions(const pptx_ct_p_photo_album *const obj)
{
    return obj->show_captions;
}

pptx_st_photo_album_layout_token_enum 
pptx_ct_p_photo_album_get_layout(const pptx_ct_p_photo_album *const obj)
{
    return obj->layout;
}

pptx_st_photo_album_frame_shape_token_enum 
pptx_ct_p_photo_album_get_frame(const pptx_ct_p_photo_album *const obj)
{
    return obj->frame;
}

int32_t
pptx_ct_p_photo_album_get_index(pptx_ct_p_photo_album *obj)
{
    return obj->index;
}

void
pptx_ct_p_photo_album_free(pptx_ct_p_photo_album *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}