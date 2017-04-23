#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-line-join-bevel.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_line_join_bevel_s {
    int32_t index;
} pptx_ct_a_line_join_bevel;

pptx_ct_a_line_join_bevel *
pptx_ct_a_line_join_bevel_new(xmlNode *node)
{
    pptx_ct_a_line_join_bevel *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

int32_t
pptx_ct_a_line_join_bevel_get_index(pptx_ct_a_line_join_bevel *obj)
{
    return obj->index;
}

void
pptx_ct_a_line_join_bevel_free(pptx_ct_a_line_join_bevel *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}