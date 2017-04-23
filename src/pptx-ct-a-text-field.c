#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-field.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-character-properties.h>
#include <private/pptx-ct-a-text-paragraph-properties.h>

typedef struct pptx_ct_a_text_field_s {
    pptx_ct_a_text_character_properties *r_pr;
    pptx_ct_a_text_paragraph_properties *p_pr;
    pptx_string t;
    pptx_string id;
    pptx_string type;
    int32_t index;
} pptx_ct_a_text_field;

pptx_ct_a_text_field *
pptx_ct_a_text_field_new(xmlNode *node)
{
    pptx_ct_a_text_field *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->r_pr = NULL;
        } else {
            obj->r_pr = pptx_ct_a_text_character_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->r_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->p_pr = NULL;
        } else {
            obj->p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->p_pr = NULL;
    }
    obj->t = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:t");
    obj->id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "id");
    obj->type = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "type");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_character_properties *
pptx_ct_a_text_field_get_r_pr(const pptx_ct_a_text_field *const obj)
{
    return obj->r_pr;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_field_get_p_pr(const pptx_ct_a_text_field *const obj)
{
    return obj->p_pr;
}

pptx_string 
pptx_ct_a_text_field_get_t(const pptx_ct_a_text_field *const obj)
{
    return obj->t;
}

pptx_string 
pptx_ct_a_text_field_get_id(const pptx_ct_a_text_field *const obj)
{
    return obj->id;
}

pptx_string 
pptx_ct_a_text_field_get_type(const pptx_ct_a_text_field *const obj)
{
    return obj->type;
}

int32_t
pptx_ct_a_text_field_get_index(pptx_ct_a_text_field *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_field_free(pptx_ct_a_text_field *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_character_properties_free(obj->r_pr);
    pptx_ct_a_text_paragraph_properties_free(obj->p_pr);
    xmlFree(obj->t);
    xmlFree(obj->id);
    xmlFree(obj->type);
    free(obj);
}