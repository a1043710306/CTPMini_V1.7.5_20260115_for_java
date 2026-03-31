package com.ctpmini.struct;

/**
 * SPMM商品群保证金明细
 * 对应 C++ 结构体: CThostFtdcSPMMInvestorCommodityGroupMarginField
 */
public class CThostFtdcSPMMInvestorCommodityGroupMarginField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 商品群代码 */
    public String CommodityGroupID;
    /** 优惠前应缴保证金 */
    public double MarginBeforeDiscount;
    /** 无优惠应缴保证金 */
    public double MarginNoDiscount;
    /** 多头风险 */
    public double LongRisk;
    /** 空头风险 */
    public double ShortRisk;
    /** 商品群平仓冻结保证金 */
    public double CloseFrozenMargin;
    /** SPMM商品间优惠系数 */
    public double InterCommodityRate;
    /** 商品群最小保证金比率 */
    public double MiniMarginRatio;
    /** 投资者保证金与交易所保证金的比率 */
    public double AdjustRatio;
    /** SPMM品种内优惠换算 */
    public double IntraCommodityDiscount;
    /** SPMM商品间优惠 */
    public double InterCommodityDiscount;
    /** 交易所保证金 */
    public double ExchMargin;
    /** 投资者保证金 */
    public double InvestorMargin;
    /** 冻结手续费 */
    public double FrozenCommission;
    /** 手续费 */
    public double Commission;
    /** 冻结的资金 */
    public double FrozenCash;
    /** 资金差额 */
    public double CashIn;
    /** 行权冻结的资金 */
    public double StrikeFrozenMargin;
}
