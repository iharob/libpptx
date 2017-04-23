#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dsp-drawing.h>
/* Imported internal stuff */
#include <private/pptx-ct-dsp-group-shape.h>

typedef struct pptx_ct_dsp_drawing_s {
    pptx_ct_dsp_group_shape *sp_tree;
    int32_t index;
} pptx_ct_dsp_drawing;

pptx_ct_dsp_drawing *
pptx_ct_dsp_drawing_new(xmlNode *node)
{
    pptx_ct_dsp_drawing *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dsp:spTree");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_tree = NULL;
        } else {
            obj->sp_tree = pptx_ct_dsp_group_shape_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_tree = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dsp_group_shape *
pptx_ct_dsp_drawing_get_sp_tree(const pptx_ct_dsp_drawing *const obj)
{
    return obj->sp_tree;
}

int32_t
pptx_ct_dsp_drawing_get_index(pptx_ct_dsp_drawing *obj)
{
    return obj->index;
}

void
pptx_ct_dsp_drawing_free(pptx_ct_dsp_drawing *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dsp_group_shape_free(obj->sp_tree);
    free(obj);
}