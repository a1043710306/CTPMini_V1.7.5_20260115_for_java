package com.ctpmini.api;

import com.ctpmini.struct.*;

/**
 * 交易回调接口（SPI）
 * 对应 C++ 类: CThostFtdcTraderSpi
 *
 * 用户需继承此类并重写感兴趣的回调方法。
 * 所有方法均提供空实现，可按需选择性覆盖。
 */
public class CThostFtdcTraderSpi {

    // ===== 连接/断连/心跳 =====

    /**
     * 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
     */
    public void OnFrontConnected() {}

    /**
     * 当客户端与交易后台通信连接断开时，该方法被调用。
     *
     * @param nReason 错误原因
     *                -3  关闭连接
     *                -4  网络读失败
     *                -5  网络写失败
     *                -6  订阅流水号错误
     *                -7  流序号错误
     *                -8  错误的心跳报文
     *                -9  收到错误报文长度
     */
    public void OnFrontDisconnected(int nReason) {}

    /**
     * 心跳超时警告
     *
     * @param nTimeLapse 距上次接收报文的时间
     */
    public void OnHeartBeatWarning(int nTimeLapse) {}

    // ===== 订阅流控 =====

    /**
     * 订阅席位流控警告响应
     */
    public void OnRspSubscribeFlowCtrlWarning(CThostFtdcSpecificTraderField pRspSubscribeTraderField,
                                               CThostFtdcRspInfoField pRspInfo,
                                               int nRequestID, boolean bIsLast) {}

    /**
     * 取消订阅席位流控警告响应
     */
    public void OnRspUnSubscribeFlowCtrlWarning(CThostFtdcSpecificTraderField pRspSubscribeTraderField,
                                                 CThostFtdcRspInfoField pRspInfo,
                                                 int nRequestID, boolean bIsLast) {}

    // ===== 认证/登录/登出 =====

    /**
     * 客户端认证响应
     */
    public void OnRspAuthenticate(CThostFtdcRspAuthenticateField pRspAuthenticateField,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {}

    /**
     * 登录请求响应
     */
    public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                               CThostFtdcRspInfoField pRspInfo,
                               int nRequestID, boolean bIsLast) {}

    /**
     * 登出请求响应
     */
    public void OnRspUserLogout(CThostFtdcUserLogoutField pUserLogout,
                                CThostFtdcRspInfoField pRspInfo,
                                int nRequestID, boolean bIsLast) {}

    // ===== 报单/撤单 =====

