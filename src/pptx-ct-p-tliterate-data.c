#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-tliterate-data.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-tliterate-interval-time.h>
#include <private/pptx-ct-p-tliterate-interval-percentage.h>
#include <private/pptx-st-iterate-type.h>

typedef struct pptx_ct_p_tliterate_data_s {
    pptx_ct_p_tliterate_interval_time *tm_abs;
    pptx_ct_p_tliterate_interval_percentage *tm_pct;
    pptx_st_iterate_type_token_enum type;
    pptx_bool backwards;
    int32_t index;
} pptx_ct_p_tliterate_data;

pptx_ct_p_tliterate_data *
pptx_ct_p_tliterate_data_new(xmlNode *node)
{
    pptx_ct_p_tliterate_data *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tmAbs");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tm_abs = NULL;
        } else {
            obj->tm_abs = pptx_ct_p_tliterate_interval_time_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tm_abs = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:tmPct");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->tm_pct = NULL;
        } else {
            obj->tm_pct = pptx_ct_p_tliterate_interval_percentage_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tm_pct = NULL;
    }
    obj->type = pptx_get_st_iterate_type(node, (const xmlChar *) "type");
    obj->backwards = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "backwards");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_tliterate_interval_time *
pptx_ct_p_tliterate_data_get_tm_abs(const pptx_ct_p_tliterate_data *const obj)
{
    return obj->tm_abs;
}

pptx_ct_p_tliterate_interval_percentage *
pptx_ct_p_tliterate_data_get_tm_pct(const pptx_ct_p_tliterate_data *const obj)
{
    return obj->tm_pct;
}

pptx_st_iterate_type_token_enum 
pptx_ct_p_tliterate_data_get_type(const pptx_ct_p_tliterate_data *const obj)
{
    return obj->type;
}

pptx_bool 
pptx_ct_p_tliterate_data_get_backwards(const pptx_ct_p_tliterate_data *const obj)
{
    return obj->backwards;
}

int32_t
pptx_ct_p_tliterate_data_get_index(pptx_ct_p_tliterate_data *obj)
{
    return obj->index;
}

void
pptx_ct_p_tliterate_data_free(pptx_ct_p_tliterate_data *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_tliterate_interval_time_free(obj->tm_abs);
    pptx_ct_p_tliterate_interval_percentage_free(obj->tm_pct);
    free(obj);
}