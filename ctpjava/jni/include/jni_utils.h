/**
 * jni_utils.h
 * JNI 通用工具：JavaVM 管理、字符串编码转换、Java POJO ↔ CTP struct 互转
 */
#pragma once

#include <jni.h>
#include <string>
#include <cstring>

// ─────────────────────────────────────────────
//  全局 JavaVM（由 JNI_OnLoad 初始化）
// ─────────────────────────────────────────────
extern JavaVM* g_jvm;

/**
 * 获取当前线程的 JNIEnv。
 * 若当前线程尚未 Attach，则自动 Attach（适用于 CTP 的 SPI 回调线程）。
 * 返回 true 表示本次调用进行了 Attach，调用方在使用完后需 DetachCurrentThread。
 */
bool GetEnv(JNIEnv** env);

// ─────────────────────────────────────────────
//  字符串辅助
// ─────────────────────────────────────────────

/** Java jstring → std::string (UTF-8) */
std::string jstr2str(JNIEnv* env, jstring js);

/** const char* (UTF-8) → jstring */
jstring str2jstr(JNIEnv* env, const char* s);

// ─────────────────────────────────────────────
//  通用字段设置宏
//  用于 CTP struct → Java POJO
// ─────────────────────────────────────────────

/** 将 char[] 字段写入 Java String 字段 */
#define SET_STR(env, obj, cls, fieldName, cStr)              \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "Ljava/lang/String;"); \
        if (fid) {                                            \
            jstring _js = str2jstr(env, (cStr));              \
            env->SetObjectField(obj, fid, _js);               \
            env->DeleteLocalRef(_js);                         \
        }                                                     \
    } while(0)

/** 将 int 字段写入 Java int 字段 */
#define SET_INT(env, obj, cls, fieldName, val)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "I"); \
        if (fid) env->SetIntField(obj, fid, (jint)(val));    \
    } while(0)

/** 将 double 字段写入 Java double 字段 */
#define SET_DBL(env, obj, cls, fieldName, val)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "D"); \
        if (fid) env->SetDoubleField(obj, fid, (jdouble)(val)); \
    } while(0)

/** 将 char（单字节枚举）写入 Java char 字段 */
#define SET_CHR(env, obj, cls, fieldName, val)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "C"); \
        if (fid) env->SetCharField(obj, fid, (jchar)(unsigned char)(val)); \
    } while(0)

// ─────────────────────────────────────────────
//  通用字段读取宏
//  用于 Java POJO → CTP struct
// ─────────────────────────────────────────────

/** 从 Java String 字段读出并复制到 char[] */
#define GET_STR(env, obj, cls, fieldName, dst, dstSize)      \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "Ljava/lang/String;"); \
        if (fid) {                                            \
            jstring _js = (jstring)env->GetObjectField(obj, fid); \
            if (_js) {                                        \
                std::string _s = jstr2str(env, _js);          \
                strncpy(dst, _s.c_str(), (dstSize)-1);        \
                (dst)[(dstSize)-1] = '\0';                    \
                env->DeleteLocalRef(_js);                     \
            }                                                 \
        }                                                     \
    } while(0)

/** 从 Java int 字段读出 */
#define GET_INT(env, obj, cls, fieldName, dst)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "I"); \
        if (fid) (dst) = (int)env->GetIntField(obj, fid);    \
    } while(0)

/** 从 Java double 字段读出 */
#define GET_DBL(env, obj, cls, fieldName, dst)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "D"); \
        if (fid) (dst) = (double)env->GetDoubleField(obj, fid); \
    } while(0)

/** 从 Java char 字段读出（对应 CTP 的单字节枚举） */
#define GET_CHR(env, obj, cls, fieldName, dst)               \
    do {                                                      \
        jfieldID fid = env->GetFieldID(cls, fieldName, "C"); \
        if (fid) (dst) = (char)env->GetCharField(obj, fid);  \
    } while(0)

// ─────────────────────────────────────────────
//  创建 Java POJO 实例辅助
// ─────────────────────────────────────────────

/**
 * 在指定类名下查找无参构造并创建实例。
 * 类名格式如："com/ctpmini/struct/CThostFtdcRspInfoField"
 */
jobject NewJavaObject(JNIEnv* env, const char* className);

// ─────────────────────────────────────────────
//  CTP struct → Java POJO 转换函数声明
// ─────────────────────────────────────────────
#include "ThostFtdcUserApiStruct.h"

