package com.ctpmini.struct;

/**
 * 深度行情
 * 对应 C++ 结构体: CThostFtdcDepthMarketDataField
 */
public class CThostFtdcDepthMarketDataField {
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 合约在交易所的代码 (81字节) */
    public String ExchangeInstID;
    /** 最新价 */
    public double LastPrice;
    /** 上次结算价 */
    public double PreSettlementPrice;
    /** 昨收盘 */
    public double PreClosePrice;
    /** 昨持仓量 */
    public double PreOpenInterest;
    /** 今开盘 */
    public double OpenPrice;
    /** 最高价 */
    public double HighestPrice;
    /** 最低价 */
    public double LowestPrice;
    /** 数量 */
    public int Volume;
    /** 成交金额 */
    public double Turnover;
    /** 持仓量 */
    public double OpenInterest;
    /** 今收盘 */
    public double ClosePrice;
    /** 本次结算价 */
    public double SettlementPrice;
    /** 涨停板价 */
    public double UpperLimitPrice;
    /** 跌停板价 */
    public double LowerLimitPrice;
    /** 昨虚实度 */
    public double PreDelta;
    /** 今虚实度 */
    public double CurrDelta;
    /** 最后修改时间 (9字节) */
    public String UpdateTime;
    /** 最后修改毫秒 */
    public int UpdateMillisec;
    /** 申买价一 */
    public double BidPrice1;
    /** 申买量一 */
    public int BidVolume1;
    /** 申卖价一 */
    public double AskPrice1;
    /** 申卖量一 */
    public int AskVolume1;
    /** 申买价二 */
    public double BidPrice2;
    /** 申买量二 */
    public int BidVolume2;
    /** 申卖价二 */
    public double AskPrice2;
    /** 申卖量二 */
    public int AskVolume2;
    /** 申买价三 */
    public double BidPrice3;
    /** 申买量三 */
    public int BidVolume3;
    /** 申卖价三 */
    public double AskPrice3;
    /** 申卖量三 */
    public int AskVolume3;
    /** 申买价四 */
    public double BidPrice4;
    /** 申买量四 */
    public int BidVolume4;
    /** 申卖价四 */
    public double AskPrice4;
    /** 申卖量四 */
    public int AskVolume4;
    /** 申买价五 */
    public double BidPrice5;
    /** 申买量五 */
    public int BidVolume5;
    /** 申卖价五 */
    public double AskPrice5;
    /** 申卖量五 */
    public int AskVolume5;
    /** 当日均价 */
    public double AveragePrice;
    /** 业务日期 (8字节) */
    public String ActionDay;
    /** 上带价 */
    public double BandingUpperPrice;
    /** 下带价 */
    public double BandingLowerPrice;
}
