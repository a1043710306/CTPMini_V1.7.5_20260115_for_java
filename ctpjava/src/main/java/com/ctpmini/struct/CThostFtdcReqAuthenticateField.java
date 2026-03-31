package com.ctpmini.struct;

/**
 * 客户端认证请求
 * 对应 C++ 结构体: CThostFtdcReqAuthenticateField
 */
public class CThostFtdcReqAuthenticateField {
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 用户端产品信息 (11字节) */
    public String UserProductInfo;
    /** 认证码 */
    public String AuthCode;
    /** App代码 */
    public String AppID;
}