jobject ToJava_RspInfo           (JNIEnv* env, CThostFtdcRspInfoField*            p);
jobject ToJava_RspUserLogin      (JNIEnv* env, CThostFtdcRspUserLoginField*       p);
jobject ToJava_UserLogout        (JNIEnv* env, CThostFtdcUserLogoutField*         p);
jobject ToJava_SpecificInstrument(JNIEnv* env, CThostFtdcSpecificInstrumentField* p);
jobject ToJava_DepthMarketData   (JNIEnv* env, CThostFtdcDepthMarketDataField*    p);
jobject ToJava_MBLMarketData     (JNIEnv* env, CThostFtdcMBLMarketDataField*      p);
jobject ToJava_ForQuoteRsp       (JNIEnv* env, CThostFtdcForQuoteRspField*        p);
jobject ToJava_RspAuthenticate   (JNIEnv* env, CThostFtdcRspAuthenticateField*    p);
jobject ToJava_Order             (JNIEnv* env, CThostFtdcOrderField*              p);
jobject ToJava_Trade             (JNIEnv* env, CThostFtdcTradeField*              p);
jobject ToJava_InputOrder        (JNIEnv* env, CThostFtdcInputOrderField*         p);
jobject ToJava_InputOrderAction  (JNIEnv* env, CThostFtdcInputOrderActionField*   p);
jobject ToJava_OrderAction       (JNIEnv* env, CThostFtdcOrderActionField*        p);
jobject ToJava_InvestorPosition  (JNIEnv* env, CThostFtdcInvestorPositionField*   p);
jobject ToJava_TradingAccount    (JNIEnv* env, CThostFtdcTradingAccountField*     p);
jobject ToJava_Investor          (JNIEnv* env, CThostFtdcInvestorField*           p);
jobject ToJava_TradingCode       (JNIEnv* env, CThostFtdcTradingCodeField*        p);
jobject ToJava_Exchange          (JNIEnv* env, CThostFtdcExchangeField*           p);
jobject ToJava_Product           (JNIEnv* env, CThostFtdcProductField*            p);
jobject ToJava_Instrument        (JNIEnv* env, CThostFtdcInstrumentField*         p);
jobject ToJava_CombInstrument    (JNIEnv* env, CThostFtdcCombInstrumentField*     p);
jobject ToJava_InstrumentStatus  (JNIEnv* env, CThostFtdcInstrumentStatusField*   p);
jobject ToJava_InstrMarginRate   (JNIEnv* env, CThostFtdcInstrumentMarginRateField*      p);
jobject ToJava_InstrCommRate     (JNIEnv* env, CThostFtdcInstrumentCommissionRateField*  p);
jobject ToJava_ExchMarginRate    (JNIEnv* env, CThostFtdcExchangeMarginRateField*        p);
jobject ToJava_ExchMarginRateAdj (JNIEnv* env, CThostFtdcExchangeMarginRateAdjustField* p);
jobject ToJava_DepthMarketDataQry(JNIEnv* env, CThostFtdcDepthMarketDataField*    p); // 同DepthMarketData
jobject ToJava_InvestorPosDetail (JNIEnv* env, CThostFtdcInvestorPositionDetailField* p);
jobject ToJava_OptionInstrTradeCost(JNIEnv* env, CThostFtdcOptionInstrTradeCostField* p);
jobject ToJava_OptionInstrCommRate(JNIEnv* env, CThostFtdcOptionInstrCommRateField*   p);
jobject ToJava_ExecOrder         (JNIEnv* env, CThostFtdcExecOrderField*          p);
jobject ToJava_InputExecOrder    (JNIEnv* env, CThostFtdcInputExecOrderField*     p);
jobject ToJava_InputExecOrderAction(JNIEnv* env, CThostFtdcInputExecOrderActionField* p);
jobject ToJava_ForQuote          (JNIEnv* env, CThostFtdcForQuoteField*           p);
jobject ToJava_InputForQuote     (JNIEnv* env, CThostFtdcInputForQuoteField*      p);
jobject ToJava_InputQuote        (JNIEnv* env, CThostFtdcInputQuoteField*         p);
jobject ToJava_InputQuoteAction  (JNIEnv* env, CThostFtdcInputQuoteActionField*   p);
jobject ToJava_Quote             (JNIEnv* env, CThostFtdcQuoteField*              p);
jobject ToJava_QuoteAction       (JNIEnv* env, CThostFtdcQuoteActionField*        p);
jobject ToJava_BatchOrderAction  (JNIEnv* env, CThostFtdcBatchOrderActionField*   p);
jobject ToJava_InputBatchOrderAction(JNIEnv* env, CThostFtdcInputBatchOrderActionField* p);
jobject ToJava_OptionSelfClose   (JNIEnv* env, CThostFtdcOptionSelfCloseField*    p);
jobject ToJava_InputOptionSelfClose(JNIEnv* env, CThostFtdcInputOptionSelfCloseField* p);
jobject ToJava_InputOptionSelfCloseAction(JNIEnv* env, CThostFtdcInputOptionSelfCloseActionField* p);
jobject ToJava_OptionSelfCloseAction(JNIEnv* env, CThostFtdcOptionSelfCloseActionField* p);
jobject ToJava_CombAction        (JNIEnv* env, CThostFtdcCombActionField*         p);
jobject ToJava_InputCombAction   (JNIEnv* env, CThostFtdcInputCombActionField*    p);
jobject ToJava_InvestorPosForComb(JNIEnv* env, CThostFtdcInvestorPositionForCombField* p);
jobject ToJava_ForQuoteParam     (JNIEnv* env, CThostFtdcForQuoteParamField*      p);
jobject ToJava_InstrOrderCommRate(JNIEnv* env, CThostFtdcInstrumentOrderCommRateField* p);
jobject ToJava_FlowCtrlWarning   (JNIEnv* env, CThostFtdcFlowCtrlWarningField*    p);
jobject ToJava_SpecificTrader    (JNIEnv* env, CThostFtdcSpecificTraderField*     p);
jobject ToJava_TraderOffer       (JNIEnv* env, CThostFtdcTraderOfferField*        p);
jobject ToJava_RCAMSProdMargin   (JNIEnv* env, CThostFtdcRCAMSInvestorProdMarginField* p);
jobject ToJava_RCAMSCombPos      (JNIEnv* env, CThostFtdcRCAMSInvestorCombPositionField* p);
jobject ToJava_SPBMDetail        (JNIEnv* env, CThostFtdcInvestorProdSPBMDetailField* p);
jobject ToJava_SPMMGroupMargin   (JNIEnv* env, CThostFtdcSPMMInvestorCommodityGroupMarginField* p);
jobject ToJava_RULEProdMargin    (JNIEnv* env, CThostFtdcRULEInvestorProdMarginField* p);
jobject ToJava_ControlParam      (JNIEnv* env, CThostFtdcControlParamField*       p);
jobject ToJava_OffsetSetting     (JNIEnv* env, CThostFtdcOffsetSettingField*      p);
jobject ToJava_CancelOffsetSetting(JNIEnv* env, CThostFtdcCancelOffsetSettingField* p);
jobject ToJava_InputOffsetSetting(JNIEnv* env, CThostFtdcInputOffsetSettingField* p);
jobject ToJava_UserPasswordUpdate(JNIEnv* env, CThostFtdcUserPasswordUpdateField* p);
jobject ToJava_MKInputOrderAction(JNIEnv* env, CThostFtdcMKInputOrderActionField* p);

