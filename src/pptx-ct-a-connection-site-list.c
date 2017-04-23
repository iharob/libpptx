#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-connection-site-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-connection-site.h>

typedef struct pptx_ct_a_connection_site_list_s {
    pptx_ct_a_connection_site **cxn;
    int32_t index;
} pptx_ct_a_connection_site_list;

pptx_ct_a_connection_site_list *
pptx_ct_a_connection_site_list_new(xmlNode *node)
{
    pptx_ct_a_connection_site_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cxn");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cxn = malloc((nodes->nodeNr + 1) * sizeof *obj->cxn);
            if (obj->cxn != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cxn;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_connection_site_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cxn);
                    obj->cxn = NULL;
                } else {
                    obj->cxn[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cxn = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_connection_site **
pptx_ct_a_connection_site_list_get_cxn(const pptx_ct_a_connection_site_list *const obj)
{
    return obj->cxn;
}

int32_t
pptx_ct_a_connection_site_list_get_index(pptx_ct_a_connection_site_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_connection_site_list_free(pptx_ct_a_connection_site_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cxn != NULL) {
        for (int i = 0; obj->cxn[i] != NULL; ++i) {
            pptx_ct_a_connection_site_free(obj->cxn[i]);
        }
        free(obj->cxn);
    }

    free(obj);
}