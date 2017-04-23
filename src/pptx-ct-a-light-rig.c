#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-light-rig.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sphere-coords.h>
#include <private/pptx-st-light-rig-type.h>
#include <private/pptx-st-light-rig-direction.h>

typedef struct pptx_ct_a_light_rig_s {
    pptx_ct_a_sphere_coords *rot;
    pptx_st_light_rig_type_token_enum rig;
    pptx_st_light_rig_direction_token_enum dir;
    int32_t index;
} pptx_ct_a_light_rig;

pptx_ct_a_light_rig *
pptx_ct_a_light_rig_new(xmlNode *node)
{
    pptx_ct_a_light_rig *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rot");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rot = NULL;
        } else {
            obj->rot = pptx_ct_a_sphere_coords_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rot = NULL;
    }
    obj->rig = pptx_get_st_light_rig_type(node, (const xmlChar *) "rig");
    obj->dir = pptx_get_st_light_rig_direction(node, (const xmlChar *) "dir");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sphere_coords *
pptx_ct_a_light_rig_get_rot(const pptx_ct_a_light_rig *const obj)
{
    return obj->rot;
}

pptx_st_light_rig_type_token_enum 
pptx_ct_a_light_rig_get_rig(const pptx_ct_a_light_rig *const obj)
{
    return obj->rig;
}

pptx_st_light_rig_direction_token_enum 
pptx_ct_a_light_rig_get_dir(const pptx_ct_a_light_rig *const obj)
{
    return obj->dir;
}

int32_t
pptx_ct_a_light_rig_get_index(pptx_ct_a_light_rig *obj)
{
    return obj->index;
}

void
pptx_ct_a_light_rig_free(pptx_ct_a_light_rig *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_sphere_coords_free(obj->rot);
    free(obj);
}