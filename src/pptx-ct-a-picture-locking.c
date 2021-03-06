#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-picture-locking.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_picture_locking_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_bool no_grp;
    pptx_bool no_select;
    pptx_bool no_rot;
    pptx_bool no_change_aspect;
    pptx_bool no_move;
    pptx_bool no_resize;
    pptx_bool no_edit_points;
    pptx_bool no_adjust_handles;
    pptx_bool no_change_arrowheads;
    pptx_bool no_change_shape_type;
    pptx_bool no_crop;
    int32_t index;
} pptx_ct_a_picture_locking;

pptx_ct_a_picture_locking *
pptx_ct_a_picture_locking_new(xmlNode *node)
{
    pptx_ct_a_picture_locking *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
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
    obj->no_grp = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noGrp");
    obj->no_select = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noSelect");
    obj->no_rot = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noRot");
    obj->no_change_aspect = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noChangeAspect");
    obj->no_move = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noMove");
    obj->no_resize = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noResize");
    obj->no_edit_points = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noEditPoints");
    obj->no_adjust_handles = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noAdjustHandles");
    obj->no_change_arrowheads = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noChangeArrowheads");
    obj->no_change_shape_type = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noChangeShapeType");
    obj->no_crop = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "noCrop");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_picture_locking_get_ext_lst(const pptx_ct_a_picture_locking *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_grp(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_grp;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_select(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_select;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_rot(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_rot;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_change_aspect(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_change_aspect;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_move(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_move;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_resize(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_resize;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_edit_points(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_edit_points;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_adjust_handles(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_adjust_handles;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_change_arrowheads(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_change_arrowheads;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_change_shape_type(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_change_shape_type;
}

pptx_bool 
pptx_ct_a_picture_locking_get_no_crop(const pptx_ct_a_picture_locking *const obj)
{
    return obj->no_crop;
}

int32_t
pptx_ct_a_picture_locking_get_index(pptx_ct_a_picture_locking *obj)
{
    return obj->index;
}

void
pptx_ct_a_picture_locking_free(pptx_ct_a_picture_locking *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}