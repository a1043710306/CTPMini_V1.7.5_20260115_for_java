package com.ctpmini.struct;

/**
 * 投资者持仓明细
 * 对应 C++ 结构体: CThostFtdcInvestorPositionDetailField
 */
public class CThostFtdcInvestorPositionDetailField {
    /** 合约代码 */
    public String InstrumentID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 买卖 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_D_* */
    public char Direction;
    /** 开仓日期 */
    public String OpenDate;
    /** 成交编号 */
    public String TradeID;
    /** 数量 */
    public int Volume;
    /** 开仓价 */
    public double OpenPrice;
    /** 交易日 */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 成交类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_TRDT_* */
    public char TradeType;
    /** 组合合约代码 */
    public String CombInstrumentID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 逐日盯市平仓盈亏 */
    public double CloseProfitByDate;
    /** 逐笔对冲平仓盈亏 */
    public double CloseProfitByTrade;
    /** 逐日盯市持仓盈亏 */
    public double PositionProfitByDate;
    /** 逐笔对冲持仓盈亏 */
    public double PositionProfitByTrade;
    /** 投资者保证金 */
    public double Margin;
    /** 交易所保证金 */
    public double ExchMargin;
    /** 保证金率 */
    public double MarginRateByMoney;
    /** 保证金率(按手数) */
    public double MarginRateByVolume;
    /** 昨结算价 */
    public double LastSettlementPrice;
    /** 结算价 */
    public double SettlementPrice;
    /** 平仓量 */
    public int CloseVolume;
    /** 平仓金额 */
    public double CloseAmount;
    /** 投资单元代码 */
    public String InvestUnitID;
}
