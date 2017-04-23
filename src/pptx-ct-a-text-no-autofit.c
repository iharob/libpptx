#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-no-autofit.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_text_no_autofit_s {
    int32_t index;
} pptx_ct_a_text_no_autofit;

pptx_ct_a_text_no_autofit *
pptx_ct_a_text_no_autofit_new(xmlNode *node)
{
    pptx_ct_a_text_no_autofit *obj;
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
pptx_ct_a_text_no_autofit_get_index(pptx_ct_a_text_no_autofit *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_no_autofit_free(pptx_ct_a_text_no_autofit *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}