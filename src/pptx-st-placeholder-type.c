#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-placeholder-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_placeholder_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_placeholder_type_token_enum
pptx_get_st_placeholder_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[17] = {
      {"body", ST_PLACEHOLDER_TYPE_BODY},
      {"chart", ST_PLACEHOLDER_TYPE_CHART},
      {"clipArt", ST_PLACEHOLDER_TYPE_CLIP_ART},
      {"ctrTitle", ST_PLACEHOLDER_TYPE_CTR_TITLE},
      {"dgm", ST_PLACEHOLDER_TYPE_DGM},
      {"dt", ST_PLACEHOLDER_TYPE_DT},
      {"ftr", ST_PLACEHOLDER_TYPE_FTR},
      {"hdr", ST_PLACEHOLDER_TYPE_HDR},
      {"media", ST_PLACEHOLDER_TYPE_MEDIA},
      {"nil", ST_PLACEHOLDER_TYPE_NIL},
      {"obj", ST_PLACEHOLDER_TYPE_OBJ},
      {"pic", ST_PLACEHOLDER_TYPE_PIC},
      {"sldImg", ST_PLACEHOLDER_TYPE_SLD_IMG},
      {"sldNum", ST_PLACEHOLDER_TYPE_SLD_NUM},
      {"subTitle", ST_PLACEHOLDER_TYPE_SUB_TITLE},
      {"tbl", ST_PLACEHOLDER_TYPE_TBL},
      {"title", ST_PLACEHOLDER_TYPE_TITLE}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PLACEHOLDER_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 17, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PLACEHOLDER_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
