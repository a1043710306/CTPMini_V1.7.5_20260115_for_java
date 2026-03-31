package com.ctpmini.struct;

/**
 * 录入报单
 * 对应 C++ 结构体: CThostFtdcInputOrderField
 */
public class CThostFtdcInputOrderField {
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
    /** 组合开平标志 (5字节，每位对应一腿) */
    public String CombOffsetFlag;
    /** 组合投机套保标志 (5字节，每位对应一腿) */
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
    /** 自动挂起标志 (0=否, 1=是) */
    public int IsAutoSuspend;
    /** 业务单元 (21字节) */
    public String BusinessUnit;
    /** 请求编号 */
    public int RequestID;
    /** 用户强评标志 (0=否, 1=是) */
    public int UserForceClose;
    /** 互换单标志 (0=否, 1=是) */
    public int IsSwapOrder;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** 资金账号 (13字节) */
    public String AccountID;
    /** 币种代码 (4字节) */
    public String CurrencyID;
    /** 交易编码 (11字节) */
    public String ClientID;
    /** IP地址 (16字节) */
    public String IPAddress;
    /** Mac地址 (21字节) */
    public String MacAddress;
    /** 自定义字段 */
    public String CustomOrderRef;
    /** 报单标志 */
    public char OrderFlag;
}
