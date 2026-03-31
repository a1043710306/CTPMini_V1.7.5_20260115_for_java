package com.ctpmini.struct;

/**
 * 查询投资者持仓（用于组合）
 * 对应 C++ 结构体: CThostFtdcQryInvestorPositionForCombField
 */
public class CThostFtdcQryInvestorPositionForCombField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
}
