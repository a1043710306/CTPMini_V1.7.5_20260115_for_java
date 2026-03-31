package com.ctpmini.struct;

/**
 * 询价响应
 * 对应 C++ 结构体: CThostFtdcForQuoteRspField
 */
public class CThostFtdcForQuoteRspField {
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 询价编号 */
    public String ForQuoteSysID;
    /** 询价时间 (9字节) */
    public String ForQuoteTime;
    /** 业务日期 (8字节) */
    public String ActionDay;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
}
