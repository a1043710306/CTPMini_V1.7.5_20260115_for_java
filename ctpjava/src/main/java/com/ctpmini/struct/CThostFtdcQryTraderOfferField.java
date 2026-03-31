package com.ctpmini.struct;

/**
 * 查询交易员报盘
 * 对应 C++ 结构体: CThostFtdcQryTraderOfferField
 */
public class CThostFtdcQryTraderOfferField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 会员代码 */
    public String ParticipantID;
    /** 交易员代码 */
    public String TraderID;
}
