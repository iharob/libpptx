#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-err-bars.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-err-dir.h>
#include <private/pptx-ct-a-err-bar-type.h>
#include <private/pptx-ct-a-err-val-type.h>
#include <private/pptx-ct-a-num-data-source.h>
#include <private/pptx-ct-a-double.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_err_bars_s {
    pptx_ct_a_err_dir *err_dir;
    pptx_ct_a_err_bar_type *err_bar_type;
    pptx_ct_a_err_val_type *err_val_type;
    pptx_bool no_end_cap;
    pptx_ct_a_num_data_source *plus;
    pptx_ct_a_num_data_source *minus;
    pptx_ct_a_double *val;
    pptx_ct_a_shape_properties *sp_pr;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_err_bars;

pptx_ct_a_err_bars *
pptx_ct_a_err_bars_new(xmlNode *node)
{
    pptx_ct_a_err_bars *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:errDir");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->err_dir = NULL;
        } else {
            obj->err_dir = pptx_ct_a_err_dir_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->err_dir = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:errBarType");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->err_bar_type = NULL;
        } else {
            obj->err_bar_type = pptx_ct_a_err_bar_type_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->err_bar_type = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:errValType");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->err_val_type = NULL;
        } else {
            obj->err_val_type = pptx_ct_a_err_val_type_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->err_val_type = NULL;
    }
    obj->no_end_cap = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:noEndCap");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:plus");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->plus = NULL;
        } else {
            obj->plus = pptx_ct_a_num_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->plus = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:minus");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->minus = NULL;
        } else {
            obj->minus = pptx_ct_a_num_data_source_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->minus = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:val");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->val = NULL;
        } else {
            obj->val = pptx_ct_a_double_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_pr = NULL;
        } else {
            obj->sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_pr = NULL;
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

pptx_ct_a_err_dir *
pptx_ct_a_err_bars_get_err_dir(const pptx_ct_a_err_bars *const obj)
{
    return obj->err_dir;
}

pptx_ct_a_err_bar_type *
pptx_ct_a_err_bars_get_err_bar_type(const pptx_ct_a_err_bars *const obj)
{
    return obj->err_bar_type;
}

pptx_ct_a_err_val_type *
pptx_ct_a_err_bars_get_err_val_type(const pptx_ct_a_err_bars *const obj)
{
    return obj->err_val_type;
}

pptx_bool 
pptx_ct_a_err_bars_get_no_end_cap(const pptx_ct_a_err_bars *const obj)
{
    return obj->no_end_cap;
}

pptx_ct_a_num_data_source *
pptx_ct_a_err_bars_get_plus(const pptx_ct_a_err_bars *const obj)
{
    return obj->plus;
}

pptx_ct_a_num_data_source *
pptx_ct_a_err_bars_get_minus(const pptx_ct_a_err_bars *const obj)
{
    return obj->minus;
}

pptx_ct_a_double *
pptx_ct_a_err_bars_get_val(const pptx_ct_a_err_bars *const obj)
{
    return obj->val;
}

pptx_ct_a_shape_properties *
pptx_ct_a_err_bars_get_sp_pr(const pptx_ct_a_err_bars *const obj)
{
    return obj->sp_pr;
}

pptx_ct_a_extension_list *
pptx_ct_a_err_bars_get_ext_lst(const pptx_ct_a_err_bars *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_err_bars_get_index(pptx_ct_a_err_bars *obj)
{
    return obj->index;
}

void
pptx_ct_a_err_bars_free(pptx_ct_a_err_bars *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_err_dir_free(obj->err_dir);
    pptx_ct_a_err_bar_type_free(obj->err_bar_type);
    pptx_ct_a_err_val_type_free(obj->err_val_type);
    pptx_ct_a_num_data_source_free(obj->plus);
    pptx_ct_a_num_data_source_free(obj->minus);
    pptx_ct_a_double_free(obj->val);
    pptx_ct_a_shape_properties_free(obj->sp_pr);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}