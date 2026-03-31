package com.ctpmini.struct;

/**
 * RCAMS投资者组合持仓信息
 * 对应 C++ 结构体: CThostFtdcRCAMSInvestorCombPositionField
 */
public class CThostFtdcRCAMSInvestorCombPositionField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 持仓多空方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PD_* */
    public char PosiDirection;
    /** 组合合约代码 */
    public String CombInstrumentID;
    /** LegID */
    public int LegID;
    /** 组合上交所合约代码 */
    public String ExchangeInstID;
    /** 数量 */
    public int TotalAmt;
    /** 交易所仓位保证金 */
    public double ExchMargin;
    /** 投资者保证金 */
    public double Margin;
}
