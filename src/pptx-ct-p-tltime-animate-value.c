#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltime-animate-value.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlanim-variant.h>
#include <private/pptx-st-tltime-indefinite.h>

typedef struct pptx_ct_p_tltime_animate_value_s {
    pptx_ct_p_tlanim_variant *val;
    pptx_st_tltime_indefinite_token_enum tm;
    pptx_string fmla;
    int32_t index;
} pptx_ct_p_tltime_animate_value;

pptx_ct_p_tltime_animate_value *
pptx_ct_p_tltime_animate_value_new(xmlNode *node)
{
    pptx_ct_p_tltime_animate_value *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:val");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->val = NULL;
        } else {
            obj->val = pptx_ct_p_tlanim_variant_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->val = NULL;
    }
    obj->tm = pptx_get_st_tltime_indefinite(node, (const xmlChar *) "tm");
    obj->fmla = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "fmla");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlanim_variant *
pptx_ct_p_tltime_animate_value_get_val(const pptx_ct_p_tltime_animate_value *const obj)
{
    return obj->val;
}

pptx_st_tltime_indefinite_token_enum 
pptx_ct_p_tltime_animate_value_get_tm(const pptx_ct_p_tltime_animate_value *const obj)
{
    return obj->tm;
}

pptx_string 
pptx_ct_p_tltime_animate_value_get_fmla(const pptx_ct_p_tltime_animate_value *const obj)
{
    return obj->fmla;
}

int32_t
pptx_ct_p_tltime_animate_value_get_index(pptx_ct_p_tltime_animate_value *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltime_animate_value_free(pptx_ct_p_tltime_animate_value *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlanim_variant_free(obj->val);
    xmlFree(obj->fmla);
    free(obj);
}