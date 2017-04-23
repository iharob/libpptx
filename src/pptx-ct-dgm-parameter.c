#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-parameter.h>
/* Imported internal stuff */
#include <private/pptx-st-parameter-id.h>

typedef struct pptx_ct_dgm_parameter_s {
    pptx_st_parameter_id_token_enum type;
    pptx_string val;
    int32_t index;
} pptx_ct_dgm_parameter;

pptx_ct_dgm_parameter *
pptx_ct_dgm_parameter_new(xmlNode *node)
{
    pptx_ct_dgm_parameter *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->type = pptx_get_st_parameter_id(node, (const xmlChar *) "type");
    obj->val = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_parameter_id_token_enum 
pptx_ct_dgm_parameter_get_type(const pptx_ct_dgm_parameter *const obj)
{
    return obj->type;
}

pptx_string 
pptx_ct_dgm_parameter_get_val(const pptx_ct_dgm_parameter *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_parameter_get_index(pptx_ct_dgm_parameter *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_parameter_free(pptx_ct_dgm_parameter *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->val);
    free(obj);
}