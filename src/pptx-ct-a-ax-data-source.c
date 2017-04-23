#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-ax-data-source.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-multi-lvl-str-ref.h>
#include <private/pptx-ct-a-num-ref.h>
#include <private/pptx-ct-a-num-data.h>
#include <private/pptx-ct-a-str-ref.h>
#include <private/pptx-ct-a-str-data.h>

typedef struct pptx_ct_a_ax_data_source_s {
    pptx_ct_a_multi_lvl_str_ref *multi_lvl_str_ref;
    pptx_ct_a_num_ref *num_ref;
    pptx_ct_a_num_data *num_lit;
    pptx_ct_a_str_ref *str_ref;
    pptx_ct_a_str_data *str_lit;
    int32_t index;
} pptx_ct_a_ax_data_source;

pptx_ct_a_ax_data_source *
pptx_ct_a_ax_data_source_new(xmlNode *node)
{
    pptx_ct_a_ax_data_source *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:multiLvlStrRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->multi_lvl_str_ref = NULL;
        } else {
            obj->multi_lvl_str_ref = pptx_ct_a_multi_lvl_str_ref_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->multi_lvl_str_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:numRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->num_ref = NULL;
        } else {
            obj->num_ref = pptx_ct_a_num_ref_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->num_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:numLit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->num_lit = NULL;
        } else {
            obj->num_lit = pptx_ct_a_num_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->num_lit = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:strRef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->str_ref = NULL;
        } else {
            obj->str_ref = pptx_ct_a_str_ref_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->str_ref = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:strLit");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->str_lit = NULL;
        } else {
            obj->str_lit = pptx_ct_a_str_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->str_lit = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_multi_lvl_str_ref *
pptx_ct_a_ax_data_source_get_multi_lvl_str_ref(const pptx_ct_a_ax_data_source *const obj)
{
    return obj->multi_lvl_str_ref;
}

pptx_ct_a_num_ref *
pptx_ct_a_ax_data_source_get_num_ref(const pptx_ct_a_ax_data_source *const obj)
{
    return obj->num_ref;
}

pptx_ct_a_num_data *
pptx_ct_a_ax_data_source_get_num_lit(const pptx_ct_a_ax_data_source *const obj)
{
    return obj->num_lit;
}

pptx_ct_a_str_ref *
pptx_ct_a_ax_data_source_get_str_ref(const pptx_ct_a_ax_data_source *const obj)
{
    return obj->str_ref;
}

pptx_ct_a_str_data *
pptx_ct_a_ax_data_source_get_str_lit(const pptx_ct_a_ax_data_source *const obj)
{
    return obj->str_lit;
}

int32_t
pptx_ct_a_ax_data_source_get_index(pptx_ct_a_ax_data_source *obj)
{
    return obj->index;
}

void
pptx_ct_a_ax_data_source_free(pptx_ct_a_ax_data_source *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_multi_lvl_str_ref_free(obj->multi_lvl_str_ref);
    pptx_ct_a_num_ref_free(obj->num_ref);
    pptx_ct_a_num_data_free(obj->num_lit);
    pptx_ct_a_str_ref_free(obj->str_ref);
    pptx_ct_a_str_data_free(obj->str_lit);
    free(obj);
}