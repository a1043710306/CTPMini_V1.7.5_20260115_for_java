package com.ctpmini.struct;

/**
 * 查询期权合约交易成本
 * 对应 C++ 结构体: CThostFtdcQryOptionInstrTradeCostField
 */
public class CThostFtdcQryOptionInstrTradeCostField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 期权类型 */
    public double InputPrice;
    /** 标的价格 */
    public double UnderlyingPrice;
    /** 交易所代码 */
    public String ExchangeID;
}
