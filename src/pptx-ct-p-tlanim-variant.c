#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tlanim-variant.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tlanim-variant-boolean-val.h>
#include <private/pptx-ct-p-tlanim-variant-integer-val.h>
#include <private/pptx-ct-p-tlanim-variant-float-val.h>
#include <private/pptx-ct-p-tlanim-variant-string-val.h>
#include <private/pptx-ct-a-color.h>

typedef struct pptx_ct_p_tlanim_variant_s {
    pptx_ct_p_tlanim_variant_boolean_val *bool_val;
    pptx_ct_p_tlanim_variant_integer_val *int_val;
    pptx_ct_p_tlanim_variant_float_val *flt_val;
    pptx_ct_p_tlanim_variant_string_val *str_val;
    pptx_ct_a_color *clr_val;
    int32_t index;
} pptx_ct_p_tlanim_variant;

pptx_ct_p_tlanim_variant *
pptx_ct_p_tlanim_variant_new(xmlNode *node)
{
    pptx_ct_p_tlanim_variant *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:boolVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bool_val = NULL;
        } else {
            obj->bool_val = pptx_ct_p_tlanim_variant_boolean_val_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bool_val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:intVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->int_val = NULL;
        } else {
            obj->int_val = pptx_ct_p_tlanim_variant_integer_val_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->int_val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:fltVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->flt_val = NULL;
        } else {
            obj->flt_val = pptx_ct_p_tlanim_variant_float_val_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->flt_val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:strVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->str_val = NULL;
        } else {
            obj->str_val = pptx_ct_p_tlanim_variant_string_val_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->str_val = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:clrVal");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->clr_val = NULL;
        } else {
            obj->clr_val = pptx_ct_a_color_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->clr_val = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tlanim_variant_boolean_val *
pptx_ct_p_tlanim_variant_get_bool_val(const pptx_ct_p_tlanim_variant *const obj)
{
    return obj->bool_val;
}

pptx_ct_p_tlanim_variant_integer_val *
pptx_ct_p_tlanim_variant_get_int_val(const pptx_ct_p_tlanim_variant *const obj)
{
    return obj->int_val;
}

pptx_ct_p_tlanim_variant_float_val *
pptx_ct_p_tlanim_variant_get_flt_val(const pptx_ct_p_tlanim_variant *const obj)
{
    return obj->flt_val;
}

pptx_ct_p_tlanim_variant_string_val *
pptx_ct_p_tlanim_variant_get_str_val(const pptx_ct_p_tlanim_variant *const obj)
{
    return obj->str_val;
}

pptx_ct_a_color *
pptx_ct_p_tlanim_variant_get_clr_val(const pptx_ct_p_tlanim_variant *const obj)
{
    return obj->clr_val;
}

int32_t
pptx_ct_p_tlanim_variant_get_index(pptx_ct_p_tlanim_variant *obj)
{
    return obj->index;
}

void
pptx_ct_p_tlanim_variant_free(pptx_ct_p_tlanim_variant *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tlanim_variant_boolean_val_free(obj->bool_val);
    pptx_ct_p_tlanim_variant_integer_val_free(obj->int_val);
    pptx_ct_p_tlanim_variant_float_val_free(obj->flt_val);
    pptx_ct_p_tlanim_variant_string_val_free(obj->str_val);
    pptx_ct_a_color_free(obj->clr_val);
    free(obj);
}