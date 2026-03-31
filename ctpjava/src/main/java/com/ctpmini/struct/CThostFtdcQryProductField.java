package com.ctpmini.struct;

/**
 * 查询产品
 * 对应 C++ 结构体: CThostFtdcQryProductField
 */
public class CThostFtdcQryProductField {
    /** 产品代码 */
    public String ProductID;
    /** 产品类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PC_* */
    public char ProductClass;
}
