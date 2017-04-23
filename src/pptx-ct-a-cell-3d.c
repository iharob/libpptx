#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-cell-3d.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-bevel.h>
#include <private/pptx-ct-a-light-rig.h>
#include <private/pptx-ct-a-office-art-extension-list.h>
#include <private/pptx-st-preset-material-type.h>

typedef struct pptx_ct_a_cell_3d_s {
    pptx_ct_a_bevel *bevel;
    pptx_ct_a_light_rig *light_rig;
    pptx_ct_a_office_art_extension_list *ext_lst;
    pptx_st_preset_material_type_token_enum prst_material;
    int32_t index;
} pptx_ct_a_cell_3d;

pptx_ct_a_cell_3d *
pptx_ct_a_cell_3d_new(xmlNode *node)
{
    pptx_ct_a_cell_3d *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bevel");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->bevel = NULL;
        } else {
            obj->bevel = pptx_ct_a_bevel_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->bevel = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:lightRig");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->light_rig = NULL;
        } else {
            obj->light_rig = pptx_ct_a_light_rig_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->light_rig = NULL;
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
    obj->prst_material = pptx_get_st_preset_material_type(node, (const xmlChar *) "prstMaterial");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_bevel *
pptx_ct_a_cell_3d_get_bevel(const pptx_ct_a_cell_3d *const obj)
{
    return obj->bevel;
}

pptx_ct_a_light_rig *
pptx_ct_a_cell_3d_get_light_rig(const pptx_ct_a_cell_3d *const obj)
{
    return obj->light_rig;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_cell_3d_get_ext_lst(const pptx_ct_a_cell_3d *const obj)
{
    return obj->ext_lst;
}

pptx_st_preset_material_type_token_enum 
pptx_ct_a_cell_3d_get_prst_material(const pptx_ct_a_cell_3d *const obj)
{
    return obj->prst_material;
}

int32_t
pptx_ct_a_cell_3d_get_index(pptx_ct_a_cell_3d *obj)
{
    return obj->index;
}

void
pptx_ct_a_cell_3d_free(pptx_ct_a_cell_3d *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_bevel_free(obj->bevel);
    pptx_ct_a_light_rig_free(obj->light_rig);
    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}