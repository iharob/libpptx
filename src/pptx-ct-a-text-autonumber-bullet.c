#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-autonumber-bullet.h>
/* Imported internal stuff */
#include <private/pptx-st-text-autonumber-scheme.h>

typedef struct pptx_ct_a_text_autonumber_bullet_s {
    pptx_st_text_autonumber_scheme_token_enum type;
    pptx_int start_at;
    int32_t index;
} pptx_ct_a_text_autonumber_bullet;

pptx_ct_a_text_autonumber_bullet *
pptx_ct_a_text_autonumber_bullet_new(xmlNode *node)
{
    pptx_ct_a_text_autonumber_bullet *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->type = pptx_get_st_text_autonumber_scheme(node, (const xmlChar *) "type");
    obj->start_at = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "startAt");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_st_text_autonumber_scheme_token_enum 
pptx_ct_a_text_autonumber_bullet_get_type(const pptx_ct_a_text_autonumber_bullet *const obj)
{
    return obj->type;
}

pptx_int 
pptx_ct_a_text_autonumber_bullet_get_start_at(const pptx_ct_a_text_autonumber_bullet *const obj)
{
    return obj->start_at;
}

int32_t
pptx_ct_a_text_autonumber_bullet_get_index(pptx_ct_a_text_autonumber_bullet *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_autonumber_bullet_free(pptx_ct_a_text_autonumber_bullet *obj)
{
    if (obj == NULL)
        return;
    free(obj);
}