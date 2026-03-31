package com.ctpmini.struct;

/**
 * 报价
 * 对应 C++ 结构体: CThostFtdcQuoteField
 */
public class CThostFtdcQuoteField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 合约代码 */
    public String InstrumentID;
    /** 报价引用 */
    public String QuoteRef;
    /** 用户代码 */
    public String UserID;
    /** 卖价格 */
    public double AskPrice;
    /** 买价格 */
    public double BidPrice;
    /** 卖数量 */
    public int AskVolume;
    /** 买数量 */
    public int BidVolume;
    /** 请求编号 */
    public int RequestID;
    /** 业务单元 */
    public String BusinessUnit;
    /** 卖开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char AskOffsetFlag;
    /** 买开平标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OF_* */
    public char BidOffsetFlag;
    /** 卖投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char AskHedgeFlag;
    /** 买投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char BidHedgeFlag;
    /** 本地报价编号 */
    public String QuoteLocalID;
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
    /** 撤销时间 */
    public String CancelTime;
    /** 报价状态 */
    public char QuoteStatus;
    /** 结算会员编号 */
    public String ClearingPartID;
    /** 序号 */
    public int SequenceNo;
    /** 卖方报单编号 */
    public String AskOrderSysID;
    /** 买方报单编号 */
    public String BidOrderSysID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 用户端产品信息 */
    public String UserProductInfo;
    /** 状态信息 */
    public String StatusMsg;
    /** 应价编号 */
    public String ActiveQuoteFlag;
    /** 经纪公司报单编号 */
    public int BrokerQuoteSeq;
    /** 衍生卖报单引用 */
    public String AskOrderRef;
    /** 衍生买报单引用 */
    public String BidOrderRef;
    /** 应价编号 */
    public String ForQuoteSysID;
    /** 营业部编号 */
    public String BranchID;
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
    /** 报价编号 */
    public String QuoteSysID;
}
