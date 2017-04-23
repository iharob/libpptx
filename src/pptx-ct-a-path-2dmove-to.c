#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-2dmove-to.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-adj-point-2d.h>

typedef struct pptx_ct_a_path_2dmove_to_s {
    pptx_ct_a_adj_point_2d *pt;
    int32_t index;
} pptx_ct_a_path_2dmove_to;

pptx_ct_a_path_2dmove_to *
pptx_ct_a_path_2dmove_to_new(xmlNode *node)
{
    pptx_ct_a_path_2dmove_to *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pt = NULL;
        } else {
            obj->pt = pptx_ct_a_adj_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pt = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_adj_point_2d *
pptx_ct_a_path_2dmove_to_get_pt(const pptx_ct_a_path_2dmove_to *const obj)
{
    return obj->pt;
}

int32_t
pptx_ct_a_path_2dmove_to_get_index(pptx_ct_a_path_2dmove_to *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_2dmove_to_free(pptx_ct_a_path_2dmove_to *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_adj_point_2d_free(obj->pt);
    free(obj);
}