#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-notes-master-id-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-notes-master-id-list-entry.h>

typedef struct pptx_ct_p_notes_master_id_list_s {
    pptx_ct_p_notes_master_id_list_entry *notes_master_id;
    int32_t index;
} pptx_ct_p_notes_master_id_list;

pptx_ct_p_notes_master_id_list *
pptx_ct_p_notes_master_id_list_new(xmlNode *node)
{
    pptx_ct_p_notes_master_id_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:notesMasterId");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->notes_master_id = NULL;
        } else {
            obj->notes_master_id = pptx_ct_p_notes_master_id_list_entry_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->notes_master_id = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_notes_master_id_list_entry *
pptx_ct_p_notes_master_id_list_get_notes_master_id(const pptx_ct_p_notes_master_id_list *const obj)
{
    return obj->notes_master_id;
}

int32_t
pptx_ct_p_notes_master_id_list_get_index(pptx_ct_p_notes_master_id_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_notes_master_id_list_free(pptx_ct_p_notes_master_id_list *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_notes_master_id_list_entry_free(obj->notes_master_id);
    free(obj);
}