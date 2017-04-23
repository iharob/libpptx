#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-calendar-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_calendar_type_text_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_calendar_type_text_enum
pptx_get_st_calendar_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[15] = {
      {"gregorian", ST_CALENDAR_TYPE_GREGORIAN},
      {"gregorianArabic", ST_CALENDAR_TYPE_GREGORIAN_ARABIC},
      {"gregorianMeFrench", ST_CALENDAR_TYPE_GREGORIAN_ME_FRENCH},
      {"gregorianUs", ST_CALENDAR_TYPE_GREGORIAN_US},
      {"gregorianXlitEnglish", ST_CALENDAR_TYPE_GREGORIAN_XLIT_ENGLISH},
      {"gregorianXlitFrench", ST_CALENDAR_TYPE_GREGORIAN_XLIT_FRENCH},
      {"hebrew", ST_CALENDAR_TYPE_HEBREW},
      {"hijri", ST_CALENDAR_TYPE_HIJRI},
      {"japan", ST_CALENDAR_TYPE_JAPAN},
      {"korea", ST_CALENDAR_TYPE_KOREA},
      {"nil", ST_CALENDAR_TYPE_NIL},
      {"none", ST_CALENDAR_TYPE_NONE},
      {"saka", ST_CALENDAR_TYPE_SAKA},
      {"taiwan", ST_CALENDAR_TYPE_TAIWAN},
      {"thai", ST_CALENDAR_TYPE_THAI}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_CALENDAR_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 15, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_CALENDAR_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
