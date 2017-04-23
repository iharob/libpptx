#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-constraints.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-constraint.h>

typedef struct pptx_ct_dgm_constraints_s {
    pptx_ct_dgm_constraint **constr;
    int32_t index;
} pptx_ct_dgm_constraints;

pptx_ct_dgm_constraints *
pptx_ct_dgm_constraints_new(xmlNode *node)
{
    pptx_ct_dgm_constraints *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:constr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->constr = malloc((nodes->nodeNr + 1) * sizeof *obj->constr);
            if (obj->constr != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->constr;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_constraint_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->constr);
                    obj->constr = NULL;
                } else {
                    obj->constr[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->constr = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->constr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_constraint **
pptx_ct_dgm_constraints_get_constr(const pptx_ct_dgm_constraints *const obj)
{
    return obj->constr;
}

int32_t
pptx_ct_dgm_constraints_get_index(pptx_ct_dgm_constraints *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_constraints_free(pptx_ct_dgm_constraints *obj)
{
    if (obj == NULL)
        return;
    if (obj->constr != NULL) {
        for (int i = 0; obj->constr[i] != NULL; ++i) {
            pptx_ct_dgm_constraint_free(obj->constr[i]);
        }
        free(obj->constr);
    }

    free(obj);
}