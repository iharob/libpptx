#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-view-3d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-rot-x.h>
#include <private/pptx-ct-a-hpercent.h>
#include <private/pptx-ct-a-rot-y.h>
#include <private/pptx-ct-a-depth-percent.h>
#include <private/pptx-ct-a-perspective.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_view_3d_s {
    pptx_ct_a_rot_x *rot_x;
    pptx_ct_a_hpercent *h_percent;
    pptx_ct_a_rot_y *rot_y;
    pptx_ct_a_depth_percent *depth_percent;
    pptx_bool r_ang_ax;
    pptx_ct_a_perspective *perspective;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_view_3d;

pptx_ct_a_view_3d *
pptx_ct_a_view_3d_new(xmlNode *node)
{
    pptx_ct_a_view_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rotX");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rot_x = NULL;
        } else {
            obj->rot_x = pptx_ct_a_rot_x_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rot_x = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hPercent");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->h_percent = NULL;
        } else {
            obj->h_percent = pptx_ct_a_hpercent_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->h_percent = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:rotY");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->rot_y = NULL;
        } else {
            obj->rot_y = pptx_ct_a_rot_y_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->rot_y = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:depthPercent");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->depth_percent = NULL;
        } else {
            obj->depth_percent = pptx_ct_a_depth_percent_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->depth_percent = NULL;
    }
    obj->r_ang_ax = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:rAngAx");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:perspective");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->perspective = NULL;
        } else {
            obj->perspective = pptx_ct_a_perspective_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->perspective = NULL;
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

pptx_ct_a_rot_x *
pptx_ct_a_view_3d_get_rot_x(const pptx_ct_a_view_3d *const obj)
{
    return obj->rot_x;
}

pptx_ct_a_hpercent *
pptx_ct_a_view_3d_get_h_percent(const pptx_ct_a_view_3d *const obj)
{
    return obj->h_percent;
}

pptx_ct_a_rot_y *
pptx_ct_a_view_3d_get_rot_y(const pptx_ct_a_view_3d *const obj)
{
    return obj->rot_y;
}

pptx_ct_a_depth_percent *
pptx_ct_a_view_3d_get_depth_percent(const pptx_ct_a_view_3d *const obj)
{
    return obj->depth_percent;
}

pptx_bool 
pptx_ct_a_view_3d_get_r_ang_ax(const pptx_ct_a_view_3d *const obj)
{
    return obj->r_ang_ax;
}

pptx_ct_a_perspective *
pptx_ct_a_view_3d_get_perspective(const pptx_ct_a_view_3d *const obj)
{
    return obj->perspective;
}

pptx_ct_a_extension_list *
pptx_ct_a_view_3d_get_ext_lst(const pptx_ct_a_view_3d *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_view_3d_get_index(pptx_ct_a_view_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_view_3d_free(pptx_ct_a_view_3d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_rot_x_free(obj->rot_x);
    pptx_ct_a_hpercent_free(obj->h_percent);
    pptx_ct_a_rot_y_free(obj->rot_y);
    pptx_ct_a_depth_percent_free(obj->depth_percent);
    pptx_ct_a_perspective_free(obj->perspective);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}