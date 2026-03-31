package com.ctpmini.struct;

/**
 * 流控警告
 * 对应 C++ 结构体: CThostFtdcFlowCtrlWarningField
 */
public class CThostFtdcFlowCtrlWarningField {
    /** 交易员代码 */
    public String TraderID;
    /** 交易所代码 */
    public String ExchangeID;
    /** 流控类型 */
    public char FlowCtrlType;
    /** 警告次数 */
    public int WarningCount;
}
