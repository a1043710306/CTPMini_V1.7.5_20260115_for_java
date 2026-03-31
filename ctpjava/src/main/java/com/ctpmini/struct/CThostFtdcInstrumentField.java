package com.ctpmini.struct;

/**
 * 合约
 * 对应 C++ 结构体: CThostFtdcInstrumentField
 */
public class CThostFtdcInstrumentField {
    /** 合约代码 (81字节) */
    public String InstrumentID;
    /** 交易所代码 (9字节) */
    public String ExchangeID;
    /** 合约名称 (21字节) */
    public String InstrumentName;
    /** 合约在交易所的代码 (81字节) */
    public String ExchangeInstID;
    /** 产品代码 (81字节) */
    public String ProductID;
    /** 产品类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PC_* */
    public char ProductClass;
    /** 交割年份 */
    public int DeliveryYear;
    /** 交割月 */
    public int DeliveryMonth;
    /** 市价单最大下单量 */
    public int MaxMarketOrderVolume;
    /** 市价单最小下单量 */
    public int MinMarketOrderVolume;
    /** 限价单最大下单量 */
    public int MaxLimitOrderVolume;
    /** 限价单最小下单量 */
    public int MinLimitOrderVolume;
    /** 合约数量乘数 */
    public int VolumeMultiple;
    /** 最小变动价位 */
    public double PriceTick;
    /** 创建日 (8字节) */
    public String CreateDate;
    /** 上市日 (8字节) */
    public String OpenDate;
    /** 到期日 (8字节) */
    public String ExpireDate;
    /** 开始交割日 (8字节) */
    public String StartDelivDate;
    /** 结束交割日 (8字节) */
    public String EndDelivDate;
    /** 合约生命周期状态 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_IP_* */
    public char InstLifePhase;
    /** 当前是否交易 (0=否, 1=是) */
    public int IsTrading;
    /** 持仓类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PT_* */
    public char PositionType;
    /** 持仓日期类型 @see com.ctpmini.constants.ThostFtdcUserApiDataType.THOST_FTDC_PDT_* */
    public char PositionDateType;
    /** 多头保证金率 */
    public double LongMarginRatio;
    /** 空头保证金率 */
    public double ShortMarginRatio;
    /** 是否使用大额单边保证金算法 */
    public char MaxMarginSideAlgorithm;
    /** 基础商品代码 (81字节) */
    public String UnderlyingInstrID;
    /** 执行价 */
    public double StrikePrice;
    /** 期权类型 */
    public char OptionsType;
    /** 合约基础商品乘数 */
    public double UnderlyingMultiple;
    /** 组合类型 */
    public char CombinationType;
}
