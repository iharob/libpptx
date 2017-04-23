#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-ole-object-embed.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-extension-list.h>
#include <private/pptx-st-ole-object-follow-color-scheme.h>

typedef struct pptx_ct_p_ole_object_embed_s {
    pptx_ct_p_extension_list *ext_lst;
    pptx_st_ole_object_follow_color_scheme_token_enum follow_color_scheme;
    int32_t index;
} pptx_ct_p_ole_object_embed;

pptx_ct_p_ole_object_embed *
pptx_ct_p_ole_object_embed_new(xmlNode *node)
{
    pptx_ct_p_ole_object_embed *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->follow_color_scheme = pptx_get_st_ole_object_follow_color_scheme(node, (const xmlChar *) "followColorScheme");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_extension_list *
pptx_ct_p_ole_object_embed_get_ext_lst(const pptx_ct_p_ole_object_embed *const obj)
{
    return obj->ext_lst;
}

pptx_st_ole_object_follow_color_scheme_token_enum 
pptx_ct_p_ole_object_embed_get_follow_color_scheme(const pptx_ct_p_ole_object_embed *const obj)
{
    return obj->follow_color_scheme;
}

int32_t
pptx_ct_p_ole_object_embed_get_index(pptx_ct_p_ole_object_embed *obj)
{
    return obj->index;
}

void
pptx_ct_p_ole_object_embed_free(pptx_ct_p_ole_object_embed *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_extension_list_free(obj->ext_lst);
    free(obj);
}