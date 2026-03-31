package com.ctpmini.struct;

/**
 * 查询投资者SPMM商品群保证金明细
 * 对应 C++ 结构体: CThostFtdcQrySPMMInvestorCommodityGroupMarginField
 */
public class CThostFtdcQrySPMMInvestorCommodityGroupMarginField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 商品群代码 */
    public String CommodityGroupID;
}
