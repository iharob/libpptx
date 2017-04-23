#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-scaling.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-log-base.h>
#include <private/pptx-ct-a-orientation.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_scaling_s {
    pptx_ct_a_log_base *log_base;
    pptx_ct_a_orientation *orientation;
    pptx_ct_a_double *max;
    pptx_ct_a_double *min;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_scaling;

pptx_ct_a_scaling *
pptx_ct_a_scaling_new(xmlNode *node)
{
    pptx_ct_a_scaling *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:logBase");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->log_base = NULL;
        } else {
            obj->log_base = pptx_ct_a_log_base_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->log_base = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:orientation");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->orientation = NULL;
        } else {
            obj->orientation = pptx_ct_a_orientation_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->orientation = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:max");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->max = NULL;
        } else {
            obj->max = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->max = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:min");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->min = NULL;
        } else {
            obj->min = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->min = NULL;
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

pptx_ct_a_log_base *
pptx_ct_a_scaling_get_log_base(const pptx_ct_a_scaling *const obj)
{
    return obj->log_base;
}

pptx_ct_a_orientation *
pptx_ct_a_scaling_get_orientation(const pptx_ct_a_scaling *const obj)
{
    return obj->orientation;
}

pptx_ct_a_double *
pptx_ct_a_scaling_get_max(const pptx_ct_a_scaling *const obj)
{
    return obj->max;
}

pptx_ct_a_double *
pptx_ct_a_scaling_get_min(const pptx_ct_a_scaling *const obj)
{
    return obj->min;
}

pptx_ct_a_extension_list *
pptx_ct_a_scaling_get_ext_lst(const pptx_ct_a_scaling *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_scaling_get_index(pptx_ct_a_scaling *obj)
{
    return obj->index;
}

void
pptx_ct_a_scaling_free(pptx_ct_a_scaling *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_log_base_free(obj->log_base);
    pptx_ct_a_orientation_free(obj->orientation);
    pptx_ct_a_double_free(obj->max);
    pptx_ct_a_double_free(obj->min);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}