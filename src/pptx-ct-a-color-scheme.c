#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-color-scheme.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-color.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_color_scheme_s {
    pptx_ct_a_color *dk1;
    pptx_ct_a_color *lt1;
    pptx_ct_a_color *dk2;
    pptx_ct_a_color *lt2;
    pptx_ct_a_color *accent1;
    pptx_ct_a_color *accent2;
    pptx_ct_a_color *accent3;
    pptx_ct_a_color *accent4;
    pptx_ct_a_color *accent5;
    pptx_ct_a_color *accent6;
    pptx_ct_a_color *hlink;
    pptx_ct_a_color *fol_hlink;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string name;
    int32_t index;
} pptx_ct_a_color_scheme;

pptx_ct_a_color_scheme *
pptx_ct_a_color_scheme_new(xmlNode *node)
{
    pptx_ct_a_color_scheme *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dk1");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dk1 = NULL;
        } else {
            obj->dk1 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dk1 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lt1");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lt1 = NULL;
        } else {
            obj->lt1 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lt1 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:dk2");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->dk2 = NULL;
        } else {
            obj->dk2 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->dk2 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lt2");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lt2 = NULL;
        } else {
            obj->lt2 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lt2 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent1");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent1 = NULL;
        } else {
            obj->accent1 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent1 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent2");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent2 = NULL;
        } else {
            obj->accent2 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent2 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent3");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent3 = NULL;
        } else {
            obj->accent3 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent3 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent4");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent4 = NULL;
        } else {
            obj->accent4 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent4 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent5");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent5 = NULL;
        } else {
            obj->accent5 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent5 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:accent6");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->accent6 = NULL;
        } else {
            obj->accent6 = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->accent6 = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:hlink");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->hlink = NULL;
        } else {
            obj->hlink = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->hlink = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:folHlink");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->fol_hlink = NULL;
        } else {
            obj->fol_hlink = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->fol_hlink = NULL;
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
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_dk1(const pptx_ct_a_color_scheme *const obj)
{
    return obj->dk1;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_lt1(const pptx_ct_a_color_scheme *const obj)
{
    return obj->lt1;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_dk2(const pptx_ct_a_color_scheme *const obj)
{
    return obj->dk2;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_lt2(const pptx_ct_a_color_scheme *const obj)
{
    return obj->lt2;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent1(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent1;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent2(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent2;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent3(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent3;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent4(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent4;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent5(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent5;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_accent6(const pptx_ct_a_color_scheme *const obj)
{
    return obj->accent6;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_hlink(const pptx_ct_a_color_scheme *const obj)
{
    return obj->hlink;
}

pptx_ct_a_color *
pptx_ct_a_color_scheme_get_fol_hlink(const pptx_ct_a_color_scheme *const obj)
{
    return obj->fol_hlink;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_color_scheme_get_ext_lst(const pptx_ct_a_color_scheme *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_a_color_scheme_get_name(const pptx_ct_a_color_scheme *const obj)
{
    return obj->name;
}

int32_t
pptx_ct_a_color_scheme_get_index(pptx_ct_a_color_scheme *obj)
{
    return obj->index;
}

void
pptx_ct_a_color_scheme_free(pptx_ct_a_color_scheme *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_color_free(obj->dk1);
    pptx_ct_a_color_free(obj->lt1);
    pptx_ct_a_color_free(obj->dk2);
    pptx_ct_a_color_free(obj->lt2);
    pptx_ct_a_color_free(obj->accent1);
    pptx_ct_a_color_free(obj->accent2);
    pptx_ct_a_color_free(obj->accent3);
    pptx_ct_a_color_free(obj->accent4);
    pptx_ct_a_color_free(obj->accent5);
    pptx_ct_a_color_free(obj->accent6);
    pptx_ct_a_color_free(obj->hlink);
    pptx_ct_a_color_free(obj->fol_hlink);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->name);
    free(obj);
}