package com.ctpmini.api;

import com.ctpmini.struct.*;
import com.ctpmini.constants.ThostFtdcUserApiDataType;

/**
 * 交易API接口
 * 对应 C++ 类: CThostFtdcTraderApi
 *
 * 典型使用流程：
 * <pre>
 * CThostFtdcTraderApi traderApi = CThostFtdcTraderApi.CreateFtdcTraderApi("./flow/");
 * traderApi.RegisterSpi(mySpi);
 * traderApi.SubscribePrivateTopic(ThostFtdcUserApiDataType.THOST_TERT_QUICK);
 * traderApi.SubscribePublicTopic(ThostFtdcUserApiDataType.THOST_TERT_QUICK);
 * traderApi.RegisterFront("tcp://127.0.0.1:17001");
 * traderApi.Init();
 * // 等待 OnFrontConnected 后，进行认证和登录
 * </pre>
 *
 * 注意：本类为Java接口层定义，实际调用需通过JNI加载 libthosttraderapi.so 本地库实现。
 */
public abstract class CThostFtdcTraderApi {

    /**
     * 创建TraderApi实例（工厂方法，需要JNI实现）
     *
     * @param pszFlowPath 存储订阅信息文件的目录，默认为当前目录
     * @return TraderApi实例
     */
    public static native CThostFtdcTraderApi CreateFtdcTraderApi(String pszFlowPath);

    /**
     * 获取API版本信息
     *
     * @return 版本号字符串
     */
    public static native String GetApiVersion();

    /**
     * 删除接口对象本身（释放资源）
     */
    public abstract void Release();

    /**
     * 初始化
     *
     * @param bContinuous true=线程不中断，false=单次运行
     */
    public abstract void Init(boolean bContinuous);

    /**
     * 初始化（使用默认参数）
     */
    public void Init() {
        Init(false);
    }

    /**
     * 等待接口线程结束运行
     *
     * @return 线程退出代码
     */
    public abstract int Join();

    /**
     * 获取当前交易日
     *
     * @return 交易日字符串 (yyyyMMdd)，只有登录成功后才能获取正确的交易日
     */
    public abstract String GetTradingDay();

    /**
     * 注册前置机网络地址
     *
     * @param pszFrontAddress 前置机网络地址，格式: "tcp://ip:port"
     */
    public abstract void RegisterFront(String pszFrontAddress);

    /**
     * 注册回调接口（SPI）
     *
     * @param pSpi 派生自回调接口类的实例
     */
    public abstract void RegisterSpi(CThostFtdcTraderSpi pSpi);

    /**
     * 订阅私有流
     *
     * @param nResumeType 私有流重传方式
     *                    THOST_TERT_RESTART: 从本地记录的序号开始重传
     *                    THOST_TERT_RESUME:  从上次收到的续传
     *                    THOST_TERT_QUICK:   只传送登录后私有流的内容
     */
    public abstract void SubscribePrivateTopic(int nResumeType);

    /**
     * 订阅公共流
     *
     * @param nResumeType 公共流重传方式
     *                    THOST_TERT_RESTART: 从本地记录的序号开始重传
     *                    THOST_TERT_RESUME:  从上次收到的续传
     *                    THOST_TERT_QUICK:   只传送登录后公共流的内容
     */
    public abstract void SubscribePublicTopic(int nResumeType);

    /**
     * 订阅交易员席位流控警告（需在登录成功之后调用）
     *
     * @param ppTraderID 交易员ID数组
     * @param nCount     数量
     * @return 0=成功，非0=失败
     */
    public abstract int SubscribeFlowCtrlWarning(String[] ppTraderID, int nCount);

    /**
     * 取消订阅交易员席位流控警告
     *
     * @param ppTraderID 交易员ID数组
     * @param nCount     数量
     * @return 0=成功，非0=失败
     */
    public abstract int UnSubscribeFlowCtrlWarning(String[] ppTraderID, int nCount);

    // ===== 认证/登录/登出 =====

