#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-fill-style-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-no-fill-properties.h>
#include <private/pptx-ct-a-solid-color-fill-properties.h>
#include <private/pptx-ct-a-gradient-fill-properties.h>
#include <private/pptx-ct-a-blip-fill-properties.h>
#include <private/pptx-ct-a-pattern-fill-properties.h>
#include <private/pptx-ct-a-group-fill-properties.h>

typedef struct pptx_ct_a_fill_style_list_s {
    pptx_ct_a_no_fill_properties **fill_properties_no_fill;
    pptx_ct_a_solid_color_fill_properties **fill_properties_solid_fill;
    pptx_ct_a_gradient_fill_properties **fill_properties_grad_fill;
    pptx_ct_a_blip_fill_properties **fill_properties_blip_fill;
    pptx_ct_a_pattern_fill_properties **fill_properties_patt_fill;
    pptx_ct_a_group_fill_properties **fill_properties_grp_fill;
    int32_t index;
} pptx_ct_a_fill_style_list;

pptx_ct_a_fill_style_list *
pptx_ct_a_fill_style_list_new(xmlNode *node)
{
    pptx_ct_a_fill_style_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:noFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_no_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_no_fill);
            if (obj->fill_properties_no_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_no_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_no_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_no_fill);
                    obj->fill_properties_no_fill = NULL;
                } else {
                    obj->fill_properties_no_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_no_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_no_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:solidFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_solid_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_solid_fill);
            if (obj->fill_properties_solid_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_solid_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_solid_color_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_solid_fill);
                    obj->fill_properties_solid_fill = NULL;
                } else {
                    obj->fill_properties_solid_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_solid_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_solid_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:gradFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_grad_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_grad_fill);
            if (obj->fill_properties_grad_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_grad_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_gradient_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_grad_fill);
                    obj->fill_properties_grad_fill = NULL;
                } else {
                    obj->fill_properties_grad_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_grad_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grad_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:blipFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_blip_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_blip_fill);
            if (obj->fill_properties_blip_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_blip_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_blip_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_blip_fill);
                    obj->fill_properties_blip_fill = NULL;
                } else {
                    obj->fill_properties_blip_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_blip_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_blip_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pattFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_patt_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_patt_fill);
            if (obj->fill_properties_patt_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_patt_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_pattern_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_patt_fill);
                    obj->fill_properties_patt_fill = NULL;
                } else {
                    obj->fill_properties_patt_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_patt_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_patt_fill = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpFill");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->fill_properties_grp_fill = malloc((nodes->nodeNr + 1) * sizeof *obj->fill_properties_grp_fill);
            if (obj->fill_properties_grp_fill != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->fill_properties_grp_fill;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_group_fill_properties_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 3, -1);
                if (result == -1) {
                    free(obj->fill_properties_grp_fill);
                    obj->fill_properties_grp_fill = NULL;
                } else {
                    obj->fill_properties_grp_fill[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->fill_properties_grp_fill = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fill_properties_grp_fill = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_no_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_no_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_no_fill;
}

pptx_ct_a_solid_color_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_solid_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_solid_fill;
}

pptx_ct_a_gradient_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_grad_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_grad_fill;
}

pptx_ct_a_blip_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_blip_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_blip_fill;
}

pptx_ct_a_pattern_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_patt_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_patt_fill;
}

pptx_ct_a_group_fill_properties **
pptx_ct_a_fill_style_list_get_fill_properties_grp_fill(const pptx_ct_a_fill_style_list *const obj)
{
    return obj->fill_properties_grp_fill;
}

int32_t
pptx_ct_a_fill_style_list_get_index(pptx_ct_a_fill_style_list *obj)
{
    return obj->index;
}

void
pptx_ct_a_fill_style_list_free(pptx_ct_a_fill_style_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->fill_properties_no_fill != NULL) {
        for (int i = 0; obj->fill_properties_no_fill[i] != NULL; ++i) {
            pptx_ct_a_no_fill_properties_free(obj->fill_properties_no_fill[i]);
        }
        free(obj->fill_properties_no_fill);
    }

    if (obj->fill_properties_solid_fill != NULL) {
        for (int i = 0; obj->fill_properties_solid_fill[i] != NULL; ++i) {
            pptx_ct_a_solid_color_fill_properties_free(obj->fill_properties_solid_fill[i]);
        }
        free(obj->fill_properties_solid_fill);
    }

    if (obj->fill_properties_grad_fill != NULL) {
        for (int i = 0; obj->fill_properties_grad_fill[i] != NULL; ++i) {
            pptx_ct_a_gradient_fill_properties_free(obj->fill_properties_grad_fill[i]);
        }
        free(obj->fill_properties_grad_fill);
    }

    if (obj->fill_properties_blip_fill != NULL) {
        for (int i = 0; obj->fill_properties_blip_fill[i] != NULL; ++i) {
            pptx_ct_a_blip_fill_properties_free(obj->fill_properties_blip_fill[i]);
        }
        free(obj->fill_properties_blip_fill);
    }

    if (obj->fill_properties_patt_fill != NULL) {
        for (int i = 0; obj->fill_properties_patt_fill[i] != NULL; ++i) {
            pptx_ct_a_pattern_fill_properties_free(obj->fill_properties_patt_fill[i]);
        }
        free(obj->fill_properties_patt_fill);
    }

    if (obj->fill_properties_grp_fill != NULL) {
        for (int i = 0; obj->fill_properties_grp_fill[i] != NULL; ++i) {
            pptx_ct_a_group_fill_properties_free(obj->fill_properties_grp_fill[i]);
        }
        free(obj->fill_properties_grp_fill);
    }

    free(obj);
}