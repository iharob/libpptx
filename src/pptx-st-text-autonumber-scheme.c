#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-autonumber-scheme.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_autonumber_scheme_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_autonumber_scheme_token_enum
pptx_get_st_text_autonumber_scheme(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[42] = {
      {"alphaLcParenBoth", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_LC_PAREN_BOTH},
      {"alphaLcParenR", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_LC_PAREN_R},
      {"alphaLcPeriod", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_LC_PERIOD},
      {"alphaUcParenBoth", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_UC_PAREN_BOTH},
      {"alphaUcParenR", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_UC_PAREN_R},
      {"alphaUcPeriod", ST_TEXT_AUTONUMBER_SCHEME_ALPHA_UC_PERIOD},
      {"arabic1Minus", ST_TEXT_AUTONUMBER_SCHEME_ARABIC1_MINUS},
      {"arabic2Minus", ST_TEXT_AUTONUMBER_SCHEME_ARABIC2_MINUS},
      {"arabicDbPeriod", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_DB_PERIOD},
      {"arabicDbPlain", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_DB_PLAIN},
      {"arabicParenBoth", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_PAREN_BOTH},
      {"arabicParenR", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_PAREN_R},
      {"arabicPeriod", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_PERIOD},
      {"arabicPlain", ST_TEXT_AUTONUMBER_SCHEME_ARABIC_PLAIN},
      {"circleNumDbPlain", ST_TEXT_AUTONUMBER_SCHEME_CIRCLE_NUM_DB_PLAIN},
      {"circleNumWdBlackPlain", ST_TEXT_AUTONUMBER_SCHEME_CIRCLE_NUM_WD_BLACK_PLAIN},
      {"circleNumWdWhitePlain", ST_TEXT_AUTONUMBER_SCHEME_CIRCLE_NUM_WD_WHITE_PLAIN},
      {"ea1ChsPeriod", ST_TEXT_AUTONUMBER_SCHEME_EA1_CHS_PERIOD},
      {"ea1ChsPlain", ST_TEXT_AUTONUMBER_SCHEME_EA1_CHS_PLAIN},
      {"ea1ChtPeriod", ST_TEXT_AUTONUMBER_SCHEME_EA1_CHT_PERIOD},
      {"ea1ChtPlain", ST_TEXT_AUTONUMBER_SCHEME_EA1_CHT_PLAIN},
      {"ea1JpnChsDbPeriod", ST_TEXT_AUTONUMBER_SCHEME_EA1_JPN_CHS_DB_PERIOD},
      {"ea1JpnKorPeriod", ST_TEXT_AUTONUMBER_SCHEME_EA1_JPN_KOR_PERIOD},
      {"ea1JpnKorPlain", ST_TEXT_AUTONUMBER_SCHEME_EA1_JPN_KOR_PLAIN},
      {"hebrew2Minus", ST_TEXT_AUTONUMBER_SCHEME_HEBREW2_MINUS},
      {"hindiAlpha1Period", ST_TEXT_AUTONUMBER_SCHEME_HINDI_ALPHA1_PERIOD},
      {"hindiAlphaPeriod", ST_TEXT_AUTONUMBER_SCHEME_HINDI_ALPHA_PERIOD},
      {"hindiNumParenR", ST_TEXT_AUTONUMBER_SCHEME_HINDI_NUM_PAREN_R},
      {"hindiNumPeriod", ST_TEXT_AUTONUMBER_SCHEME_HINDI_NUM_PERIOD},
      {"nil", ST_TEXT_AUTONUMBER_SCHEME_NIL},
      {"romanLcParenBoth", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_LC_PAREN_BOTH},
      {"romanLcParenR", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_LC_PAREN_R},
      {"romanLcPeriod", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_LC_PERIOD},
      {"romanUcParenBoth", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_UC_PAREN_BOTH},
      {"romanUcParenR", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_UC_PAREN_R},
      {"romanUcPeriod", ST_TEXT_AUTONUMBER_SCHEME_ROMAN_UC_PERIOD},
      {"thaiAlphaParenBoth", ST_TEXT_AUTONUMBER_SCHEME_THAI_ALPHA_PAREN_BOTH},
      {"thaiAlphaParenR", ST_TEXT_AUTONUMBER_SCHEME_THAI_ALPHA_PAREN_R},
      {"thaiAlphaPeriod", ST_TEXT_AUTONUMBER_SCHEME_THAI_ALPHA_PERIOD},
      {"thaiNumParenBoth", ST_TEXT_AUTONUMBER_SCHEME_THAI_NUM_PAREN_BOTH},
      {"thaiNumParenR", ST_TEXT_AUTONUMBER_SCHEME_THAI_NUM_PAREN_R},
      {"thaiNumPeriod", ST_TEXT_AUTONUMBER_SCHEME_THAI_NUM_PERIOD}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_AUTONUMBER_SCHEME_NIL;
    // Perform binary search
    found = bsearch(&key, base, 42, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_AUTONUMBER_SCHEME_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
