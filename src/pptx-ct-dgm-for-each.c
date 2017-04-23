#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-for-each.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-algorithm.h>
#include <private/pptx-ct-dgm-shape.h>
#include <private/pptx-ct-dgm-presentation-of.h>
#include <private/pptx-ct-dgm-constraints.h>
#include <private/pptx-ct-dgm-rules.h>
#include <private/pptx-ct-dgm-for-each.h>
#include <private/pptx-ct-dgm-layout-node.h>
#include <private/pptx-ct-dgm-choose.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-axis-type.h>
#include <private/pptx-st-element-type.h>

typedef struct pptx_ct_dgm_for_each_s {
    pptx_ct_dgm_algorithm **alg;
    pptx_ct_dgm_shape **shape;
    pptx_ct_dgm_presentation_of **pres_of;
    pptx_ct_dgm_constraints **constr_lst;
    pptx_ct_dgm_rules **rule_lst;
    pptx_ct_dgm_for_each **for_each;
    pptx_ct_dgm_layout_node **layout_node;
    pptx_ct_dgm_choose **choose;
    pptx_ct_a_office_art_extension_list **ext_lst;
    pptx_string name;
    pptx_string ref;
    pptx_st_axis_type_token_enum axis;
    pptx_st_element_type_token_enum pt_type;
    pptx_bool hide_last_trans;
    pptx_int st;
    pptx_uint cnt;
    pptx_int step;
    int32_t index;
} pptx_ct_dgm_for_each;

