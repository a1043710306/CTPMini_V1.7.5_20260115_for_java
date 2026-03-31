package com.ctpmini.struct;

/**
 * MBL市场行情 (逐笔行情)
 * 对应 C++ 结构体: CThostFtdcMBLMarketDataField
 */
public class CThostFtdcMBLMarketDataField {
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 买卖方向 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_D_* */
    public char Direction;
    /** 价格 */
    public double Price;
    /** 数量 */
    public int Volume;
}
