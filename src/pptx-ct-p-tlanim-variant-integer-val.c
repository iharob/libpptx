#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanim-variant-integer-val.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_tlanim_variant_integer_val_s {
    pptx_int val;
    int32_t index;
} pptx_ct_p_tlanim_variant_integer_val;

pptx_ct_p_tlanim_variant_integer_val *
pptx_ct_p_tlanim_variant_integer_val_new(xmlNode *node)
{
    pptx_ct_p_tlanim_variant_integer_val *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_int 
pptx_ct_p_tlanim_variant_integer_val_get_val(const pptx_ct_p_tlanim_variant_integer_val *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_p_tlanim_variant_integer_val_get_index(pptx_ct_p_tlanim_variant_integer_val *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanim_variant_integer_val_free(pptx_ct_p_tlanim_variant_integer_val *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}