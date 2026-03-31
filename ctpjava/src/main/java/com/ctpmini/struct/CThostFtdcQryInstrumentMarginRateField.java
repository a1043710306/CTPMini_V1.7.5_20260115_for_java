package com.ctpmini.struct;

/**
 * 查询合约保证金率
 * 对应 C++ 结构体: CThostFtdcQryInstrumentMarginRateField
 */
public class CThostFtdcQryInstrumentMarginRateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
}
