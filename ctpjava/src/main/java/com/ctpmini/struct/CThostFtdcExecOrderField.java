package com.ctpmini.struct;

/**
 * 执行报单
 * 对应 C++ 结构体: CThostFtdcExecOrderField
 */
public class CThostFtdcExecOrderField {
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
    /** 期权行权后是否保留期货头寸(废弃) */
    public char ReservePositionFlag;
    /** 期权行权后生成的头寸是否自动平仓 */
    public char CloseFlag;
    /** 本地执行报单编号 */
    public String ExecOrderLocalID;
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
    /** 执行报单提交状态 */
    public char OrderSubmitStatus;
    /** 报单提示序号 */
    public int NotifySequence;
    /** 交易日 */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 执行报单编号 */
    public String ExecOrderSysID;
    /** 报单日期 */
    public String InsertDate;
    /** 插入时间 */
    public String InsertTime;
    /** 撤销时间 */
    public String CancelTime;
    /** 执行结果 */
    public char ExecResult;
    /** 结算会员编号 */
    public String ClearingPartID;
    /** 序号 */
    public int SequenceNo;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 用户端产品信息 */
    public String UserProductInfo;
    /** 状态信息 */
    public String StatusMsg;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 资金账号 */
    public String AccountID;
    /** 币种代码 */
    public String CurrencyID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
