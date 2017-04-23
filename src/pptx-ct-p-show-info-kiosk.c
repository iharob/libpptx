#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-show-info-kiosk.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_show_info_kiosk_s {
    pptx_uint restart;
    int32_t index;
} pptx_ct_p_show_info_kiosk;

pptx_ct_p_show_info_kiosk *
pptx_ct_p_show_info_kiosk_new(xmlNode *node)
{
    pptx_ct_p_show_info_kiosk *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->restart = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "restart");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_uint 
pptx_ct_p_show_info_kiosk_get_restart(const pptx_ct_p_show_info_kiosk *const obj)
{
    return obj->restart;
}

int32_t
pptx_ct_p_show_info_kiosk_get_index(pptx_ct_p_show_info_kiosk *obj)
{
    return obj->index;
}

void
pptx_ct_p_show_info_kiosk_free(pptx_ct_p_show_info_kiosk *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}