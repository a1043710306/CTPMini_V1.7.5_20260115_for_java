package com.ctpmini.struct;

/**
 * 用户登出请求
 * 对应 C++ 结构体: CThostFtdcUserLogoutField
 */
public class CThostFtdcUserLogoutField {
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 用户代码 (16字节) */
    public String UserID;
}
