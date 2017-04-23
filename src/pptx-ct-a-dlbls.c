#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-dlbls.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-dlbl.h>
#include <private/pptx-ct-a-num-fmt.h>
#include <private/pptx-ct-a-shape-properties.h>
#include <private/pptx-ct-a-text-body.h>
#include <private/pptx-ct-a-dlbl-pos.h>
#include <private/pptx-ct-a-chart-lines.h>
#include <private/pptx-ct-a-extension-list.h>

typedef struct pptx_ct_a_dlbls_s {
    pptx_ct_a_dlbl **d_lbl;
    pptx_bool delete;
    pptx_ct_a_num_fmt *dlbl_shared_num_fmt;
    pptx_ct_a_shape_properties *dlbl_shared_sp_pr;
    pptx_ct_a_text_body *dlbl_shared_tx_pr;
    pptx_ct_a_dlbl_pos *dlbl_shared_d_lbl_pos;
    pptx_bool dlbl_shared_show_legend_key;
    pptx_bool dlbl_shared_show_val;
    pptx_bool dlbl_shared_show_cat_name;
    pptx_bool dlbl_shared_show_ser_name;
    pptx_bool dlbl_shared_show_percent;
    pptx_bool dlbl_shared_show_bubble_size;
    pptx_string dlbl_shared_separator;
    pptx_bool group_dlbls_show_leader_lines;
    pptx_ct_a_chart_lines *group_dlbls_leader_lines;
    pptx_ct_a_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_dlbls;

pptx_ct_a_dlbls *
pptx_ct_a_dlbls_new(xmlNode *node)
{
    pptx_ct_a_dlbls *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLbl");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->d_lbl = malloc((nodes->nodeNr + 1) * sizeof *obj->d_lbl);
            if (obj->d_lbl != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->d_lbl;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_dlbl_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->d_lbl);
                    obj->d_lbl = NULL;
                } else {
                    obj->d_lbl[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->d_lbl = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->d_lbl = NULL;
    }
    obj->delete = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:delete");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:numFmt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_num_fmt = NULL;
        } else {
            obj->dlbl_shared_num_fmt = pptx_ct_a_num_fmt_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_num_fmt = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_sp_pr = NULL;
        } else {
            obj->dlbl_shared_sp_pr = pptx_ct_a_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_tx_pr = NULL;
        } else {
            obj->dlbl_shared_tx_pr = pptx_ct_a_text_body_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_tx_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dLblPos");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dlbl_shared_d_lbl_pos = NULL;
        } else {
            obj->dlbl_shared_d_lbl_pos = pptx_ct_a_dlbl_pos_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dlbl_shared_d_lbl_pos = NULL;
    }
    obj->dlbl_shared_show_legend_key = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showLegendKey");
    obj->dlbl_shared_show_val = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showVal");
    obj->dlbl_shared_show_cat_name = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showCatName");
    obj->dlbl_shared_show_ser_name = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showSerName");
    obj->dlbl_shared_show_percent = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showPercent");
    obj->dlbl_shared_show_bubble_size = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showBubbleSize");
    obj->dlbl_shared_separator = pptx_xml_get_content_as_string(node, (const xmlChar *) "a:separator");
    obj->group_dlbls_show_leader_lines = pptx_xml_get_content_as_bool(node, (const xmlChar *) "a:showLeaderLines");

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:leaderLines");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->group_dlbls_leader_lines = NULL;
        } else {
            obj->group_dlbls_leader_lines = pptx_ct_a_chart_lines_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->group_dlbls_leader_lines = NULL;
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

pptx_ct_a_dlbl **
pptx_ct_a_dlbls_get_d_lbl(const pptx_ct_a_dlbls *const obj)
{
    return obj->d_lbl;
}

pptx_bool 
pptx_ct_a_dlbls_get_delete(const pptx_ct_a_dlbls *const obj)
{
    return obj->delete;
}

pptx_ct_a_num_fmt *
pptx_ct_a_dlbls_get_dlbl_shared_num_fmt(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_num_fmt;
}

pptx_ct_a_shape_properties *
pptx_ct_a_dlbls_get_dlbl_shared_sp_pr(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_sp_pr;
}

pptx_ct_a_text_body *
pptx_ct_a_dlbls_get_dlbl_shared_tx_pr(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_tx_pr;
}

pptx_ct_a_dlbl_pos *
pptx_ct_a_dlbls_get_dlbl_shared_d_lbl_pos(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_d_lbl_pos;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_legend_key(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_legend_key;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_val(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_val;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_cat_name(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_cat_name;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_ser_name(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_ser_name;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_percent(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_percent;
}

pptx_bool 
pptx_ct_a_dlbls_get_dlbl_shared_show_bubble_size(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_show_bubble_size;
}

pptx_string 
pptx_ct_a_dlbls_get_dlbl_shared_separator(const pptx_ct_a_dlbls *const obj)
{
    return obj->dlbl_shared_separator;
}

pptx_bool 
pptx_ct_a_dlbls_get_group_dlbls_show_leader_lines(const pptx_ct_a_dlbls *const obj)
{
    return obj->group_dlbls_show_leader_lines;
}

pptx_ct_a_chart_lines *
pptx_ct_a_dlbls_get_group_dlbls_leader_lines(const pptx_ct_a_dlbls *const obj)
{
    return obj->group_dlbls_leader_lines;
}

pptx_ct_a_extension_list *
pptx_ct_a_dlbls_get_ext_lst(const pptx_ct_a_dlbls *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_dlbls_get_index(pptx_ct_a_dlbls *obj)
{
    return obj->index;
}

void
pptx_ct_a_dlbls_free(pptx_ct_a_dlbls *obj)
{
    if (obj == NULL)
        return;
    if (obj->d_lbl != NULL) {
        for (int i = 0; obj->d_lbl[i] != NULL; ++i) {
            pptx_ct_a_dlbl_free(obj->d_lbl[i]);
        }
        free(obj->d_lbl);
    }

    pptx_ct_a_num_fmt_free(obj->dlbl_shared_num_fmt);
    pptx_ct_a_shape_properties_free(obj->dlbl_shared_sp_pr);
    pptx_ct_a_text_body_free(obj->dlbl_shared_tx_pr);
    pptx_ct_a_dlbl_pos_free(obj->dlbl_shared_d_lbl_pos);
    xmlFree(obj->dlbl_shared_separator);
    pptx_ct_a_chart_lines_free(obj->group_dlbls_leader_lines);
    pptx_ct_a_extension_list_free(obj->ext_lst);
    free(obj);
}