#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-manual-layout.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-layout-target.h>
#include <private/pptx-ct-a-layout-mode.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_manual_layout_s {
    pptx_ct_a_layout_target *layout_target;
    pptx_ct_a_layout_mode *x_mode;
    pptx_ct_a_layout_mode *y_mode;
    pptx_ct_a_layout_mode *w_mode;
    pptx_ct_a_layout_mode *h_mode;
    pptx_ct_a_double *x;
    pptx_ct_a_double *y;
    pptx_ct_a_double *w;
    pptx_ct_a_double *h;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_manual_layout;

pptx_ct_a_manual_layout *
pptx_ct_a_manual_layout_new(xmlNode *node)
{
    pptx_ct_a_manual_layout *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:layoutTarget");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->layout_target = NULL;
        } else {
            obj->layout_target = pptx_ct_a_layout_target_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->layout_target = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:xMode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->x_mode = NULL;
        } else {
            obj->x_mode = pptx_ct_a_layout_mode_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->x_mode = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:yMode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->y_mode = NULL;
        } else {
            obj->y_mode = pptx_ct_a_layout_mode_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->y_mode = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:wMode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->w_mode = NULL;
        } else {
            obj->w_mode = pptx_ct_a_layout_mode_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->w_mode = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hMode");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->h_mode = NULL;
        } else {
            obj->h_mode = pptx_ct_a_layout_mode_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->h_mode = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:x");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->x = NULL;
        } else {
            obj->x = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->x = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:y");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->y = NULL;
        } else {
            obj->y = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->y = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:w");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->w = NULL;
        } else {
            obj->w = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->w = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:h");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->h = NULL;
        } else {
            obj->h = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->h = NULL;
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

pptx_ct_a_layout_target *
pptx_ct_a_manual_layout_get_layout_target(const pptx_ct_a_manual_layout *const obj)
{
    return obj->layout_target;
}

pptx_ct_a_layout_mode *
pptx_ct_a_manual_layout_get_x_mode(const pptx_ct_a_manual_layout *const obj)
{
    return obj->x_mode;
}

pptx_ct_a_layout_mode *
pptx_ct_a_manual_layout_get_y_mode(const pptx_ct_a_manual_layout *const obj)
{
    return obj->y_mode;
}

pptx_ct_a_layout_mode *
pptx_ct_a_manual_layout_get_w_mode(const pptx_ct_a_manual_layout *const obj)
{
    return obj->w_mode;
}

pptx_ct_a_layout_mode *
pptx_ct_a_manual_layout_get_h_mode(const pptx_ct_a_manual_layout *const obj)
{
    return obj->h_mode;
}

pptx_ct_a_double *
pptx_ct_a_manual_layout_get_x(const pptx_ct_a_manual_layout *const obj)
{
    return obj->x;
}

pptx_ct_a_double *
pptx_ct_a_manual_layout_get_y(const pptx_ct_a_manual_layout *const obj)
{
    return obj->y;
}

pptx_ct_a_double *
pptx_ct_a_manual_layout_get_w(const pptx_ct_a_manual_layout *const obj)
{
    return obj->w;
}

pptx_ct_a_double *
pptx_ct_a_manual_layout_get_h(const pptx_ct_a_manual_layout *const obj)
{
    return obj->h;
}

pptx_ct_a_extension_list *
pptx_ct_a_manual_layout_get_ext_lst(const pptx_ct_a_manual_layout *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_manual_layout_get_index(pptx_ct_a_manual_layout *obj)
{
    return obj->index;
}

void
pptx_ct_a_manual_layout_free(pptx_ct_a_manual_layout *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_layout_target_free(obj->layout_target);
    pptx_ct_a_layout_mode_free(obj->x_mode);
    pptx_ct_a_layout_mode_free(obj->y_mode);
    pptx_ct_a_layout_mode_free(obj->w_mode);
    pptx_ct_a_layout_mode_free(obj->h_mode);
    pptx_ct_a_double_free(obj->x);
    pptx_ct_a_double_free(obj->y);
    pptx_ct_a_double_free(obj->w);
    pptx_ct_a_double_free(obj->h);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}