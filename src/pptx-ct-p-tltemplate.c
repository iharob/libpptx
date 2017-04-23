#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tltemplate.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-time-node-list.h>

typedef struct pptx_ct_p_tltemplate_s {
    pptx_ct_p_time_node_list *tn_lst;
    pptx_uint lvl;
    int32_t index;
} pptx_ct_p_tltemplate;

pptx_ct_p_tltemplate *
pptx_ct_p_tltemplate_new(xmlNode *node)
{
    pptx_ct_p_tltemplate *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tnLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tn_lst = NULL;
        } else {
            obj->tn_lst = pptx_ct_p_time_node_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tn_lst = NULL;
    }
    obj->lvl = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "lvl");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_time_node_list *
pptx_ct_p_tltemplate_get_tn_lst(const pptx_ct_p_tltemplate *const obj)
{
    return obj->tn_lst;
}

pptx_uint 
pptx_ct_p_tltemplate_get_lvl(const pptx_ct_p_tltemplate *const obj)
{
    return obj->lvl;
}

int32_t
pptx_ct_p_tltemplate_get_index(pptx_ct_p_tltemplate *obj)
{
    return obj->index;
}

void
pptx_ct_p_tltemplate_free(pptx_ct_p_tltemplate *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_time_node_list_free(obj->tn_lst);
    free(obj);
}