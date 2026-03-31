package com.ctpmini.struct;

/**
 * 期权自对冲
 * 对应 C++ 结构体: CThostFtdcOptionSelfCloseField
 */
public class CThostFtdcOptionSelfCloseField {
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
    /** 本地期权自对冲编号 */
    public String OptionSelfCloseLocalID;
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
    /** 期权自对冲提交状态 */
    public char OrderSubmitStatus;
    /** 报单提示序号 */
    public int NotifySequence;
    /** 交易日 */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 期权自对冲编号 */
    public String OptionSelfCloseSysID;
    /** 报单日期 */
    public String InsertDate;
    /** 插入时间 */
    public String InsertTime;
    /** 撤销时间 */
    public String CancelTime;
    /** 自对冲结果 */
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
