package com.ctpmini.struct;

/**
 * 投资者RCAMS合并保证金信息
 * 对应 C++ 结构体: CThostFtdcRCAMSInvestorProdMarginField
 */
public class CThostFtdcRCAMSInvestorProdMarginField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 产品组合代码 */
    public String CombProductID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 产品群代码 */
    public String ProductGroupID;
    /** 品种折前风险 */
    public double RiskBeforeDiscount;
    /** 同合约对冲风险 */
    public double IntraInstrRisk;
    /** 品种多仓风险 */
    public double BPosRisk;
    /** 品种空仓风险 */
    public double SPosRisk;
    /** 品种内对冲风险 */
    public double IntraProdRisk;
    /** 品种净仓风险 */
    public double NetRisk;
    /** 品种间对冲风险 */
    public double InterProdRisk;
    /** 多头期权权利金 */
    public double OptionRoyalty;
    /** 新开仓自然人交割占用保证金 */
    public double DeliveryOpenFrozenMargin;
    /** 新开仓占用保证金 */
    public double OpenFrozenMargin;
    /** 投资者占用保证金 */
    public double UseFrozenMargin;
    /** 投资者占用保证金 */
    public double MMSAExchMargin;
    /** 新开仓自然人交割仓位保证金 */
    public double DeliveryExchMargin;
    /** 组合上交所保证金 */
    public double CombExchMargin;
    /** 交易所仓位保证金 */
    public double ExchMargin;
    /** 投资者仓位保证金 */
    public double UseMargin;
}
