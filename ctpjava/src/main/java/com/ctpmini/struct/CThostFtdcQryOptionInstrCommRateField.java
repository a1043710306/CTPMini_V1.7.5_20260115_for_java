package com.ctpmini.struct;

/**
 * 查询期权合约手续费
 * 对应 C++ 结构体: CThostFtdcQryOptionInstrCommRateField
 */
public class CThostFtdcQryOptionInstrCommRateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
}
