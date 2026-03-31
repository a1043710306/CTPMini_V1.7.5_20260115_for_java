package com.ctpmini.struct;

/**
 * 询价
 * 对应 C++ 结构体: CThostFtdcForQuoteField
 */
public class CThostFtdcForQuoteField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 询价引用 */
    public String ForQuoteRef;
    /** 用户代码 */
    public String UserID;
    /** 本地询价编号 */
    public String ForQuoteLocalID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 会员代码 */
    public String ParticipantID;
    /** 客户代码 */
    public String ClientID;
    /** 合约在交易所的代码 */
    public String ExchangeInstID;
    /** 交易所交易员代码 */
    public String TraderID;
    /** 安装编号 */
    public int InstallID;
    /** 报单日期 */
    public String InsertDate;
    /** 插入时间 */
    public String InsertTime;
    /** 询价状态 */
    public char ForQuoteStatus;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 状态信息 */
    public String StatusMsg;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
