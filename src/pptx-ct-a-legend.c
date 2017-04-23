#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-legend.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-legend-pos.h>
#include <private/pptx-ct-a-legend-entry.h>
#include <private/pptx-ct-a-layout.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_legend_s {
    pptx_ct_a_legend_pos *legend_pos;
    pptx_ct_a_legend_entry **legend_entry;
    pptx_ct_a_layout *layout;
    pptx_bool overlay;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_text_body *tx_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_legend;

pptx_ct_a_legend *
pptx_ct_a_legend_new(xmlNode *node)
{
    pptx_ct_a_legend *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:legendPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->legend_pos = NULL;
        } else {
            obj->legend_pos = pptx_ct_a_legend_pos_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->legend_pos = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:legendEntry");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->legend_entry = malloc((nodes->nodeNr + 1) * sizeof *obj->legend_entry);
            if (obj->legend_entry != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->legend_entry;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_legend_entry_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->legend_entry);
                    obj->legend_entry = NULL;
                } else {
                    obj->legend_entry[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->legend_entry = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->legend_entry = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:layout");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->layout = NULL;
        } else {
            obj->layout = pptx_ct_a_layout_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->layout = NULL;
    }
    obj->overlay = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:overlay");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_pr = NULL;
        } else {
            obj->tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_pr = NULL;
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

pptx_ct_a_legend_pos *
pptx_ct_a_legend_get_legend_pos(const pptx_ct_a_legend *const obj)
{
    return obj->legend_pos;
}

pptx_ct_a_legend_entry **
pptx_ct_a_legend_get_legend_entry(const pptx_ct_a_legend *const obj)
{
    return obj->legend_entry;
}

pptx_ct_a_layout *
pptx_ct_a_legend_get_layout(const pptx_ct_a_legend *const obj)
{
    return obj->layout;
}

pptx_bool 
pptx_ct_a_legend_get_overlay(const pptx_ct_a_legend *const obj)
{
    return obj->overlay;
}

pptx_ct_a_shape_properties *
pptx_ct_a_legend_get_sp_pr(const pptx_ct_a_legend *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_legend_get_tx_pr(const pptx_ct_a_legend *const obj)
{
    return obj->tx_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_legend_get_ext_lst(const pptx_ct_a_legend *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_legend_get_index(pptx_ct_a_legend *obj)
{
    return obj->index;
}

void
pptx_ct_a_legend_free(pptx_ct_a_legend *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_legend_pos_free(obj->legend_pos);
    if (obj->legend_entry != NULL) {
        for (int i = 0; obj->legend_entry[i] != NULL; ++i) {
            pptx_ct_a_legend_entry_free(obj->legend_entry[i]);
        }
        free(obj->legend_entry);
    }

    pptx_ct_a_layout_free(obj->layout);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_text_body_free(obj->tx_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}