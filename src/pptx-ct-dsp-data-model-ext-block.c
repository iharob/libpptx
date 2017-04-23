#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dsp-data-model-ext-block.h>
/* Imported internal stuff */

typedef struct pptx_ct_dsp_data_model_ext_block_s {
    pptx_string rel_id;
    pptx_string min_ver;
    int32_t index;
} pptx_ct_dsp_data_model_ext_block;

pptx_ct_dsp_data_model_ext_block *
pptx_ct_dsp_data_model_ext_block_new(xmlNode *node)
{
    pptx_ct_dsp_data_model_ext_block *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->rel_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "relId");
    obj->min_ver = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minVer");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_dsp_data_model_ext_block_get_rel_id(const pptx_ct_dsp_data_model_ext_block *const obj)
{
    return obj->rel_id;
}

pptx_string 
pptx_ct_dsp_data_model_ext_block_get_min_ver(const pptx_ct_dsp_data_model_ext_block *const obj)
{
    return obj->min_ver;
}

int32_t
pptx_ct_dsp_data_model_ext_block_get_index(pptx_ct_dsp_data_model_ext_block *obj)
{
    return obj->index;
}

void
pptx_ct_dsp_data_model_ext_block_free(pptx_ct_dsp_data_model_ext_block *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->rel_id);
    xmlFree(obj->min_ver);
    free(obj);
}