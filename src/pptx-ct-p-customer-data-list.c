#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-customer-data-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-customer-data.h>
#include <private/pptx-ct-p-tags-data.h>

typedef struct pptx_ct_p_customer_data_list_s {
    pptx_ct_p_customer_data **cust_data;
    pptx_ct_p_tags_data *tags;
    int32_t index;
} pptx_ct_p_customer_data_list;

pptx_ct_p_customer_data_list *
pptx_ct_p_customer_data_list_new(xmlNode *node)
{
    pptx_ct_p_customer_data_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:custData");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cust_data = malloc((nodes->nodeNr + 1) * sizeof *obj->cust_data);
            if (obj->cust_data != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cust_data;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_customer_data_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cust_data);
                    obj->cust_data = NULL;
                } else {
                    obj->cust_data[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cust_data = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cust_data = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tags");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tags = NULL;
        } else {
            obj->tags = pptx_ct_p_tags_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tags = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_customer_data **
pptx_ct_p_customer_data_list_get_cust_data(const pptx_ct_p_customer_data_list *const obj)
{
    return obj->cust_data;
}

pptx_ct_p_tags_data *
pptx_ct_p_customer_data_list_get_tags(const pptx_ct_p_customer_data_list *const obj)
{
    return obj->tags;
}

int32_t
pptx_ct_p_customer_data_list_get_index(pptx_ct_p_customer_data_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_customer_data_list_free(pptx_ct_p_customer_data_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->cust_data != NULL) {
        for (int i = 0; obj->cust_data[i] != NULL; ++i) {
            pptx_ct_p_customer_data_free(obj->cust_data[i]);
        }
        free(obj->cust_data);
    }

    pptx_ct_p_tags_data_free(obj->tags);
    free(obj);
}