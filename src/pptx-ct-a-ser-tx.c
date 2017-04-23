#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-ser-tx.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-str-ref.h>

typedef struct pptx_ct_a_ser_tx_s {
    pptx_ct_a_str_ref *str_ref;
    pptx_string v;
    int32_t index;
} pptx_ct_a_ser_tx;

pptx_ct_a_ser_tx *
pptx_ct_a_ser_tx_new(xmlNode *node)
{
    pptx_ct_a_ser_tx *obj;
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
    obj->v = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:v");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_str_ref *
pptx_ct_a_ser_tx_get_str_ref(const pptx_ct_a_ser_tx *const obj)
{
    return obj->str_ref;
}

pptx_string 
pptx_ct_a_ser_tx_get_v(const pptx_ct_a_ser_tx *const obj)
{
    return obj->v;
}

int32_t
pptx_ct_a_ser_tx_get_index(pptx_ct_a_ser_tx *obj)
{
    return obj->index;
}

void
pptx_ct_a_ser_tx_free(pptx_ct_a_ser_tx *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_str_ref_free(obj->str_ref);
    xmlFree(obj->v);
    free(obj);
}