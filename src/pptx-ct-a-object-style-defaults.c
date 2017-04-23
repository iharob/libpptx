#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-object-style-defaults.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-default-shape-definition.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_object_style_defaults_s {
    pptx_ct_a_default_shape_definition *sp_def;
    pptx_ct_a_default_shape_definition *ln_def;
    pptx_ct_a_default_shape_definition *tx_def;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_object_style_defaults;

pptx_ct_a_object_style_defaults *
pptx_ct_a_object_style_defaults_new(xmlNode *node)
{
    pptx_ct_a_object_style_defaults *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:spDef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->sp_def = NULL;
        } else {
            obj->sp_def = pptx_ct_a_default_shape_definition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp_def = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lnDef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ln_def = NULL;
        } else {
            obj->ln_def = pptx_ct_a_default_shape_definition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ln_def = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txDef");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tx_def = NULL;
        } else {
            obj->tx_def = pptx_ct_a_default_shape_definition_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_def = NULL;
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

pptx_ct_a_default_shape_definition *
pptx_ct_a_object_style_defaults_get_sp_def(const pptx_ct_a_object_style_defaults *const obj)
{
    return obj->sp_def;
}

pptx_ct_a_default_shape_definition *
pptx_ct_a_object_style_defaults_get_ln_def(const pptx_ct_a_object_style_defaults *const obj)
{
    return obj->ln_def;
}

pptx_ct_a_default_shape_definition *
pptx_ct_a_object_style_defaults_get_tx_def(const pptx_ct_a_object_style_defaults *const obj)
{
    return obj->tx_def;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_object_style_defaults_get_ext_lst(const pptx_ct_a_object_style_defaults *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_object_style_defaults_get_index(pptx_ct_a_object_style_defaults *obj)
{
    return obj->index;
}

void
pptx_ct_a_object_style_defaults_free(pptx_ct_a_object_style_defaults *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_default_shape_definition_free(obj->sp_def);
    pptx_ct_a_default_shape_definition_free(obj->ln_def);
    pptx_ct_a_default_shape_definition_free(obj->tx_def);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}