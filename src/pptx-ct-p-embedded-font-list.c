#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-embedded-font-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-embedded-font-list-entry.h>

typedef struct pptx_ct_p_embedded_font_list_s {
    pptx_ct_p_embedded_font_list_entry **embedded_font;
    int32_t index;
} pptx_ct_p_embedded_font_list;

pptx_ct_p_embedded_font_list *
pptx_ct_p_embedded_font_list_new(xmlNode *node)
{
    pptx_ct_p_embedded_font_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:embeddedFont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->embedded_font = malloc((nodes->nodeNr + 1) * sizeof *obj->embedded_font);
            if (obj->embedded_font != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->embedded_font;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_embedded_font_list_entry_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->embedded_font);
                    obj->embedded_font = NULL;
                } else {
                    obj->embedded_font[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->embedded_font = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->embedded_font = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_embedded_font_list_entry **
pptx_ct_p_embedded_font_list_get_embedded_font(const pptx_ct_p_embedded_font_list *const obj)
{
    return obj->embedded_font;
}

int32_t
pptx_ct_p_embedded_font_list_get_index(pptx_ct_p_embedded_font_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_embedded_font_list_free(pptx_ct_p_embedded_font_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->embedded_font != NULL) {
        for (int i = 0; obj->embedded_font[i] != NULL; ++i) {
            pptx_ct_p_embedded_font_list_entry_free(obj->embedded_font[i]);
        }
        free(obj->embedded_font);
    }

    free(obj);
}