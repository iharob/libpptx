#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-ole-object.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-ole-object-embed.h>
#include <private/pptx-ct-p-ole-object-link.h>
#include <private/pptx-ct-p-picture.h>

typedef struct pptx_ct_p_ole_object_s {
    pptx_ct_p_ole_object_embed *embed;
    pptx_ct_p_ole_object_link *link;
    pptx_ct_p_picture *pic;
    pptx_string spid;
    pptx_string name;
    pptx_bool show_as_icon;
    pptx_string r_id;
    pptx_int img_w;
    pptx_int img_h;
    pptx_string prog_id;
    int32_t index;
} pptx_ct_p_ole_object;

pptx_ct_p_ole_object *
pptx_ct_p_ole_object_new(xmlNode *node)
{
    pptx_ct_p_ole_object *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:embed");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->embed = NULL;
        } else {
            obj->embed = pptx_ct_p_ole_object_embed_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->embed = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:link");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->link = NULL;
        } else {
            obj->link = pptx_ct_p_ole_object_link_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->link = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->pic = NULL;
        } else {
            obj->pic = pptx_ct_p_picture_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pic = NULL;
    }
    obj->spid = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "spid");
    obj->name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "name");
    obj->show_as_icon = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "showAsIcon");
    obj->r_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "r:id");
    obj->img_w = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "imgW");
    obj->img_h = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "imgH");
    obj->prog_id = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "progId");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_ole_object_embed *
pptx_ct_p_ole_object_get_embed(const pptx_ct_p_ole_object *const obj)
{
    return obj->embed;
}

pptx_ct_p_ole_object_link *
pptx_ct_p_ole_object_get_link(const pptx_ct_p_ole_object *const obj)
{
    return obj->link;
}

pptx_ct_p_picture *
pptx_ct_p_ole_object_get_pic(const pptx_ct_p_ole_object *const obj)
{
    return obj->pic;
}

pptx_string 
pptx_ct_p_ole_object_get_spid(const pptx_ct_p_ole_object *const obj)
{
    return obj->spid;
}

pptx_string 
pptx_ct_p_ole_object_get_name(const pptx_ct_p_ole_object *const obj)
{
    return obj->name;
}

pptx_bool 
pptx_ct_p_ole_object_get_show_as_icon(const pptx_ct_p_ole_object *const obj)
{
    return obj->show_as_icon;
}

pptx_string 
pptx_ct_p_ole_object_get_r_id(const pptx_ct_p_ole_object *const obj)
{
    return obj->r_id;
}

pptx_int 
pptx_ct_p_ole_object_get_img_w(const pptx_ct_p_ole_object *const obj)
{
    return obj->img_w;
}

pptx_int 
pptx_ct_p_ole_object_get_img_h(const pptx_ct_p_ole_object *const obj)
{
    return obj->img_h;
}

pptx_string 
pptx_ct_p_ole_object_get_prog_id(const pptx_ct_p_ole_object *const obj)
{
    return obj->prog_id;
}

int32_t
pptx_ct_p_ole_object_get_index(pptx_ct_p_ole_object *obj)
{
    return obj->index;
}

void
pptx_ct_p_ole_object_free(pptx_ct_p_ole_object *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_ole_object_embed_free(obj->embed);
    pptx_ct_p_ole_object_link_free(obj->link);
    pptx_ct_p_picture_free(obj->pic);
    xmlFree(obj->spid);
    xmlFree(obj->name);
    xmlFree(obj->r_id);
    xmlFree(obj->prog_id);
    free(obj);
}