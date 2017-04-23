#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-first-slice-ang.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_first_slice_ang_s {
    pptx_ushort val;
    int32_t index;
} pptx_ct_a_first_slice_ang;

pptx_ct_a_first_slice_ang *
pptx_ct_a_first_slice_ang_new(xmlNode *node)
{
    pptx_ct_a_first_slice_ang *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_ushort(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ushort 
pptx_ct_a_first_slice_ang_get_val(const pptx_ct_a_first_slice_ang *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_first_slice_ang_get_index(pptx_ct_a_first_slice_ang *obj)
{
    return obj->index;
}

void
pptx_ct_a_first_slice_ang_free(pptx_ct_a_first_slice_ang *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}