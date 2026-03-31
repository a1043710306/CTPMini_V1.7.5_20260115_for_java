package com.ctpmini.struct;

/**
 * SPBM产品组保证金明细
 * 对应 C++ 结构体: CThostFtdcInvestorProdSPBMDetailField
 */
public class CThostFtdcInvestorProdSPBMDetailField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 产品族代码 */
    public String ProdFamilyCode;
    /** 合约内跨期保证金 */
    public double IntraInstrMargin;
    /** 多方集合保证金 */
    public double BCollectingMargin;
    /** 空方集合保证金 */
    public double SCollectingMargin;
    /** 品种内合约跨期保证金 */
    public double IntraProdMargin;
    /** 净保证金 */
    public double NetMargin;
    /** 跨产品组保证金 */
    public double InterProdMargin;
    /** 单腿保证金 */
    public double SingleMargin;
    /** 附加保证金 */
    public double AddOnMargin;
    /** 交割保证金 */
    public double DeliveryMargin;
    /** 期权最小风险敞口 */
    public double OptionMinRisk;
    /** 权值抵扣 */
    public double RealOptionValueOffset;
    /** 保证金 */
    public double Margin;
    /** 交易所保证金 */
    public double ExchMargin;
}
