package com.ctpmini.struct;

/**
 * 合约状态
 * 对应 C++ 结构体: CThostFtdcInstrumentStatusField
 */
public class CThostFtdcInstrumentStatusField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约在交易所的代码 */
    public String ExchangeInstID;
    /** 结算组代码 */
    public String SettlementGroupID;
    /** 合约代码 */
    public String InstrumentID;
    /** 合约交易状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_IS_* */
    public char InstrumentStatus;
    /** 交易阶段编号 */
    public int TradingSegmentSN;
    /** 进入本状态时间 */
    public String EnterTime;
    /** 进入本状态原因 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_IER_* */
    public char EnterReason;
}
