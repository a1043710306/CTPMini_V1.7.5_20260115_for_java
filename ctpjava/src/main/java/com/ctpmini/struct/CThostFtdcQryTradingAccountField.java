package com.ctpmini.struct;

/**
 * 查询资金账户
 * 对应 C++ 结构体: CThostFtdcQryTradingAccountField
 */
public class CThostFtdcQryTradingAccountField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 币种代码 */
    public String CurrencyID;
}
