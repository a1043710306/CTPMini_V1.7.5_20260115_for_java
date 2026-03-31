package com.ctpmini.struct;

/**
 * 报单手续费
 * 对应 C++ 结构体: CThostFtdcInstrumentOrderCommRateField
 */
public class CThostFtdcInstrumentOrderCommRateField {
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
    /** 报单手续费 */
    public double OrderCommByVolume;
    /** 撤单手续费 */
    public double OrderActionCommByVolume;
    /** 交易所代码 */
    public String ExchangeID;
    /** 投资单元代码 */
    public String InvestUnitID;
}
