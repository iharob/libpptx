#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlgraphical-object-build.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-empty.h>
#include <private/pptx-ct-a-animation-graphical-object-build-properties.h>

typedef struct pptx_ct_p_tlgraphical_object_build_s {
    pptx_ct_p_empty *bld_as_one;
    pptx_ct_a_animation_graphical_object_build_properties *bld_sub;
    pptx_uint spid;
    pptx_uint grp_id;
    pptx_bool ui_expand;
    int32_t index;
} pptx_ct_p_tlgraphical_object_build;

pptx_ct_p_tlgraphical_object_build *
pptx_ct_p_tlgraphical_object_build_new(xmlNode *node)
{
    pptx_ct_p_tlgraphical_object_build *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldAsOne");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bld_as_one = NULL;
        } else {
            obj->bld_as_one = pptx_ct_p_empty_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_as_one = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldSub");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bld_sub = NULL;
        } else {
            obj->bld_sub = pptx_ct_a_animation_graphical_object_build_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_sub = NULL;
    }
    obj->spid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spid");
    obj->grp_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "grpId");
    obj->ui_expand = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "uiExpand");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_empty *
pptx_ct_p_tlgraphical_object_build_get_bld_as_one(const pptx_ct_p_tlgraphical_object_build *const obj)
{
    return obj->bld_as_one;
}

pptx_ct_a_animation_graphical_object_build_properties *
pptx_ct_p_tlgraphical_object_build_get_bld_sub(const pptx_ct_p_tlgraphical_object_build *const obj)
{
    return obj->bld_sub;
}

pptx_uint 
pptx_ct_p_tlgraphical_object_build_get_spid(const pptx_ct_p_tlgraphical_object_build *const obj)
{
    return obj->spid;
}

pptx_uint 
pptx_ct_p_tlgraphical_object_build_get_grp_id(const pptx_ct_p_tlgraphical_object_build *const obj)
{
    return obj->grp_id;
}

pptx_bool 
pptx_ct_p_tlgraphical_object_build_get_ui_expand(const pptx_ct_p_tlgraphical_object_build *const obj)
{
    return obj->ui_expand;
}

int32_t
pptx_ct_p_tlgraphical_object_build_get_index(pptx_ct_p_tlgraphical_object_build *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlgraphical_object_build_free(pptx_ct_p_tlgraphical_object_build *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_empty_free(obj->bld_as_one);
    pptx_ct_a_animation_graphical_object_build_properties_free(obj->bld_sub);
    free(obj);
}