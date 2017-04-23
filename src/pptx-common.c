#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */

#include <private/pptx-common.h>
#include <libxml/xpathInternals.h>
#include <string.h>

#define RELS_NS ((const xmlChar *) "http://schemas.openxmlformats.org/package/2006/relationships")
#define P_NS ((const xmlChar *) "http://schemas.openxmlformats.org/presentationml/2006/main")
#define A_NS ((const xmlChar *) "http://schemas.openxmlformats.org/drawingml/2006/main")
#define R_NS ((const xmlChar *) "http://schemas.openxmlformats.org/officeDocument/2006/relationships")
#define DGM_NS ((const xmlChar *) "http://schemas.openxmlformats.org/drawingml/2006/diagram")
#define XMLNS ((const xmlChar *) "http://schemas.openxmlformats.org/package/2006/relationships")
#define DSP_NS ((const xmlChar *) "http://schemas.microsoft.com/office/drawing/2008/diagram")
#define CDR_NS ((const xmlChar *) "http://schemas.openxmlformats.org/drawingml/2006/chartDrawing")

#define RELATIONSHIP_XPATH_EXPR "//r:Relationship[@%s='%s']"

static void
pptx_xml_xpath_register_namespaces(xmlXPathContext *context)
{
    xmlXPathRegisterNs(context, (const xmlChar *) "dgm", DGM_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "p", P_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "a", A_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "r", R_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "rels", RELS_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "dsp", DSP_NS);
    xmlXPathRegisterNs(context, (const xmlChar *) "cdr", CDR_NS);
}

xmlChar *
pptx_resolve_relation(xmlDoc *document, const xmlChar *const property, const xmlChar *const id)
{
    char expr[0x400] = {0};
    xmlXPathContext *ctx;
    int length;
    xmlXPathObject *xpath;
    xmlNodeSet *nodes;
    xmlChar *result;

    length = snprintf(expr, sizeof expr, RELATIONSHIP_XPATH_EXPR, property, id);
    if ((length >= sizeof expr) || (length < 0))
        return NULL;
    result = NULL;
    ctx = xmlXPathNewContext(document);
    if (ctx == NULL)
        return NULL;
    xmlXPathRegisterNs(ctx, (const xmlChar *) "r", XMLNS);

    xpath = xmlXPathEvalExpression((const xmlChar *) expr, ctx);
    if ((xpath == NULL) || (xpath->nodesetval == NULL))
        goto error;
    nodes = xpath->nodesetval;
    if (nodes->nodeNr != 1)
        goto error;
    for (int i = 0; i < nodes->nodeNr; ++i) {
        result = pptx_xml_get_attribute_as_string(nodes->nodeTab[i], (const xmlChar *) "Target");
    }
error:
    if (xpath != NULL)
        xmlXPathFreeObject(xpath);
    xmlXPathFreeContext(ctx);
    return result;
}

pptx_string
pptx_xml_get_attribute_as_string(xmlNode *node, const xmlChar *const property)
{
    xmlAttr *prop;
    // FIXME: this should be implemented using libxml's functions
    for (prop = node->properties; prop != NULL; prop = prop->next) {
        const xmlChar *name;
        const xmlNode *child;
        const xmlNs *ns;
        const xmlChar *head;

        child = prop->children;
        ns = prop->ns;
        name = prop->name;

        if ((ns != NULL) && (ns->prefix != NULL)) {
            head = xmlStrstr(property, ns->prefix);
            if (head == NULL)
                return NULL;
            head += xmlStrlen(ns->prefix) + 1;
        } else {
            head = property;
        }

        if (xmlStrcmp(name, head) == 0) {
            return xmlNodeGetContent(child);
        }
    }
    return NULL;
}

pptx_long
pptx_xml_get_attribute_as_long(xmlNode *node, const xmlChar *const property)
{
    xmlChar *value;
    pptx_long result;
    char *endptr;
    value = pptx_xml_get_attribute_as_string(node, property);
    if (value == NULL)
        return -1;
    result = (pptx_long) strtol((const char *) value, &endptr, 10);
    if (*endptr != '\0')
        result = -1;
    xmlFree(value);
    return result;
}

