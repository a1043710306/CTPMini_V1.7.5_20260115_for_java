package com.ctpmini.struct;

/**
 * RULE投资者产品保证金
 * 对应 C++ 结构体: CThostFtdcRULEInvestorProdMarginField
 */
public class CThostFtdcRULEInvestorProdMarginField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 产品族代码 */
    public String ProdFamilyCode;
    /** 合约类型 */
    public String InstrumentClass;
    /** 商品群号 */
    public String CommodityGroupID;
    /** 品种内跨期保证金 */
    public double IntraProdMargin;
    /** 品种间保证金 */
    public double InterProdMargin;
    /** 单品种的单独保证金 */
    public double SingleMargin;
    /** 非组合合约保证金 */
    public double NonCombMargin;
    /** 附加保证金 */
    public double AddOnMargin;
    /** 交易所保证金 */
    public double ExchMargin;
    /** 新开仓冻结保证金 */
    public double OpenFrozenMargin;
    /** 平仓冻结保证金 */
    public double CloseFrozenMargin;
    /** 品种保证金 */
    public double Margin;
    /** 冻结保证金 */
    public double FrozenMargin;
}
