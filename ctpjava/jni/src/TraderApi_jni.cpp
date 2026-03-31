/**
 * TraderApi_jni.cpp
 * 交易 API JNI 桥接
 *
 * Java 类:  com.ctpmini.api.CThostFtdcTraderApi   (abstract)
 *            com.ctpmini.api.CThostFtdcTraderSpi   (concrete callbacks)
 */

#include "jni_utils.h"
#include "ThostFtdcTraderApi.h"
#include <string>
#include <cstring>
#include <vector>
#include <cstdint>

/* ────────────────────────────────────────────────────────────
 *  抑制 -Wdelete-non-virtual-dtor 警告
 *  CTP SDK 基类 CThostFtdcTraderSpi 是多态类但未声明 virtual 析构函数，
 *  属于 SDK 设计缺陷，我们无法修改。此处所有 delete 均通过子类指针执行，
 *  子类析构函数会被正确调用，行为安全。
 * ──────────────────────────────────────────────────────────── */
#if defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic push
    #pragma GCC diagnostic ignored "-Wdelete-non-virtual-dtor"
#elif defined(_MSC_VER)
    #pragma warning(push)
    #pragma warning(disable: 4265)  // class has virtual functions, but destructor is not virtual
#endif

/* ────────────────────────────────────────────────────────────
 *  C++ SPI 实现（转发所有回调到 Java SPI 对象）
 * ──────────────────────────────────────────────────────────── */
class JavaTraderSpiImpl : public CThostFtdcTraderSpi {
public:
    explicit JavaTraderSpiImpl(JNIEnv* env, jobject jSpi)
        : jSpi_(env->NewGlobalRef(jSpi)) {}

    ~JavaTraderSpiImpl() {
        JNIEnv* env; bool d = GetEnv(&env);
        if (env) env->DeleteGlobalRef(jSpi_);
        if (d) g_jvm->DetachCurrentThread();
    }

    /* ---- 连接/断连/心跳 ---- */
    void OnFrontConnected() override { VoidCall("OnFrontConnected", "()V"); }
    void OnFrontDisconnected(int r) override { VoidCall1I("OnFrontDisconnected", r); }
    void OnHeartBeatWarning(int t) override { VoidCall1I("OnHeartBeatWarning", t); }

