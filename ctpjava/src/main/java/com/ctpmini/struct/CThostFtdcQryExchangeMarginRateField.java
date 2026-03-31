package com.ctpmini.struct;

/**
 * 查询交易所保证金率
 * 对应 C++ 结构体: CThostFtdcQryExchangeMarginRateField
 */
public class CThostFtdcQryExchangeMarginRateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
}
