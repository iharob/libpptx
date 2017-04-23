#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-header-footer.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_header_footer_s {
    pptx_ct_p_extension_list_modify *ext_lst;
    pptx_bool sld_num;
    pptx_bool hdr;
    pptx_bool ftr;
    pptx_bool dt;
    int32_t index;
} pptx_ct_p_header_footer;

pptx_ct_p_header_footer *
pptx_ct_p_header_footer_new(xmlNode *node)
{
    pptx_ct_p_header_footer *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->sld_num = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "sldNum");
    obj->hdr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "hdr");
    obj->ftr = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "ftr");
    obj->dt = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "dt");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_header_footer_get_ext_lst(const pptx_ct_p_header_footer *const obj)
{
    return obj->ext_lst;
}

pptx_bool 
pptx_ct_p_header_footer_get_sld_num(const pptx_ct_p_header_footer *const obj)
{
    return obj->sld_num;
}

pptx_bool 
pptx_ct_p_header_footer_get_hdr(const pptx_ct_p_header_footer *const obj)
{
    return obj->hdr;
}

pptx_bool 
pptx_ct_p_header_footer_get_ftr(const pptx_ct_p_header_footer *const obj)
{
    return obj->ftr;
}

pptx_bool 
pptx_ct_p_header_footer_get_dt(const pptx_ct_p_header_footer *const obj)
{
    return obj->dt;
}

int32_t
pptx_ct_p_header_footer_get_index(pptx_ct_p_header_footer *obj)
{
    return obj->index;
}

void
pptx_ct_p_header_footer_free(pptx_ct_p_header_footer *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}