pptx_ulong
pptx_xml_get_attribute_as_ulong(xmlNode *node, const xmlChar *const property)
{
    xmlChar *value;
    pptx_ulong result;
    char *endptr;
    value = pptx_xml_get_attribute_as_string(node, property);
    if (value == NULL)
        return -1;
    result = (pptx_long) strtoul((const char *) value, &endptr, 10);
    if (*endptr != '\0')
        result = -1;
    xmlFree(value);
    return result;
}

pptx_uint
pptx_xml_get_attribute_as_uint(xmlNode *node, const xmlChar *const property)
{
    return (pptx_uint) pptx_xml_get_attribute_as_ulong(node, property);
}

pptx_int
pptx_xml_get_attribute_as_int(xmlNode *node, const xmlChar *const property)
{
    return (pptx_int) pptx_xml_get_attribute_as_long(node, property);
}

pptx_ushort
pptx_xml_get_attribute_as_ushort(xmlNode *node, const xmlChar *const property)
{
    return (pptx_ushort) pptx_xml_get_attribute_as_uint(node, property);
}

pptx_short
pptx_xml_get_attribute_as_short(xmlNode *node, const xmlChar *const property)
{
    return (pptx_short) pptx_xml_get_attribute_as_int(node, property);
}

pptx_float
pptx_xml_get_attribute_as_float(xmlNode *node, const xmlChar *const property)
{
    xmlChar *value;
    pptx_float result;
    char *endptr;
    value = pptx_xml_get_attribute_as_string(node, property);
    if (value == NULL)
        return -1;
    result = (pptx_float) strtod((const char *) value, &endptr);
    if (*endptr != '\0')
        result = -1;
    xmlFree(value);
    return result;
}

pptx_double
pptx_xml_get_attribute_as_double(xmlNode *node, const xmlChar *const property)
{
    xmlChar *value;
    pptx_double result;
    char *endptr;
    value = pptx_xml_get_attribute_as_string(node, property);
    if (value == NULL)
        return -1;
    result = (pptx_double) strtod((const char *) value, &endptr);
    if (*endptr != '\0')
        result = -1;
    xmlFree(value);
    return result;
}

pptx_bool
pptx_xml_get_attribute_as_bool(xmlNode *node, const xmlChar *const property)
{
    pptx_bool result;
    xmlChar *value;
    value = pptx_xml_get_attribute_as_string(node, property);
    if (value == NULL)
        return false;
    result = (
            (xmlStrcasecmp(value, (xmlChar *) "true") == 0) ||
            (xmlStrcasecmp(value, (xmlChar *) "1") == 0)
             );
    xmlFree(value);
    return result;
}

pptx_byte
pptx_xml_get_attribute_as_byte(xmlNode *node, const xmlChar *const xpath)
{
    return 0x00;
}

pptx_hexbin
pptx_xml_get_attribute_as_hexbin(xmlNode *node, const xmlChar *const property)
{
    return pptx_xml_get_attribute_as_string(node, property);
}

xmlXPathObject *
pptx_xml_find_node(xmlNode *node, const xmlChar *const expression)
{
    xmlXPathContext *context;
    xmlXPathObject *result;
    context = xmlXPathNewContext(node->doc);
    if (context == NULL)
        return NULL;
    pptx_xml_xpath_register_namespaces(context);

    xmlXPathSetContextNode(node, context);

    result = xmlXPathEval(expression, context);
    xmlXPathFreeContext(context);

    return result;
}

int
pptx_xml_apply_for_each(void **list, xmlNodeSet *nodes, pptx_allocator_fn allocator, int min, int max)
{
    if ((nodes->nodeNr < min) || ((max != -1) && (nodes->nodeNr > max)))
        return -1;
    for (int i = 0; i < nodes->nodeNr; ++i)
        list[i] = allocator(nodes->nodeTab[i]);
    return 0;
}

pptx_string
pptx_xml_get_content_as_string(xmlNode *node, const xmlChar *const tag)
{
    xmlXPathObject *xpath;
    xmlNodeSet *nodes;
    xpath = pptx_xml_find_node(node, tag);
    if (xpath == NULL)
        return NULL;
    node = NULL;
    nodes = xpath->nodesetval;
    if ((nodes == NULL) || (nodes->nodeNr != 1))
        goto error;
    node = nodes->nodeTab[0];
error:
    xmlXPathFreeObject(xpath);
    if (node != NULL)
        return xmlNodeGetContent(node);
    return NULL;
}

