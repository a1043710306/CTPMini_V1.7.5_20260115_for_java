package com.ctpmini.struct;

/**
 * 对冲参数录入
 * 对应 C++ 结构体: CThostFtdcInputOffsetSettingField
 */
public class CThostFtdcInputOffsetSettingField {
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
    /** 上日持仓 */
    public int YdVolume;
    /** 今日持仓 */
    public int Volume;
}
