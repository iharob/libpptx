#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-sample-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-data-model.h>

typedef struct pptx_ct_dgm_sample_data_s {
    pptx_ct_dgm_data_model *data_model;
    pptx_bool use_def;
    int32_t index;
} pptx_ct_dgm_sample_data;

pptx_ct_dgm_sample_data *
pptx_ct_dgm_sample_data_new(xmlNode *node)
{
    pptx_ct_dgm_sample_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:dataModel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->data_model = NULL;
        } else {
            obj->data_model = pptx_ct_dgm_data_model_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->data_model = NULL;
    }
    obj->use_def = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "useDef");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_data_model *
pptx_ct_dgm_sample_data_get_data_model(const pptx_ct_dgm_sample_data *const obj)
{
    return obj->data_model;
}

pptx_bool 
pptx_ct_dgm_sample_data_get_use_def(const pptx_ct_dgm_sample_data *const obj)
{
    return obj->use_def;
}

int32_t
pptx_ct_dgm_sample_data_get_index(pptx_ct_dgm_sample_data *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_sample_data_free(pptx_ct_dgm_sample_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_data_model_free(obj->data_model);
    free(obj);
}