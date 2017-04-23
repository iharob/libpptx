#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-backdrop.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-point-3d.h>
#include <private/pptx-ct-a-vector-3d.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_backdrop_s {
    pptx_ct_a_point_3d *anchor;
    pptx_ct_a_vector_3d *norm;
    pptx_ct_a_vector_3d *up;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_backdrop;

pptx_ct_a_backdrop *
pptx_ct_a_backdrop_new(xmlNode *node)
{
    pptx_ct_a_backdrop *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:anchor");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->anchor = NULL;
        } else {
            obj->anchor = pptx_ct_a_point_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->anchor = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:norm");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->norm = NULL;
        } else {
            obj->norm = pptx_ct_a_vector_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->norm = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:up");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->up = NULL;
        } else {
            obj->up = pptx_ct_a_vector_3d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->up = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:extLst");
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_point_3d *
pptx_ct_a_backdrop_get_anchor(const pptx_ct_a_backdrop *const obj)
{
    return obj->anchor;
}

pptx_ct_a_vector_3d *
pptx_ct_a_backdrop_get_norm(const pptx_ct_a_backdrop *const obj)
{
    return obj->norm;
}

pptx_ct_a_vector_3d *
pptx_ct_a_backdrop_get_up(const pptx_ct_a_backdrop *const obj)
{
    return obj->up;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_backdrop_get_ext_lst(const pptx_ct_a_backdrop *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_backdrop_get_index(pptx_ct_a_backdrop *obj)
{
    return obj->index;
}

void
pptx_ct_a_backdrop_free(pptx_ct_a_backdrop *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_point_3d_free(obj->anchor);
    pptx_ct_a_vector_3d_free(obj->norm);
    pptx_ct_a_vector_3d_free(obj->up);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}