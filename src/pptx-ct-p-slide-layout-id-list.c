#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-slide-layout-id-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-slide-layout-id-list-entry.h>

typedef struct pptx_ct_p_slide_layout_id_list_s {
    pptx_ct_p_slide_layout_id_list_entry **sld_layout_id;
    int32_t index;
} pptx_ct_p_slide_layout_id_list;

pptx_ct_p_slide_layout_id_list *
pptx_ct_p_slide_layout_id_list_new(xmlNode *node)
{
    pptx_ct_p_slide_layout_id_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sldLayoutId");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->sld_layout_id = malloc((nodes->nodeNr + 1) * sizeof *obj->sld_layout_id);
            if (obj->sld_layout_id != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->sld_layout_id;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_slide_layout_id_list_entry_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->sld_layout_id);
                    obj->sld_layout_id = NULL;
                } else {
                    obj->sld_layout_id[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->sld_layout_id = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sld_layout_id = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_slide_layout_id_list_entry **
pptx_ct_p_slide_layout_id_list_get_sld_layout_id(const pptx_ct_p_slide_layout_id_list *const obj)
{
    return obj->sld_layout_id;
}

int32_t
pptx_ct_p_slide_layout_id_list_get_index(pptx_ct_p_slide_layout_id_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_slide_layout_id_list_free(pptx_ct_p_slide_layout_id_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->sld_layout_id != NULL) {
        for (int i = 0; obj->sld_layout_id[i] != NULL; ++i) {
            pptx_ct_p_slide_layout_id_list_entry_free(obj->sld_layout_id[i]);
        }
        free(obj->sld_layout_id);
    }

    free(obj);
}