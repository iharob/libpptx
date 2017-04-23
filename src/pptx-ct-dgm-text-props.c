#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-text-props.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-shape-3d.h>
#include <private/pptx-ct-a-flat-text.h>

typedef struct pptx_ct_dgm_text_props_s {
    pptx_ct_a_shape_3d *text_3d_sp3d;
    pptx_ct_a_flat_text *text_3d_flat_tx;
    int32_t index;
} pptx_ct_dgm_text_props;

pptx_ct_dgm_text_props *
pptx_ct_dgm_text_props_new(xmlNode *node)
{
    pptx_ct_dgm_text_props *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sp3d");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_3d_sp3d = NULL;
        } else {
            obj->text_3d_sp3d = pptx_ct_a_shape_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_3d_sp3d = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:flatTx");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->text_3d_flat_tx = NULL;
        } else {
            obj->text_3d_flat_tx = pptx_ct_a_flat_text_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_3d_flat_tx = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_shape_3d *
pptx_ct_dgm_text_props_get_text_3d_sp3d(const pptx_ct_dgm_text_props *const obj)
{
    return obj->text_3d_sp3d;
}

pptx_ct_a_flat_text *
pptx_ct_dgm_text_props_get_text_3d_flat_tx(const pptx_ct_dgm_text_props *const obj)
{
    return obj->text_3d_flat_tx;
}

int32_t
pptx_ct_dgm_text_props_get_index(pptx_ct_dgm_text_props *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_text_props_free(pptx_ct_dgm_text_props *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_shape_3d_free(obj->text_3d_sp3d);
    pptx_ct_a_flat_text_free(obj->text_3d_flat_tx);
    free(obj);
}