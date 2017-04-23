#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-constraint-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_constraint_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_constraint_type_token_enum
pptx_get_st_constraint_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[65] = {
      {"alignOff", ST_CONSTRAINT_TYPE_ALIGN_OFF},
      {"b", ST_CONSTRAINT_TYPE_B},
      {"bMarg", ST_CONSTRAINT_TYPE_B_MARG},
      {"bOff", ST_CONSTRAINT_TYPE_B_OFF},
      {"begMarg", ST_CONSTRAINT_TYPE_BEG_MARG},
      {"begPad", ST_CONSTRAINT_TYPE_BEG_PAD},
      {"bendDist", ST_CONSTRAINT_TYPE_BEND_DIST},
      {"connDist", ST_CONSTRAINT_TYPE_CONN_DIST},
      {"ctrX", ST_CONSTRAINT_TYPE_CTR_X},
      {"ctrXOff", ST_CONSTRAINT_TYPE_CTR_XOFF},
      {"ctrY", ST_CONSTRAINT_TYPE_CTR_Y},
      {"ctrYOff", ST_CONSTRAINT_TYPE_CTR_YOFF},
      {"diam", ST_CONSTRAINT_TYPE_DIAM},
      {"endMarg", ST_CONSTRAINT_TYPE_END_MARG},
      {"endPad", ST_CONSTRAINT_TYPE_END_PAD},
      {"h", ST_CONSTRAINT_TYPE_H},
      {"hArH", ST_CONSTRAINT_TYPE_H_AR_H},
      {"hOff", ST_CONSTRAINT_TYPE_H_OFF},
      {"l", ST_CONSTRAINT_TYPE_L},
      {"lMarg", ST_CONSTRAINT_TYPE_L_MARG},
      {"lOff", ST_CONSTRAINT_TYPE_L_OFF},
      {"nil", ST_CONSTRAINT_TYPE_NIL},
      {"none", ST_CONSTRAINT_TYPE_NONE},
      {"primFontSz", ST_CONSTRAINT_TYPE_PRIM_FONT_SZ},
      {"pyraAcctRatio", ST_CONSTRAINT_TYPE_PYRA_ACCT_RATIO},
      {"r", ST_CONSTRAINT_TYPE_R},
      {"rMarg", ST_CONSTRAINT_TYPE_R_MARG},
      {"rOff", ST_CONSTRAINT_TYPE_R_OFF},
      {"secFontSz", ST_CONSTRAINT_TYPE_SEC_FONT_SZ},
      {"secSibSp", ST_CONSTRAINT_TYPE_SEC_SIB_SP},
      {"sibSp", ST_CONSTRAINT_TYPE_SIB_SP},
      {"sp", ST_CONSTRAINT_TYPE_SP},
      {"stemThick", ST_CONSTRAINT_TYPE_STEM_THICK},
      {"t", ST_CONSTRAINT_TYPE_T},
      {"tMarg", ST_CONSTRAINT_TYPE_T_MARG},
      {"tOff", ST_CONSTRAINT_TYPE_T_OFF},
      {"userA", ST_CONSTRAINT_TYPE_USER_A},
      {"userB", ST_CONSTRAINT_TYPE_USER_B},
      {"userC", ST_CONSTRAINT_TYPE_USER_C},
      {"userD", ST_CONSTRAINT_TYPE_USER_D},
      {"userE", ST_CONSTRAINT_TYPE_USER_E},
      {"userF", ST_CONSTRAINT_TYPE_USER_F},
      {"userG", ST_CONSTRAINT_TYPE_USER_G},
      {"userH", ST_CONSTRAINT_TYPE_USER_H},
      {"userI", ST_CONSTRAINT_TYPE_USER_I},
      {"userJ", ST_CONSTRAINT_TYPE_USER_J},
      {"userK", ST_CONSTRAINT_TYPE_USER_K},
      {"userL", ST_CONSTRAINT_TYPE_USER_L},
      {"userM", ST_CONSTRAINT_TYPE_USER_M},
      {"userN", ST_CONSTRAINT_TYPE_USER_N},
      {"userO", ST_CONSTRAINT_TYPE_USER_O},
      {"userP", ST_CONSTRAINT_TYPE_USER_P},
      {"userQ", ST_CONSTRAINT_TYPE_USER_Q},
      {"userR", ST_CONSTRAINT_TYPE_USER_R},
      {"userS", ST_CONSTRAINT_TYPE_USER_S},
      {"userT", ST_CONSTRAINT_TYPE_USER_T},
      {"userU", ST_CONSTRAINT_TYPE_USER_U},
      {"userV", ST_CONSTRAINT_TYPE_USER_V},
      {"userW", ST_CONSTRAINT_TYPE_USER_W},
      {"userX", ST_CONSTRAINT_TYPE_USER_X},
      {"userY", ST_CONSTRAINT_TYPE_USER_Y},
      {"userZ", ST_CONSTRAINT_TYPE_USER_Z},
      {"w", ST_CONSTRAINT_TYPE_W},
      {"wArH", ST_CONSTRAINT_TYPE_W_AR_H},
      {"wOff", ST_CONSTRAINT_TYPE_W_OFF}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CONSTRAINT_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 65, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CONSTRAINT_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