pptx_double
pptx_xml_get_content_as_double(xmlNode *node, const xmlChar *const tag)
{
    pptx_double value;
    xmlChar *string;
    string = pptx_xml_get_content_as_string(node, tag);
    if (string == NULL)
        return 0.0;
    value = strtod((const char *) string, NULL);
    xmlFree(string);
    return value;
}

pptx_long
pptx_xml_get_content_as_long(xmlNode *node, const xmlChar *const tag)
{
    pptx_long value;
    xmlChar *string;
    string = pptx_xml_get_content_as_string(node, tag);
    if (string == NULL)
        return 0.0;
    value = strtol((const char *) string, NULL, 10);
    xmlFree(string);
    return value;
}

pptx_ulong
pptx_xml_get_content_as_ulong(xmlNode *node, const xmlChar *const tag)
{
    pptx_ulong value;
    xmlChar *string;
    string = pptx_xml_get_content_as_string(node, tag);
    if (string == NULL)
        return 0.0;
    value = strtoul((const char *) string, NULL, 10);
    xmlFree(string);
    return value;
}

pptx_uint
pptx_xml_get_content_as_uint(xmlNode *node, const xmlChar *const tag)
{
    return (pptx_uint) pptx_xml_get_content_as_ulong(node, tag);
}

pptx_int
pptx_xml_get_content_as_int(xmlNode *node, const xmlChar *const tag)
{
    return (pptx_int) pptx_xml_get_content_as_long(node, tag);
}

pptx_ushort
pptx_xml_get_content_as_ushort(xmlNode *node, const xmlChar *const tag)
{
    return (pptx_ushort) pptx_xml_get_content_as_ulong(node, tag);
}

pptx_short
pptx_xml_get_content_as_short(xmlNode *node, const xmlChar *const tag)
{
    return (pptx_short) pptx_xml_get_content_as_long(node, tag);
}

pptx_float
pptx_xml_get_content_as_float(xmlNode *node, const xmlChar *const tag)
{
    return (pptx_float) pptx_xml_get_content_as_double(node, tag);
}

pptx_bool
pptx_xml_get_content_as_bool(xmlNode *node, const xmlChar *const tag)
{
    pptx_bool value;
    xmlChar *string;
    string = pptx_xml_get_content_as_string(node, tag);
    if (string == NULL)
        return false;
    value = ((xmlStrcmp(string, (const xmlChar *) "1") == 0) || (xmlStrcmp(string, (const xmlChar *) "true") == 0));
    xmlFree(string);
    return value;
}

pptx_byte
pptx_xml_get_content_as_byte(xmlNode *node, const xmlChar *const tag)
{
    return 0x00;
}

pptx_hexbin
pptx_xml_get_content_as_hexbin(xmlNode *node, const xmlChar *const tag)
{
    return pptx_xml_get_content_as_string(node, tag);
}

char *
pptx_vstrdupf(const char *const format, va_list args)
{
    char *result;
    va_list copy;
    int length;
    va_copy(copy, args);
    result = NULL;
    length = vsnprintf(NULL, 0, format, copy);
    if (length == -1)
        goto error;
    result = malloc(length + 1);
    if (result == NULL)
        goto error;
    if (vsnprintf(result, length + 1, format, args) == -1)
        goto error;
    va_end(copy);
    return result;
error:
    free(result);
    va_end(copy);
    return NULL;
}

char *
pptx_strdupf(const char *const format, ...)
{
    va_list args;
    char *result;
    va_start(args, format);
    result = pptx_vstrdupf(format, args);
    va_end(args);
    return result;
}

char *
pptx_strdup(const char *const source)
{
    size_t length;
    char *result;
    // Instead of causing undefined behavior,
    // behave as if `NULL' is equal to `NULL'
    // even as a string
    if (source == NULL)
        return NULL;
    length = strlen(source);
    result = malloc(length + 1);
    if (result == NULL)
        return NULL;
    return memcpy(result, source, length + 1);
}

char *
pptx_xml_get_prefixed_name(xmlNode *node)
{
    char *name;
    xmlNs *ns;
    ns = node->ns;
    if (ns != NULL) {
        name = pptx_strdupf("%s:%s", ns->prefix, node->name);
    } else {
        name = pptx_strdup((const char *) node->name);
    }
    return name;
}

int32_t
pptx_xml_get_node_depth(xmlNode *node)
{
    int32_t depth;
    depth = 0;
    for (; node != NULL; node = node->prev)
        depth += 1;
    return depth;
}
