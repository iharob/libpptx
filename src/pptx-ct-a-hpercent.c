#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-hpercent.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_hpercent_s {
    pptx_string val;
    int32_t index;
} pptx_ct_a_hpercent;

pptx_ct_a_hpercent *
pptx_ct_a_hpercent_new(xmlNode *node)
{
    pptx_ct_a_hpercent *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_hpercent_get_val(const pptx_ct_a_hpercent *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_hpercent_get_index(pptx_ct_a_hpercent *obj)
{
    return obj->index;
}

void
pptx_ct_a_hpercent_free(pptx_ct_a_hpercent *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->val);
    free(obj);
}