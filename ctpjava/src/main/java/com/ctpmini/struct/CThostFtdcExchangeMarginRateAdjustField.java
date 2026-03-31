package com.ctpmini.struct;

/**
 * 交易所调整后保证金率
 * 对应 C++ 结构体: CThostFtdcExchangeMarginRateAdjustField
 */
public class CThostFtdcExchangeMarginRateAdjustField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 跟随交易所投资者多头保证金率 */
    public double LongMarginRatioByMoney;
    /** 跟随交易所投资者多头保证金费 */
    public double LongMarginRatioByVolume;
    /** 跟随交易所投资者空头保证金率 */
    public double ShortMarginRatioByMoney;
    /** 跟随交易所投资者空头保证金费 */
    public double ShortMarginRatioByVolume;
    /** 交易所多头保证金率 */
    public double ExchLongMarginRatioByMoney;
    /** 交易所多头保证金费 */
    public double ExchLongMarginRatioByVolume;
    /** 交易所空头保证金率 */
    public double ExchShortMarginRatioByMoney;
    /** 交易所空头保证金费 */
    public double ExchShortMarginRatioByVolume;
    /** 不跟随交易所投资者多头保证金率 */
    public double NoLongMarginRatioByMoney;
    /** 不跟随交易所投资者多头保证金费 */
    public double NoLongMarginRatioByVolume;
    /** 不跟随交易所投资者空头保证金率 */
    public double NoShortMarginRatioByMoney;
    /** 不跟随交易所投资者空头保证金费 */
    public double NoShortMarginRatioByVolume;
}
