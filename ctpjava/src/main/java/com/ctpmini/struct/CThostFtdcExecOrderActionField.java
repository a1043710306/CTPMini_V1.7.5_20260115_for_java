package com.ctpmini.struct;

/**
 * 执行报单操作
 * 对应 C++ 结构体: CThostFtdcExecOrderActionField
 */
public class CThostFtdcExecOrderActionField {
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
    /** 操作日期 */
    public String ActionDate;
    /** 操作时间 */
    public String ActionTime;
    /** 交易所交易员代码 */
    public String TraderID;
    /** 安装编号 */
    public int InstallID;
    /** 本地执行报单编号 */
    public String ExecOrderLocalID;
    /** 操作本地编号 */
    public String ActionLocalID;
    /** 会员代码 */
    public String ParticipantID;
    /** 客户代码 */
    public String ClientID;
    /** 业务单元 */
    public String BusinessUnit;
    /** 报单操作状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OAS_* */
    public char OrderActionStatus;
    /** 用户代码 */
    public String UserID;
    /** 执行类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_ACTP_* */
    public char ActionType;
    /** 状态信息 */
    public String StatusMsg;
    /** 合约代码 */
    public String InstrumentID;
    /** 营业部编号 */
    public String BranchID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
