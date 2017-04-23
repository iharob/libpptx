#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-gvml-group-shape.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-gvml-group-shape-non-visual.h>
#include <private/pptx-ct-a-group-shape-properties.h>
#include <private/pptx-ct-a-gvml-text-shape.h>
#include <private/pptx-ct-a-gvml-shape.h>
#include <private/pptx-ct-a-gvml-connector.h>
#include <private/pptx-ct-a-gvml-picture.h>
#include <private/pptx-ct-a-gvml-graphical-object-frame.h>
#include <private/pptx-ct-a-gvml-group-shape.h>
#include <private/pptx-ct-a-office-art-extension-list.h>

typedef struct pptx_ct_a_gvml_group_shape_s {
    pptx_ct_a_gvml_group_shape_non_visual *nv_grp_sp_pr;
    pptx_ct_a_group_shape_properties *grp_sp_pr;
    pptx_ct_a_gvml_text_shape **tx_sp;
    pptx_ct_a_gvml_shape **sp;
    pptx_ct_a_gvml_connector **cxn_sp;
    pptx_ct_a_gvml_picture **pic;
    pptx_ct_a_gvml_graphical_object_frame **graphic_frame;
    pptx_ct_a_gvml_group_shape **grp_sp;
    pptx_ct_a_office_art_extension_list *ext_lst;
    int32_t index;
} pptx_ct_a_gvml_group_shape;

pptx_ct_a_gvml_group_shape *
pptx_ct_a_gvml_group_shape_new(xmlNode *node)
{
    pptx_ct_a_gvml_group_shape *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:nvGrpSpPr");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes->nodeNr != 1) || (nodes->nodeNr < -1)) {       
            obj->nv_grp_sp_pr = NULL;
        } else {
            obj->nv_grp_sp_pr = pptx_ct_a_gvml_group_shape_non_visual_new(nodes->nodeTab[0]);
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->nv_grp_sp_pr = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpSpPr");
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:txSp");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->tx_sp = malloc((nodes->nodeNr + 1) * sizeof *obj->tx_sp);
            if (obj->tx_sp != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->tx_sp;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_text_shape_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->tx_sp);
                    obj->tx_sp = NULL;
                } else {
                    obj->tx_sp[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->tx_sp = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->tx_sp = NULL;
    }

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:sp");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_shape_new;;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:cxnSp");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_connector_new;;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:pic");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_picture_new;;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:graphicFrame");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_graphical_object_frame_new;;
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

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:grpSp");
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
                allocator = (pptx_allocator_fn) pptx_ct_a_gvml_group_shape_new;;
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
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_gvml_group_shape_non_visual *
pptx_ct_a_gvml_group_shape_get_nv_grp_sp_pr(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->nv_grp_sp_pr;
}

pptx_ct_a_group_shape_properties *
pptx_ct_a_gvml_group_shape_get_grp_sp_pr(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->grp_sp_pr;
}

pptx_ct_a_gvml_text_shape **
pptx_ct_a_gvml_group_shape_get_tx_sp(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->tx_sp;
}

pptx_ct_a_gvml_shape **
pptx_ct_a_gvml_group_shape_get_sp(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->sp;
}

pptx_ct_a_gvml_connector **
pptx_ct_a_gvml_group_shape_get_cxn_sp(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->cxn_sp;
}

pptx_ct_a_gvml_picture **
pptx_ct_a_gvml_group_shape_get_pic(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->pic;
}

pptx_ct_a_gvml_graphical_object_frame **
pptx_ct_a_gvml_group_shape_get_graphic_frame(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->graphic_frame;
}

pptx_ct_a_gvml_group_shape **
pptx_ct_a_gvml_group_shape_get_grp_sp(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->grp_sp;
}

pptx_ct_a_office_art_extension_list *
pptx_ct_a_gvml_group_shape_get_ext_lst(const pptx_ct_a_gvml_group_shape *const obj)
{
    return obj->ext_lst;
}

int32_t
pptx_ct_a_gvml_group_shape_get_index(pptx_ct_a_gvml_group_shape *obj)
{
    return obj->index;
}

void
pptx_ct_a_gvml_group_shape_free(pptx_ct_a_gvml_group_shape *obj)
{
    if (obj == NULL)
        return;
    pptx_ct_a_gvml_group_shape_non_visual_free(obj->nv_grp_sp_pr);
    pptx_ct_a_group_shape_properties_free(obj->grp_sp_pr);
    if (obj->tx_sp != NULL) {
        for (int i = 0; obj->tx_sp[i] != NULL; ++i) {
            pptx_ct_a_gvml_text_shape_free(obj->tx_sp[i]);
        }
        free(obj->tx_sp);
    }

    if (obj->sp != NULL) {
        for (int i = 0; obj->sp[i] != NULL; ++i) {
            pptx_ct_a_gvml_shape_free(obj->sp[i]);
        }
        free(obj->sp);
    }

    if (obj->cxn_sp != NULL) {
        for (int i = 0; obj->cxn_sp[i] != NULL; ++i) {
            pptx_ct_a_gvml_connector_free(obj->cxn_sp[i]);
        }
        free(obj->cxn_sp);
    }

    if (obj->pic != NULL) {
        for (int i = 0; obj->pic[i] != NULL; ++i) {
            pptx_ct_a_gvml_picture_free(obj->pic[i]);
        }
        free(obj->pic);
    }

    if (obj->graphic_frame != NULL) {
        for (int i = 0; obj->graphic_frame[i] != NULL; ++i) {
            pptx_ct_a_gvml_graphical_object_frame_free(obj->graphic_frame[i]);
        }
        free(obj->graphic_frame);
    }

    if (obj->grp_sp != NULL) {
        for (int i = 0; obj->grp_sp[i] != NULL; ++i) {
            pptx_ct_a_gvml_group_shape_free(obj->grp_sp[i]);
        }
        free(obj->grp_sp);
    }

    pptx_ct_a_office_art_extension_list_free(obj->ext_lst);
    free(obj);
}