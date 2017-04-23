#ifndef __PPTX_ST_VIEW_TYPE_H__
#define __PPTX_ST_VIEW_TYPE_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_view_type_token_enum {
    ST_VIEW_TYPE_SLD_VIEW,
    ST_VIEW_TYPE_NIL,
    ST_VIEW_TYPE_HANDOUT_VIEW,
    ST_VIEW_TYPE_SLD_THUMBNAIL_VIEW,
    ST_VIEW_TYPE_NOTES_MASTER_VIEW,
    ST_VIEW_TYPE_OUTLINE_VIEW,
    ST_VIEW_TYPE_SLD_SORTER_VIEW,
    ST_VIEW_TYPE_NOTES_VIEW,
    ST_VIEW_TYPE_SLD_MASTER_VIEW
} pptx_st_view_type_token_enum;

pptx_st_view_type_token_enum pptx_get_st_view_type(xmlNode *node, const xmlChar *property);

#endif /* __PPTX_ST_VIEW_TYPE_H__ */
