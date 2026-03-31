package com.ctpmini.struct;

/**
 * 查询投资者RCAMS合约保证金
 * 对应 C++ 结构体: CThostFtdcQryRCAMSInvestorProdMarginField
 */
public class CThostFtdcQryRCAMSInvestorProdMarginField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 产品代码 */
    public String CombProductID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
}
