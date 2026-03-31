package com.ctpmini.struct;

/**
 * 成交
 * 对应 C++ 结构体: CThostFtdcTradeField
 */
public class CThostFtdcTradeField {
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 报单引用 (13字节) */
    public String OrderRef;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 成交编号 (21字节) */
    public String TradeID;
    /** 买卖方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_D_* */
    public char Direction;
    /** 报单编号 (21字节) */
    public String OrderSysID;
    /** 会员代码 (11字节) */
    public String ParticipantID;
    /** 客户代码 (11字节) */
    public String ClientID;
    /** 交易角色 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_ER_* */
    public char TradingRole;
    /** 合约在交易所的代码 (81字节) */
    public String ExchangeInstID;
    /** 开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char OffsetFlag;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 价格 */
    public double Price;
    /** 数量 */
    public int Volume;
    /** 成交时期 (8字节) */
    public String TradeDate;
    /** 成交时间 (9字节) */
    public String TradeTime;
    /** 成交类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_TRDT_* */
    public char TradeType;
    /** 成交价来源 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PSRC_* */
    public char PriceSource;
    /** 交易所交易员代码 (21字节) */
    public String TraderID;
    /** 本地报单编号 (13字节) */
    public String OrderLocalID;
    /** 结算会员编号 (11字节) */
    public String ClearingPartID;
    /** 业务单元 (21字节) */
    public String BusinessUnit;
    /** 序号 */
    public int SequenceNo;
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 经纪公司报单编号 */
    public int BrokerOrderSeq;
    /** 成交来源 */
    public char TradeSource;
    /** 投资单元代码 */
    public String InvestUnitID;
}
