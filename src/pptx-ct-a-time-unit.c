#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-time-unit.h>
/* Imported internal stuff */
#include <private/pptx-st-time-unit.h>

typedef struct pptx_ct_a_time_unit_s {
    pptx_st_time_unit_text_enum val;
    int32_t index;
} pptx_ct_a_time_unit;

pptx_ct_a_time_unit *
pptx_ct_a_time_unit_new(xmlNode *node)
{
    pptx_ct_a_time_unit *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_time_unit(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_time_unit_text_enum 
pptx_ct_a_time_unit_get_val(const pptx_ct_a_time_unit *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_time_unit_get_index(pptx_ct_a_time_unit *obj)
{
    return obj->index;
}

void
pptx_ct_a_time_unit_free(pptx_ct_a_time_unit *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}