// ─────────────────────────────────────────────
//  Java POJO → CTP struct 转换函数声明
// ─────────────────────────────────────────────
void FromJava_ReqUserLogin   (JNIEnv* env, jobject obj, CThostFtdcReqUserLoginField&   out);
void FromJava_UserLogout     (JNIEnv* env, jobject obj, CThostFtdcUserLogoutField&     out);
void FromJava_ReqAuthenticate(JNIEnv* env, jobject obj, CThostFtdcReqAuthenticateField& out);
void FromJava_InputOrder     (JNIEnv* env, jobject obj, CThostFtdcInputOrderField&     out);
void FromJava_InputOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputOrderActionField& out);
void FromJava_MKInputOrderAction(JNIEnv* env, jobject obj, CThostFtdcMKInputOrderActionField& out);
void FromJava_InputExecOrder (JNIEnv* env, jobject obj, CThostFtdcInputExecOrderField& out);
void FromJava_InputExecOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputExecOrderActionField& out);
void FromJava_InputForQuote  (JNIEnv* env, jobject obj, CThostFtdcInputForQuoteField&  out);
void FromJava_InputQuote     (JNIEnv* env, jobject obj, CThostFtdcInputQuoteField&     out);
void FromJava_InputQuoteAction(JNIEnv* env, jobject obj, CThostFtdcInputQuoteActionField& out);
void FromJava_InputBatchOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputBatchOrderActionField& out);
void FromJava_InputOptionSelfClose(JNIEnv* env, jobject obj, CThostFtdcInputOptionSelfCloseField& out);
void FromJava_InputOptionSelfCloseAction(JNIEnv* env, jobject obj, CThostFtdcInputOptionSelfCloseActionField& out);
void FromJava_InputCombAction(JNIEnv* env, jobject obj, CThostFtdcInputCombActionField& out);
void FromJava_InputOffsetSetting(JNIEnv* env, jobject obj, CThostFtdcInputOffsetSettingField& out);
void FromJava_UserPasswordUpdate(JNIEnv* env, jobject obj, CThostFtdcUserPasswordUpdateField& out);

