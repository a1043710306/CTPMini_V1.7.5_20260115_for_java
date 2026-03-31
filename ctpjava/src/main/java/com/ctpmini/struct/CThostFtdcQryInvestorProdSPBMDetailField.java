package com.ctpmini.struct;

/**
 * 查询SPBM产品组保证金明细
 * 对应 C++ 结构体: CThostFtdcQryInvestorProdSPBMDetailField
 */
public class CThostFtdcQryInvestorProdSPBMDetailField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 产品族代码 */
    public String ProdFamilyCode;
}
