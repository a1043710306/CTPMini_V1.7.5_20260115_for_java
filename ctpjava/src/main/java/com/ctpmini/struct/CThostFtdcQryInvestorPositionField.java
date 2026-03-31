package com.ctpmini.struct;

/**
 * 查询投资者持仓
 * 对应 C++ 结构体: CThostFtdcQryInvestorPositionField
 */
public class CThostFtdcQryInvestorPositionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
}
