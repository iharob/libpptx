#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-animation-graphical-object-build-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-animation-dgm-build-properties.h>
#include <private/pptx-ct-a-animation-chart-build-properties.h>

typedef struct pptx_ct_a_animation_graphical_object_build_properties_s {
    pptx_ct_a_animation_dgm_build_properties *bld_dgm;
    pptx_ct_a_animation_chart_build_properties *bld_chart;
    int32_t index;
} pptx_ct_a_animation_graphical_object_build_properties;

pptx_ct_a_animation_graphical_object_build_properties *
pptx_ct_a_animation_graphical_object_build_properties_new(xmlNode *node)
{
    pptx_ct_a_animation_graphical_object_build_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bldDgm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bld_dgm = NULL;
        } else {
            obj->bld_dgm = pptx_ct_a_animation_dgm_build_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_dgm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bldChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bld_chart = NULL;
        } else {
            obj->bld_chart = pptx_ct_a_animation_chart_build_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_chart = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_animation_dgm_build_properties *
pptx_ct_a_animation_graphical_object_build_properties_get_bld_dgm(const pptx_ct_a_animation_graphical_object_build_properties *const obj)
{
    return obj->bld_dgm;
}

pptx_ct_a_animation_chart_build_properties *
pptx_ct_a_animation_graphical_object_build_properties_get_bld_chart(const pptx_ct_a_animation_graphical_object_build_properties *const obj)
{
    return obj->bld_chart;
}

int32_t
pptx_ct_a_animation_graphical_object_build_properties_get_index(pptx_ct_a_animation_graphical_object_build_properties *obj)
{
    return obj->index;
}

void
pptx_ct_a_animation_graphical_object_build_properties_free(pptx_ct_a_animation_graphical_object_build_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_animation_dgm_build_properties_free(obj->bld_dgm);
    pptx_ct_a_animation_chart_build_properties_free(obj->bld_chart);
    free(obj);
}