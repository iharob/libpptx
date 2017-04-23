#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-empty.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_empty_s {
    int32_t index;
} pptx_ct_p_empty;

pptx_ct_p_empty *
pptx_ct_p_empty_new(xmlNode *node)
{
    pptx_ct_p_empty *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

int32_t
pptx_ct_p_empty_get_index(pptx_ct_p_empty *obj)
{
    return obj->index;
}

void
pptx_ct_p_empty_free(pptx_ct_p_empty *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}