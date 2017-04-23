#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-size-represents.h>
/* Imported internal stuff */
#include <private/pptx-st-size-represents.h>

typedef struct pptx_ct_a_size_represents_s {
    pptx_st_size_represents_text_enum val;
    int32_t index;
} pptx_ct_a_size_represents;

pptx_ct_a_size_represents *
pptx_ct_a_size_represents_new(xmlNode *node)
{
    pptx_ct_a_size_represents *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_size_represents(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_size_represents_text_enum 
pptx_ct_a_size_represents_get_val(const pptx_ct_a_size_represents *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_size_represents_get_index(pptx_ct_a_size_represents *obj)
{
    return obj->index;
}

void
pptx_ct_a_size_represents_free(pptx_ct_a_size_represents *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}