#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-blip-bullet.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-blip.h>

typedef struct pptx_ct_a_text_blip_bullet_s {
    pptx_ct_a_blip *blip;
    int32_t index;
} pptx_ct_a_text_blip_bullet;

pptx_ct_a_text_blip_bullet *
pptx_ct_a_text_blip_bullet_new(xmlNode *node)
{
    pptx_ct_a_text_blip_bullet *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blip");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->blip = NULL;
        } else {
            obj->blip = pptx_ct_a_blip_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->blip = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_blip *
pptx_ct_a_text_blip_bullet_get_blip(const pptx_ct_a_text_blip_bullet *const obj)
{
    return obj->blip;
}

int32_t
pptx_ct_a_text_blip_bullet_get_index(pptx_ct_a_text_blip_bullet *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_blip_bullet_free(pptx_ct_a_text_blip_bullet *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_blip_free(obj->blip);
    free(obj);
}