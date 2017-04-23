#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-common-view-properties.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-scale-2d.h>
#include <private/pptx-ct-a-point-2d.h>

typedef struct pptx_ct_p_common_view_properties_s {
    pptx_ct_a_scale_2d *scale;
    pptx_ct_a_point_2d *origin;
    pptx_bool var_scale;
    int32_t index;
} pptx_ct_p_common_view_properties;

pptx_ct_p_common_view_properties *
pptx_ct_p_common_view_properties_new(xmlNode *node)
{
    pptx_ct_p_common_view_properties *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:scale");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->scale = NULL;
        } else {
            obj->scale = pptx_ct_a_scale_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->scale = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:origin");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->origin = NULL;
        } else {
            obj->origin = pptx_ct_a_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->origin = NULL;
    }
    obj->var_scale = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "varScale");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_scale_2d *
pptx_ct_p_common_view_properties_get_scale(const pptx_ct_p_common_view_properties *const obj)
{
    return obj->scale;
}

pptx_ct_a_point_2d *
pptx_ct_p_common_view_properties_get_origin(const pptx_ct_p_common_view_properties *const obj)
{
    return obj->origin;
}

pptx_bool 
pptx_ct_p_common_view_properties_get_var_scale(const pptx_ct_p_common_view_properties *const obj)
{
    return obj->var_scale;
}

int32_t
pptx_ct_p_common_view_properties_get_index(pptx_ct_p_common_view_properties *obj)
{
    return obj->index;
}

void
pptx_ct_p_common_view_properties_free(pptx_ct_p_common_view_properties *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_scale_2d_free(obj->scale);
    pptx_ct_a_point_2d_free(obj->origin);
    free(obj);
}