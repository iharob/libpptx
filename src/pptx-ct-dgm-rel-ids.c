#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-dgm-rel-ids.h>
/* Imported internal stuff */

typedef struct pptx_ct_dgm_rel_ids_s {
    pptx_string dm;
    pptx_string lo;
    pptx_string qs;
    pptx_string cs;
    int32_t index;
} pptx_ct_dgm_rel_ids;

pptx_ct_dgm_rel_ids *
pptx_ct_dgm_rel_ids_new(xmlNode *node)
{
    pptx_ct_dgm_rel_ids *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->dm = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:dm");
    obj->lo = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:lo");
    obj->qs = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:qs");
    obj->cs = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:cs");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_dgm_rel_ids_get_dm(const pptx_ct_dgm_rel_ids *const obj)
{
    return obj->dm;
}

pptx_string 
pptx_ct_dgm_rel_ids_get_lo(const pptx_ct_dgm_rel_ids *const obj)
{
    return obj->lo;
}

pptx_string 
pptx_ct_dgm_rel_ids_get_qs(const pptx_ct_dgm_rel_ids *const obj)
{
    return obj->qs;
}

pptx_string 
pptx_ct_dgm_rel_ids_get_cs(const pptx_ct_dgm_rel_ids *const obj)
{
    return obj->cs;
}

int32_t
pptx_ct_dgm_rel_ids_get_index(pptx_ct_dgm_rel_ids *obj)
{
    return obj->index;
}

void
pptx_ct_dgm_rel_ids_free(pptx_ct_dgm_rel_ids *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->dm);
    xmlFree(obj->lo);
    xmlFree(obj->qs);
    xmlFree(obj->cs);
    free(obj);
}