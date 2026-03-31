package com.ctpmini.struct;

/**
 * 组合合约信息
 * 对应 C++ 结构体: CThostFtdcCombInstrumentField
 */
public class CThostFtdcCombInstrumentField {
    /** 合约代码 */
    public String InstrumentID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 组合类型 */
    public char CombinationType;
    /** 产品代码 */
    public String ProductID;
    /** 保证金优惠比例 */
    public double Xparameter;
}
