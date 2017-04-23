#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-lbl-algn.h>
/* Imported internal stuff */
#include <private/pptx-st-lbl-algn.h>

typedef struct pptx_ct_a_lbl_algn_s {
    pptx_st_lbl_algn_text_enum val;
    int32_t index;
} pptx_ct_a_lbl_algn;

pptx_ct_a_lbl_algn *
pptx_ct_a_lbl_algn_new(xmlNode *node)
{
    pptx_ct_a_lbl_algn *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_lbl_algn(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_lbl_algn_text_enum 
pptx_ct_a_lbl_algn_get_val(const pptx_ct_a_lbl_algn *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_lbl_algn_get_index(pptx_ct_a_lbl_algn *obj)
{
    return obj->index;
}

void
pptx_ct_a_lbl_algn_free(pptx_ct_a_lbl_algn *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}