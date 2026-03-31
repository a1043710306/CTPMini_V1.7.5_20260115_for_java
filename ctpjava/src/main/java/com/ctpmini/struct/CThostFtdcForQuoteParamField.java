package com.ctpmini.struct;

/**
 * 询价价格参数
 * 对应 C++ 结构体: CThostFtdcForQuoteParamField
 */
public class CThostFtdcForQuoteParamField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约代码 */
    public String InstrumentID;
    /** 最新价 */
    public double LastPrice;
    /** 上浮价格偏差 */
    public double UpperLimitPrice;
    /** 下浮价格偏差 */
    public double LowerLimitPrice;
    /** 买报价偏差 */
    public double BidPriceOffset;
}
