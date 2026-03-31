package com.ctpmini.struct;

/**
 * 交易所
 * 对应 C++ 结构体: CThostFtdcExchangeField
 */
public class CThostFtdcExchangeField {
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 交易所名称 (61字节) */
    public String ExchangeName;
    /** 交易所属性 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_EXP_* */
    public char ExchangeProperty;
}
