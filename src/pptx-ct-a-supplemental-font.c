#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-supplemental-font.h>
/* Imported internal stuff */

typedef struct pptx_ct_a_supplemental_font_s {
    pptx_string script;
    pptx_string typeface;
    int32_t index;
} pptx_ct_a_supplemental_font;

pptx_ct_a_supplemental_font *
pptx_ct_a_supplemental_font_new(xmlNode *node)
{
    pptx_ct_a_supplemental_font *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->script = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "script");
    obj->typeface = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "typeface");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_supplemental_font_get_script(const pptx_ct_a_supplemental_font *const obj)
{
    return obj->script;
}

pptx_string 
pptx_ct_a_supplemental_font_get_typeface(const pptx_ct_a_supplemental_font *const obj)
{
    return obj->typeface;
}

int32_t
pptx_ct_a_supplemental_font_get_index(pptx_ct_a_supplemental_font *obj)
{
    return obj->index;
}

void
pptx_ct_a_supplemental_font_free(pptx_ct_a_supplemental_font *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->script);
    xmlFree(obj->typeface);
    free(obj);
}