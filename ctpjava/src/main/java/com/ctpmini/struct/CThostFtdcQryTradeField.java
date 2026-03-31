package com.ctpmini.struct;

/**
 * 查询成交
 * 对应 C++ 结构体: CThostFtdcQryTradeField
 */
public class CThostFtdcQryTradeField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 成交编号 */
    public String TradeID;
    /** 开始时间 */
    public String TradeTimeStart;
    /** 结束时间 */
    public String TradeTimeEnd;
}
