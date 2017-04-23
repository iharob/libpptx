#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-font-collection.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-font.h>
#include <private/pptx-ct-a-supplemental-font.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_font_collection_s {
    pptx_ct_a_text_font *latin;
    pptx_ct_a_text_font *ea;
    pptx_ct_a_text_font *cs;
    pptx_ct_a_supplemental_font **font;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_font_collection;

pptx_ct_a_font_collection *
pptx_ct_a_font_collection_new(xmlNode *node)
{
    pptx_ct_a_font_collection *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:latin");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->latin = NULL;
        } else {
            obj->latin = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->latin = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:ea");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ea = NULL;
        } else {
            obj->ea = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ea = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cs");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->cs = NULL;
        } else {
            obj->cs = pptx_ct_a_text_font_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cs = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:font");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->font = malloc((nodes->nodeNr + 1) * sizeof *obj->font);
            if (obj->font != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->font;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_supplemental_font_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->font);
                    obj->font = NULL;
                } else {
                    obj->font[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->font = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->font = NULL;
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

pptx_ct_a_text_font *
pptx_ct_a_font_collection_get_latin(const pptx_ct_a_font_collection *const obj)
{
    return obj->latin;
}

pptx_ct_a_text_font *
pptx_ct_a_font_collection_get_ea(const pptx_ct_a_font_collection *const obj)
{
    return obj->ea;
}

pptx_ct_a_text_font *
pptx_ct_a_font_collection_get_cs(const pptx_ct_a_font_collection *const obj)
{
    return obj->cs;
}

pptx_ct_a_supplemental_font **
pptx_ct_a_font_collection_get_font(const pptx_ct_a_font_collection *const obj)
{
    return obj->font;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_font_collection_get_ext_lst(const pptx_ct_a_font_collection *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_font_collection_get_index(pptx_ct_a_font_collection *obj)
{
    return obj->index;
}

void
pptx_ct_a_font_collection_free(pptx_ct_a_font_collection *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_font_free(obj->latin);
    pptx_ct_a_text_font_free(obj->ea);
    pptx_ct_a_text_font_free(obj->cs);
    if (obj->font != NULL) {
        for (int i = 0; obj->font[i] != NULL; ++i) {
            pptx_ct_a_supplemental_font_free(obj->font[i]);
        }
        free(obj->font);
    }

    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}