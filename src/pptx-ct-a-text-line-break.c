#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-line-break.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-character-properties.h>

typedef struct pptx_ct_a_text_line_break_s {
    pptx_ct_a_text_character_properties *r_pr;
    int32_t index;
} pptx_ct_a_text_line_break;

pptx_ct_a_text_line_break *
pptx_ct_a_text_line_break_new(xmlNode *node)
{
    pptx_ct_a_text_line_break *obj;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_character_properties *
pptx_ct_a_text_line_break_get_r_pr(const pptx_ct_a_text_line_break *const obj)
{
    return obj->r_pr;
}

int32_t
pptx_ct_a_text_line_break_get_index(pptx_ct_a_text_line_break *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_line_break_free(pptx_ct_a_text_line_break *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_character_properties_free(obj->r_pr);
    free(obj);
}