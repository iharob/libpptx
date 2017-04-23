#ifndef __PPTX_CT_A_ERR_DIR_H__
#define __PPTX_CT_A_ERR_DIR_H__

#ifndef __PPTX_PRIVATE_INCLUDES__
#error "Please do not include this file directly"
#endif /* __PPTX_H__ */

#include <libxml/parser.h>
#include <private/pptx-common.h>

typedef enum pptx_st_err_dir_text_enum pptx_st_err_dir_text_enum;

typedef struct pptx_ct_a_err_dir_s pptx_ct_a_err_dir;
pptx_ct_a_err_dir *pptx_ct_a_err_dir_new(xmlNode *node);
void pptx_ct_a_err_dir_free(pptx_ct_a_err_dir *obj);
pptx_st_err_dir_text_enum pptx_ct_a_err_dir_get_val(const pptx_ct_a_err_dir *const obj);
int32_t pptx_ct_a_err_dir_get_index(pptx_ct_a_err_dir *obj);

#endif /* __PPTX_CT_A_ERR_DIR_H__ */
