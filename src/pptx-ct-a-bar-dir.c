#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-bar-dir.h>
/* Imported internal stuff */
#include <private/pptx-st-bar-dir.h>

typedef struct pptx_ct_a_bar_dir_s {
    pptx_st_bar_dir_text_enum val;
    int32_t index;
} pptx_ct_a_bar_dir;

pptx_ct_a_bar_dir *
pptx_ct_a_bar_dir_new(xmlNode *node)
{
    pptx_ct_a_bar_dir *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->val = pptx_get_st_bar_dir(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_bar_dir_text_enum 
pptx_ct_a_bar_dir_get_val(const pptx_ct_a_bar_dir *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_a_bar_dir_get_index(pptx_ct_a_bar_dir *obj)
{
    return obj->index;
}

void
pptx_ct_a_bar_dir_free(pptx_ct_a_bar_dir *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}