package com.ctpmini.struct;

/**
 * 查询报价
 * 对应 C++ 结构体: CThostFtdcQryQuoteField
 */
public class CThostFtdcQryQuoteField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 报价编号 */
    public String QuoteSysID;
    /** 开始时间 */
    public String InsertTimeStart;
    /** 结束时间 */
    public String InsertTimeEnd;
}
