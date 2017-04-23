#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlbuild-paragraph.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tltemplate-list.h>
#include <private/pptx-st-tlpara-build-type.h>
#include <private/pptx-st-tltime-indefinite.h>

typedef struct pptx_ct_p_tlbuild_paragraph_s {
    pptx_ct_p_tltemplate_list *tmpl_lst;
    pptx_uint spid;
    pptx_uint grp_id;
    pptx_bool ui_expand;
    pptx_st_tlpara_build_type_token_enum build;
    pptx_uint bld_lvl;
    pptx_bool anim_bg;
    pptx_bool auto_update_anim_bg;
    pptx_bool rev;
    pptx_st_tltime_indefinite_token_enum adv_auto;
    int32_t index;
} pptx_ct_p_tlbuild_paragraph;

pptx_ct_p_tlbuild_paragraph *
pptx_ct_p_tlbuild_paragraph_new(xmlNode *node)
{
    pptx_ct_p_tlbuild_paragraph *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tmplLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tmpl_lst = NULL;
        } else {
            obj->tmpl_lst = pptx_ct_p_tltemplate_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tmpl_lst = NULL;
    }
    obj->spid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spid");
    obj->grp_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "grpId");
    obj->ui_expand = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "uiExpand");
    obj->build = pptx_get_st_tlpara_build_type(node, (const xmlChar *) "build");
    obj->bld_lvl = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "bldLvl");
    obj->anim_bg = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "animBg");
    obj->auto_update_anim_bg = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "autoUpdateAnimBg");
    obj->rev = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rev");
    obj->adv_auto = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "advAuto");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tltemplate_list *
pptx_ct_p_tlbuild_paragraph_get_tmpl_lst(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->tmpl_lst;
}

pptx_uint 
pptx_ct_p_tlbuild_paragraph_get_spid(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->spid;
}

pptx_uint 
pptx_ct_p_tlbuild_paragraph_get_grp_id(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->grp_id;
}

pptx_bool 
pptx_ct_p_tlbuild_paragraph_get_ui_expand(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->ui_expand;
}

pptx_st_tlpara_build_type_token_enum 
pptx_ct_p_tlbuild_paragraph_get_build(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->build;
}

pptx_uint 
pptx_ct_p_tlbuild_paragraph_get_bld_lvl(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->bld_lvl;
}

pptx_bool 
pptx_ct_p_tlbuild_paragraph_get_anim_bg(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->anim_bg;
}

pptx_bool 
pptx_ct_p_tlbuild_paragraph_get_auto_update_anim_bg(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->auto_update_anim_bg;
}

pptx_bool 
pptx_ct_p_tlbuild_paragraph_get_rev(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->rev;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tlbuild_paragraph_get_adv_auto(const pptx_ct_p_tlbuild_paragraph *const obj)
{
    return obj->adv_auto;
}

int32_t
pptx_ct_p_tlbuild_paragraph_get_index(pptx_ct_p_tlbuild_paragraph *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlbuild_paragraph_free(pptx_ct_p_tlbuild_paragraph *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tltemplate_list_free(obj->tmpl_lst);
    free(obj);
}