#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-char-bullet.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_text_char_bullet_s {
    pptx_string _char;
    int32_t index;
} pptx_ct_a_text_char_bullet;

pptx_ct_a_text_char_bullet *
pptx_ct_a_text_char_bullet_new(xmlNode *node)
{
    pptx_ct_a_text_char_bullet *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->_char = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "char");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_text_char_bullet_get__char(const pptx_ct_a_text_char_bullet *const obj)
{
    return obj->_char;
}

int32_t
pptx_ct_a_text_char_bullet_get_index(pptx_ct_a_text_char_bullet *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_char_bullet_free(pptx_ct_a_text_char_bullet *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->_char);
    free(obj);
}