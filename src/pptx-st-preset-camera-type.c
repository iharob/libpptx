#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-preset-camera-type.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_preset_camera_type_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_preset_camera_type_token_enum
pptx_get_st_preset_camera_type(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[63] = {
      {"isometricBottomDown", ST_PRESET_CAMERA_TYPE_ISOMETRIC_BOTTOM_DOWN},
      {"isometricBottomUp", ST_PRESET_CAMERA_TYPE_ISOMETRIC_BOTTOM_UP},
      {"isometricLeftDown", ST_PRESET_CAMERA_TYPE_ISOMETRIC_LEFT_DOWN},
      {"isometricLeftUp", ST_PRESET_CAMERA_TYPE_ISOMETRIC_LEFT_UP},
      {"isometricOffAxis1Left", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS1_LEFT},
      {"isometricOffAxis1Right", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS1_RIGHT},
      {"isometricOffAxis1Top", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS1_TOP},
      {"isometricOffAxis2Left", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS2_LEFT},
      {"isometricOffAxis2Right", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS2_RIGHT},
      {"isometricOffAxis2Top", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS2_TOP},
      {"isometricOffAxis3Bottom", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS3_BOTTOM},
      {"isometricOffAxis3Left", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS3_LEFT},
      {"isometricOffAxis3Right", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS3_RIGHT},
      {"isometricOffAxis4Bottom", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS4_BOTTOM},
      {"isometricOffAxis4Left", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS4_LEFT},
      {"isometricOffAxis4Right", ST_PRESET_CAMERA_TYPE_ISOMETRIC_OFF_AXIS4_RIGHT},
      {"isometricRightDown", ST_PRESET_CAMERA_TYPE_ISOMETRIC_RIGHT_DOWN},
      {"isometricRightUp", ST_PRESET_CAMERA_TYPE_ISOMETRIC_RIGHT_UP},
      {"isometricTopDown", ST_PRESET_CAMERA_TYPE_ISOMETRIC_TOP_DOWN},
      {"isometricTopUp", ST_PRESET_CAMERA_TYPE_ISOMETRIC_TOP_UP},
      {"legacyObliqueBottom", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_BOTTOM},
      {"legacyObliqueBottomLeft", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_BOTTOM_LEFT},
      {"legacyObliqueBottomRight", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_BOTTOM_RIGHT},
      {"legacyObliqueFront", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_FRONT},
      {"legacyObliqueLeft", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_LEFT},
      {"legacyObliqueRight", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_RIGHT},
      {"legacyObliqueTop", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_TOP},
      {"legacyObliqueTopLeft", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_TOP_LEFT},
      {"legacyObliqueTopRight", ST_PRESET_CAMERA_TYPE_LEGACY_OBLIQUE_TOP_RIGHT},
      {"legacyPerspectiveBottom", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_BOTTOM},
      {"legacyPerspectiveBottomLeft", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_BOTTOM_LEFT},
      {"legacyPerspectiveBottomRight", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_BOTTOM_RIGHT},
      {"legacyPerspectiveFront", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_FRONT},
      {"legacyPerspectiveLeft", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_LEFT},
      {"legacyPerspectiveRight", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_RIGHT},
      {"legacyPerspectiveTop", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_TOP},
      {"legacyPerspectiveTopLeft", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_TOP_LEFT},
      {"legacyPerspectiveTopRight", ST_PRESET_CAMERA_TYPE_LEGACY_PERSPECTIVE_TOP_RIGHT},
      {"nil", ST_PRESET_CAMERA_TYPE_NIL},
      {"obliqueBottom", ST_PRESET_CAMERA_TYPE_OBLIQUE_BOTTOM},
      {"obliqueBottomLeft", ST_PRESET_CAMERA_TYPE_OBLIQUE_BOTTOM_LEFT},
      {"obliqueBottomRight", ST_PRESET_CAMERA_TYPE_OBLIQUE_BOTTOM_RIGHT},
      {"obliqueLeft", ST_PRESET_CAMERA_TYPE_OBLIQUE_LEFT},
      {"obliqueRight", ST_PRESET_CAMERA_TYPE_OBLIQUE_RIGHT},
      {"obliqueTop", ST_PRESET_CAMERA_TYPE_OBLIQUE_TOP},
      {"obliqueTopLeft", ST_PRESET_CAMERA_TYPE_OBLIQUE_TOP_LEFT},
      {"obliqueTopRight", ST_PRESET_CAMERA_TYPE_OBLIQUE_TOP_RIGHT},
      {"orthographicFront", ST_PRESET_CAMERA_TYPE_ORTHOGRAPHIC_FRONT},
      {"perspectiveAbove", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_ABOVE},
      {"perspectiveAboveLeftFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_ABOVE_LEFT_FACING},
      {"perspectiveAboveRightFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_ABOVE_RIGHT_FACING},
      {"perspectiveBelow", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_BELOW},
      {"perspectiveContrastingLeftFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_CONTRASTING_LEFT_FACING},
      {"perspectiveContrastingRightFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_CONTRASTING_RIGHT_FACING},
      {"perspectiveFront", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_FRONT},
      {"perspectiveHeroicExtremeLeftFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_HEROIC_EXTREME_LEFT_FACING},
      {"perspectiveHeroicExtremeRightFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_HEROIC_EXTREME_RIGHT_FACING},
      {"perspectiveHeroicLeftFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_HEROIC_LEFT_FACING},
      {"perspectiveHeroicRightFacing", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_HEROIC_RIGHT_FACING},
      {"perspectiveLeft", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_LEFT},
      {"perspectiveRelaxed", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_RELAXED},
      {"perspectiveRelaxedModerately", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_RELAXED_MODERATELY},
      {"perspectiveRight", ST_PRESET_CAMERA_TYPE_PERSPECTIVE_RIGHT}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PRESET_CAMERA_TYPE_NIL;
    // Perform binary search
    found = bsearch(&key, base, 63, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PRESET_CAMERA_TYPE_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
