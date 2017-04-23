#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlbuild-diagram.h>
/* Imported internal stuff */
#include <private/pptx-st-tldiagram-build-type.h>

typedef struct pptx_ct_p_tlbuild_diagram_s {
    pptx_uint spid;
    pptx_uint grp_id;
    pptx_bool ui_expand;
    pptx_st_tldiagram_build_type_token_enum bld;
    int32_t index;
} pptx_ct_p_tlbuild_diagram;

pptx_ct_p_tlbuild_diagram *
pptx_ct_p_tlbuild_diagram_new(xmlNode *node)
{
    pptx_ct_p_tlbuild_diagram *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->spid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spid");
    obj->grp_id = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "grpId");
    obj->ui_expand = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "uiExpand");
    obj->bld = pptx_get_st_tldiagram_build_type(node, (const xmlChar *) "bld");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_tlbuild_diagram_get_spid(const pptx_ct_p_tlbuild_diagram *const obj)
{
    return obj->spid;
}

pptx_uint 
pptx_ct_p_tlbuild_diagram_get_grp_id(const pptx_ct_p_tlbuild_diagram *const obj)
{
    return obj->grp_id;
}

pptx_bool 
pptx_ct_p_tlbuild_diagram_get_ui_expand(const pptx_ct_p_tlbuild_diagram *const obj)
{
    return obj->ui_expand;
}

pptx_st_tldiagram_build_type_token_enum 
pptx_ct_p_tlbuild_diagram_get_bld(const pptx_ct_p_tlbuild_diagram *const obj)
{
    return obj->bld;
}

int32_t
pptx_ct_p_tlbuild_diagram_get_index(pptx_ct_p_tlbuild_diagram *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlbuild_diagram_free(pptx_ct_p_tlbuild_diagram *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}