#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-normal-autofit.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_text_normal_autofit_s {
    pptx_string font_scale;
    pptx_string ln_spc_reduction;
    int32_t index;
} pptx_ct_a_text_normal_autofit;

pptx_ct_a_text_normal_autofit *
pptx_ct_a_text_normal_autofit_new(xmlNode *node)
{
    pptx_ct_a_text_normal_autofit *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->font_scale = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "fontScale");
    obj->ln_spc_reduction = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lnSpcReduction");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_text_normal_autofit_get_font_scale(const pptx_ct_a_text_normal_autofit *const obj)
{
    return obj->font_scale;
}

pptx_string 
pptx_ct_a_text_normal_autofit_get_ln_spc_reduction(const pptx_ct_a_text_normal_autofit *const obj)
{
    return obj->ln_spc_reduction;
}

int32_t
pptx_ct_a_text_normal_autofit_get_index(pptx_ct_a_text_normal_autofit *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_normal_autofit_free(pptx_ct_a_text_normal_autofit *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->font_scale);
    xmlFree(obj->ln_spc_reduction);
    free(obj);
}