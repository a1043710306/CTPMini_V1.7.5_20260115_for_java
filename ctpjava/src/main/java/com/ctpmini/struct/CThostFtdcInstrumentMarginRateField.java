package com.ctpmini.struct;

/**
 * 合约保证金率
 * 对应 C++ 结构体: CThostFtdcInstrumentMarginRateField
 */
public class CThostFtdcInstrumentMarginRateField {
    /** 合约代码 */
    public String InstrumentID;
    /** 投资者范围 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_IR_* */
    public char InvestorRange;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
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
    /** 是否相对交易所收取 (0=否, 1=是) */
    public int IsRelative;
}
