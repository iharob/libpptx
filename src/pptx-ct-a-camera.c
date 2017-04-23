#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-camera.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-sphere-coords.h>
#include <private/pptx-st-preset-camera-type.h>

typedef struct pptx_ct_a_camera_s {
    pptx_ct_a_sphere_coords *rot;
    pptx_st_preset_camera_type_token_enum prst;
    pptx_int fov;
    pptx_string zoom;
    int32_t index;
} pptx_ct_a_camera;

pptx_ct_a_camera *
pptx_ct_a_camera_new(xmlNode *node)
{
    pptx_ct_a_camera *obj;
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
    obj->prst = pptx_get_st_preset_camera_type(node, (const xmlChar *) "prst");
    obj->fov = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "fov");
    obj->zoom = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "zoom");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_sphere_coords *
pptx_ct_a_camera_get_rot(const pptx_ct_a_camera *const obj)
{
    return obj->rot;
}

pptx_st_preset_camera_type_token_enum 
pptx_ct_a_camera_get_prst(const pptx_ct_a_camera *const obj)
{
    return obj->prst;
}

pptx_int 
pptx_ct_a_camera_get_fov(const pptx_ct_a_camera *const obj)
{
    return obj->fov;
}

pptx_string 
pptx_ct_a_camera_get_zoom(const pptx_ct_a_camera *const obj)
{
    return obj->zoom;
}

int32_t
pptx_ct_a_camera_get_index(pptx_ct_a_camera *obj)
{
    return obj->index;
}

void
pptx_ct_a_camera_free(pptx_ct_a_camera *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_sphere_coords_free(obj->rot);
    xmlFree(obj->zoom);
    free(obj);
}