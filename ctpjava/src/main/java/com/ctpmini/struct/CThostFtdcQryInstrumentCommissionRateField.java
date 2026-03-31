package com.ctpmini.struct;

/**
 * 查询合约手续费率
 * 对应 C++ 结构体: CThostFtdcQryInstrumentCommissionRateField
 */
public class CThostFtdcQryInstrumentCommissionRateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
}
