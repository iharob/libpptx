#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-style-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-line-properties.h>

typedef struct pptx_ct_a_line_style_list_s {
    pptx_ct_a_line_properties **ln;
    int32_t index;
} pptx_ct_a_line_style_list;

pptx_ct_a_line_style_list *
pptx_ct_a_line_style_list_new(xmlNode *node)
{
    pptx_ct_a_line_style_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ln");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ln = malloc((nodes->nodeNr + 1) * sizeof *obj->ln);
            if (obj->ln != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ln;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_line_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->ln);
                    obj->ln = NULL;
                } else {
                    obj->ln[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ln = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_line_properties **
pptx_ct_a_line_style_list_get_ln(const pptx_ct_a_line_style_list *const obj)
{
    return obj->ln;
}

int32_t
pptx_ct_a_line_style_list_get_index(pptx_ct_a_line_style_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_style_list_free(pptx_ct_a_line_style_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->ln != NULL) {
        for (int i = 0; obj->ln[i] != NULL; ++i) {
            pptx_ct_a_line_properties_free(obj->ln[i]);
        }
        free(obj->ln);
    }

    free(obj);
}