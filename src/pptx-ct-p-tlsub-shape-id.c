#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlsub-shape-id.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tlsub_shape_id_s {
    pptx_string spid;
    int32_t index;
} pptx_ct_p_tlsub_shape_id;

pptx_ct_p_tlsub_shape_id *
pptx_ct_p_tlsub_shape_id_new(xmlNode *node)
{
    pptx_ct_p_tlsub_shape_id *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->spid = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "spid");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_tlsub_shape_id_get_spid(const pptx_ct_p_tlsub_shape_id *const obj)
{
    return obj->spid;
}

int32_t
pptx_ct_p_tlsub_shape_id_get_index(pptx_ct_p_tlsub_shape_id *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlsub_shape_id_free(pptx_ct_p_tlsub_shape_id *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->spid);
    free(obj);
}