#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-ct-p-modify-verifier.h>
/* Imported internal stuff */
#include <private/pptx-st-crypt-prov.h>
#include <private/pptx-st-alg-class.h>
#include <private/pptx-st-alg-type.h>

typedef struct pptx_ct_p_modify_verifier_s {
    pptx_string algorithm_name;
    pptx_string hash_value;
    pptx_string salt_value;
    pptx_uint spin_value;
    pptx_st_crypt_prov_text_enum crypt_provider_type;
    pptx_st_alg_class_text_enum crypt_algorithm_class;
    pptx_st_alg_type_text_enum crypt_algorithm_type;
    pptx_uint crypt_algorithm_sid;
    pptx_uint spin_count;
    pptx_string salt_data;
    pptx_string hash_data;
    pptx_string crypt_provider;
    pptx_uint alg_id_ext;
    pptx_string alg_id_ext_source;
    pptx_uint crypt_provider_type_ext;
    pptx_string crypt_provider_type_ext_source;
    int32_t index;
} pptx_ct_p_modify_verifier;

pptx_ct_p_modify_verifier *
pptx_ct_p_modify_verifier_new(xmlNode *node)
{
    pptx_ct_p_modify_verifier *obj;
    xmlXPathObject *xpath __attribute__((unused));
    if (node == NULL)
        return NULL;
    obj = malloc(sizeof *obj);
    if (obj == NULL)
        return NULL;
    obj->algorithm_name = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "algorithmName");
    obj->hash_value = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "hashValue");
    obj->salt_value = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "saltValue");
    obj->spin_value = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spinValue");
    obj->crypt_provider_type = pptx_get_st_crypt_prov(node, (const xmlChar *) "cryptProviderType");
    obj->crypt_algorithm_class = pptx_get_st_alg_class(node, (const xmlChar *) "cryptAlgorithmClass");
    obj->crypt_algorithm_type = pptx_get_st_alg_type(node, (const xmlChar *) "cryptAlgorithmType");
    obj->crypt_algorithm_sid = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "cryptAlgorithmSid");
    obj->spin_count = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "spinCount");
    obj->salt_data = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "saltData");
    obj->hash_data = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "hashData");
    obj->crypt_provider = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "cryptProvider");
    obj->alg_id_ext = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "algIdExt");
    obj->alg_id_ext_source = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "algIdExtSource");
    obj->crypt_provider_type_ext = pptx_xml_get_attribute_as_uint(node, (const xmlChar *) "cryptProviderTypeExt");
    obj->crypt_provider_type_ext_source = pptx_xml_get_attribute_as_string(node, (const xmlChar *) "cryptProviderTypeExtSource");
    obj->index = pptx_xml_get_node_depth(node);
    return obj;
}

pptx_string 
pptx_ct_p_modify_verifier_get_algorithm_name(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->algorithm_name;
}

pptx_string 
pptx_ct_p_modify_verifier_get_hash_value(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->hash_value;
}

pptx_string 
pptx_ct_p_modify_verifier_get_salt_value(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->salt_value;
}

pptx_uint 
pptx_ct_p_modify_verifier_get_spin_value(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->spin_value;
}

pptx_st_crypt_prov_text_enum 
pptx_ct_p_modify_verifier_get_crypt_provider_type(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_provider_type;
}

pptx_st_alg_class_text_enum 
pptx_ct_p_modify_verifier_get_crypt_algorithm_class(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_algorithm_class;
}

pptx_st_alg_type_text_enum 
pptx_ct_p_modify_verifier_get_crypt_algorithm_type(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_algorithm_type;
}

pptx_uint 
pptx_ct_p_modify_verifier_get_crypt_algorithm_sid(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_algorithm_sid;
}

pptx_uint 
pptx_ct_p_modify_verifier_get_spin_count(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->spin_count;
}

pptx_string 
pptx_ct_p_modify_verifier_get_salt_data(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->salt_data;
}

pptx_string 
pptx_ct_p_modify_verifier_get_hash_data(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->hash_data;
}

pptx_string 
pptx_ct_p_modify_verifier_get_crypt_provider(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_provider;
}

pptx_uint 
pptx_ct_p_modify_verifier_get_alg_id_ext(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->alg_id_ext;
}

pptx_string 
pptx_ct_p_modify_verifier_get_alg_id_ext_source(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->alg_id_ext_source;
}

pptx_uint 
pptx_ct_p_modify_verifier_get_crypt_provider_type_ext(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_provider_type_ext;
}

pptx_string 
pptx_ct_p_modify_verifier_get_crypt_provider_type_ext_source(const pptx_ct_p_modify_verifier *const obj)
{
    return obj->crypt_provider_type_ext_source;
}

int32_t
pptx_ct_p_modify_verifier_get_index(pptx_ct_p_modify_verifier *obj)
{
    return obj->index;
}

void
pptx_ct_p_modify_verifier_free(pptx_ct_p_modify_verifier *obj)
{
    if (obj == NULL)
        return;
    xmlFree(obj->algorithm_name);
    xmlFree(obj->hash_value);
    xmlFree(obj->salt_value);
    xmlFree(obj->salt_data);
    xmlFree(obj->hash_data);
    xmlFree(obj->crypt_provider);
    xmlFree(obj->alg_id_ext_source);
    xmlFree(obj->crypt_provider_type_ext_source);
    free(obj);
}