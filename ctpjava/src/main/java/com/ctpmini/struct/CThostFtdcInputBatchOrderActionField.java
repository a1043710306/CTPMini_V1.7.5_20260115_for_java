package com.ctpmini.struct;

/**
 * 批量报单操作请求
 * 对应 C++ 结构体: CThostFtdcInputBatchOrderActionField
 */
public class CThostFtdcInputBatchOrderActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 报单操作引用 */
    public int OrderActionRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 用户代码 */
    public String UserID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
