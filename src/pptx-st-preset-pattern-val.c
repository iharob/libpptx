#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-preset-pattern-val.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_preset_pattern_val_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_preset_pattern_val_token_enum
pptx_get_st_preset_pattern_val(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[55] = {
      {"cross", ST_PRESET_PATTERN_VAL_CROSS},
      {"dashDnDiag", ST_PRESET_PATTERN_VAL_DASH_DN_DIAG},
      {"dashHorz", ST_PRESET_PATTERN_VAL_DASH_HORZ},
      {"dashUpDiag", ST_PRESET_PATTERN_VAL_DASH_UP_DIAG},
      {"dashVert", ST_PRESET_PATTERN_VAL_DASH_VERT},
      {"diagBrick", ST_PRESET_PATTERN_VAL_DIAG_BRICK},
      {"diagCross", ST_PRESET_PATTERN_VAL_DIAG_CROSS},
      {"divot", ST_PRESET_PATTERN_VAL_DIVOT},
      {"dkDnDiag", ST_PRESET_PATTERN_VAL_DK_DN_DIAG},
      {"dkHorz", ST_PRESET_PATTERN_VAL_DK_HORZ},
      {"dkUpDiag", ST_PRESET_PATTERN_VAL_DK_UP_DIAG},
      {"dkVert", ST_PRESET_PATTERN_VAL_DK_VERT},
      {"dnDiag", ST_PRESET_PATTERN_VAL_DN_DIAG},
      {"dotDmnd", ST_PRESET_PATTERN_VAL_DOT_DMND},
      {"dotGrid", ST_PRESET_PATTERN_VAL_DOT_GRID},
      {"horz", ST_PRESET_PATTERN_VAL_HORZ},
      {"horzBrick", ST_PRESET_PATTERN_VAL_HORZ_BRICK},
      {"lgCheck", ST_PRESET_PATTERN_VAL_LG_CHECK},
      {"lgConfetti", ST_PRESET_PATTERN_VAL_LG_CONFETTI},
      {"lgGrid", ST_PRESET_PATTERN_VAL_LG_GRID},
      {"ltDnDiag", ST_PRESET_PATTERN_VAL_LT_DN_DIAG},
      {"ltHorz", ST_PRESET_PATTERN_VAL_LT_HORZ},
      {"ltUpDiag", ST_PRESET_PATTERN_VAL_LT_UP_DIAG},
      {"ltVert", ST_PRESET_PATTERN_VAL_LT_VERT},
      {"narHorz", ST_PRESET_PATTERN_VAL_NAR_HORZ},
      {"narVert", ST_PRESET_PATTERN_VAL_NAR_VERT},
      {"nil", ST_PRESET_PATTERN_VAL_NIL},
      {"openDmnd", ST_PRESET_PATTERN_VAL_OPEN_DMND},
      {"pct10", ST_PRESET_PATTERN_VAL_PCT10},
      {"pct20", ST_PRESET_PATTERN_VAL_PCT20},
      {"pct25", ST_PRESET_PATTERN_VAL_PCT25},
      {"pct30", ST_PRESET_PATTERN_VAL_PCT30},
      {"pct40", ST_PRESET_PATTERN_VAL_PCT40},
      {"pct5", ST_PRESET_PATTERN_VAL_PCT5},
      {"pct50", ST_PRESET_PATTERN_VAL_PCT50},
      {"pct60", ST_PRESET_PATTERN_VAL_PCT60},
      {"pct70", ST_PRESET_PATTERN_VAL_PCT70},
      {"pct75", ST_PRESET_PATTERN_VAL_PCT75},
      {"pct80", ST_PRESET_PATTERN_VAL_PCT80},
      {"pct90", ST_PRESET_PATTERN_VAL_PCT90},
      {"plaid", ST_PRESET_PATTERN_VAL_PLAID},
      {"shingle", ST_PRESET_PATTERN_VAL_SHINGLE},
      {"smCheck", ST_PRESET_PATTERN_VAL_SM_CHECK},
      {"smConfetti", ST_PRESET_PATTERN_VAL_SM_CONFETTI},
      {"smGrid", ST_PRESET_PATTERN_VAL_SM_GRID},
      {"solidDmnd", ST_PRESET_PATTERN_VAL_SOLID_DMND},
      {"sphere", ST_PRESET_PATTERN_VAL_SPHERE},
      {"trellis", ST_PRESET_PATTERN_VAL_TRELLIS},
      {"upDiag", ST_PRESET_PATTERN_VAL_UP_DIAG},
      {"vert", ST_PRESET_PATTERN_VAL_VERT},
      {"wave", ST_PRESET_PATTERN_VAL_WAVE},
      {"wdDnDiag", ST_PRESET_PATTERN_VAL_WD_DN_DIAG},
      {"wdUpDiag", ST_PRESET_PATTERN_VAL_WD_UP_DIAG},
      {"weave", ST_PRESET_PATTERN_VAL_WEAVE},
      {"zigZag", ST_PRESET_PATTERN_VAL_ZIG_ZAG}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRESET_PATTERN_VAL_NIL;
    // Perform binary search
    found = bsearch(&key, base, 55, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRESET_PATTERN_VAL_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
