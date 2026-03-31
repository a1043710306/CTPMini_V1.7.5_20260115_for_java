package com.ctpmini.struct;

/**
 * 录入执行报单
 * 对应 C++ 结构体: CThostFtdcInputExecOrderField
 */
public class CThostFtdcInputExecOrderField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 执行报单引用 */
    public String ExecOrderRef;
    /** 用户代码 */
    public String UserID;
    /** 数量 */
    public int Volume;
    /** 请求编号 */
    public int RequestID;
    /** 业务单元 */
    public String BusinessUnit;
    /** 开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char OffsetFlag;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 执行类型 */
    public char ActionType;
    /** 保留头寸申请的持仓方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PD_* */
    public char PosiDirection;
    /** 期权行权后是否保留期货头寸的标记,该字段已废弃 */
    public char ReservePositionFlag;
    /** 期权行权后生成的头寸是否自动平仓 */
    public char CloseFlag;
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
