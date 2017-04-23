#ifndef __PPTX_ST_TLTIME_NODE_PRESET_CLASS_TYPE_H__
#define __PPTX_ST_TLTIME_NODE_PRESET_CLASS_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_tltime_node_preset_class_type_token_enum {
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_ENTR,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_NIL,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_EMPH,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_VERB,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_EXIT,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_MEDIACALL,
    ST_TLTIME_NODE_PRESET_CLASS_TYPE_PATH
} pptx_st_tltime_node_preset_class_type_token_enum;

pptx_st_tltime_node_preset_class_type_token_enum pptx_get_st_tltime_node_preset_class_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_TLTIME_NODE_PRESET_CLASS_TYPE_H__ */
