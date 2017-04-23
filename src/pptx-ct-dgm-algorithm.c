#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-algorithm.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-parameter.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-algorithm-type.h>

typedef struct pptx_ct_dgm_algorithm_s {
    pptx_ct_dgm_parameter **param;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_algorithm_type_token_enum type;
    pptx_uint rev;
    int32_t index;
} pptx_ct_dgm_algorithm;

pptx_ct_dgm_algorithm *
pptx_ct_dgm_algorithm_new(xmlNode *node)
{
    pptx_ct_dgm_algorithm *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:param");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->param = malloc((nodes->nodeNr + 1) * sizeof *obj->param);
            if (obj->param != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->param;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_parameter_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->param);
                    obj->param = NULL;
                } else {
                    obj->param[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->param = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->param = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_office_art_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->type = pptx_get_st_algorithm_type(node, (const xmlChar *) "type");
    obj->rev = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "rev");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_parameter **
pptx_ct_dgm_algorithm_get_param(const pptx_ct_dgm_algorithm *const obj)
{
    return obj->param;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_algorithm_get_ext_lst(const pptx_ct_dgm_algorithm *const obj)
{
    return obj->ext_lst;
}

pptx_st_algorithm_type_token_enum 
pptx_ct_dgm_algorithm_get_type(const pptx_ct_dgm_algorithm *const obj)
{
    return obj->type;
}

pptx_uint 
pptx_ct_dgm_algorithm_get_rev(const pptx_ct_dgm_algorithm *const obj)
{
    return obj->rev;
}

int32_t
pptx_ct_dgm_algorithm_get_index(pptx_ct_dgm_algorithm *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_algorithm_free(pptx_ct_dgm_algorithm *obj)
{
    if (obj == NULL)
        return;
    if (obj->param != NULL) {
        for (int i = 0; obj->param[i] != NULL; ++i) {
            pptx_ct_dgm_parameter_free(obj->param[i]);
        }
        free(obj->param);
    }

    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}