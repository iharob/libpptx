#ifndef __PPTX_COMMON_H__
#define __PPTX_COMMON_H__

#include <libxml/xpath.h>
#include <stdbool.h>
#include <stdint.h>

#define UNUSED __attribute__((unused))

typedef struct pptx_date_time {
    void *data;
} pptx_date_time;

typedef xmlChar *pptx_string;
typedef pptx_string pptx_any_uri;
typedef uint8_t *pptx_base64_binary;
typedef uint32_t pptx_uint;
typedef bool pptx_bool;
typedef double pptx_double;
typedef float pptx_float;
typedef int32_t pptx_int;
typedef int64_t pptx_long;
typedef uint64_t pptx_ulong;
typedef uint8_t pptx_byte;
typedef uint8_t *pptx_hexbin;
typedef int16_t pptx_short;
typedef uint16_t pptx_ushort;

typedef void *(*pptx_allocator_fn)(xmlNode *);

pptx_uint pptx_xml_get_attribute_as_uint(xmlNode *node, const xmlChar *const property);
pptx_int pptx_xml_get_attribute_as_int(xmlNode *node, const xmlChar *const property);
pptx_ushort pptx_xml_get_attribute_as_ushort(xmlNode *node, const xmlChar *const property);
pptx_short pptx_xml_get_attribute_as_short(xmlNode *node, const xmlChar *const property);
pptx_long pptx_xml_get_attribute_as_long(xmlNode *node, const xmlChar *const property);
pptx_ulong pptx_xml_get_attribute_as_ulong(xmlNode *node, const xmlChar *const property);
pptx_float pptx_xml_get_attribute_as_float(xmlNode *node, const xmlChar *const property);
pptx_double pptx_xml_get_attribute_as_double(xmlNode *node, const xmlChar *const property);
pptx_bool pptx_xml_get_attribute_as_bool(xmlNode *node, const xmlChar *const property);
pptx_byte pptx_xml_get_attribute_as_byte(xmlNode *node, const xmlChar *const property);
pptx_string pptx_xml_get_attribute_as_string(xmlNode *node, const xmlChar *const property);
pptx_hexbin pptx_xml_get_attribute_as_hexbin(xmlNode *node, const xmlChar *const property);

pptx_uint pptx_xml_get_content_as_uint(xmlNode *node, const xmlChar *const tag);
pptx_int pptx_xml_get_content_as_int(xmlNode *node, const xmlChar *const tag);
pptx_ushort pptx_xml_get_content_as_ushort(xmlNode *node, const xmlChar *const tag);
pptx_short pptx_xml_get_content_as_short(xmlNode *node, const xmlChar *const tag);
pptx_long pptx_xml_get_content_as_long(xmlNode *node, const xmlChar *const tag);
pptx_ulong pptx_xml_get_content_as_ulong(xmlNode *node, const xmlChar *const tag);
pptx_float pptx_xml_get_content_as_float(xmlNode *node, const xmlChar *const tag);
pptx_double pptx_xml_get_content_as_double(xmlNode *node, const xmlChar *const tag);
pptx_bool pptx_xml_get_content_as_bool(xmlNode *node, const xmlChar *const tag);
pptx_byte pptx_xml_get_content_as_byte(xmlNode *node, const xmlChar *const tag);
pptx_string pptx_xml_get_content_as_string(xmlNode *node, const xmlChar *const tag);
pptx_hexbin pptx_xml_get_content_as_hexbin(xmlNode *node, const xmlChar *const tag);

xmlXPathObject *pptx_xml_find_node(xmlNode *node, const xmlChar *const xpath);
int pptx_xml_apply_for_each(void **list, xmlNodeSet *nodes, pptx_allocator_fn allocator, int min, int max);
xmlChar *pptx_resolve_relation(xmlDoc *document, const xmlChar *const property, const xmlChar *const id);

char *pptx_strdupf(const char *const format, ...) __attribute__((format(printf,1,2)));
char *pptx_vstrdupf(const char *const format, va_list args);
char *pptx_strdup(const char *const source);
char *pptx_xml_get_prefixed_name(xmlNode *node);

int32_t pptx_xml_get_node_depth(xmlNode *node);

#endif /* __PPTX_COMMON_H__ */
