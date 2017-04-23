#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-geom-guide.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_geom_guide_s {
    pptx_string name;
    pptx_string fmla;
    int32_t index;
} pptx_ct_a_geom_guide;

pptx_ct_a_geom_guide *
pptx_ct_a_geom_guide_new(xmlNode *node)
{
    pptx_ct_a_geom_guide *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->fmla = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "fmla");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_geom_guide_get_name(const pptx_ct_a_geom_guide *const obj)
{
    return obj->name;
}

pptx_string 
pptx_ct_a_geom_guide_get_fmla(const pptx_ct_a_geom_guide *const obj)
{
    return obj->fmla;
}

int32_t
pptx_ct_a_geom_guide_get_index(pptx_ct_a_geom_guide *obj)
{
    return obj->index;
}

void
pptx_ct_a_geom_guide_free(pptx_ct_a_geom_guide *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->name);
    xmlFree(obj->fmla);
    free(obj);
}