package com.ctpmini.struct;

/**
 * 用户口令变更
 * 对应 C++ 结构体: CThostFtdcUserPasswordUpdateField
 */
public class CThostFtdcUserPasswordUpdateField {
    /** 经纪公司代码 */
    public String BrokerID;
    /** 用户代码 */
    public String UserID;
    /** 原来的口令 */
    public String OldPassword;
    /** 新的口令 */
    public String NewPassword;
}
