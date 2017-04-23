#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-build-list.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlbuild-paragraph.h>
#include <private/pptx-ct-p-tlbuild-diagram.h>
#include <private/pptx-ct-p-tlole-build-chart.h>
#include <private/pptx-ct-p-tlgraphical-object-build.h>

typedef struct pptx_ct_p_build_list_s {
    pptx_ct_p_tlbuild_paragraph **bld_p;
    pptx_ct_p_tlbuild_diagram **bld_dgm;
    pptx_ct_p_tlole_build_chart **bld_ole_chart;
    pptx_ct_p_tlgraphical_object_build **bld_graphic;
    int32_t index;
} pptx_ct_p_build_list;

pptx_ct_p_build_list *
pptx_ct_p_build_list_new(xmlNode *node)
{
    pptx_ct_p_build_list *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldP");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bld_p = malloc((nodes->nodeNr + 1) * sizeof *obj->bld_p);
            if (obj->bld_p != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bld_p;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlbuild_paragraph_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bld_p);
                    obj->bld_p = NULL;
                } else {
                    obj->bld_p[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bld_p = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_p = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldDgm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bld_dgm = malloc((nodes->nodeNr + 1) * sizeof *obj->bld_dgm);
            if (obj->bld_dgm != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bld_dgm;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlbuild_diagram_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bld_dgm);
                    obj->bld_dgm = NULL;
                } else {
                    obj->bld_dgm[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bld_dgm = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_dgm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldOleChart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bld_ole_chart = malloc((nodes->nodeNr + 1) * sizeof *obj->bld_ole_chart);
            if (obj->bld_ole_chart != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bld_ole_chart;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlole_build_chart_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bld_ole_chart);
                    obj->bld_ole_chart = NULL;
                } else {
                    obj->bld_ole_chart[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bld_ole_chart = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_ole_chart = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:bldGraphic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->bld_graphic = malloc((nodes->nodeNr + 1) * sizeof *obj->bld_graphic);
            if (obj->bld_graphic != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->bld_graphic;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_tlgraphical_object_build_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->bld_graphic);
                    obj->bld_graphic = NULL;
                } else {
                    obj->bld_graphic[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->bld_graphic = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bld_graphic = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlbuild_paragraph **
pptx_ct_p_build_list_get_bld_p(const pptx_ct_p_build_list *const obj)
{
    return obj->bld_p;
}

pptx_ct_p_tlbuild_diagram **
pptx_ct_p_build_list_get_bld_dgm(const pptx_ct_p_build_list *const obj)
{
    return obj->bld_dgm;
}

pptx_ct_p_tlole_build_chart **
pptx_ct_p_build_list_get_bld_ole_chart(const pptx_ct_p_build_list *const obj)
{
    return obj->bld_ole_chart;
}

pptx_ct_p_tlgraphical_object_build **
pptx_ct_p_build_list_get_bld_graphic(const pptx_ct_p_build_list *const obj)
{
    return obj->bld_graphic;
}

int32_t
pptx_ct_p_build_list_get_index(pptx_ct_p_build_list *obj)
{
    return obj->index;
}

void
pptx_ct_p_build_list_free(pptx_ct_p_build_list *obj)
{
    if (obj == NULL)
        return;
    if (obj->bld_p != NULL) {
        for (int i = 0; obj->bld_p[i] != NULL; ++i) {
            pptx_ct_p_tlbuild_paragraph_free(obj->bld_p[i]);
        }
        free(obj->bld_p);
    }

    if (obj->bld_dgm != NULL) {
        for (int i = 0; obj->bld_dgm[i] != NULL; ++i) {
            pptx_ct_p_tlbuild_diagram_free(obj->bld_dgm[i]);
        }
        free(obj->bld_dgm);
    }

    if (obj->bld_ole_chart != NULL) {
        for (int i = 0; obj->bld_ole_chart[i] != NULL; ++i) {
            pptx_ct_p_tlole_build_chart_free(obj->bld_ole_chart[i]);
        }
        free(obj->bld_ole_chart);
    }

    if (obj->bld_graphic != NULL) {
        for (int i = 0; obj->bld_graphic[i] != NULL; ++i) {
            pptx_ct_p_tlgraphical_object_build_free(obj->bld_graphic[i]);
        }
        free(obj->bld_graphic);
    }

    free(obj);
}