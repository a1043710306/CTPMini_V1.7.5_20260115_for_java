package com.ctpmini.struct;

/**
 * 查询RCAMS投资者组合持仓
 * 对应 C++ 结构体: CThostFtdcQryRCAMSInvestorCombPositionField
 */
public class CThostFtdcQryRCAMSInvestorCombPositionField {
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
}
