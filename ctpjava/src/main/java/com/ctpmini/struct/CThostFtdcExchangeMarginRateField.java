package com.ctpmini.struct;

/**
 * 交易所保证金率
 * 对应 C++ 结构体: CThostFtdcExchangeMarginRateField
 */
public class CThostFtdcExchangeMarginRateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 多头保证金率 */
    public double LongMarginRatioByMoney;
    /** 多头保证金费 */
    public double LongMarginRatioByVolume;
    /** 空头保证金率 */
    public double ShortMarginRatioByMoney;
    /** 空头保证金费 */
    public double ShortMarginRatioByVolume;
}
