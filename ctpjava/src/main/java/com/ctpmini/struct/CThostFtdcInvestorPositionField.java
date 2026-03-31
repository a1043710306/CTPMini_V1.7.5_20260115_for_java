package com.ctpmini.struct;

/**
 * 投资者持仓
 * 对应 C++ 结构体: CThostFtdcInvestorPositionField
 */
public class CThostFtdcInvestorPositionField {
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 持仓多空方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PD_* */
    public char PosiDirection;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 持仓日期 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PSD_* */
    public char PositionDate;
    /** 上日持仓 */
    public int YdPosition;
    /** 今日持仓 */
    public int Position;
    /** 多头冻结 */
    public int LongFrozen;
    /** 空头冻结 */
    public int ShortFrozen;
    /** 开仓冻结金额 */
    public double LongFrozenAmount;
    /** 开仓冻结金额 */
    public double ShortFrozenAmount;
    /** 开仓量 */
    public int OpenVolume;
    /** 平仓量 */
    public int CloseVolume;
    /** 开仓金额 */
    public double OpenAmount;
    /** 平仓金额 */
    public double CloseAmount;
    /** 持仓成本 */
    public double PositionCost;
    /** 上次占用的保证金 */
    public double PreMargin;
    /** 占用的保证金 */
    public double UseMargin;
    /** 冻结的保证金 */
    public double FrozenMargin;
    /** 冻结的资金 */
    public double FrozenCash;
    /** 冻结的手续费 */
    public double FrozenCommission;
    /** 资金差额 */
    public double CashIn;
    /** 手续费 */
    public double Commission;
    /** 平仓盈亏 */
    public double CloseProfit;
    /** 持仓盈亏 */
    public double PositionProfit;
    /** 上次结算价 */
    public double PreSettlementPrice;
    /** 本次结算价 */
    public double SettlementPrice;
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 开仓成本 */
    public double OpenCost;
    /** 交易所保证金 */
    public double ExchangeMargin;
    /** 组合成交形成的持仓 */
    public int CombPosition;
    /** 组合多头冻结 */
    public int CombLongFrozen;
    /** 组合空头冻结 */
    public int CombShortFrozen;
    /** 逐日盯市平仓盈亏 */
    public double CloseProfitByDate;
    /** 逐笔对冲平仓盈亏 */
    public double CloseProfitByTrade;
    /** 今日持仓 */
    public int TodayPosition;
    /** 保证金率 */
    public double MarginRateByMoney;
    /** 保证金率(按手数) */
    public double MarginRateByVolume;
    /** 执行冻结 */
    public int StrikeFrozen;
    /** 执行冻结金额 */
    public double StrikeFrozenAmount;
    /** 放弃执行冻结 */
    public int AbandonFrozen;
}
