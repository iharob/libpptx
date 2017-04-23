#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-non-visual-group-drawing-shape-props.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-group-locking.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_non_visual_group_drawing_shape_props_s {
    pptx_ct_a_group_locking *grp_sp_locks;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_non_visual_group_drawing_shape_props;

pptx_ct_a_non_visual_group_drawing_shape_props *
pptx_ct_a_non_visual_group_drawing_shape_props_new(xmlNode *node)
{
    pptx_ct_a_non_visual_group_drawing_shape_props *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpSpLocks");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->grp_sp_locks = NULL;
        } else {
            obj->grp_sp_locks = pptx_ct_a_group_locking_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grp_sp_locks = NULL;
    }

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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_group_locking *
pptx_ct_a_non_visual_group_drawing_shape_props_get_grp_sp_locks(const pptx_ct_a_non_visual_group_drawing_shape_props *const obj)
{
    return obj->grp_sp_locks;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_non_visual_group_drawing_shape_props_get_ext_lst(const pptx_ct_a_non_visual_group_drawing_shape_props *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_non_visual_group_drawing_shape_props_get_index(pptx_ct_a_non_visual_group_drawing_shape_props *obj)
{
    return obj->index;
}

void
pptx_ct_a_non_visual_group_drawing_shape_props_free(pptx_ct_a_non_visual_group_drawing_shape_props *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_group_locking_free(obj->grp_sp_locks);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}