#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-body.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-body-properties.h>
#include <private/pptx-ct-a-text-list-style.h>
#include <private/pptx-ct-a-text-paragraph.h>

typedef struct pptx_ct_a_text_body_s {
    pptx_ct_a_text_body_properties *body_pr;
    pptx_ct_a_text_list_style *lst_style;
    pptx_ct_a_text_paragraph **p;
    int32_t index;
} pptx_ct_a_text_body;

pptx_ct_a_text_body *
pptx_ct_a_text_body_new(xmlNode *node)
{
    pptx_ct_a_text_body *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bodyPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->body_pr = NULL;
        } else {
            obj->body_pr = pptx_ct_a_text_body_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->body_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lstStyle");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->lst_style = NULL;
        } else {
            obj->lst_style = pptx_ct_a_text_list_style_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->lst_style = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:p");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->p = malloc((nodes->nodeNr + 1) * sizeof *obj->p);
            if (obj->p != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->p;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_text_paragraph_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 1, -1);
                if (result == -1) {
                    free(obj->p);
                    obj->p = NULL;
                } else {
                    obj->p[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->p = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->p = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_body_properties *
pptx_ct_a_text_body_get_body_pr(const pptx_ct_a_text_body *const obj)
{
    return obj->body_pr;
}

pptx_ct_a_text_list_style *
pptx_ct_a_text_body_get_lst_style(const pptx_ct_a_text_body *const obj)
{
    return obj->lst_style;
}

pptx_ct_a_text_paragraph **
pptx_ct_a_text_body_get_p(const pptx_ct_a_text_body *const obj)
{
    return obj->p;
}

int32_t
pptx_ct_a_text_body_get_index(pptx_ct_a_text_body *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_body_free(pptx_ct_a_text_body *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_body_properties_free(obj->body_pr);
    pptx_ct_a_text_list_style_free(obj->lst_style);
    if (obj->p != NULL) {
        for (int i = 0; obj->p[i] != NULL; ++i) {
            pptx_ct_a_text_paragraph_free(obj->p[i]);
        }
        free(obj->p);
    }

    free(obj);
}