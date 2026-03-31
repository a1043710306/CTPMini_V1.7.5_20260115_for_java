package com.ctpmini.struct;

/**
 * 报价操作
 * 对应 C++ 结构体: CThostFtdcInputQuoteActionField
 */
public class CThostFtdcInputQuoteActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 报价操作引用 */
    public int QuoteActionRef;
    /** 报价引用 */
    public String QuoteRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 报价编号 */
    public String QuoteSysID;
    /** 操作标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_AF_* */
    public char ActionFlag;
    /** 用户代码 */
    public String UserID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 交易编码 */
    public String ClientID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
