package com.ctpmini.struct;

/**
 * 报价录入
 * 对应 C++ 结构体: CThostFtdcInputQuoteField
 */
public class CThostFtdcInputQuoteField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 报价引用 */
    public String QuoteRef;
    /** 用户代码 */
    public String UserID;
    /** 卖价格 */
    public double AskPrice;
    /** 买价格 */
    public double BidPrice;
    /** 卖数量 */
    public int AskVolume;
    /** 买数量 */
    public int BidVolume;
    /** 请求编号 */
    public int RequestID;
    /** 业务单元 */
    public String BusinessUnit;
    /** 卖开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char AskOffsetFlag;
    /** 买开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char BidOffsetFlag;
    /** 卖投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char AskHedgeFlag;
    /** 买投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char BidHedgeFlag;
    /** 衍生卖报单引用 */
    public String AskOrderRef;
    /** 衍生买报单引用 */
    public String BidOrderRef;
    /** 应价编号 */
    public String ForQuoteSysID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 交易编码 */
    public String ClientID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
