#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-2dcubic-bezier-to.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-adj-point-2d.h>

typedef struct pptx_ct_a_path_2dcubic_bezier_to_s {
    pptx_ct_a_adj_point_2d **pt;
    int32_t index;
} pptx_ct_a_path_2dcubic_bezier_to;

pptx_ct_a_path_2dcubic_bezier_to *
pptx_ct_a_path_2dcubic_bezier_to_new(xmlNode *node)
{
    pptx_ct_a_path_2dcubic_bezier_to *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_adj_point_2d **
pptx_ct_a_path_2dcubic_bezier_to_get_pt(const pptx_ct_a_path_2dcubic_bezier_to *const obj)
{
    return obj->pt;
}

int32_t
pptx_ct_a_path_2dcubic_bezier_to_get_index(pptx_ct_a_path_2dcubic_bezier_to *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_2dcubic_bezier_to_free(pptx_ct_a_path_2dcubic_bezier_to *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}