#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-rules.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-numeric-rule.h>

typedef struct pptx_ct_dgm_rules_s {
    pptx_ct_dgm_numeric_rule **rule;
    int32_t index;
} pptx_ct_dgm_rules;

pptx_ct_dgm_rules *
pptx_ct_dgm_rules_new(xmlNode *node)
{
    pptx_ct_dgm_rules *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:rule");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->rule = malloc((nodes->nodeNr + 1) * sizeof *obj->rule);
            if (obj->rule != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->rule;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_numeric_rule_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->rule);
                    obj->rule = NULL;
                } else {
                    obj->rule[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->rule = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rule = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_numeric_rule **
pptx_ct_dgm_rules_get_rule(const pptx_ct_dgm_rules *const obj)
{
    return obj->rule;
}

int32_t
pptx_ct_dgm_rules_get_index(pptx_ct_dgm_rules *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_rules_free(pptx_ct_dgm_rules *obj)
{
    if (obj == NULL)
        return;
    if (obj->rule != NULL) {
        for (int i = 0; obj->rule[i] != NULL; ++i) {
            pptx_ct_dgm_numeric_rule_free(obj->rule[i]);
        }
        free(obj->rule);
    }

    free(obj);
}