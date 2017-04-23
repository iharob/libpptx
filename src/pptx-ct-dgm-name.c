#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-name.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_name_s {
    pptx_string lang;
    pptx_string val;
    int32_t index;
} pptx_ct_dgm_name;

pptx_ct_dgm_name *
pptx_ct_dgm_name_new(xmlNode *node)
{
    pptx_ct_dgm_name *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->lang = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "lang");
    obj->val = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "val");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_dgm_name_get_lang(const pptx_ct_dgm_name *const obj)
{
    return obj->lang;
}

pptx_string 
pptx_ct_dgm_name_get_val(const pptx_ct_dgm_name *const obj)
{
    return obj->val;
}

int32_t
pptx_ct_dgm_name_get_index(pptx_ct_dgm_name *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_name_free(pptx_ct_dgm_name *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->lang);
    xmlFree(obj->val);
    free(obj);
}