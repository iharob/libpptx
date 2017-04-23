#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-layout-variable-property-set.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-org-chart.h>
#include <private/pptx-ct-dgm-child-max.h>
#include <private/pptx-ct-dgm-child-pref.h>
#include <private/pptx-ct-dgm-bullet-enabled.h>
#include <private/pptx-ct-dgm-direction.h>
#include <private/pptx-ct-dgm-hier-branch-style.h>
#include <private/pptx-ct-dgm-anim-one.h>
#include <private/pptx-ct-dgm-anim-lvl.h>
#include <private/pptx-ct-dgm-resize-handles.h>

typedef struct pptx_ct_dgm_layout_variable_property_set_s {
    pptx_ct_dgm_org_chart *org_chart;
    pptx_ct_dgm_child_max *ch_max;
    pptx_ct_dgm_child_pref *ch_pref;
    pptx_ct_dgm_bullet_enabled *bullet_enabled;
    pptx_ct_dgm_direction *dir;
    pptx_ct_dgm_hier_branch_style *hier_branch;
    pptx_ct_dgm_anim_one *anim_one;
    pptx_ct_dgm_anim_lvl *anim_lvl;
    pptx_ct_dgm_resize_handles *resize_handles;
    int32_t index;
} pptx_ct_dgm_layout_variable_property_set;

pptx_ct_dgm_layout_variable_property_set *
pptx_ct_dgm_layout_variable_property_set_new(xmlNode *node)
{
    pptx_ct_dgm_layout_variable_property_set *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:orgChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->org_chart = NULL;
        } else {
            obj->org_chart = pptx_ct_dgm_org_chart_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->org_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:chMax");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ch_max = NULL;
        } else {
            obj->ch_max = pptx_ct_dgm_child_max_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ch_max = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:chPref");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ch_pref = NULL;
        } else {
            obj->ch_pref = pptx_ct_dgm_child_pref_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ch_pref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:bulletEnabled");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bullet_enabled = NULL;
        } else {
            obj->bullet_enabled = pptx_ct_dgm_bullet_enabled_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bullet_enabled = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:dir");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dir = NULL;
        } else {
            obj->dir = pptx_ct_dgm_direction_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dir = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:hierBranch");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hier_branch = NULL;
        } else {
            obj->hier_branch = pptx_ct_dgm_hier_branch_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hier_branch = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:animOne");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->anim_one = NULL;
        } else {
            obj->anim_one = pptx_ct_dgm_anim_one_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_one = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:animLvl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->anim_lvl = NULL;
        } else {
            obj->anim_lvl = pptx_ct_dgm_anim_lvl_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anim_lvl = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:resizeHandles");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->resize_handles = NULL;
        } else {
            obj->resize_handles = pptx_ct_dgm_resize_handles_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->resize_handles = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_org_chart *
pptx_ct_dgm_layout_variable_property_set_get_org_chart(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->org_chart;
}

pptx_ct_dgm_child_max *
pptx_ct_dgm_layout_variable_property_set_get_ch_max(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->ch_max;
}

pptx_ct_dgm_child_pref *
pptx_ct_dgm_layout_variable_property_set_get_ch_pref(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->ch_pref;
}

pptx_ct_dgm_bullet_enabled *
pptx_ct_dgm_layout_variable_property_set_get_bullet_enabled(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->bullet_enabled;
}

pptx_ct_dgm_direction *
pptx_ct_dgm_layout_variable_property_set_get_dir(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->dir;
}

pptx_ct_dgm_hier_branch_style *
pptx_ct_dgm_layout_variable_property_set_get_hier_branch(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->hier_branch;
}

pptx_ct_dgm_anim_one *
pptx_ct_dgm_layout_variable_property_set_get_anim_one(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->anim_one;
}

pptx_ct_dgm_anim_lvl *
pptx_ct_dgm_layout_variable_property_set_get_anim_lvl(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->anim_lvl;
}

pptx_ct_dgm_resize_handles *
pptx_ct_dgm_layout_variable_property_set_get_resize_handles(const pptx_ct_dgm_layout_variable_property_set *const obj)
{
    return obj->resize_handles;
}

int32_t
pptx_ct_dgm_layout_variable_property_set_get_index(pptx_ct_dgm_layout_variable_property_set *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_layout_variable_property_set_free(pptx_ct_dgm_layout_variable_property_set *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_dgm_org_chart_free(obj->org_chart);
    pptx_ct_dgm_child_max_free(obj->ch_max);
    pptx_ct_dgm_child_pref_free(obj->ch_pref);
    pptx_ct_dgm_bullet_enabled_free(obj->bullet_enabled);
    pptx_ct_dgm_direction_free(obj->dir);
    pptx_ct_dgm_hier_branch_style_free(obj->hier_branch);
    pptx_ct_dgm_anim_one_free(obj->anim_one);
    pptx_ct_dgm_anim_lvl_free(obj->anim_lvl);
    pptx_ct_dgm_resize_handles_free(obj->resize_handles);
    free(obj);
}