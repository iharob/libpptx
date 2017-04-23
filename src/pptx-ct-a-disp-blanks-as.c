#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-disp-blanks-as.h>
/* Imported internal stuff */
#include <private/pptx-st-disp-blanks-as.h>

typedef struct pptx_ct_a_disp_blanks_as_s {
    pptx_st_disp_blanks_as_text_enum val;
    int32_t index;
} pptx_ct_a_disp_blanks_as;

pptx_ct_a_disp_blanks_as *
pptx_ct_a_disp_blanks_as_new(xmlNode *node)
{
    pptx_ct_a_disp_blanks_as *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_disp_blanks_as(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_disp_blanks_as_text_enum 
pptx_ct_a_disp_blanks_as_get_val(const pptx_ct_a_disp_blanks_as *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_disp_blanks_as_get_index(pptx_ct_a_disp_blanks_as *obj)
{
    return obj->index;
}

void
pptx_ct_a_disp_blanks_as_free(pptx_ct_a_disp_blanks_as *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}