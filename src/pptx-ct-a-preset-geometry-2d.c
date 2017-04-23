#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-preset-geometry-2d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-geom-guide-list.h>
#include <private/pptx-st-shape-type.h>

typedef struct pptx_ct_a_preset_geometry_2d_s {
    pptx_ct_a_geom_guide_list *av_lst;
    pptx_st_shape_type_token_enum prst;
    int32_t index;
} pptx_ct_a_preset_geometry_2d;

pptx_ct_a_preset_geometry_2d *
pptx_ct_a_preset_geometry_2d_new(xmlNode *node)
{
    pptx_ct_a_preset_geometry_2d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:avLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->av_lst = NULL;
        } else {
            obj->av_lst = pptx_ct_a_geom_guide_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->av_lst = NULL;
    }
    obj->prst = pptx_get_st_shape_type(node, (const xmlChar *) "prst");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_geom_guide_list *
pptx_ct_a_preset_geometry_2d_get_av_lst(const pptx_ct_a_preset_geometry_2d *const obj)
{
    return obj->av_lst;
}

pptx_st_shape_type_token_enum 
pptx_ct_a_preset_geometry_2d_get_prst(const pptx_ct_a_preset_geometry_2d *const obj)
{
    return obj->prst;
}

int32_t
pptx_ct_a_preset_geometry_2d_get_index(pptx_ct_a_preset_geometry_2d *obj)
{
    return obj->index;
}

void
pptx_ct_a_preset_geometry_2d_free(pptx_ct_a_preset_geometry_2d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_geom_guide_list_free(obj->av_lst);
    free(obj);
}