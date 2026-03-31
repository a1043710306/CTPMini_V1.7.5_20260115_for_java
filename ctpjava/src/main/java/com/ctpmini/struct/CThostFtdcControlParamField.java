package com.ctpmini.struct;

/**
 * 交易控制参数
 * 对应 C++ 结构体: CThostFtdcControlParamField
 */
public class CThostFtdcControlParamField {
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 控制参数代码 */
    public char ControlParamID;
    /** 控制参数值 (81字节) */
    public String ControlParamValue;
    /** 备注说明 */
    public String Memo;
}
