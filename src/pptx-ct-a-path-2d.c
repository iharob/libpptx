#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-path-2d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-path-2dclose.h>
#include <private/pptx-ct-a-path-2dmove-to.h>
#include <private/pptx-ct-a-path-2dline-to.h>
#include <private/pptx-ct-a-path-2darc-to.h>
#include <private/pptx-ct-a-path-2dquad-bezier-to.h>
#include <private/pptx-ct-a-path-2dcubic-bezier-to.h>
#include <private/pptx-st-path-fill-mode.h>

typedef struct pptx_ct_a_path_2d_s {
    pptx_ct_a_path_2dclose **close;
    pptx_ct_a_path_2dmove_to **move_to;
    pptx_ct_a_path_2dline_to **ln_to;
    pptx_ct_a_path_2darc_to **arc_to;
    pptx_ct_a_path_2dquad_bezier_to **quad_bez_to;
    pptx_ct_a_path_2dcubic_bezier_to **cubic_bez_to;
    pptx_long w;
    pptx_long h;
    pptx_st_path_fill_mode_token_enum fill;
    pptx_bool stroke;
    pptx_bool extrusion_ok;
    int32_t index;
} pptx_ct_a_path_2d;

pptx_ct_a_path_2d *
pptx_ct_a_path_2d_new(xmlNode *node)
{
    pptx_ct_a_path_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:close");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->close = malloc((nodes->nodeNr + 1) * sizeof *obj->close);
            if (obj->close != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->close;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2dclose_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->close);
                    obj->close = NULL;
                } else {
                    obj->close[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->close = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->close = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:moveTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->move_to = malloc((nodes->nodeNr + 1) * sizeof *obj->move_to);
            if (obj->move_to != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->move_to;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2dmove_to_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->move_to);
                    obj->move_to = NULL;
                } else {
                    obj->move_to[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->move_to = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->move_to = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->ln_to = malloc((nodes->nodeNr + 1) * sizeof *obj->ln_to);
            if (obj->ln_to != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->ln_to;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2dline_to_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->ln_to);
                    obj->ln_to = NULL;
                } else {
                    obj->ln_to[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->ln_to = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_to = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:arcTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->arc_to = malloc((nodes->nodeNr + 1) * sizeof *obj->arc_to);
            if (obj->arc_to != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->arc_to;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2darc_to_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->arc_to);
                    obj->arc_to = NULL;
                } else {
                    obj->arc_to[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->arc_to = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->arc_to = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:quadBezTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->quad_bez_to = malloc((nodes->nodeNr + 1) * sizeof *obj->quad_bez_to);
            if (obj->quad_bez_to != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->quad_bez_to;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2dquad_bezier_to_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->quad_bez_to);
                    obj->quad_bez_to = NULL;
                } else {
                    obj->quad_bez_to[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->quad_bez_to = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->quad_bez_to = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cubicBezTo");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cubic_bez_to = malloc((nodes->nodeNr + 1) * sizeof *obj->cubic_bez_to);
            if (obj->cubic_bez_to != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cubic_bez_to;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_path_2dcubic_bezier_to_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cubic_bez_to);
                    obj->cubic_bez_to = NULL;
                } else {
                    obj->cubic_bez_to[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cubic_bez_to = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cubic_bez_to = NULL;
    }
    obj->w = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "w");
    obj->h = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "h");
    obj->fill = pptx_get_st_path_fill_mode(node, (const xmlChar *) "fill");
    obj->stroke = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "stroke");
    obj->extrusion_ok = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "extrusionOk");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_path_2dclose **
pptx_ct_a_path_2d_get_close(const pptx_ct_a_path_2d *const obj)
{
    return obj->close;
}

pptx_ct_a_path_2dmove_to **
pptx_ct_a_path_2d_get_move_to(const pptx_ct_a_path_2d *const obj)
{
    return obj->move_to;
}

pptx_ct_a_path_2dline_to **
pptx_ct_a_path_2d_get_ln_to(const pptx_ct_a_path_2d *const obj)
{
    return obj->ln_to;
}

pptx_ct_a_path_2darc_to **
pptx_ct_a_path_2d_get_arc_to(const pptx_ct_a_path_2d *const obj)
{
    return obj->arc_to;
}

pptx_ct_a_path_2dquad_bezier_to **
pptx_ct_a_path_2d_get_quad_bez_to(const pptx_ct_a_path_2d *const obj)
{
    return obj->quad_bez_to;
}

pptx_ct_a_path_2dcubic_bezier_to **
pptx_ct_a_path_2d_get_cubic_bez_to(const pptx_ct_a_path_2d *const obj)
{
    return obj->cubic_bez_to;
}

pptx_long 
pptx_ct_a_path_2d_get_w(const pptx_ct_a_path_2d *const obj)
{
    return obj->w;
}

pptx_long 
pptx_ct_a_path_2d_get_h(const pptx_ct_a_path_2d *const obj)
{
    return obj->h;
}

pptx_st_path_fill_mode_token_enum 
pptx_ct_a_path_2d_get_fill(const pptx_ct_a_path_2d *const obj)
{
    return obj->fill;
}

pptx_bool 
pptx_ct_a_path_2d_get_stroke(const pptx_ct_a_path_2d *const obj)
{
    return obj->stroke;
}

pptx_bool 
pptx_ct_a_path_2d_get_extrusion_ok(const pptx_ct_a_path_2d *const obj)
{
    return obj->extrusion_ok;
}

int32_t
pptx_ct_a_path_2d_get_index(pptx_ct_a_path_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_path_2d_free(pptx_ct_a_path_2d *obj)
{
    if (obj == NULL)
        return;
    if (obj->close != NULL) {
        for (int i = 0; obj->close[i] != NULL; ++i) {
            pptx_ct_a_path_2dclose_free(obj->close[i]);
        }
        free(obj->close);
    }

    if (obj->move_to != NULL) {
        for (int i = 0; obj->move_to[i] != NULL; ++i) {
            pptx_ct_a_path_2dmove_to_free(obj->move_to[i]);
        }
        free(obj->move_to);
    }

    if (obj->ln_to != NULL) {
        for (int i = 0; obj->ln_to[i] != NULL; ++i) {
            pptx_ct_a_path_2dline_to_free(obj->ln_to[i]);
        }
        free(obj->ln_to);
    }

    if (obj->arc_to != NULL) {
        for (int i = 0; obj->arc_to[i] != NULL; ++i) {
            pptx_ct_a_path_2darc_to_free(obj->arc_to[i]);
        }
        free(obj->arc_to);
    }

    if (obj->quad_bez_to != NULL) {
        for (int i = 0; obj->quad_bez_to[i] != NULL; ++i) {
            pptx_ct_a_path_2dquad_bezier_to_free(obj->quad_bez_to[i]);
        }
        free(obj->quad_bez_to);
    }

    if (obj->cubic_bez_to != NULL) {
        for (int i = 0; obj->cubic_bez_to[i] != NULL; ++i) {
            pptx_ct_a_path_2dcubic_bezier_to_free(obj->cubic_bez_to[i]);
        }
        free(obj->cubic_bez_to);
    }

    free(obj);
}