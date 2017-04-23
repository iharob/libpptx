#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-layout.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-manual-layout.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_layout_s {
    pptx_ct_a_manual_layout *manual_layout;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_layout;

pptx_ct_a_layout *
pptx_ct_a_layout_new(xmlNode *node)
{
    pptx_ct_a_layout *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:manualLayout");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->manual_layout = NULL;
        } else {
            obj->manual_layout = pptx_ct_a_manual_layout_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->manual_layout = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_manual_layout *
pptx_ct_a_layout_get_manual_layout(const pptx_ct_a_layout *const obj)
{
    return obj->manual_layout;
}

pptx_ct_a_extension_list *
pptx_ct_a_layout_get_ext_lst(const pptx_ct_a_layout *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_layout_get_index(pptx_ct_a_layout *obj)
{
    return obj->index;
}

void
pptx_ct_a_layout_free(pptx_ct_a_layout *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_manual_layout_free(obj->manual_layout);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}