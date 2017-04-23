#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-tx.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-str-ref.h>
#include <private/pptx-ct-a-text-body.h>

typedef struct pptx_ct_a_tx_s {
    pptx_ct_a_str_ref *str_ref;
    pptx_ct_a_text_body *rich;
    int32_t index;
} pptx_ct_a_tx;

pptx_ct_a_tx *
pptx_ct_a_tx_new(xmlNode *node)
{
    pptx_ct_a_tx *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:strRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->str_ref = NULL;
        } else {
            obj->str_ref = pptx_ct_a_str_ref_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->str_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rich");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rich = NULL;
        } else {
            obj->rich = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rich = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_str_ref *
pptx_ct_a_tx_get_str_ref(const pptx_ct_a_tx *const obj)
{
    return obj->str_ref;
}

pptx_ct_a_text_body *
pptx_ct_a_tx_get_rich(const pptx_ct_a_tx *const obj)
{
    return obj->rich;
}

int32_t
pptx_ct_a_tx_get_index(pptx_ct_a_tx *obj)
{
    return obj->index;
}

void
pptx_ct_a_tx_free(pptx_ct_a_tx *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_str_ref_free(obj->str_ref);
    pptx_ct_a_text_body_free(obj->rich);
    free(obj);
}