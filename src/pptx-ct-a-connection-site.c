#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-connection-site.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-adj-point-2d.h>

typedef struct pptx_ct_a_connection_site_s {
    pptx_ct_a_adj_point_2d *pos;
    pptx_string ang;
    int32_t index;
} pptx_ct_a_connection_site;

pptx_ct_a_connection_site *
pptx_ct_a_connection_site_new(xmlNode *node)
{
    pptx_ct_a_connection_site *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pos = NULL;
        } else {
            obj->pos = pptx_ct_a_adj_point_2d_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pos = NULL;
    }
    obj->ang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "ang");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_adj_point_2d *
pptx_ct_a_connection_site_get_pos(const pptx_ct_a_connection_site *const obj)
{
    return obj->pos;
}

pptx_string 
pptx_ct_a_connection_site_get_ang(const pptx_ct_a_connection_site *const obj)
{
    return obj->ang;
}

int32_t
pptx_ct_a_connection_site_get_index(pptx_ct_a_connection_site *obj)
{
    return obj->index;
}

void
pptx_ct_a_connection_site_free(pptx_ct_a_connection_site *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_adj_point_2d_free(obj->pos);
    xmlFree(obj->ang);
    free(obj);
}