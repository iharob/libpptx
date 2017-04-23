#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-text-paragraph.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-text-paragraph-properties.h>
#include <private/pptx-ct-a-regular-text-run.h>
#include <private/pptx-ct-a-text-line-break.h>
#include <private/pptx-ct-a-text-field.h>
#include <private/pptx-ct-a-text-character-properties.h>

typedef struct pptx_ct_a_text_paragraph_s {
    pptx_ct_a_text_paragraph_properties *p_pr;
    pptx_ct_a_regular_text_run **text_run_r;
    pptx_ct_a_text_line_break **text_run_br;
    pptx_ct_a_text_field **text_run_fld;
    pptx_ct_a_text_character_properties *end_para_rpr;
    int32_t index;
} pptx_ct_a_text_paragraph;

pptx_ct_a_text_paragraph *
pptx_ct_a_text_paragraph_new(xmlNode *node)
{
    pptx_ct_a_text_paragraph *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->p_pr = NULL;
        } else {
            obj->p_pr = pptx_ct_a_text_paragraph_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->p_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:r");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->text_run_r = malloc((nodes->nodeNr + 1) * sizeof *obj->text_run_r);
            if (obj->text_run_r != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->text_run_r;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_regular_text_run_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->text_run_r);
                    obj->text_run_r = NULL;
                } else {
                    obj->text_run_r[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->text_run_r = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_run_r = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:br");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->text_run_br = malloc((nodes->nodeNr + 1) * sizeof *obj->text_run_br);
            if (obj->text_run_br != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->text_run_br;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_text_line_break_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->text_run_br);
                    obj->text_run_br = NULL;
                } else {
                    obj->text_run_br[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->text_run_br = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_run_br = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:fld");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->text_run_fld = malloc((nodes->nodeNr + 1) * sizeof *obj->text_run_fld);
            if (obj->text_run_fld != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->text_run_fld;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_text_field_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->text_run_fld);
                    obj->text_run_fld = NULL;
                } else {
                    obj->text_run_fld[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->text_run_fld = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->text_run_fld = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:endParaRPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->end_para_rpr = NULL;
        } else {
            obj->end_para_rpr = pptx_ct_a_text_character_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->end_para_rpr = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_text_paragraph_properties *
pptx_ct_a_text_paragraph_get_p_pr(const pptx_ct_a_text_paragraph *const obj)
{
    return obj->p_pr;
}

pptx_ct_a_regular_text_run **
pptx_ct_a_text_paragraph_get_text_run_r(const pptx_ct_a_text_paragraph *const obj)
{
    return obj->text_run_r;
}

pptx_ct_a_text_line_break **
pptx_ct_a_text_paragraph_get_text_run_br(const pptx_ct_a_text_paragraph *const obj)
{
    return obj->text_run_br;
}

pptx_ct_a_text_field **
pptx_ct_a_text_paragraph_get_text_run_fld(const pptx_ct_a_text_paragraph *const obj)
{
    return obj->text_run_fld;
}

pptx_ct_a_text_character_properties *
pptx_ct_a_text_paragraph_get_end_para_rpr(const pptx_ct_a_text_paragraph *const obj)
{
    return obj->end_para_rpr;
}

int32_t
pptx_ct_a_text_paragraph_get_index(pptx_ct_a_text_paragraph *obj)
{
    return obj->index;
}

void
pptx_ct_a_text_paragraph_free(pptx_ct_a_text_paragraph *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_text_paragraph_properties_free(obj->p_pr);
    if (obj->text_run_r != NULL) {
        for (int i = 0; obj->text_run_r[i] != NULL; ++i) {
            pptx_ct_a_regular_text_run_free(obj->text_run_r[i]);
        }
        free(obj->text_run_r);
    }

    if (obj->text_run_br != NULL) {
        for (int i = 0; obj->text_run_br[i] != NULL; ++i) {
            pptx_ct_a_text_line_break_free(obj->text_run_br[i]);
        }
        free(obj->text_run_br);
    }

    if (obj->text_run_fld != NULL) {
        for (int i = 0; obj->text_run_fld[i] != NULL; ++i) {
            pptx_ct_a_text_field_free(obj->text_run_fld[i]);
        }
        free(obj->text_run_fld);
    }

    pptx_ct_a_text_character_properties_free(obj->end_para_rpr);
    free(obj);
}