    /* ---- 流控 ---- */
    void OnRspSubscribeFlowCtrlWarning(CThostFtdcSpecificTraderField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspSubscribeFlowCtrlWarning",
             "Lcom/ctpmini/struct/CThostFtdcSpecificTraderField;",
             ToJava_SpecificTrader, p, r, id, last);
    }
    void OnRspUnSubscribeFlowCtrlWarning(CThostFtdcSpecificTraderField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspUnSubscribeFlowCtrlWarning",
             "Lcom/ctpmini/struct/CThostFtdcSpecificTraderField;",
             ToJava_SpecificTrader, p, r, id, last);
    }

    /* ---- 认证/登录/登出 ---- */
    void OnRspAuthenticate(CThostFtdcRspAuthenticateField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspAuthenticate",
             "Lcom/ctpmini/struct/CThostFtdcRspAuthenticateField;",
             ToJava_RspAuthenticate, p, r, id, last);
    }
    void OnRspUserLogin(CThostFtdcRspUserLoginField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspUserLogin",
             "Lcom/ctpmini/struct/CThostFtdcRspUserLoginField;",
             ToJava_RspUserLogin, p, r, id, last);
    }
    void OnRspUserLogout(CThostFtdcUserLogoutField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspUserLogout",
             "Lcom/ctpmini/struct/CThostFtdcUserLogoutField;",
             ToJava_UserLogout, p, r, id, last);
    }

    /* ---- 报单/撤单 ---- */
    void OnRspOrderInsert(CThostFtdcInputOrderField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspOrderInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputOrderField;",
             ToJava_InputOrder, p, r, id, last);
    }
    void OnRspOrderAction(CThostFtdcInputOrderActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspOrderAction",
             "Lcom/ctpmini/struct/CThostFtdcInputOrderActionField;",
             ToJava_InputOrderAction, p, r, id, last);
    }
    void OnRspMKBatchOrderAction(CThostFtdcMKInputOrderActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspMKBatchOrderAction",
             "Lcom/ctpmini/struct/CThostFtdcMKInputOrderActionField;",
             ToJava_MKInputOrderAction, p, r, id, last);
    }

    /* ---- 执行报单 ---- */
    void OnRspExecOrderInsert(CThostFtdcInputExecOrderField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspExecOrderInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputExecOrderField;",
             ToJava_InputExecOrder, p, r, id, last);
    }
    void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspExecOrderAction",
             "Lcom/ctpmini/struct/CThostFtdcInputExecOrderActionField;",
             ToJava_InputExecOrderAction, p, r, id, last);
    }

    /* ---- 询价/报价 ---- */
    void OnRspForQuoteInsert(CThostFtdcInputForQuoteField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspForQuoteInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputForQuoteField;",
             ToJava_InputForQuote, p, r, id, last);
    }
    void OnRspQuoteInsert(CThostFtdcInputQuoteField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspQuoteInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputQuoteField;",
             ToJava_InputQuote, p, r, id, last);
    }
    void OnRspQuoteAction(CThostFtdcInputQuoteActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspQuoteAction",
             "Lcom/ctpmini/struct/CThostFtdcInputQuoteActionField;",
             ToJava_InputQuoteAction, p, r, id, last);
    }

    /* ---- 批量撤单 ---- */
    void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspBatchOrderAction",
             "Lcom/ctpmini/struct/CThostFtdcInputBatchOrderActionField;",
             ToJava_InputBatchOrderAction, p, r, id, last);
    }

    /* ---- 期权自对冲 ---- */
    void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspOptionSelfCloseInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputOptionSelfCloseField;",
             ToJava_InputOptionSelfClose, p, r, id, last);
    }
    void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspOptionSelfCloseAction",
             "Lcom/ctpmini/struct/CThostFtdcInputOptionSelfCloseActionField;",
             ToJava_InputOptionSelfCloseAction, p, r, id, last);
    }

    /* ---- 申请组合 ---- */
    void OnRspCombActionInsert(CThostFtdcInputCombActionField* p,
        CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspCombActionInsert",
             "Lcom/ctpmini/struct/CThostFtdcInputCombActionField;",
             ToJava_InputCombAction, p, r, id, last);
    }

    /* ---- 查询响应 ---- */
    void OnRspQryOrder(CThostFtdcOrderField* p, CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspQryOrder","Lcom/ctpmini/struct/CThostFtdcOrderField;",ToJava_Order,p,r,id,last); }
    void OnRspQryTrade(CThostFtdcTradeField* p, CThostFtdcRspInfoField* r, int id, bool last) override {
        Rsp4("OnRspQryTrade","Lcom/ctpmini/struct/CThostFtdcTradeField;",ToJava_Trade,p,r,id,last); }
    void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInvestorPosition","Lcom/ctpmini/struct/CThostFtdcInvestorPositionField;",ToJava_InvestorPosition,p,r,id,last); }
    void OnRspQryTradingAccount(CThostFtdcTradingAccountField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryTradingAccount","Lcom/ctpmini/struct/CThostFtdcTradingAccountField;",ToJava_TradingAccount,p,r,id,last); }
    void OnRspQryInvestor(CThostFtdcInvestorField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInvestor","Lcom/ctpmini/struct/CThostFtdcInvestorField;",ToJava_Investor,p,r,id,last); }
    void OnRspQryTradingCode(CThostFtdcTradingCodeField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryTradingCode","Lcom/ctpmini/struct/CThostFtdcTradingCodeField;",ToJava_TradingCode,p,r,id,last); }
    void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInstrumentMarginRate","Lcom/ctpmini/struct/CThostFtdcInstrumentMarginRateField;",ToJava_InstrMarginRate,p,r,id,last); }
    void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInstrumentCommissionRate","Lcom/ctpmini/struct/CThostFtdcInstrumentCommissionRateField;",ToJava_InstrCommRate,p,r,id,last); }
    void OnRspQryExchange(CThostFtdcExchangeField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryExchange","Lcom/ctpmini/struct/CThostFtdcExchangeField;",ToJava_Exchange,p,r,id,last); }
    void OnRspQryProduct(CThostFtdcProductField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryProduct","Lcom/ctpmini/struct/CThostFtdcProductField;",ToJava_Product,p,r,id,last); }
    void OnRspQryInstrument(CThostFtdcInstrumentField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInstrument","Lcom/ctpmini/struct/CThostFtdcInstrumentField;",ToJava_Instrument,p,r,id,last); }
    void OnRspQryCombInstrument(CThostFtdcCombInstrumentField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryCombInstrument","Lcom/ctpmini/struct/CThostFtdcCombInstrumentField;",ToJava_CombInstrument,p,r,id,last); }
    void OnRspQryRCAMSInvestorProdMargin(CThostFtdcRCAMSInvestorProdMarginField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryRCAMSInvestorProdMargin","Lcom/ctpmini/struct/CThostFtdcRCAMSInvestorProdMarginField;",ToJava_RCAMSProdMargin,p,r,id,last); }
    void OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryRCAMSInvestorCombPosition","Lcom/ctpmini/struct/CThostFtdcRCAMSInvestorCombPositionField;",ToJava_RCAMSCombPos,p,r,id,last); }
    void OnRspQryCombAction(CThostFtdcCombActionField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryCombAction","Lcom/ctpmini/struct/CThostFtdcCombActionField;",ToJava_CombAction,p,r,id,last); }
    void OnRspQryInvestorPositionForComb(CThostFtdcInvestorPositionForCombField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInvestorPositionForComb","Lcom/ctpmini/struct/CThostFtdcInvestorPositionForCombField;",ToJava_InvestorPosForComb,p,r,id,last); }
    void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryDepthMarketData","Lcom/ctpmini/struct/CThostFtdcDepthMarketDataField;",ToJava_DepthMarketData,p,r,id,last); }
    void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInstrumentStatus","Lcom/ctpmini/struct/CThostFtdcInstrumentStatusField;",ToJava_InstrumentStatus,p,r,id,last); }
    void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInvestorPositionDetail","Lcom/ctpmini/struct/CThostFtdcInvestorPositionDetailField;",ToJava_InvestorPosDetail,p,r,id,last); }
    void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryExchangeMarginRate","Lcom/ctpmini/struct/CThostFtdcExchangeMarginRateField;",ToJava_ExchMarginRate,p,r,id,last); }
    void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryExchangeMarginRateAdjust","Lcom/ctpmini/struct/CThostFtdcExchangeMarginRateAdjustField;",ToJava_ExchMarginRateAdj,p,r,id,last); }
    void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryOptionInstrTradeCost","Lcom/ctpmini/struct/CThostFtdcOptionInstrTradeCostField;",ToJava_OptionInstrTradeCost,p,r,id,last); }
    void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryOptionInstrCommRate","Lcom/ctpmini/struct/CThostFtdcOptionInstrCommRateField;",ToJava_OptionInstrCommRate,p,r,id,last); }
    void OnRspQryExecOrder(CThostFtdcExecOrderField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryExecOrder","Lcom/ctpmini/struct/CThostFtdcExecOrderField;",ToJava_ExecOrder,p,r,id,last); }
    void OnRspQryForQuote(CThostFtdcForQuoteField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryForQuote","Lcom/ctpmini/struct/CThostFtdcForQuoteField;",ToJava_ForQuote,p,r,id,last); }
    void OnRspQryForQuoteParam(CThostFtdcForQuoteParamField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryForQuoteParam","Lcom/ctpmini/struct/CThostFtdcForQuoteParamField;",ToJava_ForQuoteParam,p,r,id,last); }
    void OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInvestorProdSPBMDetail","Lcom/ctpmini/struct/CThostFtdcInvestorProdSPBMDetailField;",ToJava_SPBMDetail,p,r,id,last); }
    void OnRspQrySPMMInvestorCommodityGroupMargin(CThostFtdcSPMMInvestorCommodityGroupMarginField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQrySPMMInvestorCommodityGroupMargin","Lcom/ctpmini/struct/CThostFtdcSPMMInvestorCommodityGroupMarginField;",ToJava_SPMMGroupMargin,p,r,id,last); }
    void OnRspQryRULEInvestorProdMargin(CThostFtdcRULEInvestorProdMarginField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryRULEInvestorProdMargin","Lcom/ctpmini/struct/CThostFtdcRULEInvestorProdMarginField;",ToJava_RULEProdMargin,p,r,id,last); }
    void OnRspQryTraderOffer(CThostFtdcTraderOfferField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryTraderOffer","Lcom/ctpmini/struct/CThostFtdcTraderOfferField;",ToJava_TraderOffer,p,r,id,last); }
    void OnRspQryQuote(CThostFtdcQuoteField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryQuote","Lcom/ctpmini/struct/CThostFtdcQuoteField;",ToJava_Quote,p,r,id,last); }
    void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryOptionSelfClose","Lcom/ctpmini/struct/CThostFtdcOptionSelfCloseField;",ToJava_OptionSelfClose,p,r,id,last); }
    void OnRspQryControlParam(CThostFtdcControlParamField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryControlParam","Lcom/ctpmini/struct/CThostFtdcControlParamField;",ToJava_ControlParam,p,r,id,last); }
    void OnRspQryOffsetSetting(CThostFtdcOffsetSettingField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryOffsetSetting","Lcom/ctpmini/struct/CThostFtdcOffsetSettingField;",ToJava_OffsetSetting,p,r,id,last); }
    void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspQryInstrumentOrderCommRate","Lcom/ctpmini/struct/CThostFtdcInstrumentOrderCommRateField;",ToJava_InstrOrderCommRate,p,r,id,last); }

    /* ---- 错误应答 ---- */
    void OnRspError(CThostFtdcRspInfoField* rsp, int id, bool last) override {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jRsp = ToJava_RspInfo(env, rsp);
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls,"OnRspError",
            "(Lcom/ctpmini/struct/CThostFtdcRspInfoField;IZ)V");
        if (mid) env->CallVoidMethod(jSpi_, mid, jRsp, (jint)id, (jboolean)last);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }

    /* ---- 推送通知 ---- */
    void OnRtnOrder(CThostFtdcOrderField* p) override {
        Rtn1("OnRtnOrder","Lcom/ctpmini/struct/CThostFtdcOrderField;",ToJava_Order,p); }
    void OnRtnTrade(CThostFtdcTradeField* p) override {
        Rtn1("OnRtnTrade","Lcom/ctpmini/struct/CThostFtdcTradeField;",ToJava_Trade,p); }
    void OnErrRtnOrderInsert(CThostFtdcInputOrderField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnOrderInsert","Lcom/ctpmini/struct/CThostFtdcInputOrderField;",ToJava_InputOrder,p,r); }
    void OnErrRtnOrderAction(CThostFtdcOrderActionField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnOrderAction","Lcom/ctpmini/struct/CThostFtdcOrderActionField;",ToJava_OrderAction,p,r); }
    void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField* p) override {
        Rtn1("OnRtnInstrumentStatus","Lcom/ctpmini/struct/CThostFtdcInstrumentStatusField;",ToJava_InstrumentStatus,p); }
    void OnRtnExecOrder(CThostFtdcExecOrderField* p) override {
        Rtn1("OnRtnExecOrder","Lcom/ctpmini/struct/CThostFtdcExecOrderField;",ToJava_ExecOrder,p); }
    void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnExecOrderInsert","Lcom/ctpmini/struct/CThostFtdcInputExecOrderField;",ToJava_InputExecOrder,p,r); }
    void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField* p, CThostFtdcRspInfoField* r) override {
        // ExecOrderAction 只在错误通知中使用，复用 ToJava_InputExecOrderAction 近似
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jO = ToJava_ExecOrder(env, nullptr); // placeholder
        (void)jO;
        // 实际 field 类型不同，直接用原始 ToJava
        jobject jField = NewJavaObject(env,"com/ctpmini/struct/CThostFtdcExecOrderActionField");
        jobject jRsp   = ToJava_RspInfo(env, r);
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls,"OnErrRtnExecOrderAction",
            "(Lcom/ctpmini/struct/CThostFtdcExecOrderActionField;"
            "Lcom/ctpmini/struct/CThostFtdcRspInfoField;)V");
        if (mid) env->CallVoidMethod(jSpi_, mid, jField, jRsp);
        if (jField) env->DeleteLocalRef(jField);
        if (jRsp)   env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }
    void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnForQuoteInsert","Lcom/ctpmini/struct/CThostFtdcInputForQuoteField;",ToJava_InputForQuote,p,r); }
    void OnRtnQuote(CThostFtdcQuoteField* p) override {
        Rtn1("OnRtnQuote","Lcom/ctpmini/struct/CThostFtdcQuoteField;",ToJava_Quote,p); }
    void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnQuoteInsert","Lcom/ctpmini/struct/CThostFtdcInputQuoteField;",ToJava_InputQuote,p,r); }
    void OnErrRtnQuoteAction(CThostFtdcQuoteActionField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnQuoteAction","Lcom/ctpmini/struct/CThostFtdcQuoteActionField;",ToJava_QuoteAction,p,r); }
    void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField* p) override {
        Rtn1("OnRtnForQuoteRsp","Lcom/ctpmini/struct/CThostFtdcForQuoteRspField;",ToJava_ForQuoteRsp,p); }
    void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnBatchOrderAction","Lcom/ctpmini/struct/CThostFtdcBatchOrderActionField;",ToJava_BatchOrderAction,p,r); }
    void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField* p) override {
        Rtn1("OnRtnOptionSelfClose","Lcom/ctpmini/struct/CThostFtdcOptionSelfCloseField;",ToJava_OptionSelfClose,p); }
    void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnOptionSelfCloseInsert","Lcom/ctpmini/struct/CThostFtdcInputOptionSelfCloseField;",ToJava_InputOptionSelfClose,p,r); }
    void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnOptionSelfCloseAction","Lcom/ctpmini/struct/CThostFtdcOptionSelfCloseActionField;",ToJava_OptionSelfCloseAction,p,r); }
    void OnRtnCombAction(CThostFtdcCombActionField* p) override {
        Rtn1("OnRtnCombAction","Lcom/ctpmini/struct/CThostFtdcCombActionField;",ToJava_CombAction,p); }
    void OnRtnFlowCtrlWarning(CThostFtdcFlowCtrlWarningField* p) override {
        Rtn1("OnRtnFlowCtrlWarning","Lcom/ctpmini/struct/CThostFtdcFlowCtrlWarningField;",ToJava_FlowCtrlWarning,p); }
    void OnRspSubscribeFundChange(CThostFtdcRspInfoField* r, int id, bool last) override {
        RspInfo3("OnRspSubscribeFundChange", r, id, last); }
    void OnRspUnSubscribeFundChange(CThostFtdcRspInfoField* r, int id, bool last) override {
        RspInfo3("OnRspUnSubscribeFundChange", r, id, last); }
    void OnRtnFundChange(CThostFtdcTradingAccountField* p) override {
        Rtn1("OnRtnFundChange","Lcom/ctpmini/struct/CThostFtdcTradingAccountField;",ToJava_TradingAccount,p); }
    void OnRspOffsetSetting(CThostFtdcInputOffsetSettingField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspOffsetSetting","Lcom/ctpmini/struct/CThostFtdcInputOffsetSettingField;",ToJava_InputOffsetSetting,p,r,id,last); }
    void OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspCancelOffsetSetting","Lcom/ctpmini/struct/CThostFtdcInputOffsetSettingField;",ToJava_InputOffsetSetting,p,r,id,last); }
    void OnRtnOffsetSetting(CThostFtdcOffsetSettingField* p) override {
        Rtn1("OnRtnOffsetSetting","Lcom/ctpmini/struct/CThostFtdcOffsetSettingField;",ToJava_OffsetSetting,p); }
    void OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField* p, CThostFtdcRspInfoField* r) override {
        Err2("OnErrRtnCancelOffsetSetting","Lcom/ctpmini/struct/CThostFtdcCancelOffsetSettingField;",ToJava_CancelOffsetSetting,p,r); }
    void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField* p,CThostFtdcRspInfoField* r,int id,bool last) override {
        Rsp4("OnRspUserPasswordUpdate","Lcom/ctpmini/struct/CThostFtdcUserPasswordUpdateField;",ToJava_UserPasswordUpdate,p,r,id,last); }

private:
    jobject jSpi_;

    void VoidCall(const char* m, const char* sig) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls, m, sig);
        if (mid) env->CallVoidMethod(jSpi_, mid);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }
    void VoidCall1I(const char* m, int v) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls, m, "(I)V");
        if (mid) env->CallVoidMethod(jSpi_, mid, (jint)v);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }

    template<typename CS, typename Fn>
    void Rsp4(const char* m, const char* sig, Fn cvt, CS* p,
              CThostFtdcRspInfoField* r, int id, bool last) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jO  = cvt(env, p);
        jobject jRsp = ToJava_RspInfo(env, r);
        jclass cls = env->GetObjectClass(jSpi_);
        std::string s = std::string("(") + sig
            + "Lcom/ctpmini/struct/CThostFtdcRspInfoField;IZ)V";
        jmethodID mid = env->GetMethodID(cls, m, s.c_str());
        if (mid) env->CallVoidMethod(jSpi_, mid, jO, jRsp, (jint)id, (jboolean)last);
        if (jO)  env->DeleteLocalRef(jO);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }

    template<typename CS, typename Fn>
    void Rtn1(const char* m, const char* sig, Fn cvt, CS* p) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jO = cvt(env, p);
        jclass cls = env->GetObjectClass(jSpi_);
        std::string s = std::string("(") + sig + ")V";
        jmethodID mid = env->GetMethodID(cls, m, s.c_str());
        if (mid) env->CallVoidMethod(jSpi_, mid, jO);
        if (jO) env->DeleteLocalRef(jO);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }

    template<typename CS, typename Fn>
    void Err2(const char* m, const char* sig, Fn cvt, CS* p, CThostFtdcRspInfoField* r) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jO  = cvt(env, p);
        jobject jRsp = ToJava_RspInfo(env, r);
        jclass cls = env->GetObjectClass(jSpi_);
        std::string s = std::string("(") + sig
            + "Lcom/ctpmini/struct/CThostFtdcRspInfoField;)V";
        jmethodID mid = env->GetMethodID(cls, m, s.c_str());
        if (mid) env->CallVoidMethod(jSpi_, mid, jO, jRsp);
        if (jO)  env->DeleteLocalRef(jO);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }

    void RspInfo3(const char* m, CThostFtdcRspInfoField* r, int id, bool last) {
        JNIEnv* env; bool d = GetEnv(&env); if (!env) return;
        jobject jRsp = ToJava_RspInfo(env, r);
        jclass cls = env->GetObjectClass(jSpi_);
        jmethodID mid = env->GetMethodID(cls, m,
            "(Lcom/ctpmini/struct/CThostFtdcRspInfoField;IZ)V");
        if (mid) env->CallVoidMethod(jSpi_, mid, jRsp, (jint)id, (jboolean)last);
        if (jRsp) env->DeleteLocalRef(jRsp);
        env->DeleteLocalRef(cls);
        if (d) g_jvm->DetachCurrentThread();
    }
};

/* ────────────────────────────────────────────────────────────
 *  辅助：native 指针存取
 * ──────────────────────────────────────────────────────────── */
static CThostFtdcTraderApi* getTraderApi(JNIEnv* env, jobject jApi) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeHandle", "J");
    env->DeleteLocalRef(cls);
    return fid ? reinterpret_cast<CThostFtdcTraderApi*>(env->GetLongField(jApi, fid)) : nullptr;
}
static void setTraderApi(JNIEnv* env, jobject jApi, CThostFtdcTraderApi* p) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeHandle", "J");
    env->DeleteLocalRef(cls);
    if (fid) env->SetLongField(jApi, fid, (jlong)(intptr_t)p);
}
static JavaTraderSpiImpl* getTraderSpi(JNIEnv* env, jobject jApi) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeSpiHandle", "J");
    env->DeleteLocalRef(cls);
    return fid ? reinterpret_cast<JavaTraderSpiImpl*>(env->GetLongField(jApi, fid)) : nullptr;
}
static void setTraderSpi(JNIEnv* env, jobject jApi, JavaTraderSpiImpl* p) {
    jclass cls = env->GetObjectClass(jApi);
    jfieldID fid = env->GetFieldID(cls, "nativeSpiHandle", "J");
    env->DeleteLocalRef(cls);
    if (fid) env->SetLongField(jApi, fid, (jlong)(intptr_t)p);
}

/* ────────────────────────────────────────────────────────────
 *  JNI 函数
 * ──────────────────────────────────────────────────────────── */
extern "C" {

JNIEXPORT jobject JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApi_CreateFtdcTraderApi(
        JNIEnv* env, jclass /*cls*/, jstring jFlowPath)
{
    std::string fp = jstr2str(env, jFlowPath);
    CThostFtdcTraderApi* api = CThostFtdcTraderApi::CreateFtdcTraderApi(fp.c_str());
    if (!api) return nullptr;
    jobject jApi = NewJavaObject(env, "com/ctpmini/api/CThostFtdcTraderApiImpl");
    if (!jApi) { api->Release(); return nullptr; }
    setTraderApi(env, jApi, api);
    return jApi;
}

JNIEXPORT jstring JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApi_GetApiVersion(JNIEnv* env, jclass /*cls*/)
{
    return str2jstr(env, CThostFtdcTraderApi::GetApiVersion());
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_Release(JNIEnv* env, jobject jApi)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (api) { api->Release(); setTraderApi(env, jApi, nullptr); }
    JavaTraderSpiImpl* spi = getTraderSpi(env, jApi);
    if (spi) { delete spi; setTraderSpi(env, jApi, nullptr); }
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_Init(JNIEnv* env, jobject jApi, jboolean cont)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (api) api->Init((bool)cont);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_Join(JNIEnv* env, jobject jApi)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    return api ? (jint)api->Join() : -1;
}

JNIEXPORT jstring JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_GetTradingDay(JNIEnv* env, jobject jApi)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    return str2jstr(env, api ? api->GetTradingDay() : "");
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_RegisterFront(
        JNIEnv* env, jobject jApi, jstring jAddr)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (!api) return;
    std::string s = jstr2str(env, jAddr);
    char buf[256]; strncpy(buf, s.c_str(), 255); buf[255]='\0';
    api->RegisterFront(buf);
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_RegisterSpi(
        JNIEnv* env, jobject jApi, jobject jSpi)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (!api) return;
    JavaTraderSpiImpl* old = getTraderSpi(env, jApi);
    if (old) delete old;
    if (!jSpi) { api->RegisterSpi(nullptr); setTraderSpi(env, jApi, nullptr); return; }
    JavaTraderSpiImpl* spi = new JavaTraderSpiImpl(env, jSpi);
    setTraderSpi(env, jApi, spi);
    api->RegisterSpi(spi);
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_SubscribePrivateTopic(
        JNIEnv* env, jobject jApi, jint type)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (api) api->SubscribePrivateTopic((THOST_TE_RESUME_TYPE)type);
}

JNIEXPORT void JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_SubscribePublicTopic(
        JNIEnv* env, jobject jApi, jint type)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (api) api->SubscribePublicTopic((THOST_TE_RESUME_TYPE)type);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_SubscribeFlowCtrlWarning(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint n)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (!api) return -1;
    int cnt = (int)n;
    std::vector<std::string> ss(cnt); std::vector<char*> ps(cnt);
    for (int i=0;i<cnt;i++){
        jstring js=(jstring)env->GetObjectArrayElement(jArr,i);
        ss[i]=jstr2str(env,js); env->DeleteLocalRef(js);
        ps[i]=const_cast<char*>(ss[i].c_str());
    }
    return (jint)api->SubscribeFlowCtrlWarning(ps.data(), cnt);
}

JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_UnSubscribeFlowCtrlWarning(
        JNIEnv* env, jobject jApi, jobjectArray jArr, jint n)
{
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    if (!api) return -1;
    int cnt = (int)n;
    std::vector<std::string> ss(cnt); std::vector<char*> ps(cnt);
    for (int i=0;i<cnt;i++){
        jstring js=(jstring)env->GetObjectArrayElement(jArr,i);
        ss[i]=jstr2str(env,js); env->DeleteLocalRef(js);
        ps[i]=const_cast<char*>(ss[i].c_str());
    }
    return (jint)api->UnSubscribeFlowCtrlWarning(ps.data(), cnt);
}

/* ---- 认证/登录/登出 ---- */
#define REQ1(jname, cname, Struct, FromFn) \
JNIEXPORT jint JNICALL \
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_##jname( \
        JNIEnv* env, jobject jApi, jobject jF, jint id) { \
    CThostFtdcTraderApi* api = getTraderApi(env, jApi); if (!api) return -1; \
    Struct f{}; FromFn(env, jF, f); return (jint)api->cname(&f, (int)id); }

REQ1(ReqAuthenticate,      ReqAuthenticate,      CThostFtdcReqAuthenticateField,      FromJava_ReqAuthenticate)
REQ1(ReqUserLogin,         ReqUserLogin,          CThostFtdcReqUserLoginField,          FromJava_ReqUserLogin)
REQ1(ReqUserLoginEncrypt,  ReqUserLoginEncrypt,   CThostFtdcReqUserLoginField,          FromJava_ReqUserLogin)
REQ1(ReqUserLogout,        ReqUserLogout,         CThostFtdcUserLogoutField,            FromJava_UserLogout)
REQ1(ReqOrderInsert,       ReqOrderInsert,        CThostFtdcInputOrderField,            FromJava_InputOrder)
REQ1(ReqOrderAction,       ReqOrderAction,        CThostFtdcInputOrderActionField,      FromJava_InputOrderAction)
REQ1(ReqMKBatchOrderAction,ReqMKBatchOrderAction, CThostFtdcMKInputOrderActionField,    FromJava_MKInputOrderAction)
REQ1(ReqExecOrderInsert,   ReqExecOrderInsert,    CThostFtdcInputExecOrderField,        FromJava_InputExecOrder)
REQ1(ReqExecOrderAction,   ReqExecOrderAction,    CThostFtdcInputExecOrderActionField,  FromJava_InputExecOrderAction)
REQ1(ReqForQuoteInsert,    ReqForQuoteInsert,     CThostFtdcInputForQuoteField,         FromJava_InputForQuote)
REQ1(ReqQuoteInsert,       ReqQuoteInsert,        CThostFtdcInputQuoteField,            FromJava_InputQuote)
REQ1(ReqQuoteAction,       ReqQuoteAction,        CThostFtdcInputQuoteActionField,      FromJava_InputQuoteAction)
REQ1(ReqBatchOrderAction,  ReqBatchOrderAction,   CThostFtdcInputBatchOrderActionField, FromJava_InputBatchOrderAction)
REQ1(ReqOptionSelfCloseInsert, ReqOptionSelfCloseInsert, CThostFtdcInputOptionSelfCloseField, FromJava_InputOptionSelfClose)
REQ1(ReqOptionSelfCloseAction, ReqOptionSelfCloseAction, CThostFtdcInputOptionSelfCloseActionField, FromJava_InputOptionSelfCloseAction)
REQ1(ReqCombActionInsert,  ReqCombActionInsert,   CThostFtdcInputCombActionField,       FromJava_InputCombAction)
REQ1(ReqOffsetSetting,     ReqOffsetSetting,      CThostFtdcInputOffsetSettingField,    FromJava_InputOffsetSetting)
REQ1(ReqCancelOffsetSetting,ReqCancelOffsetSetting,CThostFtdcInputOffsetSettingField,   FromJava_InputOffsetSetting)
REQ1(ReqUserPasswordUpdate, ReqUserPasswordUpdate, CThostFtdcUserPasswordUpdateField,   FromJava_UserPasswordUpdate)

/* ---- 无结构体请求 ---- */
JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_ReqSubscribeFundChange(
        JNIEnv* env, jobject jApi, jint id) {
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    return api ? (jint)api->ReqSubscribeFundChange((int)id) : -1;
}
JNIEXPORT jint JNICALL
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_ReqUnSubscribeFundChange(
        JNIEnv* env, jobject jApi, jint id) {
    CThostFtdcTraderApi* api = getTraderApi(env, jApi);
    return api ? (jint)api->ReqUnSubscribeFundChange((int)id) : -1;
}

/* ---- 查询请求宏 ---- */
#define QRY1(jname, cname, Struct, FromFn) \
JNIEXPORT jint JNICALL \
Java_com_ctpmini_api_CThostFtdcTraderApiImpl_##jname( \
        JNIEnv* env, jobject jApi, jobject jF, jint id) { \
    CThostFtdcTraderApi* api = getTraderApi(env, jApi); if (!api) return -1; \
    Struct f{}; FromFn(env, jF, f); return (jint)api->cname(&f, (int)id); }

QRY1(ReqQryOrder,                  ReqQryOrder,                   CThostFtdcQryOrderField,                         FromJava_QryOrder)
QRY1(ReqQryTrade,                  ReqQryTrade,                   CThostFtdcQryTradeField,                         FromJava_QryTrade)
QRY1(ReqQryInvestorPosition,       ReqQryInvestorPosition,        CThostFtdcQryInvestorPositionField,              FromJava_QryInvestorPos)
QRY1(ReqQryTradingAccount,         ReqQryTradingAccount,          CThostFtdcQryTradingAccountField,                FromJava_QryTradingAcct)
QRY1(ReqQryInvestor,               ReqQryInvestor,                CThostFtdcQryInvestorField,                      FromJava_QryInvestor)
QRY1(ReqQryTradingCode,            ReqQryTradingCode,             CThostFtdcQryTradingCodeField,                   FromJava_QryTradingCode)
QRY1(ReqQryInstrumentMarginRate,   ReqQryInstrumentMarginRate,    CThostFtdcQryInstrumentMarginRateField,          FromJava_QryInstrMarginRate)
QRY1(ReqQryInstrumentCommissionRate,ReqQryInstrumentCommissionRate,CThostFtdcQryInstrumentCommissionRateField,     FromJava_QryInstrCommRate)
QRY1(ReqQryExchange,               ReqQryExchange,                CThostFtdcQryExchangeField,                      FromJava_QryExchange)
QRY1(ReqQryProduct,                ReqQryProduct,                 CThostFtdcQryProductField,                       FromJava_QryProduct)
QRY1(ReqQryInstrument,             ReqQryInstrument,              CThostFtdcQryInstrumentField,                    FromJava_QryInstrument)
QRY1(ReqQryCombInstrument,         ReqQryCombInstrument,          CThostFtdcQryCombInstrumentField,                FromJava_QryCombInstrument)
QRY1(ReqQryRCAMSInvestorProdMargin,ReqQryRCAMSInvestorProdMargin, CThostFtdcQryRCAMSInvestorProdMarginField,       FromJava_QryRCAMSProdMargin)
QRY1(ReqQryRCAMSInvestorCombPosition,ReqQryRCAMSInvestorCombPosition,CThostFtdcQryRCAMSInvestorCombPositionField, FromJava_QryRCAMSCombPos)
QRY1(ReqQryInvestorPositionForComb,ReqQryInvestorPositionForComb, CThostFtdcQryInvestorPositionForCombField,       FromJava_QryInvestorPosForComb)
QRY1(ReqQryCombAction,             ReqQryCombAction,              CThostFtdcQryCombActionField,                    FromJava_QryCombAction)
QRY1(ReqQryDepthMarketData,        ReqQryDepthMarketData,         CThostFtdcQryDepthMarketDataField,               FromJava_QryDepthMD)
QRY1(ReqQryOptionSelfClose,        ReqQryOptionSelfClose,         CThostFtdcQryOptionSelfCloseField,               FromJava_QryOptionSelfClose)
QRY1(ReqQryInstrumentStatus,       ReqQryInstrumentStatus,        CThostFtdcQryInstrumentStatusField,              FromJava_QryInstrStatus)
QRY1(ReqQryInvestorPositionDetail, ReqQryInvestorPositionDetail,  CThostFtdcQryInvestorPositionDetailField,        FromJava_QryInvestorPosDetail)
QRY1(ReqQryExchangeMarginRate,     ReqQryExchangeMarginRate,      CThostFtdcQryExchangeMarginRateField,            FromJava_QryExchMarginRate)
QRY1(ReqQryExchangeMarginRateAdjust,ReqQryExchangeMarginRateAdjust,CThostFtdcQryExchangeMarginRateAdjustField,    FromJava_QryExchMarginRateAdj)
QRY1(ReqQryOptionInstrTradeCost,   ReqQryOptionInstrTradeCost,    CThostFtdcQryOptionInstrTradeCostField,          FromJava_QryOptInstrTradeCost)
QRY1(ReqQryOptionInstrCommRate,    ReqQryOptionInstrCommRate,     CThostFtdcQryOptionInstrCommRateField,           FromJava_QryOptInstrCommRate)
QRY1(ReqQryExecOrder,              ReqQryExecOrder,               CThostFtdcQryExecOrderField,                     FromJava_QryExecOrder)
QRY1(ReqQryForQuote,               ReqQryForQuote,                CThostFtdcQryForQuoteField,                      FromJava_QryForQuote)
QRY1(ReqQryQuote,                  ReqQryQuote,                   CThostFtdcQryQuoteField,                         FromJava_QryQuote)
QRY1(ReqQryInstrumentOrderCommRate,ReqQryInstrumentOrderCommRate, CThostFtdcQryInstrumentOrderCommRateField,       FromJava_QryInstrOrderCommRate)
QRY1(ReqQryForQuoteParam,          ReqQryForQuoteParam,           CThostFtdcQryForQuoteParamField,                 FromJava_QryForQuoteParam)
QRY1(ReqQryTraderOffer,            ReqQryTraderOffer,             CThostFtdcQryTraderOfferField,                   FromJava_QryTraderOffer)
QRY1(ReqQryInvestorProdSPBMDetail, ReqQryInvestorProdSPBMDetail,  CThostFtdcQryInvestorProdSPBMDetailField,        FromJava_QrySPBMDetail)
QRY1(ReqQrySPMMInvestorCommodityGroupMargin,ReqQrySPMMInvestorCommodityGroupMargin,CThostFtdcQrySPMMInvestorCommodityGroupMarginField,FromJava_QrySPMMGroupMargin)
QRY1(ReqQryRULEInvestorProdMargin, ReqQryRULEInvestorProdMargin,  CThostFtdcQryRULEInvestorProdMarginField,        FromJava_QryRULEProdMargin)
QRY1(ReqQryControlParam,           ReqQryControlParam,            CThostFtdcQryControlParamField,                  FromJava_QryControlParam)
QRY1(ReqQryOffsetSetting,          ReqQryOffsetSetting,           CThostFtdcQryOffsetSettingField,                 FromJava_QryOffsetSetting)

} // extern "C"

#if defined(__GNUC__) || defined(__clang__)
    #pragma GCC diagnostic pop
#elif defined(_MSC_VER)
    #pragma warning(pop)
#endif
