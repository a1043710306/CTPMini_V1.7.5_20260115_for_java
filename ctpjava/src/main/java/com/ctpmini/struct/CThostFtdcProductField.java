package com.ctpmini.struct;

/**
 * 产品
 * 对应 C++ 结构体: CThostFtdcProductField
 */
public class CThostFtdcProductField {
    /** 产品代码 (81字节) */
    public String ProductID;
    /** 产品名称 (21字节) */
    public String ProductName;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 产品类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PC_* */
    public char ProductClass;
    /** 合约数量乘数 */
    public int VolumeMultiple;
    /** 最小变动价位 */
    public double PriceTick;
    /** 市价单最大下单量 */
    public int MaxMarketOrderVolume;
    /** 市价单最小下单量 */
    public int MinMarketOrderVolume;
    /** 限价单最大下单量 */
    public int MaxLimitOrderVolume;
    /** 限价单最小下单量 */
    public int MinLimitOrderVolume;
    /** 持仓类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PT_* */
    public char PositionType;
    /** 持仓日期类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PDT_* */
    public char PositionDateType;
    /** 平仓处理类型 */
    public char CloseDealType;
    /** 交易币种类型 */
    public String TradeCurrencyID;
    /** 质押资金使用范围 */
    public char MortgageFundUseRange;
    /** 交易所产品代码 (81字节) */
    public String ExchangeProductID;
    /** 合约基础商品乘数 */
    public double UnderlyingMultiple;
}
