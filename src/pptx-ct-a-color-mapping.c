#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-mapping.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-color-scheme-index.h>

typedef struct pptx_ct_a_color_mapping_s {
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_color_scheme_index_token_enum bg1;
    pptx_st_color_scheme_index_token_enum tx1;
    pptx_st_color_scheme_index_token_enum bg2;
    pptx_st_color_scheme_index_token_enum tx2;
    pptx_st_color_scheme_index_token_enum accent1;
    pptx_st_color_scheme_index_token_enum accent2;
    pptx_st_color_scheme_index_token_enum accent3;
    pptx_st_color_scheme_index_token_enum accent4;
    pptx_st_color_scheme_index_token_enum accent5;
    pptx_st_color_scheme_index_token_enum accent6;
    pptx_st_color_scheme_index_token_enum hlink;
    pptx_st_color_scheme_index_token_enum fol_hlink;
    int32_t index;
} pptx_ct_a_color_mapping;

pptx_ct_a_color_mapping *
pptx_ct_a_color_mapping_new(xmlNode *node)
{
    pptx_ct_a_color_mapping *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

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
    obj->bg1 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "bg1");
    obj->tx1 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "tx1");
    obj->bg2 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "bg2");
    obj->tx2 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "tx2");
    obj->accent1 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent1");
    obj->accent2 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent2");
    obj->accent3 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent3");
    obj->accent4 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent4");
    obj->accent5 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent5");
    obj->accent6 = pptx_get_st_color_scheme_index(node, (const xmlChar *) "accent6");
    obj->hlink = pptx_get_st_color_scheme_index(node, (const xmlChar *) "hlink");
    obj->fol_hlink = pptx_get_st_color_scheme_index(node, (const xmlChar *) "folHlink");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_color_mapping_get_ext_lst(const pptx_ct_a_color_mapping *const obj)
{
    return obj->ext_lst;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_bg1(const pptx_ct_a_color_mapping *const obj)
{
    return obj->bg1;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_tx1(const pptx_ct_a_color_mapping *const obj)
{
    return obj->tx1;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_bg2(const pptx_ct_a_color_mapping *const obj)
{
    return obj->bg2;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_tx2(const pptx_ct_a_color_mapping *const obj)
{
    return obj->tx2;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent1(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent1;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent2(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent2;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent3(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent3;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent4(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent4;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent5(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent5;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_accent6(const pptx_ct_a_color_mapping *const obj)
{
    return obj->accent6;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_hlink(const pptx_ct_a_color_mapping *const obj)
{
    return obj->hlink;
}

pptx_st_color_scheme_index_token_enum 
pptx_ct_a_color_mapping_get_fol_hlink(const pptx_ct_a_color_mapping *const obj)
{
    return obj->fol_hlink;
}

int32_t
pptx_ct_a_color_mapping_get_index(pptx_ct_a_color_mapping *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_mapping_free(pptx_ct_a_color_mapping *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}