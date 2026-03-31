package com.ctpmini.struct;

/**
 * 撤销对冲参数（错误回报）
 * 对应 C++ 结构体: CThostFtdcCancelOffsetSettingField
 */
public class CThostFtdcCancelOffsetSettingField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 投资者代码 */
    public String InvestorID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约代码 */
    public String InstrumentID;
    /** 开平方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PD_* */
    public char PosiDirection;
    /** 投机套保标志 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_HF_* */
    public char HedgeFlag;
    /** 错误代码 */
    public int ErrorID;
    /** 错误信息 */
    public String ErrorMsg;
}
