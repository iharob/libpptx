#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-tltrigger-event.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_tltrigger_event_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_tltrigger_event_token_enum
pptx_get_st_tltrigger_event(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[12] = {
      {"begin", ST_TLTRIGGER_EVENT_BEGIN},
      {"end", ST_TLTRIGGER_EVENT_END},
      {"nil", ST_TLTRIGGER_EVENT_NIL},
      {"onBegin", ST_TLTRIGGER_EVENT_ON_BEGIN},
      {"onClick", ST_TLTRIGGER_EVENT_ON_CLICK},
      {"onDblClick", ST_TLTRIGGER_EVENT_ON_DBL_CLICK},
      {"onEnd", ST_TLTRIGGER_EVENT_ON_END},
      {"onMouseOut", ST_TLTRIGGER_EVENT_ON_MOUSE_OUT},
      {"onMouseOver", ST_TLTRIGGER_EVENT_ON_MOUSE_OVER},
      {"onNext", ST_TLTRIGGER_EVENT_ON_NEXT},
      {"onPrev", ST_TLTRIGGER_EVENT_ON_PREV},
      {"onStopAudio", ST_TLTRIGGER_EVENT_ON_STOP_AUDIO}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TLTRIGGER_EVENT_NIL;
    // Perform binary search
    found = bsearch(&key, base, 12, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TLTRIGGER_EVENT_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
