#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-reflection-effect.h>
/* Imported internal stuff */
#include <private/pptx-st-rect-alignment.h>

typedef struct pptx_ct_a_reflection_effect_s {
    pptx_long blur_rad;
    pptx_string st_a;
    pptx_string st_pos;
    pptx_string end_a;
    pptx_string end_pos;
    pptx_long dist;
    pptx_int dir;
    pptx_int fade_dir;
    pptx_string sx;
    pptx_string sy;
    pptx_int kx;
    pptx_int ky;
    pptx_st_rect_alignment_token_enum algn;
    pptx_bool rot_with_shape;
    int32_t index;
} pptx_ct_a_reflection_effect;

pptx_ct_a_reflection_effect *
pptx_ct_a_reflection_effect_new(xmlNode *node)
{
    pptx_ct_a_reflection_effect *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->blur_rad = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "blurRad");
    obj->st_a = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "stA");
    obj->st_pos = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "stPos");
    obj->end_a = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "endA");
    obj->end_pos = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "endPos");
    obj->dist = pptx_xml_get_attribute_as_long(node, (const xmlChar *) "dist");
    obj->dir = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "dir");
    obj->fade_dir = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "fadeDir");
    obj->sx = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sx");
    obj->sy = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "sy");
    obj->kx = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "kx");
    obj->ky = pptx_xml_get_attribute_as_int(node, (const xmlChar *) "ky");
    obj->algn = pptx_get_st_rect_alignment(node, (const xmlChar *) "algn");
    obj->rot_with_shape = pptx_xml_get_attribute_as_bool(node, (const xmlChar *) "rotWithShape");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_long 
pptx_ct_a_reflection_effect_get_blur_rad(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->blur_rad;
}

pptx_string 
pptx_ct_a_reflection_effect_get_st_a(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->st_a;
}

pptx_string 
pptx_ct_a_reflection_effect_get_st_pos(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->st_pos;
}

pptx_string 
pptx_ct_a_reflection_effect_get_end_a(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->end_a;
}

pptx_string 
pptx_ct_a_reflection_effect_get_end_pos(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->end_pos;
}

pptx_long 
pptx_ct_a_reflection_effect_get_dist(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->dist;
}

pptx_int 
pptx_ct_a_reflection_effect_get_dir(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->dir;
}

pptx_int 
pptx_ct_a_reflection_effect_get_fade_dir(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->fade_dir;
}

pptx_string 
pptx_ct_a_reflection_effect_get_sx(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->sx;
}

pptx_string 
pptx_ct_a_reflection_effect_get_sy(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->sy;
}

pptx_int 
pptx_ct_a_reflection_effect_get_kx(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->kx;
}

pptx_int 
pptx_ct_a_reflection_effect_get_ky(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->ky;
}

pptx_st_rect_alignment_token_enum 
pptx_ct_a_reflection_effect_get_algn(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->algn;
}

pptx_bool 
pptx_ct_a_reflection_effect_get_rot_with_shape(const pptx_ct_a_reflection_effect *const obj)
{
    return obj->rot_with_shape;
}

int32_t
pptx_ct_a_reflection_effect_get_index(pptx_ct_a_reflection_effect *obj)
{
    return obj->index;
}

void
pptx_ct_a_reflection_effect_free(pptx_ct_a_reflection_effect *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->st_a);
    xmlFree(obj->st_pos);
    xmlFree(obj->end_a);
    xmlFree(obj->end_pos);
    xmlFree(obj->sx);
    xmlFree(obj->sy);
    free(obj);
}