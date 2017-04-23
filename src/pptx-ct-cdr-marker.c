#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-cdr-marker.h>
/* Imported internal stuff */

typedef struct pptx_ct_cdr_marker_s {
    pptx_double x;
    pptx_double y;
    int32_t index;
} pptx_ct_cdr_marker;

pptx_ct_cdr_marker *
pptx_ct_cdr_marker_new(xmlNode *node)
{
    pptx_ct_cdr_marker *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->x = pptx_xml_get_content_as_double(node, (const xmlChar *) "cdr:x");
    obj->y = pptx_xml_get_content_as_double(node, (const xmlChar *) "cdr:y");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_double 
pptx_ct_cdr_marker_get_x(const pptx_ct_cdr_marker *const obj)
{
    return obj->x;
}

pptx_double 
pptx_ct_cdr_marker_get_y(const pptx_ct_cdr_marker *const obj)
{
    return obj->y;
}

int32_t
pptx_ct_cdr_marker_get_index(pptx_ct_cdr_marker *obj)
{
    return obj->index;
}

void
pptx_ct_cdr_marker_free(pptx_ct_cdr_marker *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}