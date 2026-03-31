package com.ctpmini.struct;

/**
 * 查询对冲参数
 * 对应 C++ 结构体: CThostFtdcQryOffsetSettingField
 */
public class CThostFtdcQryOffsetSettingField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约代码 */
    public String InstrumentID;
}
