package com.ctpmini.struct;

/**
 * 查询合约
 * 对应 C++ 结构体: CThostFtdcQryInstrumentField
 */
public class CThostFtdcQryInstrumentField {
    /** 合约代码 */
    public String InstrumentID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 合约在交易所的代码 */
    public String ExchangeInstID;
    /** 产品代码 */
    public String ProductID;
}