// Qry
void FromJava_QryOrder       (JNIEnv* env, jobject obj, CThostFtdcQryOrderField&       out);
void FromJava_QryTrade       (JNIEnv* env, jobject obj, CThostFtdcQryTradeField&       out);
void FromJava_QryInvestorPos (JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionField& out);
void FromJava_QryTradingAcct (JNIEnv* env, jobject obj, CThostFtdcQryTradingAccountField& out);
void FromJava_QryInvestor    (JNIEnv* env, jobject obj, CThostFtdcQryInvestorField&    out);
void FromJava_QryTradingCode (JNIEnv* env, jobject obj, CThostFtdcQryTradingCodeField& out);
void FromJava_QryInstrMarginRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentMarginRateField& out);
void FromJava_QryInstrCommRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentCommissionRateField& out);
void FromJava_QryExchange    (JNIEnv* env, jobject obj, CThostFtdcQryExchangeField&    out);
void FromJava_QryProduct     (JNIEnv* env, jobject obj, CThostFtdcQryProductField&     out);
void FromJava_QryInstrument  (JNIEnv* env, jobject obj, CThostFtdcQryInstrumentField&  out);
void FromJava_QryCombInstrument(JNIEnv* env, jobject obj, CThostFtdcQryCombInstrumentField& out);
void FromJava_QryDepthMD     (JNIEnv* env, jobject obj, CThostFtdcQryDepthMarketDataField& out);
void FromJava_QryInstrStatus (JNIEnv* env, jobject obj, CThostFtdcQryInstrumentStatusField& out);
void FromJava_QryInvestorPosDetail(JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionDetailField& out);
void FromJava_QryExchMarginRate(JNIEnv* env, jobject obj, CThostFtdcQryExchangeMarginRateField& out);
void FromJava_QryExchMarginRateAdj(JNIEnv* env, jobject obj, CThostFtdcQryExchangeMarginRateAdjustField& out);
void FromJava_QryOptInstrTradeCost(JNIEnv* env, jobject obj, CThostFtdcQryOptionInstrTradeCostField& out);
void FromJava_QryOptInstrCommRate(JNIEnv* env, jobject obj, CThostFtdcQryOptionInstrCommRateField& out);
void FromJava_QryExecOrder   (JNIEnv* env, jobject obj, CThostFtdcQryExecOrderField&   out);
void FromJava_QryForQuote    (JNIEnv* env, jobject obj, CThostFtdcQryForQuoteField&    out);
void FromJava_QryQuote       (JNIEnv* env, jobject obj, CThostFtdcQryQuoteField&       out);
void FromJava_QryOptionSelfClose(JNIEnv* env, jobject obj, CThostFtdcQryOptionSelfCloseField& out);
void FromJava_QryCombAction  (JNIEnv* env, jobject obj, CThostFtdcQryCombActionField&  out);
void FromJava_QryInvestorPosForComb(JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionForCombField& out);
void FromJava_QryRCAMSProdMargin(JNIEnv* env, jobject obj, CThostFtdcQryRCAMSInvestorProdMarginField& out);
void FromJava_QryRCAMSCombPos(JNIEnv* env, jobject obj, CThostFtdcQryRCAMSInvestorCombPositionField& out);
void FromJava_QrySPBMDetail  (JNIEnv* env, jobject obj, CThostFtdcQryInvestorProdSPBMDetailField& out);
void FromJava_QrySPMMGroupMargin(JNIEnv* env, jobject obj, CThostFtdcQrySPMMInvestorCommodityGroupMarginField& out);
void FromJava_QryRULEProdMargin(JNIEnv* env, jobject obj, CThostFtdcQryRULEInvestorProdMarginField& out);
void FromJava_QryControlParam(JNIEnv* env, jobject obj, CThostFtdcQryControlParamField& out);
void FromJava_QryOffsetSetting(JNIEnv* env, jobject obj, CThostFtdcQryOffsetSettingField& out);
void FromJava_QryInstrOrderCommRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentOrderCommRateField& out);
void FromJava_QryForQuoteParam(JNIEnv* env, jobject obj, CThostFtdcQryForQuoteParamField& out);
void FromJava_QryTraderOffer (JNIEnv* env, jobject obj, CThostFtdcQryTraderOfferField& out);
