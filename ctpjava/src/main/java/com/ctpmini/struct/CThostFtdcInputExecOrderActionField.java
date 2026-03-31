package com.ctpmini.struct;

/**
 * 执行报单操作
 * 对应 C++ 结构体: CThostFtdcInputExecOrderActionField
 */
public class CThostFtdcInputExecOrderActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 执行报单操作引用 */
    public int ExecOrderActionRef;
    /** 执行报单引用 */
    public String ExecOrderRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 执行报单编号 */
    public String ExecOrderSysID;
    /** 操作标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_AF_* */
    public char ActionFlag;
    /** 用户代码 */
    public String UserID;
    /** 合约代码 */
    public String InstrumentID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