pptx_ct_dgm_for_each *
pptx_ct_dgm_for_each_new(xmlNode *node)
{
    pptx_ct_dgm_for_each *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:alg");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->alg = malloc((nodes->nodeNr + 1) * sizeof *obj->alg);
            if (obj->alg != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->alg;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_algorithm_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->alg);
                    obj->alg = NULL;
                } else {
                    obj->alg[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->alg = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->alg = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:shape");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->shape = malloc((nodes->nodeNr + 1) * sizeof *obj->shape);
            if (obj->shape != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->shape;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_shape_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->shape);
                    obj->shape = NULL;
                } else {
                    obj->shape[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->shape = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->shape = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:presOf");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pres_of = malloc((nodes->nodeNr + 1) * sizeof *obj->pres_of);
            if (obj->pres_of != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pres_of;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_presentation_of_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->pres_of);
                    obj->pres_of = NULL;
                } else {
                    obj->pres_of[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pres_of = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pres_of = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:constrLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->constr_lst = malloc((nodes->nodeNr + 1) * sizeof *obj->constr_lst);
            if (obj->constr_lst != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->constr_lst;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_constraints_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->constr_lst);
                    obj->constr_lst = NULL;
                } else {
                    obj->constr_lst[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->constr_lst = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->constr_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:ruleLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->rule_lst = malloc((nodes->nodeNr + 1) * sizeof *obj->rule_lst);
            if (obj->rule_lst != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->rule_lst;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_rules_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->rule_lst);
                    obj->rule_lst = NULL;
                } else {
                    obj->rule_lst[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->rule_lst = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rule_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:forEach");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->for_each = malloc((nodes->nodeNr + 1) * sizeof *obj->for_each);
            if (obj->for_each != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->for_each;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_for_each_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->for_each);
                    obj->for_each = NULL;
                } else {
                    obj->for_each[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->for_each = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->for_each = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:layoutNode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->layout_node = malloc((nodes->nodeNr + 1) * sizeof *obj->layout_node);
            if (obj->layout_node != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->layout_node;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_layout_node_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->layout_node);
                    obj->layout_node = NULL;
                } else {
                    obj->layout_node[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->layout_node = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->layout_node = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:choose");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->choose = malloc((nodes->nodeNr + 1) * sizeof *obj->choose);
            if (obj->choose != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->choose;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_choose_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->choose);
                    obj->choose = NULL;
                } else {
                    obj->choose[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->choose = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->choose = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ext_lst = malloc((nodes->nodeNr + 1) * sizeof *obj->ext_lst);
            if (obj->ext_lst != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ext_lst;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_office_art_extension_list_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ext_lst);
                    obj->ext_lst = NULL;
                } else {
                    obj->ext_lst[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ext_lst = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->ref = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ref");
    obj->axis = pptx_get_st_axis_type(node, (const xmlChar *) "axis");
    obj->pt_type = pptx_get_st_element_type(node, (const xmlChar *) "ptType");
    obj->hide_last_trans = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hideLastTrans");
    obj->st = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "st");
    obj->cnt = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "cnt");
    obj->step = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "step");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_algorithm **
pptx_ct_dgm_for_each_get_alg(const pptx_ct_dgm_for_each *const obj)
{
    return obj->alg;
}

pptx_ct_dgm_shape **
pptx_ct_dgm_for_each_get_shape(const pptx_ct_dgm_for_each *const obj)
{
    return obj->shape;
}

pptx_ct_dgm_presentation_of **
pptx_ct_dgm_for_each_get_pres_of(const pptx_ct_dgm_for_each *const obj)
{
    return obj->pres_of;
}

pptx_ct_dgm_constraints **
pptx_ct_dgm_for_each_get_constr_lst(const pptx_ct_dgm_for_each *const obj)
{
    return obj->constr_lst;
}

pptx_ct_dgm_rules **
pptx_ct_dgm_for_each_get_rule_lst(const pptx_ct_dgm_for_each *const obj)
{
    return obj->rule_lst;
}

pptx_ct_dgm_for_each **
pptx_ct_dgm_for_each_get_for_each(const pptx_ct_dgm_for_each *const obj)
{
    return obj->for_each;
}

pptx_ct_dgm_layout_node **
pptx_ct_dgm_for_each_get_layout_node(const pptx_ct_dgm_for_each *const obj)
{
    return obj->layout_node;
}

pptx_ct_dgm_choose **
pptx_ct_dgm_for_each_get_choose(const pptx_ct_dgm_for_each *const obj)
{
    return obj->choose;
}

pptx_ct_a_office_art_extension_list **
pptx_ct_dgm_for_each_get_ext_lst(const pptx_ct_dgm_for_each *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_for_each_get_name(const pptx_ct_dgm_for_each *const obj)
{
    return obj->name;
}

pptx_string 
pptx_ct_dgm_for_each_get_ref(const pptx_ct_dgm_for_each *const obj)
{
    return obj->ref;
}

pptx_st_axis_type_token_enum 
pptx_ct_dgm_for_each_get_axis(const pptx_ct_dgm_for_each *const obj)
{
    return obj->axis;
}

pptx_st_element_type_token_enum 
pptx_ct_dgm_for_each_get_pt_type(const pptx_ct_dgm_for_each *const obj)
{
    return obj->pt_type;
}

pptx_bool 
pptx_ct_dgm_for_each_get_hide_last_trans(const pptx_ct_dgm_for_each *const obj)
{
    return obj->hide_last_trans;
}

pptx_int 
pptx_ct_dgm_for_each_get_st(const pptx_ct_dgm_for_each *const obj)
{
    return obj->st;
}

pptx_uint 
pptx_ct_dgm_for_each_get_cnt(const pptx_ct_dgm_for_each *const obj)
{
    return obj->cnt;
}

pptx_int 
pptx_ct_dgm_for_each_get_step(const pptx_ct_dgm_for_each *const obj)
{
    return obj->step;
}

int32_t
pptx_ct_dgm_for_each_get_index(pptx_ct_dgm_for_each *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_for_each_free(pptx_ct_dgm_for_each *obj)
{
    if (obj == NULL)
        return;
    if (obj->alg != NULL) {
        for (int i = 0; obj->alg[i] != NULL; ++i) {
            pptx_ct_dgm_algorithm_free(obj->alg[i]);
        }
        free(obj->alg);
    }

    if (obj->shape != NULL) {
        for (int i = 0; obj->shape[i] != NULL; ++i) {
            pptx_ct_dgm_shape_free(obj->shape[i]);
        }
        free(obj->shape);
    }

    if (obj->pres_of != NULL) {
        for (int i = 0; obj->pres_of[i] != NULL; ++i) {
            pptx_ct_dgm_presentation_of_free(obj->pres_of[i]);
        }
        free(obj->pres_of);
    }

    if (obj->constr_lst != NULL) {
        for (int i = 0; obj->constr_lst[i] != NULL; ++i) {
            pptx_ct_dgm_constraints_free(obj->constr_lst[i]);
        }
        free(obj->constr_lst);
    }

    if (obj->rule_lst != NULL) {
        for (int i = 0; obj->rule_lst[i] != NULL; ++i) {
            pptx_ct_dgm_rules_free(obj->rule_lst[i]);
        }
        free(obj->rule_lst);
    }

    if (obj->for_each != NULL) {
        for (int i = 0; obj->for_each[i] != NULL; ++i) {
            pptx_ct_dgm_for_each_free(obj->for_each[i]);
        }
        free(obj->for_each);
    }

    if (obj->layout_node != NULL) {
        for (int i = 0; obj->layout_node[i] != NULL; ++i) {
            pptx_ct_dgm_layout_node_free(obj->layout_node[i]);
        }
        free(obj->layout_node);
    }

    if (obj->choose != NULL) {
        for (int i = 0; obj->choose[i] != NULL; ++i) {
            pptx_ct_dgm_choose_free(obj->choose[i]);
        }
        free(obj->choose);
    }

    if (obj->ext_lst != NULL) {
        for (int i = 0; obj->ext_lst[i] != NULL; ++i) {
            pptx_ct_a_office_art_extension_list_free(obj->ext_lst[i]);
        }
        free(obj->ext_lst);
    }

    xmlFree(obj->name);
    xmlFree(obj->ref);
    free(obj);
}