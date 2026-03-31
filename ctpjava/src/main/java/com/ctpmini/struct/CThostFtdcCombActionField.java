package com.ctpmini.struct;

/**
 * 申请组合
 * 对应 C++ 结构体: CThostFtdcCombActionField
 */
public class CThostFtdcCombActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 组合引用 */
    public String CombActionRef;
    /** 用户代码 */
    public String UserID;
    /** 买卖方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_D_* */
    public char Direction;
    /** 数量 */
    public int Volume;
    /** 组合指令方向 */
    public char CombDirection;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 本地申请组合编号 */
    public String ActionLocalID;
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
    /** 组合状态 */
    public char ActionStatus;
    /** 报单提示序号 */
    public int NotifySequence;
    /** 交易日 */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
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
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
    /** 组合编号 */
    public String ComTradeID;
    /** 营业部编号 */
    public String BranchID;
    /** 投资单元代码 */
    public String InvestUnitID;
}
