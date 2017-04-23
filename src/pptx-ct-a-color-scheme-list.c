#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-scheme-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color-scheme-and-mapping.h>

typedef struct pptx_ct_a_color_scheme_list_s {
    pptx_ct_a_color_scheme_and_mapping **extra_clr_scheme;
    int32_t index;
} pptx_ct_a_color_scheme_list;

pptx_ct_a_color_scheme_list *
pptx_ct_a_color_scheme_list_new(xmlNode *node)
{
    pptx_ct_a_color_scheme_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extraClrScheme");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->extra_clr_scheme = malloc((nodes->nodeNr + 1) * sizeof *obj->extra_clr_scheme);
            if (obj->extra_clr_scheme != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->extra_clr_scheme;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_color_scheme_and_mapping_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->extra_clr_scheme);
                    obj->extra_clr_scheme = NULL;
                } else {
                    obj->extra_clr_scheme[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->extra_clr_scheme = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->extra_clr_scheme = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color_scheme_and_mapping **
pptx_ct_a_color_scheme_list_get_extra_clr_scheme(const pptx_ct_a_color_scheme_list *const obj)
{
    return obj->extra_clr_scheme;
}

int32_t
pptx_ct_a_color_scheme_list_get_index(pptx_ct_a_color_scheme_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_scheme_list_free(pptx_ct_a_color_scheme_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->extra_clr_scheme != NULL) {
        for (int i = 0; obj->extra_clr_scheme[i] != NULL; ++i) {
            pptx_ct_a_color_scheme_and_mapping_free(obj->extra_clr_scheme[i]);
        }
        free(obj->extra_clr_scheme);
    }

    free(obj);
}