#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-surface-chart.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-surface-ser.h>
#include <private/pptx-ct-a-band-fmts.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_surface_chart_s {
    pptx_bool surface_chart_shared_wireframe;
    pptx_ct_a_surface_ser **surface_chart_shared_ser;
    pptx_ct_a_band_fmts *surface_chart_shared_band_fmts;

    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_surface_chart;

pptx_ct_a_surface_chart *
pptx_ct_a_surface_chart_new(xmlNode *node)
{
    pptx_ct_a_surface_chart *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->surface_chart_shared_wireframe = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:wireframe");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ser");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->surface_chart_shared_ser = malloc((nodes->nodeNr + 1) * sizeof *obj->surface_chart_shared_ser);
            if (obj->surface_chart_shared_ser != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->surface_chart_shared_ser;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_surface_ser_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->surface_chart_shared_ser);
                    obj->surface_chart_shared_ser = NULL;
                } else {
                    obj->surface_chart_shared_ser[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->surface_chart_shared_ser = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->surface_chart_shared_ser = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bandFmts");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->surface_chart_shared_band_fmts = NULL;
        } else {
            obj->surface_chart_shared_band_fmts = pptx_ct_a_band_fmts_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->surface_chart_shared_band_fmts = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_a_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_bool 
pptx_ct_a_surface_chart_get_surface_chart_shared_wireframe(const pptx_ct_a_surface_chart *const obj)
{
    return obj->surface_chart_shared_wireframe;
}

pptx_ct_a_surface_ser **
pptx_ct_a_surface_chart_get_surface_chart_shared_ser(const pptx_ct_a_surface_chart *const obj)
{
    return obj->surface_chart_shared_ser;
}

pptx_ct_a_band_fmts *
pptx_ct_a_surface_chart_get_surface_chart_shared_band_fmts(const pptx_ct_a_surface_chart *const obj)
{
    return obj->surface_chart_shared_band_fmts;
}

pptx_ct_a_extension_list *
pptx_ct_a_surface_chart_get_ext_lst(const pptx_ct_a_surface_chart *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_surface_chart_get_index(pptx_ct_a_surface_chart *obj)
{
    return obj->index;
}

void
pptx_ct_a_surface_chart_free(pptx_ct_a_surface_chart *obj)
{
    if (obj == NULL)
        return;
    if (obj->surface_chart_shared_ser != NULL) {
        for (int i = 0; obj->surface_chart_shared_ser[i] != NULL; ++i) {
            pptx_ct_a_surface_ser_free(obj->surface_chart_shared_ser[i]);
        }
        free(obj->surface_chart_shared_ser);
    }

    pptx_ct_a_band_fmts_free(obj->surface_chart_shared_band_fmts);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}