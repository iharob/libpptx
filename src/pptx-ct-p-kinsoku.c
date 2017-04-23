#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-kinsoku.h>
/* Imported internal stuff */

typedef struct pptx_ct_p_kinsoku_s {
    pptx_string lang;
    pptx_string inval_st_chars;
    pptx_string inval_end_chars;
    int32_t index;
} pptx_ct_p_kinsoku;

pptx_ct_p_kinsoku *
pptx_ct_p_kinsoku_new(xmlNode *node)
{
    pptx_ct_p_kinsoku *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->lang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lang");
    obj->inval_st_chars = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "invalStChars");
    obj->inval_end_chars = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "invalEndChars");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_kinsoku_get_lang(const pptx_ct_p_kinsoku *const obj)
{
    return obj->lang;
}

pptx_string 
pptx_ct_p_kinsoku_get_inval_st_chars(const pptx_ct_p_kinsoku *const obj)
{
    return obj->inval_st_chars;
}

pptx_string 
pptx_ct_p_kinsoku_get_inval_end_chars(const pptx_ct_p_kinsoku *const obj)
{
    return obj->inval_end_chars;
}

int32_t
pptx_ct_p_kinsoku_get_index(pptx_ct_p_kinsoku *obj)
{
    return obj->index;
}

void
pptx_ct_p_kinsoku_free(pptx_ct_p_kinsoku *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->lang);
    xmlFree(obj->inval_st_chars);
    xmlFree(obj->inval_end_chars);
    free(obj);
}