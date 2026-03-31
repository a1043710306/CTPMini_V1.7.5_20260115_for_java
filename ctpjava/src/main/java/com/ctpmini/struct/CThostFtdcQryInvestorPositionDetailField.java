package com.ctpmini.struct;

/**
 * 查询投资者持仓明细
 * 对应 C++ 结构体: CThostFtdcQryInvestorPositionDetailField
 */
public class CThostFtdcQryInvestorPositionDetailField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
}
