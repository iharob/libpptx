#ifndef __PPTX_CT_A_FONT_COLLECTION_H__
#define __PPTX_CT_A_FONT_COLLECTION_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef struct pptx_ct_a_text_font_s pptx_ct_a_text_font;
typedef struct pptx_ct_a_supplemental_font_s pptx_ct_a_supplemental_font;
typedef struct pptx_ct_a_office_art_extension_list_s pptx_ct_a_office_art_extension_list;

typedef struct pptx_ct_a_font_collection_s pptx_ct_a_font_collection;
pptx_ct_a_font_collection *pptx_ct_a_font_collection_new(xmlNode *node);
void pptx_ct_a_font_collection_free(pptx_ct_a_font_collection *obj);
pptx_ct_a_text_font *pptx_ct_a_font_collection_get_latin(const pptx_ct_a_font_collection *const obj);
pptx_ct_a_text_font *pptx_ct_a_font_collection_get_ea(const pptx_ct_a_font_collection *const obj);
pptx_ct_a_text_font *pptx_ct_a_font_collection_get_cs(const pptx_ct_a_font_collection *const obj);
pptx_ct_a_supplemental_font **pptx_ct_a_font_collection_get_font(const pptx_ct_a_font_collection *const obj);
pptx_ct_a_office_art_extension_list *pptx_ct_a_font_collection_get_ext_lst(const pptx_ct_a_font_collection *const obj);
int32_t pptx_ct_a_font_collection_get_index(pptx_ct_a_font_collection *obj);

#endif /* __PPTX_CT_A_FONT_COLLECTION_H__ */
