#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-child-pref.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_child_pref_s {
    pptx_int val;
    int32_t index;
} pptx_ct_dgm_child_pref;

pptx_ct_dgm_child_pref *
pptx_ct_dgm_child_pref_new(xmlNode *node)
{
    pptx_ct_dgm_child_pref *obj;
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
pptx_ct_dgm_child_pref_get_val(const pptx_ct_dgm_child_pref *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_child_pref_get_index(pptx_ct_dgm_child_pref *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_child_pref_free(pptx_ct_dgm_child_pref *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}