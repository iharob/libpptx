#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-choose.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-when.h>
#include <private/pptx-ct-dgm-otherwise.h>

typedef struct pptx_ct_dgm_choose_s {
    pptx_ct_dgm_when **_if;
    pptx_ct_dgm_otherwise *_else;
    pptx_string name;
    int32_t index;
} pptx_ct_dgm_choose;

pptx_ct_dgm_choose *
pptx_ct_dgm_choose_new(xmlNode *node)
{
    pptx_ct_dgm_choose *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:if");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->_if = malloc((nodes->nodeNr + 1) * sizeof *obj->_if);
            if (obj->_if != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->_if;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_when_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, -1, -1);
                if (result == -1) {
                    free(obj->_if);
                    obj->_if = NULL;
                } else {
                    obj->_if[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->_if = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->_if = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:else");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->_else = NULL;
        } else {
            obj->_else = pptx_ct_dgm_otherwise_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->_else = NULL;
    }
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_when **
pptx_ct_dgm_choose_get__if(const pptx_ct_dgm_choose *const obj)
{
    return obj->_if;
}

pptx_ct_dgm_otherwise *
pptx_ct_dgm_choose_get__else(const pptx_ct_dgm_choose *const obj)
{
    return obj->_else;
}

pptx_string 
pptx_ct_dgm_choose_get_name(const pptx_ct_dgm_choose *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_dgm_choose_get_index(pptx_ct_dgm_choose *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_choose_free(pptx_ct_dgm_choose *obj)
{
    if (obj == NULL)
        return;
    if (obj->_if != NULL) {
        for (int i = 0; obj->_if[i] != NULL; ++i) {
            pptx_ct_dgm_when_free(obj->_if[i]);
        }
        free(obj->_if);
    }

    pptx_ct_dgm_otherwise_free(obj->_else);
    xmlFree(obj->name);
    free(obj);
}