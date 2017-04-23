#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-effect-style-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-effect-style-item.h>

typedef struct pptx_ct_a_effect_style_list_s {
    pptx_ct_a_effect_style_item **effect_style;
    int32_t index;
} pptx_ct_a_effect_style_list;

pptx_ct_a_effect_style_list *
pptx_ct_a_effect_style_list_new(xmlNode *node)
{
    pptx_ct_a_effect_style_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:effectStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->effect_style = malloc((nodes->nodeNr + 1) * sizeof *obj->effect_style);
            if (obj->effect_style != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->effect_style;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_effect_style_item_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->effect_style);
                    obj->effect_style = NULL;
                } else {
                    obj->effect_style[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->effect_style = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->effect_style = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_effect_style_item **
pptx_ct_a_effect_style_list_get_effect_style(const pptx_ct_a_effect_style_list *const obj)
{
    return obj->effect_style;
}

int32_t
pptx_ct_a_effect_style_list_get_index(pptx_ct_a_effect_style_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_effect_style_list_free(pptx_ct_a_effect_style_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->effect_style != NULL) {
        for (int i = 0; obj->effect_style[i] != NULL; ++i) {
            pptx_ct_a_effect_style_item_free(obj->effect_style[i]);
        }
        free(obj->effect_style);
    }

    free(obj);
}