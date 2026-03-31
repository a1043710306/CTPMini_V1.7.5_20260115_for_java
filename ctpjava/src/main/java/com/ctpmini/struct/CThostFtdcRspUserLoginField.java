package com.ctpmini.struct;

/**
 * 用户登录应答
 * 对应 C++ 结构体: CThostFtdcRspUserLoginField
 */
public class CThostFtdcRspUserLoginField {
    /** 交易日 (8字节) */
    public String TradingDay;
    /** 登录成功时间 (9字节) */
    public String LoginTime;
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 用户代码 (16字节) */
    public String UserID;
    /** 交易系统名称 (41字节) */
    public String SystemName;
    /** 前置编号 */
    public int FrontID;
    /** 会话编号 */
    public int SessionID;
    /** 最大报单引用 (13字节) */
    public String MaxOrderRef;
    /** 上期所时间 (9字节) */
    public String SHFETime;
    /** 大商所时间 (9字节) */
    public String DCETime;
    /** 郑商所时间 (9字节) */
    public String CZCETime;
    /** 中金所时间 (9字节) */
    public String FFEXTime;
    /** 能源所时间 (9字节) */
    public String INETime;
    /** 广期所时间 (9字节) */
    public String GFEXTime;
}
