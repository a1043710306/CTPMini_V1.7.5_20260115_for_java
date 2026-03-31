package com.ctpmini.struct;

/**
 * 批量撤单请求（做市商）
 * 对应 C++ 结构体: CThostFtdcMKInputOrderActionField
 */
public class CThostFtdcMKInputOrderActionField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 报单操作引用 */
    public int OrderActionRef;
    /** 请求编号 */
    public int RequestID;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 操作标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_AF_* */
    public char ActionFlag;
    /** 撤单模式 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_MKAM_* */
    public char ActionMode;
    /** 下限 */
    public String LowerLimit;
    /** 上限 */
    public String UpperLimit;
    /** 用户代码 */
    public String UserID;
    /** 产品代码 */
    public String ProductID;
    /** 合约代码 */
    public String InstrumentID;
    /** 报单状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_OST_* */
    public char OrderStatus;
    /** 投资单元代码 */
    public String InvestUnitID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
}
