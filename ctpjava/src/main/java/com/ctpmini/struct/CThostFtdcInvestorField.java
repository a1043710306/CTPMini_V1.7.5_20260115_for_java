package com.ctpmini.struct;

/**
 * 投资者
 * 对应 C++ 结构体: CThostFtdcInvestorField
 */
public class CThostFtdcInvestorField {
    /** 投资者代码 (13字节) */
    public String InvestorID;
    /** 经纪公司代码 (11字节) */
    public String BrokerID;
    /** 投资者分组代码 (13字节) */
    public String InvestorGroupID;
    /** 投资者名称 (81字节) */
    public String InvestorName;
    /** 证件类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_ICT_* */
    public char IdentifiedCardType;
    /** 证件号码 (51字节) */
    public String IdentifiedCardNo;
    /** 是否活跃 (0=否, 1=是) */
    public int IsActive;
    /** 联系电话 (41字节) */
    public String Telephone;
    /** 通讯地址 (101字节) */
    public String Address;
    /** 开户日期 (8字节) */
    public String OpenDate;
    /** 手机 (41字节) */
    public String Mobile;
    /** 手续费率模板代码 (13字节) */
    public String CommModelID;
    /** 保证金率模板代码 (13字节) */
    public String MarginModelID;
}
