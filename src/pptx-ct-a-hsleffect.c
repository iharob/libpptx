#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-hsleffect.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_hsleffect_s {
    pptx_int hue;
    pptx_string sat;
    pptx_string lum;
    int32_t index;
} pptx_ct_a_hsleffect;

pptx_ct_a_hsleffect *
pptx_ct_a_hsleffect_new(xmlNode *node)
{
    pptx_ct_a_hsleffect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->hue = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "hue");
    obj->sat = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sat");
    obj->lum = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lum");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_a_hsleffect_get_hue(const pptx_ct_a_hsleffect *const obj)
{
    return obj->hue;
}

pptx_string 
pptx_ct_a_hsleffect_get_sat(const pptx_ct_a_hsleffect *const obj)
{
    return obj->sat;
}

pptx_string 
pptx_ct_a_hsleffect_get_lum(const pptx_ct_a_hsleffect *const obj)
{
    return obj->lum;
}

int32_t
pptx_ct_a_hsleffect_get_index(pptx_ct_a_hsleffect *obj)
{
    return obj->index;
}

void
pptx_ct_a_hsleffect_free(pptx_ct_a_hsleffect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->sat);
    xmlFree(obj->lum);
    free(obj);
}