#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-transform-effect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_transform_effect_s {
    pptx_string sx;
    pptx_string sy;
    pptx_int kx;
    pptx_int ky;
    pptx_string tx;
    pptx_string ty;
    int32_t index;
} pptx_ct_a_transform_effect;

pptx_ct_a_transform_effect *
pptx_ct_a_transform_effect_new(xmlNode *node)
{
    pptx_ct_a_transform_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->sx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sx");
    obj->sy = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sy");
    obj->kx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "kx");
    obj->ky = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "ky");
    obj->tx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "tx");
    obj->ty = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ty");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_transform_effect_get_sx(const pptx_ct_a_transform_effect *const obj)
{
    return obj->sx;
}

pptx_string 
pptx_ct_a_transform_effect_get_sy(const pptx_ct_a_transform_effect *const obj)
{
    return obj->sy;
}

pptx_int 
pptx_ct_a_transform_effect_get_kx(const pptx_ct_a_transform_effect *const obj)
{
    return obj->kx;
}

pptx_int 
pptx_ct_a_transform_effect_get_ky(const pptx_ct_a_transform_effect *const obj)
{
    return obj->ky;
}

pptx_string 
pptx_ct_a_transform_effect_get_tx(const pptx_ct_a_transform_effect *const obj)
{
    return obj->tx;
}

pptx_string 
pptx_ct_a_transform_effect_get_ty(const pptx_ct_a_transform_effect *const obj)
{
    return obj->ty;
}

int32_t
pptx_ct_a_transform_effect_get_index(pptx_ct_a_transform_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_transform_effect_free(pptx_ct_a_transform_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->sx);
    xmlFree(obj->sy);
    xmlFree(obj->tx);
    xmlFree(obj->ty);
    free(obj);
}