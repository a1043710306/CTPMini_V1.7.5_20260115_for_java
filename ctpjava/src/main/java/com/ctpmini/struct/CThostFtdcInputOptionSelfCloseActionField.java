package com.ctpmini.struct;

/**
 * 期权自对冲操作
 * 对应 C++ 结构体: CThostFtdcInputOptionSelfCloseActionField
 */
public class CThostFtdcInputOptionSelfCloseActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 期权自对冲操作引用 */
    public int OptionSelfCloseActionRef;
    /** 期权自对冲引用 */
    public String OptionSelfCloseRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 期权自对冲编号 */
    public String OptionSelfCloseSysID;
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
