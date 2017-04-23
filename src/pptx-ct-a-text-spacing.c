#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-spacing.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-spacing-percent.h>
#include <private/pptx-ct-a-text-spacing-point.h>

typedef struct pptx_ct_a_text_spacing_s {
    pptx_ct_a_text_spacing_percent *spc_pct;
    pptx_ct_a_text_spacing_point *spc_pts;
    int32_t index;
} pptx_ct_a_text_spacing;

pptx_ct_a_text_spacing *
pptx_ct_a_text_spacing_new(xmlNode *node)
{
    pptx_ct_a_text_spacing *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spcPct");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->spc_pct = NULL;
        } else {
            obj->spc_pct = pptx_ct_a_text_spacing_percent_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->spc_pct = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spcPts");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->spc_pts = NULL;
        } else {
            obj->spc_pts = pptx_ct_a_text_spacing_point_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->spc_pts = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_spacing_percent *
pptx_ct_a_text_spacing_get_spc_pct(const pptx_ct_a_text_spacing *const obj)
{
    return obj->spc_pct;
}

pptx_ct_a_text_spacing_point *
pptx_ct_a_text_spacing_get_spc_pts(const pptx_ct_a_text_spacing *const obj)
{
    return obj->spc_pts;
}

int32_t
pptx_ct_a_text_spacing_get_index(pptx_ct_a_text_spacing *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_spacing_free(pptx_ct_a_text_spacing *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_spacing_percent_free(obj->spc_pct);
    pptx_ct_a_text_spacing_point_free(obj->spc_pts);
    free(obj);
}