#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-blend-effect.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-effect-container.h>
#include <private/pptx-st-blend-mode.h>

typedef struct pptx_ct_a_blend_effect_s {
    pptx_ct_a_effect_container *cont;
    pptx_st_blend_mode_token_enum blend;
    int32_t index;
} pptx_ct_a_blend_effect;

pptx_ct_a_blend_effect *
pptx_ct_a_blend_effect_new(xmlNode *node)
{
    pptx_ct_a_blend_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cont");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cont = NULL;
        } else {
            obj->cont = pptx_ct_a_effect_container_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cont = NULL;
    }
    obj->blend = pptx_get_st_blend_mode(node, (const xmlChar *) "blend");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_effect_container *
pptx_ct_a_blend_effect_get_cont(const pptx_ct_a_blend_effect *const obj)
{
    return obj->cont;
}

pptx_st_blend_mode_token_enum 
pptx_ct_a_blend_effect_get_blend(const pptx_ct_a_blend_effect *const obj)
{
    return obj->blend;
}

int32_t
pptx_ct_a_blend_effect_get_index(pptx_ct_a_blend_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_blend_effect_free(pptx_ct_a_blend_effect *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_effect_container_free(obj->cont);
    free(obj);
}