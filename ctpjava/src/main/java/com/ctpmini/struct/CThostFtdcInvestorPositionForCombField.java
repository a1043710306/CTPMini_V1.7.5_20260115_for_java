package com.ctpmini.struct;

/**
 * 持仓（用于组合还原）
 * 对应 C++ 结构体: CThostFtdcInvestorPositionForCombField
 */
public class CThostFtdcInvestorPositionForCombField {
    /** 合约代码 */
    public String InstrumentID;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
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
    /** 可用今日仓 */
    public int TodayPosition;
    /** 历史今日仓 */
    public int HistoryPosition;
    /** 历史今日冻结 */
    public int HistoryFrozen;
    /** 当日买成交量 */
    public int TodayBuyVolume;
    /** 当日卖成交量 */
    public int TodaySellVolume;
    /** 交易日 */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 持仓成本 */
    public double PositionCost;
    /** 交易所代码 */
    public String ExchangeID;
}
