package com.ctpmini.struct;

/**
 * 用户登录请求
 * 对应 C++ 结构体: CThostFtdcReqUserLoginField
 */
public class CThostFtdcReqUserLoginField {
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 密码 (41字节) */
    public String Password;
    /** 用户端产品信息 (11字节) */
    public String UserProductInfo;
    /** 接口端产品信息 (11字节) */
    public String InterfaceProductInfo;
    /** 协议信息 (11字节) */
    public String ProtocolInfo;
    /** Mac地址 (21字节) */
    public String MacAddress;
    /** 动态密码 (41字节) */
    public String OneTimePassword;
    /** 终端IP地址 (16字节) */
    public String ClientIPAddress;
    /** 登录备注 */
    public String LoginRemark;
}
