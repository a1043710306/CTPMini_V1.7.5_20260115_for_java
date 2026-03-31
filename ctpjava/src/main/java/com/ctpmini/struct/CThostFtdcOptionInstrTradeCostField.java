package com.ctpmini.struct;

/**
 * 期权合约交易成本
 * 对应 C++ 结构体: CThostFtdcOptionInstrTradeCostField
 */
public class CThostFtdcOptionInstrTradeCostField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 期权合约保证金不变部分 */
    public double FixedMargin;
    /** 期权合约最小保证金 */
    public double MiniMargin;
    /** 期权合约权利金收取方式 */
    public double Royalty;
    /** 交易所期权合约保证金不变部分 */
    public double ExchFixedMargin;
    /** 交易所期权合约最小保证金 */
    public double ExchMiniMargin;
}
