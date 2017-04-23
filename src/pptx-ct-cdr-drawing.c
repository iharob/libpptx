#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-cdr-drawing.h>
/* Imported internal stuff */
#include <private/pptx-ct-cdr-rel-size-anchor.h>
#include <private/pptx-ct-cdr-abs-size-anchor.h>

typedef struct pptx_ct_cdr_drawing_s {
    pptx_ct_cdr_rel_size_anchor **anchor_rel_size_anchor;
    pptx_ct_cdr_abs_size_anchor **anchor_abs_size_anchor;
    int32_t index;
} pptx_ct_cdr_drawing;

pptx_ct_cdr_drawing *
pptx_ct_cdr_drawing_new(xmlNode *node)
{
    pptx_ct_cdr_drawing *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:relSizeAnchor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anchor_rel_size_anchor = malloc((nodes->nodeNr + 1) * sizeof *obj->anchor_rel_size_anchor);
            if (obj->anchor_rel_size_anchor != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anchor_rel_size_anchor;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_cdr_rel_size_anchor_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->anchor_rel_size_anchor);
                    obj->anchor_rel_size_anchor = NULL;
                } else {
                    obj->anchor_rel_size_anchor[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anchor_rel_size_anchor = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anchor_rel_size_anchor = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "cdr:absSizeAnchor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->anchor_abs_size_anchor = malloc((nodes->nodeNr + 1) * sizeof *obj->anchor_abs_size_anchor);
            if (obj->anchor_abs_size_anchor != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->anchor_abs_size_anchor;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_cdr_abs_size_anchor_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->anchor_abs_size_anchor);
                    obj->anchor_abs_size_anchor = NULL;
                } else {
                    obj->anchor_abs_size_anchor[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->anchor_abs_size_anchor = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anchor_abs_size_anchor = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_cdr_rel_size_anchor **
pptx_ct_cdr_drawing_get_anchor_rel_size_anchor(const pptx_ct_cdr_drawing *const obj)
{
    return obj->anchor_rel_size_anchor;
}

pptx_ct_cdr_abs_size_anchor **
pptx_ct_cdr_drawing_get_anchor_abs_size_anchor(const pptx_ct_cdr_drawing *const obj)
{
    return obj->anchor_abs_size_anchor;
}

int32_t
pptx_ct_cdr_drawing_get_index(pptx_ct_cdr_drawing *obj)
{
    return obj->index;
}

void
pptx_ct_cdr_drawing_free(pptx_ct_cdr_drawing *obj)
{
    if (obj == NULL)
        return;
    if (obj->anchor_rel_size_anchor != NULL) {
        for (int i = 0; obj->anchor_rel_size_anchor[i] != NULL; ++i) {
            pptx_ct_cdr_rel_size_anchor_free(obj->anchor_rel_size_anchor[i]);
        }
        free(obj->anchor_rel_size_anchor);
    }

    if (obj->anchor_abs_size_anchor != NULL) {
        for (int i = 0; obj->anchor_abs_size_anchor[i] != NULL; ++i) {
            pptx_ct_cdr_abs_size_anchor_free(obj->anchor_abs_size_anchor[i]);
        }
        free(obj->anchor_abs_size_anchor);
    }

    free(obj);
}