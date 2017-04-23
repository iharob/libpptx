#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-scene-3d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-camera.h>
#include <private/pptx-ct-a-light-rig.h>
#include <private/pptx-ct-a-backdrop.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_scene_3d_s {
    pptx_ct_a_camera *camera;
    pptx_ct_a_light_rig *light_rig;
    pptx_ct_a_backdrop *backdrop;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_scene_3d;

pptx_ct_a_scene_3d *
pptx_ct_a_scene_3d_new(xmlNode *node)
{
    pptx_ct_a_scene_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:camera");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->camera = NULL;
        } else {
            obj->camera = pptx_ct_a_camera_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->camera = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lightRig");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->light_rig = NULL;
        } else {
            obj->light_rig = pptx_ct_a_light_rig_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->light_rig = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:backdrop");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->backdrop = NULL;
        } else {
            obj->backdrop = pptx_ct_a_backdrop_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->backdrop = NULL;
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

pptx_ct_a_camera *
pptx_ct_a_scene_3d_get_camera(const pptx_ct_a_scene_3d *const obj)
{
    return obj->camera;
}

pptx_ct_a_light_rig *
pptx_ct_a_scene_3d_get_light_rig(const pptx_ct_a_scene_3d *const obj)
{
    return obj->light_rig;
}

pptx_ct_a_backdrop *
pptx_ct_a_scene_3d_get_backdrop(const pptx_ct_a_scene_3d *const obj)
{
    return obj->backdrop;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_scene_3d_get_ext_lst(const pptx_ct_a_scene_3d *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_scene_3d_get_index(pptx_ct_a_scene_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_scene_3d_free(pptx_ct_a_scene_3d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_camera_free(obj->camera);
    pptx_ct_a_light_rig_free(obj->light_rig);
    pptx_ct_a_backdrop_free(obj->backdrop);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}