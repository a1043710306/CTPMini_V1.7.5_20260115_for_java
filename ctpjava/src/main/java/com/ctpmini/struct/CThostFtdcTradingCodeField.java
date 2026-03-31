package com.ctpmini.struct;

/**
 * 交易编码
 * 对应 C++ 结构体: CThostFtdcTradingCodeField
 */
public class CThostFtdcTradingCodeField {
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 客户代码 (11字节) */
    public String ClientID;
    /** 是否活跃 (0=否, 1=是) */
    public int IsActive;
    /** 交易编码类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_CIDT_* */
    public char ClientIDType;
}