    /**
     * 报单录入请求响应（被拒绝时触发）
     */
    public void OnRspOrderInsert(CThostFtdcInputOrderField pInputOrder,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 报单操作请求响应（被拒绝时触发）
     */
    public void OnRspOrderAction(CThostFtdcInputOrderActionField pInputOrderAction,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 做市商批量撤单操作响应
     */
    public void OnRspMKBatchOrderAction(CThostFtdcMKInputOrderActionField pMKInputOrderAction,
                                        CThostFtdcRspInfoField pRspInfo,
                                        int nRequestID, boolean bIsLast) {}

    // ===== 执行报单 =====

    /**
     * 执行报单录入请求响应
     */
    public void OnRspExecOrderInsert(CThostFtdcInputExecOrderField pInputExecOrder,
                                     CThostFtdcRspInfoField pRspInfo,
                                     int nRequestID, boolean bIsLast) {}

    /**
     * 执行报单操作请求响应
     */
    public void OnRspExecOrderAction(CThostFtdcInputExecOrderActionField pInputExecOrderAction,
                                     CThostFtdcRspInfoField pRspInfo,
                                     int nRequestID, boolean bIsLast) {}

    // ===== 询价/报价 =====

    /**
     * 询价录入请求响应
     */
    public void OnRspForQuoteInsert(CThostFtdcInputForQuoteField pInputForQuote,
                                    CThostFtdcRspInfoField pRspInfo,
                                    int nRequestID, boolean bIsLast) {}

    /**
     * 报价录入请求响应
     */
    public void OnRspQuoteInsert(CThostFtdcInputQuoteField pInputQuote,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 报价操作请求响应
     */
    public void OnRspQuoteAction(CThostFtdcInputQuoteActionField pInputQuoteAction,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    // ===== 批量报单操作 =====

    /**
     * 批量报单操作请求响应
     */
    public void OnRspBatchOrderAction(CThostFtdcInputBatchOrderActionField pInputBatchOrderAction,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {}

    // ===== 期权自对冲 =====

    /**
     * 期权自对冲录入请求响应
     */
    public void OnRspOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField pInputOptionSelfClose,
                                            CThostFtdcRspInfoField pRspInfo,
                                            int nRequestID, boolean bIsLast) {}

    /**
     * 期权自对冲操作请求响应
     */
    public void OnRspOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField pInputOptionSelfCloseAction,
                                            CThostFtdcRspInfoField pRspInfo,
                                            int nRequestID, boolean bIsLast) {}

    // ===== 申请组合 =====

    /**
     * 申请组合录入请求响应
     */
    public void OnRspCombActionInsert(CThostFtdcInputCombActionField pInputCombAction,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {}

    // ===== 查询响应 =====

    /**
     * 请求查询报单响应
     */
    public void OnRspQryOrder(CThostFtdcOrderField pOrder,
                              CThostFtdcRspInfoField pRspInfo,
                              int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询成交响应
     */
    public void OnRspQryTrade(CThostFtdcTradeField pTrade,
                              CThostFtdcRspInfoField pRspInfo,
                              int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者持仓响应
     */
    public void OnRspQryInvestorPosition(CThostFtdcInvestorPositionField pInvestorPosition,
                                         CThostFtdcRspInfoField pRspInfo,
                                         int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询资金账户响应
     */
    public void OnRspQryTradingAccount(CThostFtdcTradingAccountField pTradingAccount,
                                       CThostFtdcRspInfoField pRspInfo,
                                       int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者响应
     */
    public void OnRspQryInvestor(CThostFtdcInvestorField pInvestor,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易编码响应
     */
    public void OnRspQryTradingCode(CThostFtdcTradingCodeField pTradingCode,
                                    CThostFtdcRspInfoField pRspInfo,
                                    int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询合约保证金率响应
     */
    public void OnRspQryInstrumentMarginRate(CThostFtdcInstrumentMarginRateField pInstrumentMarginRate,
                                              CThostFtdcRspInfoField pRspInfo,
                                              int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询合约手续费率响应
     */
    public void OnRspQryInstrumentCommissionRate(CThostFtdcInstrumentCommissionRateField pInstrumentCommissionRate,
                                                  CThostFtdcRspInfoField pRspInfo,
                                                  int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易所响应
     */
    public void OnRspQryExchange(CThostFtdcExchangeField pExchange,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询产品响应
     */
    public void OnRspQryProduct(CThostFtdcProductField pProduct,
                                CThostFtdcRspInfoField pRspInfo,
                                int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询合约响应
     */
    public void OnRspQryInstrument(CThostFtdcInstrumentField pInstrument,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询组合合约响应
     */
    public void OnRspQryCombInstrument(CThostFtdcCombInstrumentField pCombInstrument,
                                        CThostFtdcRspInfoField pRspInfo,
                                        int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者RCAMS合并保证金响应
     */
    public void OnRspQryRCAMSInvestorProdMargin(CThostFtdcRCAMSInvestorProdMarginField pRCAMSInvestorProdMargin,
                                                  CThostFtdcRspInfoField pRspInfo,
                                                  int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询RCAMS投资者组合持仓响应
     */
    public void OnRspQryRCAMSInvestorCombPosition(CThostFtdcRCAMSInvestorCombPositionField pRCAMSInvestorCombPosition,
                                                    CThostFtdcRspInfoField pRspInfo,
                                                    int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询申请组合响应
     */
    public void OnRspQryCombAction(CThostFtdcCombActionField pCombAction,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询用于组合还原的持仓响应
     */
    public void OnRspQryInvestorPositionForComb(CThostFtdcInvestorPositionForCombField pForComb,
                                                 CThostFtdcRspInfoField pRspInfo,
                                                 int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询行情响应
     */
    public void OnRspQryDepthMarketData(CThostFtdcDepthMarketDataField pDepthMarketData,
                                        CThostFtdcRspInfoField pRspInfo,
                                        int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询合约状态响应
     */
    public void OnRspQryInstrumentStatus(CThostFtdcInstrumentStatusField pInstrumentStatus,
                                          CThostFtdcRspInfoField pRspInfo,
                                          int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者持仓明细响应
     */
    public void OnRspQryInvestorPositionDetail(CThostFtdcInvestorPositionDetailField pInvestorPositionDetail,
                                                CThostFtdcRspInfoField pRspInfo,
                                                int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易所保证金率响应
     */
    public void OnRspQryExchangeMarginRate(CThostFtdcExchangeMarginRateField pExchangeMarginRate,
                                            CThostFtdcRspInfoField pRspInfo,
                                            int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易所调整后保证金率响应
     */
    public void OnRspQryExchangeMarginRateAdjust(CThostFtdcExchangeMarginRateAdjustField pExchangeMarginRateAdjust,
                                                   CThostFtdcRspInfoField pRspInfo,
                                                   int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询期权合约交易成本响应
     */
    public void OnRspQryOptionInstrTradeCost(CThostFtdcOptionInstrTradeCostField pOptionInstrTradeCost,
                                              CThostFtdcRspInfoField pRspInfo,
                                              int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询期权合约手续费响应
     */
    public void OnRspQryOptionInstrCommRate(CThostFtdcOptionInstrCommRateField pOptionInstrCommRate,
                                             CThostFtdcRspInfoField pRspInfo,
                                             int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询执行报单响应
     */
    public void OnRspQryExecOrder(CThostFtdcExecOrderField pExecOrder,
                                  CThostFtdcRspInfoField pRspInfo,
                                  int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询询价响应
     */
    public void OnRspQryForQuote(CThostFtdcForQuoteField pForQuote,
                                 CThostFtdcRspInfoField pRspInfo,
                                 int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询询价价格参数响应
     */
    public void OnRspQryForQuoteParam(CThostFtdcForQuoteParamField pForQuoteParam,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者SPBM产品组保证金明细响应
     */
    public void OnRspQryInvestorProdSPBMDetail(CThostFtdcInvestorProdSPBMDetailField pInvestorProdSPBMDetail,
                                                CThostFtdcRspInfoField pRspInfo,
                                                int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者SPMM商品群保证金明细响应
     */
    public void OnRspQrySPMMInvestorCommodityGroupMargin(CThostFtdcSPMMInvestorCommodityGroupMarginField pSPMMInvestorCommodityGroupMargin,
                                                           CThostFtdcRspInfoField pRspInfo,
                                                           int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询投资者RULE保证金响应
     */
    public void OnRspQryRULEInvestorProdMargin(CThostFtdcRULEInvestorProdMarginField pRULEInvestorProdMargin,
                                                CThostFtdcRspInfoField pRspInfo,
                                                int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易员报盘响应
     */
    public void OnRspQryTraderOffer(CThostFtdcTraderOfferField pTraderOffer,
                                    CThostFtdcRspInfoField pRspInfo,
                                    int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询报价响应
     */
    public void OnRspQryQuote(CThostFtdcQuoteField pQuote,
                              CThostFtdcRspInfoField pRspInfo,
                              int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询期权自对冲响应
     */
    public void OnRspQryOptionSelfClose(CThostFtdcOptionSelfCloseField pOptionSelfClose,
                                        CThostFtdcRspInfoField pRspInfo,
                                        int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询交易控制参数响应
     */
    public void OnRspQryControlParam(CThostFtdcControlParamField pControlParam,
                                     CThostFtdcRspInfoField pRspInfo,
                                     int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询对冲参数响应
     */
    public void OnRspQryOffsetSetting(CThostFtdcOffsetSettingField pOffsetSetting,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {}

    /**
     * 请求查询报单手续费响应
     */
    public void OnRspQryInstrumentOrderCommRate(CThostFtdcInstrumentOrderCommRateField pInstrumentOrderCommRate,
                                                 CThostFtdcRspInfoField pRspInfo,
                                                 int nRequestID, boolean bIsLast) {}

    /**
     * 错误应答
     */
    public void OnRspError(CThostFtdcRspInfoField pRspInfo,
                           int nRequestID, boolean bIsLast) {}

    // ===== 推送通知 =====

    /**
     * 报单通知（报单状态变化时推送）
     */
    public void OnRtnOrder(CThostFtdcOrderField pOrder) {}

    /**
     * 成交通知
     */
    public void OnRtnTrade(CThostFtdcTradeField pTrade) {}

    /**
     * 报单录入错误回报
     */
    public void OnErrRtnOrderInsert(CThostFtdcInputOrderField pInputOrder,
                                    CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 报单操作错误回报
     */
    public void OnErrRtnOrderAction(CThostFtdcOrderActionField pOrderAction,
                                    CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 合约交易状态通知
     */
    public void OnRtnInstrumentStatus(CThostFtdcInstrumentStatusField pInstrumentStatus) {}

    /**
     * 执行报单通知
     */
    public void OnRtnExecOrder(CThostFtdcExecOrderField pExecOrder) {}

    /**
     * 执行报单录入错误回报
     */
    public void OnErrRtnExecOrderInsert(CThostFtdcInputExecOrderField pInputExecOrder,
                                        CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 执行报单操作错误回报
     */
    public void OnErrRtnExecOrderAction(CThostFtdcExecOrderActionField pExecOrderAction,
                                        CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 询价录入错误回报
     */
    public void OnErrRtnForQuoteInsert(CThostFtdcInputForQuoteField pInputForQuote,
                                       CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 报价通知
     */
    public void OnRtnQuote(CThostFtdcQuoteField pQuote) {}

    /**
     * 报价录入错误回报
     */
    public void OnErrRtnQuoteInsert(CThostFtdcInputQuoteField pInputQuote,
                                    CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 报价操作错误回报
     */
    public void OnErrRtnQuoteAction(CThostFtdcQuoteActionField pQuoteAction,
                                    CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 询价通知
     */
    public void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField pForQuoteRsp) {}

    /**
     * 批量报单操作错误回报
     */
    public void OnErrRtnBatchOrderAction(CThostFtdcBatchOrderActionField pBatchOrderAction,
                                         CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 期权自对冲通知
     */
    public void OnRtnOptionSelfClose(CThostFtdcOptionSelfCloseField pOptionSelfClose) {}

    /**
     * 期权自对冲录入错误回报
     */
    public void OnErrRtnOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField pInputOptionSelfClose,
                                               CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 期权自对冲操作错误回报
     */
    public void OnErrRtnOptionSelfCloseAction(CThostFtdcOptionSelfCloseActionField pOptionSelfCloseAction,
                                               CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 申请组合通知
     */
    public void OnRtnCombAction(CThostFtdcCombActionField pCombAction) {}

    /**
     * 席位流控警告通知
     */
    public void OnRtnFlowCtrlWarning(CThostFtdcFlowCtrlWarningField pFlowCtrlWarning) {}

    /**
     * 订阅资金变动响应
     */
    public void OnRspSubscribeFundChange(CThostFtdcRspInfoField pRspInfo,
                                         int nRequestID, boolean bIsLast) {}

    /**
     * 取消订阅资金变动响应
     */
    public void OnRspUnSubscribeFundChange(CThostFtdcRspInfoField pRspInfo,
                                           int nRequestID, boolean bIsLast) {}

    /**
     * 资金变动通知
     */
    public void OnRtnFundChange(CThostFtdcTradingAccountField pTradingAccount) {}

    /**
     * 对冲参数设置响应
     */
    public void OnRspOffsetSetting(CThostFtdcInputOffsetSettingField pInputOffsetSetting,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {}

    /**
     * 撤销对冲参数设置响应
     */
    public void OnRspCancelOffsetSetting(CThostFtdcInputOffsetSettingField pInputOffsetSetting,
                                          CThostFtdcRspInfoField pRspInfo,
                                          int nRequestID, boolean bIsLast) {}

    /**
     * 对冲参数通知
     */
    public void OnRtnOffsetSetting(CThostFtdcOffsetSettingField pOffsetSetting) {}

    /**
     * 撤销对冲参数错误回报
     */
    public void OnErrRtnCancelOffsetSetting(CThostFtdcCancelOffsetSettingField pCancelOffsetSetting,
                                             CThostFtdcRspInfoField pRspInfo) {}

    /**
     * 用户口令更新请求响应
     */
    public void OnRspUserPasswordUpdate(CThostFtdcUserPasswordUpdateField pUserPasswordUpdate,
                                        CThostFtdcRspInfoField pRspInfo,
                                        int nRequestID, boolean bIsLast) {}
}
