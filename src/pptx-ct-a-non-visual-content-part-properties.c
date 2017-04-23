#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-non-visual-content-part-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-content-part-locking.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_non_visual_content_part_properties_s {
    pptx_ct_a_content_part_locking *cp_locks;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_bool is_comment;
    int32_t index;
} pptx_ct_a_non_visual_content_part_properties;

pptx_ct_a_non_visual_content_part_properties *
pptx_ct_a_non_visual_content_part_properties_new(xmlNode *node)
{
    pptx_ct_a_non_visual_content_part_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cpLocks");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cp_locks = NULL;
        } else {
            obj->cp_locks = pptx_ct_a_content_part_locking_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cp_locks = NULL;
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
    obj->is_comment = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "isComment");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_content_part_locking *
pptx_ct_a_non_visual_content_part_properties_get_cp_locks(const pptx_ct_a_non_visual_content_part_properties *const obj)
{
    return obj->cp_locks;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_non_visual_content_part_properties_get_ext_lst(const pptx_ct_a_non_visual_content_part_properties *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_a_non_visual_content_part_properties_get_is_comment(const pptx_ct_a_non_visual_content_part_properties *const obj)
{
    return obj->is_comment;
}

int32_t
pptx_ct_a_non_visual_content_part_properties_get_index(pptx_ct_a_non_visual_content_part_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_non_visual_content_part_properties_free(pptx_ct_a_non_visual_content_part_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_content_part_locking_free(obj->cp_locks);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}