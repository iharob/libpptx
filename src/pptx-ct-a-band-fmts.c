#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-a-band-fmts.h>
/* Imported internal stuff */
#include <private/pptx-ct-a-band-fmt.h>

typedef struct pptx_ct_a_band_fmts_s {
    pptx_ct_a_band_fmt **band_fmt;
    int32_t index;
} pptx_ct_a_band_fmts;

pptx_ct_a_band_fmts *
pptx_ct_a_band_fmts_new(xmlNode *node)
{
    pptx_ct_a_band_fmts *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;

    xpath = pptx_xml_find_node(node, (const xmlChar *) "a:bandFmt");
    if (xpath != NULL) {
        xmlNodeSet *nodes;
        nodes = xpath->nodesetval;
        if ((nodes != NULL) || (nodes->nodeNr == 0)) {
            obj->band_fmt = malloc((nodes->nodeNr + 1) * sizeof *obj->band_fmt);
            if (obj->band_fmt != NULL) {
                int result;
                pptx_allocator_fn allocator;
                void **list;
                // Make a pointer, for the sake of readability ONLY
                list = (void **) obj->band_fmt;
                // Define the allocator function
                allocator = (pptx_allocator_fn) pptx_ct_a_band_fmt_new;;
                // Call the foreach function
                result = pptx_xml_apply_for_each(list, nodes, allocator, 0, -1);
                if (result == -1) {
                    free(obj->band_fmt);
                    obj->band_fmt = NULL;
                } else {
                    obj->band_fmt[nodes->nodeNr] = NULL;
                }
            }
        } else {
            obj->band_fmt = NULL;
        }
        xmlXPathFreeObject(xpath);
    } else {
        obj->band_fmt = NULL;
    }
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_ct_a_band_fmt **
pptx_ct_a_band_fmts_get_band_fmt(const pptx_ct_a_band_fmts *const obj)
{
    return obj->band_fmt;
}

int32_t
pptx_ct_a_band_fmts_get_index(pptx_ct_a_band_fmts *obj)
{
    return obj->index;
}

void
pptx_ct_a_band_fmts_free(pptx_ct_a_band_fmts *obj)
{
    if (obj == NULL)
        return;
    if (obj->band_fmt != NULL) {
        for (int i = 0; obj->band_fmt[i] != NULL; ++i) {
            pptx_ct_a_band_fmt_free(obj->band_fmt[i]);
        }
        free(obj->band_fmt);
    }

    free(obj);
}