#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-font.h>
/* Imported internal stuff */
#include <private/pptx-st-pitch-family.h>

typedef struct pptx_ct_a_text_font_s {
    pptx_string typeface;
    pptx_hexbin panose;
    pptx_st_pitch_family_byte_enum pitch_family;
    pptx_byte charset;
    int32_t index;
} pptx_ct_a_text_font;

pptx_ct_a_text_font *
pptx_ct_a_text_font_new(xmlNode *node)
{
    pptx_ct_a_text_font *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->typeface = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "typeface");
    obj->panose = pptx_xml_get_attribute_as_hexbin(node, (const xmlChar *) "panose");
    obj->pitch_family = pptx_get_st_pitch_family(node, (const xmlChar *) "pitchFamily");
    obj->charset = pptx_xml_get_attribute_as_byte(node, (const xmlChar *) "charset");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_a_text_font_get_typeface(const pptx_ct_a_text_font *const obj)
{
    return obj->typeface;
}

pptx_hexbin 
pptx_ct_a_text_font_get_panose(const pptx_ct_a_text_font *const obj)
{
    return obj->panose;
}

pptx_st_pitch_family_byte_enum 
pptx_ct_a_text_font_get_pitch_family(const pptx_ct_a_text_font *const obj)
{
    return obj->pitch_family;
}

pptx_byte 
pptx_ct_a_text_font_get_charset(const pptx_ct_a_text_font *const obj)
{
    return obj->charset;
}

int32_t
pptx_ct_a_text_font_get_index(pptx_ct_a_text_font *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_font_free(pptx_ct_a_text_font *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->typeface);
    xmlFree(obj->panose);
    free(obj);
}