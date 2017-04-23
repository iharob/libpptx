#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-slide-layout-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_slide_layout_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_slide_layout_type_token_enum
pptx_get_st_slide_layout_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[37] = {
      {"blank", ST_SLIDE_LAYOUT_TYPE_BLANK},
      {"chart", ST_SLIDE_LAYOUT_TYPE_CHART},
      {"chartAndTx", ST_SLIDE_LAYOUT_TYPE_CHART_AND_TX},
      {"clipArtAndTx", ST_SLIDE_LAYOUT_TYPE_CLIP_ART_AND_TX},
      {"clipArtAndVertTx", ST_SLIDE_LAYOUT_TYPE_CLIP_ART_AND_VERT_TX},
      {"cust", ST_SLIDE_LAYOUT_TYPE_CUST},
      {"dgm", ST_SLIDE_LAYOUT_TYPE_DGM},
      {"fourObj", ST_SLIDE_LAYOUT_TYPE_FOUR_OBJ},
      {"mediaAndTx", ST_SLIDE_LAYOUT_TYPE_MEDIA_AND_TX},
      {"nil", ST_SLIDE_LAYOUT_TYPE_NIL},
      {"obj", ST_SLIDE_LAYOUT_TYPE_OBJ},
      {"objAndTwoObj", ST_SLIDE_LAYOUT_TYPE_OBJ_AND_TWO_OBJ},
      {"objAndTx", ST_SLIDE_LAYOUT_TYPE_OBJ_AND_TX},
      {"objOnly", ST_SLIDE_LAYOUT_TYPE_OBJ_ONLY},
      {"objOverTx", ST_SLIDE_LAYOUT_TYPE_OBJ_OVER_TX},
      {"objTx", ST_SLIDE_LAYOUT_TYPE_OBJ_TX},
      {"picTx", ST_SLIDE_LAYOUT_TYPE_PIC_TX},
      {"secHead", ST_SLIDE_LAYOUT_TYPE_SEC_HEAD},
      {"tbl", ST_SLIDE_LAYOUT_TYPE_TBL},
      {"title", ST_SLIDE_LAYOUT_TYPE_TITLE},
      {"titleOnly", ST_SLIDE_LAYOUT_TYPE_TITLE_ONLY},
      {"twoColTx", ST_SLIDE_LAYOUT_TYPE_TWO_COL_TX},
      {"twoObj", ST_SLIDE_LAYOUT_TYPE_TWO_OBJ},
      {"twoObjAndObj", ST_SLIDE_LAYOUT_TYPE_TWO_OBJ_AND_OBJ},
      {"twoObjAndTx", ST_SLIDE_LAYOUT_TYPE_TWO_OBJ_AND_TX},
      {"twoObjOverTx", ST_SLIDE_LAYOUT_TYPE_TWO_OBJ_OVER_TX},
      {"twoTxTwoObj", ST_SLIDE_LAYOUT_TYPE_TWO_TX_TWO_OBJ},
      {"tx", ST_SLIDE_LAYOUT_TYPE_TX},
      {"txAndChart", ST_SLIDE_LAYOUT_TYPE_TX_AND_CHART},
      {"txAndClipArt", ST_SLIDE_LAYOUT_TYPE_TX_AND_CLIP_ART},
      {"txAndMedia", ST_SLIDE_LAYOUT_TYPE_TX_AND_MEDIA},
      {"txAndObj", ST_SLIDE_LAYOUT_TYPE_TX_AND_OBJ},
      {"txAndTwoObj", ST_SLIDE_LAYOUT_TYPE_TX_AND_TWO_OBJ},
      {"txOverObj", ST_SLIDE_LAYOUT_TYPE_TX_OVER_OBJ},
      {"vertTitleAndTx", ST_SLIDE_LAYOUT_TYPE_VERT_TITLE_AND_TX},
      {"vertTitleAndTxOverChart", ST_SLIDE_LAYOUT_TYPE_VERT_TITLE_AND_TX_OVER_CHART},
      {"vertTx", ST_SLIDE_LAYOUT_TYPE_VERT_TX}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_SLIDE_LAYOUT_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 37, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_SLIDE_LAYOUT_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
