package com.ctpmini.struct;

/**
 * 申请组合录入
 * 对应 C++ 结构体: CThostFtdcInputCombActionField
 */
public class CThostFtdcInputCombActionField {
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
    /** 交易所代码 */
    public String ExchangeID;
    /** IP地址 */
    public String IPAddress;
    /** Mac地址 */
    public String MacAddress;
    /** 投资单元代码 */
    public String InvestUnitID;
}
