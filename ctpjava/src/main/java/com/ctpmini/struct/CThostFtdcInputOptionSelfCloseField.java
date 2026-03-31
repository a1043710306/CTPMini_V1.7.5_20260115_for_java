package com.ctpmini.struct;

/**
 * 期权自对冲录入
 * 对应 C++ 结构体: CThostFtdcInputOptionSelfCloseField
 */
public class CThostFtdcInputOptionSelfCloseField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 期权自对冲引用 */
    public String OptionSelfCloseRef;
    /** 用户代码 */
    public String UserID;
    /** 数量 */
    public int Volume;
    /** 请求编号 */
    public int RequestID;
    /** 业务单元 */
    public String BusinessUnit;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 期权行权的头寸是否自对冲 */
    public char OptSelfCloseFlag;
    /** 交易所代码 */
    public String ExchangeID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 资金账号 */
    public String AccountID;
    /** 币种代码 */
    public String CurrencyID;
    /** 交易编码 */
    public String ClientID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
