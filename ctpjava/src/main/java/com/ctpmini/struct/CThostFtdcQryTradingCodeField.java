package com.ctpmini.struct;

/**
 * 查询交易编码
 * 对应 C++ 结构体: CThostFtdcQryTradingCodeField
 */
public class CThostFtdcQryTradingCodeField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 客户代码 */
    public String ClientID;
    /** 交易编码类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_CIDT_* */
    public char ClientIDType;
}