    /**
     * 客户端认证请求
     *
     * @param pReqAuthenticateField 认证请求域
     * @param nRequestID            请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqAuthenticate(CThostFtdcReqAuthenticateField pReqAuthenticateField, int nRequestID);

    /**
     * 用户登录请求
     *
     * @param pReqUserLoginField 登录请求域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLogin(CThostFtdcReqUserLoginField pReqUserLoginField, int nRequestID);

    /**
     * 用户加密登录请求
     *
     * @param pReqUserLoginField 登录请求域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLoginEncrypt(CThostFtdcReqUserLoginField pReqUserLoginField, int nRequestID);

    /**
     * 登出请求
     *
     * @param pUserLogout 登出请求域
     * @param nRequestID  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLogout(CThostFtdcUserLogoutField pUserLogout, int nRequestID);

    // ===== 报单/撤单 =====

    /**
     * 报单录入请求
     *
     * @param pInputOrder 录入报单域
     * @param nRequestID  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqOrderInsert(CThostFtdcInputOrderField pInputOrder, int nRequestID);

    /**
     * 报单操作请求（撤单/改单）
     *
     * @param pInputOrderAction 报单操作域
     * @param nRequestID        请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqOrderAction(CThostFtdcInputOrderActionField pInputOrderAction, int nRequestID);

    /**
     * 做市商批量撤单请求
     *
     * @param pMKInputOrderAction 做市商批量撤单域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqMKBatchOrderAction(CThostFtdcMKInputOrderActionField pMKInputOrderAction, int nRequestID);

    // ===== 执行报单 =====

    /**
     * 执行报单录入请求
     *
     * @param pInputExecOrder 录入执行报单域
     * @param nRequestID      请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqExecOrderInsert(CThostFtdcInputExecOrderField pInputExecOrder, int nRequestID);

    /**
     * 执行报单操作请求
     *
     * @param pInputExecOrderAction 执行报单操作域
     * @param nRequestID            请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqExecOrderAction(CThostFtdcInputExecOrderActionField pInputExecOrderAction, int nRequestID);

    // ===== 询价/报价 =====

    /**
     * 询价录入请求
     *
     * @param pInputForQuote 录入询价域
     * @param nRequestID     请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqForQuoteInsert(CThostFtdcInputForQuoteField pInputForQuote, int nRequestID);

    /**
     * 报价录入请求
     *
     * @param pInputQuote 录入报价域
     * @param nRequestID  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQuoteInsert(CThostFtdcInputQuoteField pInputQuote, int nRequestID);

    /**
     * 报价操作请求
     *
     * @param pInputQuoteAction 报价操作域
     * @param nRequestID        请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQuoteAction(CThostFtdcInputQuoteActionField pInputQuoteAction, int nRequestID);

    // ===== 批量报单操作 =====

    /**
     * 批量报单操作请求
     *
     * @param pInputBatchOrderAction 批量报单操作域
     * @param nRequestID             请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqBatchOrderAction(CThostFtdcInputBatchOrderActionField pInputBatchOrderAction, int nRequestID);

    // ===== 期权自对冲 =====

    /**
     * 期权自对冲录入请求
     *
     * @param pInputOptionSelfClose 录入期权自对冲域
     * @param nRequestID            请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqOptionSelfCloseInsert(CThostFtdcInputOptionSelfCloseField pInputOptionSelfClose, int nRequestID);

    /**
     * 期权自对冲操作请求
     *
     * @param pInputOptionSelfCloseAction 期权自对冲操作域
     * @param nRequestID                  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqOptionSelfCloseAction(CThostFtdcInputOptionSelfCloseActionField pInputOptionSelfCloseAction, int nRequestID);

    // ===== 申请组合 =====

    /**
     * 申请组合录入请求
     *
     * @param pInputCombAction 录入申请组合域
     * @param nRequestID       请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqCombActionInsert(CThostFtdcInputCombActionField pInputCombAction, int nRequestID);

    // ===== 资金变动订阅 =====

    /**
     * 订阅资金变动
     *
     * @param nRequestID 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqSubscribeFundChange(int nRequestID);

    /**
     * 取消订阅资金变动
     *
     * @param nRequestID 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUnSubscribeFundChange(int nRequestID);

    // ===== 对冲参数 =====

    /**
     * 对冲参数设置
     *
     * @param pInputOffsetSetting 录入对冲参数域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqOffsetSetting(CThostFtdcInputOffsetSettingField pInputOffsetSetting, int nRequestID);

    /**
     * 撤销对冲参数设置
     *
     * @param pInputOffsetSetting 录入对冲参数域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqCancelOffsetSetting(CThostFtdcInputOffsetSettingField pInputOffsetSetting, int nRequestID);

    // ===== 查询请求 =====

    /**
     * 请求查询报单
     *
     * @param pQryOrder  查询报单域
     * @param nRequestID 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryOrder(CThostFtdcQryOrderField pQryOrder, int nRequestID);

    /**
     * 请求查询成交
     *
     * @param pQryTrade  查询成交域
     * @param nRequestID 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryTrade(CThostFtdcQryTradeField pQryTrade, int nRequestID);

    /**
     * 请求查询投资者持仓
     *
     * @param pQryInvestorPosition 查询投资者持仓域
     * @param nRequestID           请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInvestorPosition(CThostFtdcQryInvestorPositionField pQryInvestorPosition, int nRequestID);

    /**
     * 请求查询资金账户
     *
     * @param pQryTradingAccount 查询资金账户域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryTradingAccount(CThostFtdcQryTradingAccountField pQryTradingAccount, int nRequestID);

    /**
     * 请求查询投资者
     *
     * @param pQryInvestor 查询投资者域
     * @param nRequestID   请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInvestor(CThostFtdcQryInvestorField pQryInvestor, int nRequestID);

    /**
     * 请求查询交易编码
     *
     * @param pQryTradingCode 查询交易编码域
     * @param nRequestID      请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryTradingCode(CThostFtdcQryTradingCodeField pQryTradingCode, int nRequestID);

    /**
     * 请求查询合约保证金率
     *
     * @param pQryInstrumentMarginRate 查询合约保证金率域
     * @param nRequestID               请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInstrumentMarginRate(CThostFtdcQryInstrumentMarginRateField pQryInstrumentMarginRate, int nRequestID);

    /**
     * 请求查询合约手续费率
     *
     * @param pQryInstrumentCommissionRate 查询合约手续费率域
     * @param nRequestID                   请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInstrumentCommissionRate(CThostFtdcQryInstrumentCommissionRateField pQryInstrumentCommissionRate, int nRequestID);

    /**
     * 请求查询交易所
     *
     * @param pQryExchange 查询交易所域
     * @param nRequestID   请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryExchange(CThostFtdcQryExchangeField pQryExchange, int nRequestID);

    /**
     * 请求查询产品
     *
     * @param pQryProduct 查询产品域
     * @param nRequestID  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryProduct(CThostFtdcQryProductField pQryProduct, int nRequestID);

    /**
     * 请求查询合约
     *
     * @param pQryInstrument 查询合约域
     * @param nRequestID     请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInstrument(CThostFtdcQryInstrumentField pQryInstrument, int nRequestID);

    /**
     * 请求查询组合合约
     *
     * @param pQryCombInstrument 查询组合合约域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryCombInstrument(CThostFtdcQryCombInstrumentField pQryCombInstrument, int nRequestID);

    /**
     * 查询投资者RCAMS合并保证金
     *
     * @param pQryRCAMSInvestorProdMargin 查询域
     * @param nRequestID                  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryRCAMSInvestorProdMargin(CThostFtdcQryRCAMSInvestorProdMarginField pQryRCAMSInvestorProdMargin, int nRequestID);

    /**
     * 查询RCAMS投资者组合持仓
     *
     * @param pQryRCAMSInvestorCombPosition 查询域
     * @param nRequestID                    请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryRCAMSInvestorCombPosition(CThostFtdcQryRCAMSInvestorCombPositionField pQryRCAMSInvestorCombPosition, int nRequestID);

    /**
     * 请求查询用于组合还原的持仓
     *
     * @param pQryIPForComb 查询域
     * @param nRequestID    请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInvestorPositionForComb(CThostFtdcQryInvestorPositionForCombField pQryIPForComb, int nRequestID);

    /**
     * 请求查询申请组合
     *
     * @param pQryCombAction 查询域
     * @param nRequestID     请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryCombAction(CThostFtdcQryCombActionField pQryCombAction, int nRequestID);

    /**
     * 请求查询行情
     *
     * @param pQryDepthMarketData 查询行情域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryDepthMarketData(CThostFtdcQryDepthMarketDataField pQryDepthMarketData, int nRequestID);

    /**
     * 请求查询期权自对冲
     *
     * @param pQryOptionSelfClose 查询期权自对冲域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryOptionSelfClose(CThostFtdcQryOptionSelfCloseField pQryOptionSelfClose, int nRequestID);

    /**
     * 请求查询合约状态
     *
     * @param pQryInstrumentStatus 查询合约状态域
     * @param nRequestID           请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInstrumentStatus(CThostFtdcQryInstrumentStatusField pQryInstrumentStatus, int nRequestID);

    /**
     * 请求查询投资者持仓明细
     *
     * @param pQryInvestorPositionDetail 查询持仓明细域
     * @param nRequestID                 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInvestorPositionDetail(CThostFtdcQryInvestorPositionDetailField pQryInvestorPositionDetail, int nRequestID);

    /**
     * 请求查询交易所保证金率
     *
     * @param pQryExchangeMarginRate 查询域
     * @param nRequestID             请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryExchangeMarginRate(CThostFtdcQryExchangeMarginRateField pQryExchangeMarginRate, int nRequestID);

    /**
     * 请求查询交易所调整后保证金率
     *
     * @param pQryExchangeMarginRateAdjust 查询域
     * @param nRequestID                   请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryExchangeMarginRateAdjust(CThostFtdcQryExchangeMarginRateAdjustField pQryExchangeMarginRateAdjust, int nRequestID);

    /**
     * 请求查询期权合约交易成本
     *
     * @param pQryOptionInstrTradeCost 查询期权合约交易成本域
     * @param nRequestID               请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryOptionInstrTradeCost(CThostFtdcQryOptionInstrTradeCostField pQryOptionInstrTradeCost, int nRequestID);

    /**
     * 请求查询期权合约手续费
     *
     * @param pQryOptionInstrCommRate 查询期权合约手续费域
     * @param nRequestID              请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryOptionInstrCommRate(CThostFtdcQryOptionInstrCommRateField pQryOptionInstrCommRate, int nRequestID);

    /**
     * 请求查询执行报单
     *
     * @param pQryExecOrder 查询执行报单域
     * @param nRequestID    请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryExecOrder(CThostFtdcQryExecOrderField pQryExecOrder, int nRequestID);

    /**
     * 请求查询询价
     *
     * @param pQryForQuote 查询询价域
     * @param nRequestID   请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryForQuote(CThostFtdcQryForQuoteField pQryForQuote, int nRequestID);

    /**
     * 请求查询报价
     *
     * @param pQryQuote  查询报价域
     * @param nRequestID 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryQuote(CThostFtdcQryQuoteField pQryQuote, int nRequestID);

    /**
     * 请求查询报单手续费
     *
     * @param pQryInstrumentOrderCommRate 查询域
     * @param nRequestID                  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInstrumentOrderCommRate(CThostFtdcQryInstrumentOrderCommRateField pQryInstrumentOrderCommRate, int nRequestID);

    /**
     * 请求查询询价价格参数
     *
     * @param pQryForQuoteParam 查询域
     * @param nRequestID        请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryForQuoteParam(CThostFtdcQryForQuoteParamField pQryForQuoteParam, int nRequestID);

    /**
     * 请求查询交易员报盘
     *
     * @param pQryTraderOffer 查询交易员报盘域
     * @param nRequestID      请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryTraderOffer(CThostFtdcQryTraderOfferField pQryTraderOffer, int nRequestID);

    /**
     * 请求查询投资者SPBM产品组保证金明细
     *
     * @param pQryInvestorProdSPBMDetail 查询域
     * @param nRequestID                 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryInvestorProdSPBMDetail(CThostFtdcQryInvestorProdSPBMDetailField pQryInvestorProdSPBMDetail, int nRequestID);

    /**
     * 请求查询投资者SPMM商品群保证金明细
     *
     * @param pQrySPMMInvestorCommodityGroupMargin 查询域
     * @param nRequestID                           请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQrySPMMInvestorCommodityGroupMargin(CThostFtdcQrySPMMInvestorCommodityGroupMarginField pQrySPMMInvestorCommodityGroupMargin, int nRequestID);

    /**
     * 请求查询投资者RULE保证金明细
     *
     * @param pQryRULEInvestorProdMargin 查询域
     * @param nRequestID                 请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryRULEInvestorProdMargin(CThostFtdcQryRULEInvestorProdMarginField pQryRULEInvestorProdMargin, int nRequestID);

    /**
     * 请求查询系统功能控制参数
     *
     * @param pQryControlParam 查询控制参数域
     * @param nRequestID       请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryControlParam(CThostFtdcQryControlParamField pQryControlParam, int nRequestID);

    /**
     * 请求查询对冲参数
     *
     * @param pQryOffsetSetting 查询域
     * @param nRequestID        请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqQryOffsetSetting(CThostFtdcQryOffsetSettingField pQryOffsetSetting, int nRequestID);

    /**
     * 用户口令更新请求
     *
     * @param pUserPasswordUpdate 用户口令变更域
     * @param nRequestID          请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserPasswordUpdate(CThostFtdcUserPasswordUpdateField pUserPasswordUpdate, int nRequestID);
}
