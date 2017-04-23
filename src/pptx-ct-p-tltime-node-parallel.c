#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-node-parallel.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlcommon-time-node-data.h>

typedef struct pptx_ct_p_tltime_node_parallel_s {
    pptx_ct_p_tlcommon_time_node_data *c_tn;
    int32_t index;
} pptx_ct_p_tltime_node_parallel;

pptx_ct_p_tltime_node_parallel *
pptx_ct_p_tltime_node_parallel_new(xmlNode *node)
{
    pptx_ct_p_tltime_node_parallel *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cTn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->c_tn = NULL;
        } else {
            obj->c_tn = pptx_ct_p_tlcommon_time_node_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->c_tn = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlcommon_time_node_data *
pptx_ct_p_tltime_node_parallel_get_c_tn(const pptx_ct_p_tltime_node_parallel *const obj)
{
    return obj->c_tn;
}

int32_t
pptx_ct_p_tltime_node_parallel_get_index(pptx_ct_p_tltime_node_parallel *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_node_parallel_free(pptx_ct_p_tltime_node_parallel *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlcommon_time_node_data_free(obj->c_tn);
    free(obj);
}