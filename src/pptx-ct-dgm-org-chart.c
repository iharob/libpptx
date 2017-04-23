#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-org-chart.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_org_chart_s {
    pptx_bool val;
    int32_t index;
} pptx_ct_dgm_org_chart;

pptx_ct_dgm_org_chart *
pptx_ct_dgm_org_chart_new(xmlNode *node)
{
    pptx_ct_dgm_org_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_dgm_org_chart_get_val(const pptx_ct_dgm_org_chart *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_org_chart_get_index(pptx_ct_dgm_org_chart *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_org_chart_free(pptx_ct_dgm_org_chart *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}