package com.ctpmini.struct;

/**
 * 查询询价参数
 * 对应 C++ 结构体: CThostFtdcQryForQuoteParamField
 */
public class CThostFtdcQryForQuoteParamField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约代码 */
    public String InstrumentID;
}
