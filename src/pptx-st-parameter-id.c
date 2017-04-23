#define __PPTX_PRIVATE_INCLUDES__ /* Allow private includes */
/* Standard headers */
#include <string.h>
/* Self header */
#include <private/pptx-st-parameter-id.h>
/* Imported internal stuff */

struct map {
    char *key;
    pptx_st_parameter_id_token_enum value;
};

static int
comparator(const void *const lhs, const void *const rhs)
{
    return strcmp(((struct map *) lhs)->key, ((struct map *) rhs)->key);

}

pptx_st_parameter_id_token_enum
pptx_get_st_parameter_id(xmlNode *node, const xmlChar *property)
{
    struct map *found;
    struct map key;
    struct map base[56] = {
      {"alignTx", ST_PARAMETER_ID_ALIGN_TX},
      {"ar", ST_PARAMETER_ID_AR},
      {"autoTxRot", ST_PARAMETER_ID_AUTO_TX_ROT},
      {"begPts", ST_PARAMETER_ID_BEG_PTS},
      {"begSty", ST_PARAMETER_ID_BEG_STY},
      {"bendPt", ST_PARAMETER_ID_BEND_PT},
      {"bkPtFixedVal", ST_PARAMETER_ID_BK_PT_FIXED_VAL},
      {"bkpt", ST_PARAMETER_ID_BKPT},
      {"chAlign", ST_PARAMETER_ID_CH_ALIGN},
      {"chDir", ST_PARAMETER_ID_CH_DIR},
      {"connRout", ST_PARAMETER_ID_CONN_ROUT},
      {"contDir", ST_PARAMETER_ID_CONT_DIR},
      {"ctrShpMap", ST_PARAMETER_ID_CTR_SHP_MAP},
      {"dim", ST_PARAMETER_ID_DIM},
      {"dstNode", ST_PARAMETER_ID_DST_NODE},
      {"endPts", ST_PARAMETER_ID_END_PTS},
      {"endSty", ST_PARAMETER_ID_END_STY},
      {"fallback", ST_PARAMETER_ID_FALLBACK},
      {"flowDir", ST_PARAMETER_ID_FLOW_DIR},
      {"grDir", ST_PARAMETER_ID_GR_DIR},
      {"hierAlign", ST_PARAMETER_ID_HIER_ALIGN},
      {"horzAlign", ST_PARAMETER_ID_HORZ_ALIGN},
      {"linDir", ST_PARAMETER_ID_LIN_DIR},
      {"lnSpAfChP", ST_PARAMETER_ID_LN_SP_AF_CH_P},
      {"lnSpAfParP", ST_PARAMETER_ID_LN_SP_AF_PAR_P},
      {"lnSpCh", ST_PARAMETER_ID_LN_SP_CH},
      {"lnSpPar", ST_PARAMETER_ID_LN_SP_PAR},
      {"nil", ST_PARAMETER_ID_NIL},
      {"nodeHorzAlign", ST_PARAMETER_ID_NODE_HORZ_ALIGN},
      {"nodeVertAlign", ST_PARAMETER_ID_NODE_VERT_ALIGN},
      {"off", ST_PARAMETER_ID_OFF},
      {"parTxLTRAlign", ST_PARAMETER_ID_PAR_TX_LTRALIGN},
      {"parTxRTLAlign", ST_PARAMETER_ID_PAR_TX_RTLALIGN},
      {"pyraAcctBkgdNode", ST_PARAMETER_ID_PYRA_ACCT_BKGD_NODE},
      {"pyraAcctPos", ST_PARAMETER_ID_PYRA_ACCT_POS},
      {"pyraAcctTxMar", ST_PARAMETER_ID_PYRA_ACCT_TX_MAR},
      {"pyraAcctTxNode", ST_PARAMETER_ID_PYRA_ACCT_TX_NODE},
      {"pyraLvlNode", ST_PARAMETER_ID_PYRA_LVL_NODE},
      {"rotPath", ST_PARAMETER_ID_ROT_PATH},
      {"rtShortDist", ST_PARAMETER_ID_RT_SHORT_DIST},
      {"secChAlign", ST_PARAMETER_ID_SEC_CH_ALIGN},
      {"secLinDir", ST_PARAMETER_ID_SEC_LIN_DIR},
      {"shpTxLTRAlignCh", ST_PARAMETER_ID_SHP_TX_LTRALIGN_CH},
      {"shpTxRTLAlignCh", ST_PARAMETER_ID_SHP_TX_RTLALIGN_CH},
      {"spanAng", ST_PARAMETER_ID_SPAN_ANG},
      {"srcNode", ST_PARAMETER_ID_SRC_NODE},
      {"stAng", ST_PARAMETER_ID_ST_ANG},
      {"stBulletLvl", ST_PARAMETER_ID_ST_BULLET_LVL},
      {"stElem", ST_PARAMETER_ID_ST_ELEM},
      {"txAnchorHorz", ST_PARAMETER_ID_TX_ANCHOR_HORZ},
      {"txAnchorHorzCh", ST_PARAMETER_ID_TX_ANCHOR_HORZ_CH},
      {"txAnchorVert", ST_PARAMETER_ID_TX_ANCHOR_VERT},
      {"txAnchorVertCh", ST_PARAMETER_ID_TX_ANCHOR_VERT_CH},
      {"txBlDir", ST_PARAMETER_ID_TX_BL_DIR},
      {"txDir", ST_PARAMETER_ID_TX_DIR},
      {"vertAlign", ST_PARAMETER_ID_VERT_ALIGN}
    };
    // Prepare the key object
    key.key = (char *) pptx_xml_get_attribute_as_string(node, property);
    if (key.key == NULL)
        return ST_PARAMETER_ID_NIL;
    // Perform binary search
    found = bsearch(&key, base, 56, sizeof key, comparator);
    if (found == NULL) {
        xmlFree(key.key);
        return ST_PARAMETER_ID_NIL;
    }
    xmlFree(key.key);
    return found->value;
}
