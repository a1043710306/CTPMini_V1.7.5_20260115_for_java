package com.ctpmini.struct;

/**
 * 报单
 * 对应 C++ 结构体: CThostFtdcOrderField
 */
public class CThostFtdcOrderField {
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 报单引用 (13字节) */
    public String OrderRef;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 报单价格条件 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OPT_* */
    public char OrderPriceType;
    /** 买卖方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_D_* */
    public char Direction;
    /** 组合开平标志 (5字节) */
    public String CombOffsetFlag;
    /** 组合投机套保标志 (5字节) */
    public String CombHedgeFlag;
    /** 价格 */
    public double LimitPrice;
    /** 数量 */
    public int VolumeTotalOriginal;
    /** 有效期类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_TC_* */
    public char TimeCondition;
    /** GTD日期 (8字节) */
    public String GTDDate;
    /** 成交量类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_VC_* */
    public char VolumeCondition;
    /** 最小成交量 */
    public int MinVolume;
    /** 触发条件 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_CC_* */
    public char ContingentCondition;
    /** 止损价 */
    public double StopPrice;
    /** 强平原因 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_FCC_* */
    public char ForceCloseReason;
    /** 自动挂起标志 */
    public int IsAutoSuspend;
    /** 业务单元 (21字节) */
    public String BusinessUnit;
    /** 请求编号 */
    public int RequestID;
    /** 本地报单编号 (13字节) */
    public String OrderLocalID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 会员代码 (11字节) */
    public String ParticipantID;
    /** 客户代码 (11字节) */
    public String ClientID;
    /** 合约在交易所的代码 (81字节) */
    public String ExchangeInstID;
    /** 交易所交易员代码 (21字节) */
    public String TraderID;
    /** 安装编号 */
    public int InstallID;
    /** 报单提交状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OSS_* */
    public char OrderSubmitStatus;
    /** 报单提示序号 */
    public int NotifySequence;
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 结算编号 */
    public int SettlementID;
    /** 报单编号 (21字节) */
    public String OrderSysID;
    /** 报单来源 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OSRC_* */
    public char OrderSource;
    /** 报单状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OST_* */
    public char OrderStatus;
    /** 报单类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_ORDT_* */
    public char OrderType;
    /** 今成交数量 */
    public int VolumeTraded;
    /** 剩余数量 */
    public int VolumeTotal;
    /** 报单日期 (8字节) */
    public String InsertDate;
    /** 委托时间 (9字节) */
    public String InsertTime;
    /** 激活时间 (9字节) */
    public String ActiveTime;
    /** 挂起时间 (9字节) */
    public String SuspendTime;
    /** 最后修改时间 (9字节) */
    public String UpdateTime;
    /** 撤销时间 (9字节) */
    public String CancelTime;
    /** 最后修改交易所交易员代码 (21字节) */
    public String ActiveTraderID;
    /** 结算会员编号 (11字节) */
    public String ClearingPartID;
    /** 序号 */
    public int SequenceNo;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 用户端产品信息 (11字节) */
    public String UserProductInfo;
    /** 状态信息 (81字节) */
    public String StatusMsg;
    /** 用户强评标志 */
    public int UserForceClose;
    /** 操作用户代码 (16字节) */
    public String ActiveUserID;
    /** 经纪公司报单编号 */
    public int BrokerOrderSeq;
    /** 相关报单 (21字节) */
    public String RelativeOrderSysID;
    /** 郑商所成交数量 */
    public int ZCETotalTradedVolume;
    /** 互换单标志 */
    public int IsSwapOrder;
    /** 营业部编号 */
    public String BranchID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 资金账号 (13字节) */
    public String AccountID;
    /** 币种代码 (4字节) */
    public String CurrencyID;
    /** IP地址 (16字节) */
    public String IPAddress;
    /** Mac地址 (21字节) */
    public String MacAddress;
    /** 自定义字段 */
    public String CustomOrderRef;
    /** 成交均价 */
    public double TradeAvgPrice;
}
