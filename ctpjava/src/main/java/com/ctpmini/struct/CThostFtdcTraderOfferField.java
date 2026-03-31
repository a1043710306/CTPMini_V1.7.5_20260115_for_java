package com.ctpmini.struct;

/**
 * 交易员报盘
 * 对应 C++ 结构体: CThostFtdcTraderOfferField
 */
public class CThostFtdcTraderOfferField {
    /** 交易所代码 */
    public String ExchangeID;
    /** 交易员代码 */
    public String TraderID;
    /** 会员代码 */
    public String ParticipantID;
    /** 密码 */
    public String Password;
    /** 安装编号 */
    public int InstallID;
    /** 本地报单编号 */
    public String OrderLocalID;
    /** 交易员连接状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_TCS_* */
    public char TraderConnectStatus;
    /** 发出连接请求的日期 */
    public String ConnectRequestDate;
    /** 发出连接请求的时间 */
    public String ConnectRequestTime;
    /** 上次报告日期 */
    public String LastReportDate;
    /** 上次报告时间 */
    public String LastReportTime;
    /** 完成连接日期 */
    public String ConnectDate;
    /** 完成连接时间 */
    public String ConnectTime;
    /** 启动日期 */
    public String StartDate;
    /** 启动时间 */
    public String StartTime;
    /** 交易日 */
    public String TradingDay;
    /** 经纪公司代码 */
    public String BrokerID;
    /** 本席位最大成交编号 */
    public String MaxTradeID;
    /** 本席位最大报单备拷 */
    public String MaxOrderMessageReference;
}
