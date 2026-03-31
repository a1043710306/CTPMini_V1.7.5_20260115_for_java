package com.ctpmini.struct;

/**
 * 录入询价
 * 对应 C++ 结构体: CThostFtdcInputForQuoteField
 */
public class CThostFtdcInputForQuoteField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 询价引用 */
    public String ForQuoteRef;
    /** 用户代码 */
    public String UserID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
