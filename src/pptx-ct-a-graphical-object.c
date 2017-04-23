#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-graphical-object.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-graphical-object-data.h>

typedef struct pptx_ct_a_graphical_object_s {
    pptx_ct_a_graphical_object_data *graphic_data;
    int32_t index;
} pptx_ct_a_graphical_object;

pptx_ct_a_graphical_object *
pptx_ct_a_graphical_object_new(xmlNode *node)
{
    pptx_ct_a_graphical_object *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:graphicData");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->graphic_data = NULL;
        } else {
            obj->graphic_data = pptx_ct_a_graphical_object_data_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->graphic_data = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_graphical_object_data *
pptx_ct_a_graphical_object_get_graphic_data(const pptx_ct_a_graphical_object *const obj)
{
    return obj->graphic_data;
}

int32_t
pptx_ct_a_graphical_object_get_index(pptx_ct_a_graphical_object *obj)
{
    return obj->index;
}

void
pptx_ct_a_graphical_object_free(pptx_ct_a_graphical_object *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_graphical_object_data_free(obj->graphic_data);
    free(obj);
}