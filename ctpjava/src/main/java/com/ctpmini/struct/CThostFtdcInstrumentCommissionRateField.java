package com.ctpmini.struct;

/**
 * 合约手续费率
 * 对应 C++ 结构体: CThostFtdcInstrumentCommissionRateField
 */
public class CThostFtdcInstrumentCommissionRateField {
    /** 合约代码 */
    public String InstrumentID;
    /** 投资者范围 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_IR_* */
    public char InvestorRange;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 开仓手续费率 */
    public double OpenRatioByMoney;
    /** 开仓手续费 */
    public double OpenRatioByVolume;
    /** 平仓手续费率 */
    public double CloseRatioByMoney;
    /** 平仓手续费 */
    public double CloseRatioByVolume;
    /** 平今手续费率 */
    public double CloseTodayRatioByMoney;
    /** 平今手续费 */
    public double CloseTodayRatioByVolume;
}
