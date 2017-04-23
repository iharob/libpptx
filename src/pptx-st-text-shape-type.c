#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-text-shape-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_text_shape_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_text_shape_type_token_enum
pptx_get_st_text_shape_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[42] = {
      {"nil", ST_TEXT_SHAPE_TYPE_NIL},
      {"textArchDown", ST_TEXT_SHAPE_TYPE_TEXT_ARCH_DOWN},
      {"textArchDownPour", ST_TEXT_SHAPE_TYPE_TEXT_ARCH_DOWN_POUR},
      {"textArchUp", ST_TEXT_SHAPE_TYPE_TEXT_ARCH_UP},
      {"textArchUpPour", ST_TEXT_SHAPE_TYPE_TEXT_ARCH_UP_POUR},
      {"textButton", ST_TEXT_SHAPE_TYPE_TEXT_BUTTON},
      {"textButtonPour", ST_TEXT_SHAPE_TYPE_TEXT_BUTTON_POUR},
      {"textCanDown", ST_TEXT_SHAPE_TYPE_TEXT_CAN_DOWN},
      {"textCanUp", ST_TEXT_SHAPE_TYPE_TEXT_CAN_UP},
      {"textCascadeDown", ST_TEXT_SHAPE_TYPE_TEXT_CASCADE_DOWN},
      {"textCascadeUp", ST_TEXT_SHAPE_TYPE_TEXT_CASCADE_UP},
      {"textChevron", ST_TEXT_SHAPE_TYPE_TEXT_CHEVRON},
      {"textChevronInverted", ST_TEXT_SHAPE_TYPE_TEXT_CHEVRON_INVERTED},
      {"textCircle", ST_TEXT_SHAPE_TYPE_TEXT_CIRCLE},
      {"textCirclePour", ST_TEXT_SHAPE_TYPE_TEXT_CIRCLE_POUR},
      {"textCurveDown", ST_TEXT_SHAPE_TYPE_TEXT_CURVE_DOWN},
      {"textCurveUp", ST_TEXT_SHAPE_TYPE_TEXT_CURVE_UP},
      {"textDeflate", ST_TEXT_SHAPE_TYPE_TEXT_DEFLATE},
      {"textDeflateBottom", ST_TEXT_SHAPE_TYPE_TEXT_DEFLATE_BOTTOM},
      {"textDeflateInflate", ST_TEXT_SHAPE_TYPE_TEXT_DEFLATE_INFLATE},
      {"textDeflateInflateDeflate", ST_TEXT_SHAPE_TYPE_TEXT_DEFLATE_INFLATE_DEFLATE},
      {"textDeflateTop", ST_TEXT_SHAPE_TYPE_TEXT_DEFLATE_TOP},
      {"textDoubleWave1", ST_TEXT_SHAPE_TYPE_TEXT_DOUBLE_WAVE1},
      {"textFadeDown", ST_TEXT_SHAPE_TYPE_TEXT_FADE_DOWN},
      {"textFadeLeft", ST_TEXT_SHAPE_TYPE_TEXT_FADE_LEFT},
      {"textFadeRight", ST_TEXT_SHAPE_TYPE_TEXT_FADE_RIGHT},
      {"textFadeUp", ST_TEXT_SHAPE_TYPE_TEXT_FADE_UP},
      {"textInflate", ST_TEXT_SHAPE_TYPE_TEXT_INFLATE},
      {"textInflateBottom", ST_TEXT_SHAPE_TYPE_TEXT_INFLATE_BOTTOM},
      {"textInflateTop", ST_TEXT_SHAPE_TYPE_TEXT_INFLATE_TOP},
      {"textNoShape", ST_TEXT_SHAPE_TYPE_TEXT_NO_SHAPE},
      {"textPlain", ST_TEXT_SHAPE_TYPE_TEXT_PLAIN},
      {"textRingInside", ST_TEXT_SHAPE_TYPE_TEXT_RING_INSIDE},
      {"textRingOutside", ST_TEXT_SHAPE_TYPE_TEXT_RING_OUTSIDE},
      {"textSlantDown", ST_TEXT_SHAPE_TYPE_TEXT_SLANT_DOWN},
      {"textSlantUp", ST_TEXT_SHAPE_TYPE_TEXT_SLANT_UP},
      {"textStop", ST_TEXT_SHAPE_TYPE_TEXT_STOP},
      {"textTriangle", ST_TEXT_SHAPE_TYPE_TEXT_TRIANGLE},
      {"textTriangleInverted", ST_TEXT_SHAPE_TYPE_TEXT_TRIANGLE_INVERTED},
      {"textWave1", ST_TEXT_SHAPE_TYPE_TEXT_WAVE1},
      {"textWave2", ST_TEXT_SHAPE_TYPE_TEXT_WAVE2},
      {"textWave4", ST_TEXT_SHAPE_TYPE_TEXT_WAVE4}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_TEXT_SHAPE_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 42, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_TEXT_SHAPE_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
