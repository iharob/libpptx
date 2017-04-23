#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-group-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-p-group-shape-non-visual.h>
#include <private/pptx-ct-a-group-shape-properties.h>
#include <private/pptx-ct-p-shape.h>
#include <private/pptx-ct-p-group-shape.h>
#include <private/pptx-ct-p-graphical-object-frame.h>
#include <private/pptx-ct-p-connector.h>
#include <private/pptx-ct-p-picture.h>
#include <private/pptx-ct-p-rel.h>
#include <private/pptx-ct-p-extension-list-modify.h>

typedef struct pptx_ct_p_group_shape_s {
    pptx_ct_p_group_shape_non_visual *nv_grp_sp_pr;
    pptx_ct_a_group_shape_properties *grp_sp_pr;
    pptx_ct_p_shape **sp;
    pptx_ct_p_group_shape **grp_sp;
    pptx_ct_p_graphical_object_frame **graphic_frame;
    pptx_ct_p_connector **cxn_sp;
    pptx_ct_p_picture **pic;
    pptx_ct_p_rel **content_part;
    pptx_ct_p_extension_list_modify *ext_lst;
    int32_t index;
} pptx_ct_p_group_shape;

pptx_ct_p_group_shape *
pptx_ct_p_group_shape_new(xmlNode *node)
{
    pptx_ct_p_group_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:nvGrpSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_grp_sp_pr = NULL;
        } else {
            obj->nv_grp_sp_pr = pptx_ct_p_group_shape_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_grp_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:grpSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->grp_sp_pr = NULL;
        } else {
            obj->grp_sp_pr = pptx_ct_a_group_shape_properties_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grp_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:sp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->sp = malloc((nodes->nodeNr + 1) * sizeof *obj->sp);
            if (obj->sp != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->sp;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_shape_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->sp);
                    obj->sp = NULL;
                } else {
                    obj->sp[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->sp = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:grpSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->grp_sp = malloc((nodes->nodeNr + 1) * sizeof *obj->grp_sp);
            if (obj->grp_sp != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->grp_sp;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_group_shape_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->grp_sp);
                    obj->grp_sp = NULL;
                } else {
                    obj->grp_sp[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->grp_sp = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->grp_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:graphicFrame");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->graphic_frame = malloc((nodes->nodeNr + 1) * sizeof *obj->graphic_frame);
            if (obj->graphic_frame != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->graphic_frame;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_graphical_object_frame_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->graphic_frame);
                    obj->graphic_frame = NULL;
                } else {
                    obj->graphic_frame[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->graphic_frame = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->graphic_frame = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:cxnSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->cxn_sp = malloc((nodes->nodeNr + 1) * sizeof *obj->cxn_sp);
            if (obj->cxn_sp != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->cxn_sp;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_connector_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->cxn_sp);
                    obj->cxn_sp = NULL;
                } else {
                    obj->cxn_sp[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->cxn_sp = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->cxn_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:pic");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->pic = malloc((nodes->nodeNr + 1) * sizeof *obj->pic);
            if (obj->pic != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->pic;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_picture_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->pic);
                    obj->pic = NULL;
                } else {
                    obj->pic[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->pic = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->pic = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:contentPart");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->content_part = malloc((nodes->nodeNr + 1) * sizeof *obj->content_part);
            if (obj->content_part != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->content_part;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_p_rel_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->content_part);
                    obj->content_part = NULL;
                } else {
                    obj->content_part[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->content_part = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->content_part = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "p:extLst");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->ext_lst = NULL;
        } else {
            obj->ext_lst = pptx_ct_p_extension_list_modify_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->ext_lst = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_p_group_shape_non_visual *
pptx_ct_p_group_shape_get_nv_grp_sp_pr(const pptx_ct_p_group_shape *const obj)
{
    return obj->nv_grp_sp_pr;
}

pptx_ct_a_group_shape_properties *
pptx_ct_p_group_shape_get_grp_sp_pr(const pptx_ct_p_group_shape *const obj)
{
    return obj->grp_sp_pr;
}

pptx_ct_p_shape **
pptx_ct_p_group_shape_get_sp(const pptx_ct_p_group_shape *const obj)
{
    return obj->sp;
}

pptx_ct_p_group_shape **
pptx_ct_p_group_shape_get_grp_sp(const pptx_ct_p_group_shape *const obj)
{
    return obj->grp_sp;
}

pptx_ct_p_graphical_object_frame **
pptx_ct_p_group_shape_get_graphic_frame(const pptx_ct_p_group_shape *const obj)
{
    return obj->graphic_frame;
}

pptx_ct_p_connector **
pptx_ct_p_group_shape_get_cxn_sp(const pptx_ct_p_group_shape *const obj)
{
    return obj->cxn_sp;
}

pptx_ct_p_picture **
pptx_ct_p_group_shape_get_pic(const pptx_ct_p_group_shape *const obj)
{
    return obj->pic;
}

pptx_ct_p_rel **
pptx_ct_p_group_shape_get_content_part(const pptx_ct_p_group_shape *const obj)
{
    return obj->content_part;
}

pptx_ct_p_extension_list_modify *
pptx_ct_p_group_shape_get_ext_lst(const pptx_ct_p_group_shape *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_p_group_shape_get_index(pptx_ct_p_group_shape *obj)
{
    return obj->index;
}

void
pptx_ct_p_group_shape_free(pptx_ct_p_group_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_p_group_shape_non_visual_free(obj->nv_grp_sp_pr);
    pptx_ct_a_group_shape_properties_free(obj->grp_sp_pr);
    if (obj->sp != NULL) {
        for (int i = 0; obj->sp[i] != NULL; ++i) {
            pptx_ct_p_shape_free(obj->sp[i]);
        }
        free(obj->sp);
    }

    if (obj->grp_sp != NULL) {
        for (int i = 0; obj->grp_sp[i] != NULL; ++i) {
            pptx_ct_p_group_shape_free(obj->grp_sp[i]);
        }
        free(obj->grp_sp);
    }

    if (obj->graphic_frame != NULL) {
        for (int i = 0; obj->graphic_frame[i] != NULL; ++i) {
            pptx_ct_p_graphical_object_frame_free(obj->graphic_frame[i]);
        }
        free(obj->graphic_frame);
    }

    if (obj->cxn_sp != NULL) {
        for (int i = 0; obj->cxn_sp[i] != NULL; ++i) {
            pptx_ct_p_connector_free(obj->cxn_sp[i]);
        }
        free(obj->cxn_sp);
    }

    if (obj->pic != NULL) {
        for (int i = 0; obj->pic[i] != NULL; ++i) {
            pptx_ct_p_picture_free(obj->pic[i]);
        }
        free(obj->pic);
    }

    if (obj->content_part != NULL) {
        for (int i = 0; obj->content_part[i] != NULL; ++i) {
            pptx_ct_p_rel_free(obj->content_part[i]);
        }
        free(obj->content_part);
    }

    pptx_ct_p_extension_list_modify_free(obj->ext_lst);
    free(obj);
}