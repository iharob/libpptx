#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-diagram-definition-header.h>
/* Imported internal stuff */
#include <private/pptx-ct-dgm-name.h>
#include <private/pptx-ct-dgm-description.h>
#include <private/pptx-ct-dgm-categories.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_dgm_diagram_definition_header_s {
    pptx_ct_dgm_name **title;
    pptx_ct_dgm_description **desc;
    pptx_ct_dgm_categories *cat_lst;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_string unique_id;
    pptx_string min_ver;
    pptx_string def_style;
    pptx_int res_id;
    int32_t index;
} pptx_ct_dgm_diagram_definition_header;

pptx_ct_dgm_diagram_definition_header *
pptx_ct_dgm_diagram_definition_header_new(xmlNode *node)
{
    pptx_ct_dgm_diagram_definition_header *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:title");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->title = malloc((nodes->nodeNr + 1) * sizeof *obj->title);
            if (obj->title != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->title;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_name_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->title);
                    obj->title = NULL;
                } else {
                    obj->title[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->title = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->title = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:desc");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->desc = malloc((nodes->nodeNr + 1) * sizeof *obj->desc);
            if (obj->desc != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->desc;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_dgm_description_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->desc);
                    obj->desc = NULL;
                } else {
                    obj->desc[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->desc = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->desc = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:catLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cat_lst = NULL;
        } else {
            obj->cat_lst = pptx_ct_dgm_categories_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cat_lst = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "dgm:extLst");
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
    obj->unique_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "uniqueId");
    obj->min_ver = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "minVer");
    obj->def_style = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "defStyle");
    obj->res_id = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "resId");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_dgm_name **
pptx_ct_dgm_diagram_definition_header_get_title(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->title;
}

pptx_ct_dgm_description **
pptx_ct_dgm_diagram_definition_header_get_desc(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->desc;
}

pptx_ct_dgm_categories *
pptx_ct_dgm_diagram_definition_header_get_cat_lst(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->cat_lst;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_dgm_diagram_definition_header_get_ext_lst(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->ext_lst;
}

pptx_string 
pptx_ct_dgm_diagram_definition_header_get_unique_id(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->unique_id;
}

pptx_string 
pptx_ct_dgm_diagram_definition_header_get_min_ver(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->min_ver;
}

pptx_string 
pptx_ct_dgm_diagram_definition_header_get_def_style(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->def_style;
}

pptx_int 
pptx_ct_dgm_diagram_definition_header_get_res_id(const pptx_ct_dgm_diagram_definition_header *const obj)
{
    return obj->res_id;
}

int32_t
pptx_ct_dgm_diagram_definition_header_get_index(pptx_ct_dgm_diagram_definition_header *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_diagram_definition_header_free(pptx_ct_dgm_diagram_definition_header *obj)
{
    if (obj == NULL)
        return;
    if (obj->title != NULL) {
        for (int i = 0; obj->title[i] != NULL; ++i) {
            pptx_ct_dgm_name_free(obj->title[i]);
        }
        free(obj->title);
    }

    if (obj->desc != NULL) {
        for (int i = 0; obj->desc[i] != NULL; ++i) {
            pptx_ct_dgm_description_free(obj->desc[i]);
        }
        free(obj->desc);
    }

    pptx_ct_dgm_categories_free(obj->cat_lst);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    xmlFree(obj->unique_id);
    xmlFree(obj->min_ver);
    xmlFree(obj->def_style);
    free(obj);
}