#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-regular-text-run.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-character-properties.h>

typedef struct pptx_ct_a_regular_text_run_s {
    pptx_ct_a_text_character_properties *r_pr;
    pptx_string t;
    int32_t index;
} pptx_ct_a_regular_text_run;

pptx_ct_a_regular_text_run *
pptx_ct_a_regular_text_run_new(xmlNode *node)
{
    pptx_ct_a_regular_text_run *obj;
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
    obj->t = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:t");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_character_properties *
pptx_ct_a_regular_text_run_get_r_pr(const pptx_ct_a_regular_text_run *const obj)
{
    return obj->r_pr;
}

pptx_string 
pptx_ct_a_regular_text_run_get_t(const pptx_ct_a_regular_text_run *const obj)
{
    return obj->t;
}

int32_t
pptx_ct_a_regular_text_run_get_index(pptx_ct_a_regular_text_run *obj)
{
    return obj->index;
}

void
pptx_ct_a_regular_text_run_free(pptx_ct_a_regular_text_run *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_character_properties_free(obj->r_pr);
    xmlFree(obj->t);
    free(obj);
}