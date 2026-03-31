package com.ctpmini.struct;

/**
 * 录入报单操作
 * 对应 C++ 结构体: CThostFtdcInputOrderActionField
 */
public class CThostFtdcInputOrderActionField {
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 报单操作引用 */
    public int OrderActionRef;
    /** 报单引用 (13字节) */
    public String OrderRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 报单编号 (21字节) */
    public String OrderSysID;
    /** 操作标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_AF_* */
    public char ActionFlag;
    /** 价格 */
    public double LimitPrice;
    /** 数量变化 */
    public int VolumeChange;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 (16字节) */
    public String IPAddress;
    /** Mac地址 (21字节) */
    public String MacAddress;
}
