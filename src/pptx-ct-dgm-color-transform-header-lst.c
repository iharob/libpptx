#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-color-transform-header-lst.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-color-transform-header.h>

typedef struct pptx_ct_dgm_color_transform_header_lst_s {
    pptx_ct_dgm_color_transform_header **colors_def_hdr;
    int32_t index;
} pptx_ct_dgm_color_transform_header_lst;

pptx_ct_dgm_color_transform_header_lst *
pptx_ct_dgm_color_transform_header_lst_new(xmlNode *node)
{
    pptx_ct_dgm_color_transform_header_lst *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:colorsDefHdr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->colors_def_hdr = malloc((nodes->nodeNr + 1) * sizeof *obj->colors_def_hdr);
            if (obj->colors_def_hdr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->colors_def_hdr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_color_transform_header_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->colors_def_hdr);
                    obj->colors_def_hdr = NULL;
                } else {
                    obj->colors_def_hdr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->colors_def_hdr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->colors_def_hdr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_color_transform_header **
pptx_ct_dgm_color_transform_header_lst_get_colors_def_hdr(const pptx_ct_dgm_color_transform_header_lst *const obj)
{
    return obj->colors_def_hdr;
}

int32_t
pptx_ct_dgm_color_transform_header_lst_get_index(pptx_ct_dgm_color_transform_header_lst *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_color_transform_header_lst_free(pptx_ct_dgm_color_transform_header_lst *obj)
{
    if (obj == NULL)
        return;
    if (obj->colors_def_hdr != NULL) {
        for (int i = 0; obj->colors_def_hdr[i] != NULL; ++i) {
            pptx_ct_dgm_color_transform_header_free(obj->colors_def_hdr[i]);
        }
        free(obj->colors_def_hdr);
    }

    free(obj);
}