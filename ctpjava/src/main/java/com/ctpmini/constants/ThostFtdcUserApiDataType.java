package com.ctpmini.constants;

/**
 * CTP Mini API 数据类型常量定义
 * 对应 C++ 头文件: ThostFtdcUserApiDataType.h
 *
 * @system 上海期货信息技术有限公司 - CTP Mini交易系统
 */
public class ThostFtdcUserApiDataType {

    // ===== 流控恢复类型 THOST_TE_RESUME_TYPE =====
    /** 从本地记录的序号开始重传 */
    public static final int THOST_TERT_RESTART = 0;
    /** 从上次收到的续传 */
    public static final int THOST_TERT_RESUME = 1;
    /** 只传送登录后私有流的内容 */
    public static final int THOST_TERT_QUICK = 2;

    // ===== 交易所属性 TFtdcExchangePropertyType =====
    /** 正常 */
    public static final char THOST_FTDC_EXP_Normal = '0';
    /** 根据成交生成报单 */
    public static final char THOST_FTDC_EXP_GenOrderByTrade = '1';

    // ===== 证件类型 TFtdcIdCardTypeType =====
    /** 组织机构代码 */
    public static final char THOST_FTDC_ICT_EID = '0';
    /** 中国公民身份证 */
    public static final char THOST_FTDC_ICT_IDCard = '1';
    /** 军官证 */
    public static final char THOST_FTDC_ICT_OfficerIDCard = '2';
    /** 警察证 */
    public static final char THOST_FTDC_ICT_PoliceIDCard = '3';
    /** 士兵证 */
    public static final char THOST_FTDC_ICT_SoldierIDCard = '4';
    /** 户口本 */
    public static final char THOST_FTDC_ICT_HouseholdRegister = '5';
    /** 护照 */
    public static final char THOST_FTDC_ICT_Passport = '6';
    /** 台胞证 */
    public static final char THOST_FTDC_ICT_TaiwanCompatriotIDCard = '7';
    /** 回乡证 */
    public static final char THOST_FTDC_ICT_HomeComingCard = '8';
    /** 营业执照号 */
    public static final char THOST_FTDC_ICT_LicenseNo = '9';
    /** 税务登记号/纳税人识别号 */
    public static final char THOST_FTDC_ICT_TaxNo = 'A';
    /** 港澳居民来往内地通行证 */
    public static final char THOST_FTDC_ICT_HMMainlandTravelPermit = 'B';
    /** 台湾居民来往大陆通行证 */
    public static final char THOST_FTDC_ICT_TwMainlandTravelPermit = 'C';
    /** 驾照 */
    public static final char THOST_FTDC_ICT_DrivingLicense = 'D';
    /** 当地社保ID */
    public static final char THOST_FTDC_ICT_SocialID = 'F';
    /** 当地身份证 */
    public static final char THOST_FTDC_ICT_LocalID = 'G';
    /** 商业登记证 */
    public static final char THOST_FTDC_ICT_BusinessRegistration = 'H';
    /** 港澳永久性居民身份证 */
    public static final char THOST_FTDC_ICT_HKMCIDCard = 'I';
    /** 人行开户许可证 */
    public static final char THOST_FTDC_ICT_AccountsPermits = 'J';
    /** 其他证件 */
    public static final char THOST_FTDC_ICT_OtherCard = 'x';

    // ===== 投资者范围 TFtdcInvestorRangeType =====
    /** 所有 */
    public static final char THOST_FTDC_IR_All = '1';
    /** 投资者组 */
    public static final char THOST_FTDC_IR_Group = '2';
    /** 单一投资者 */
    public static final char THOST_FTDC_IR_Single = '3';

    // ===== 部门范围 TFtdcDepartmentRangeType =====
    /** 所有 */
    public static final char THOST_FTDC_DR_All = '1';
    /** 组织架构 */
    public static final char THOST_FTDC_DR_Group = '2';
    /** 单一投资者 */
    public static final char THOST_FTDC_DR_Single = '3';

    // ===== 数据同步状态 TFtdcDataSyncStatusType =====
    /** 未同步 */
    public static final char THOST_FTDC_DS_Asynchronous = '1';
    /** 同步中 */
    public static final char THOST_FTDC_DS_Synchronizing = '2';
    /** 已同步 */
    public static final char THOST_FTDC_DS_Synchronized = '3';

    // ===== 经纪公司数据同步状态 TFtdcBrokerDataSyncStatusType =====
    /** 已同步 */
    public static final char THOST_FTDC_BDS_Synchronized = '1';
    /** 同步中 */
    public static final char THOST_FTDC_BDS_Synchronizing = '2';

    // ===== 交易所连接状态 TFtdcExchangeConnectStatusType =====
    /** 没有任何连接 */
    public static final char THOST_FTDC_ECS_NoConnection = '1';
    /** 已经发出合约查询请求 */
    public static final char THOST_FTDC_ECS_QryInstrumentSent = '2';
    /** 已经获取信息 */
    public static final char THOST_FTDC_ECS_GotInformation = '9';

    // ===== 交易所交易员连接状态 TFtdcTraderConnectStatusType =====
    /** 没有任何连接 */
    public static final char THOST_FTDC_TCS_NotConnected = '1';
    /** 已经连接 */
    public static final char THOST_FTDC_TCS_Connected = '2';
    /** 已经发出合约查询请求 */
    public static final char THOST_FTDC_TCS_QryInstrumentSent = '3';
    /** 订阅私有流 */
    public static final char THOST_FTDC_TCS_SubPrivateFlow = '4';

    // ===== 功能代码 TFtdcFunctionCodeType =====
    /** 数据异步化 */
    public static final char THOST_FTDC_FC_DataAsync = '1';
    /** 强制用户退出 */
    public static final char THOST_FTDC_FC_ForceUserLogout = '2';
    /** 变更用户口令 */
    public static final char THOST_FTDC_FC_UserPasswordUpdate = '3';
    /** 变更经纪公司口令 */
    public static final char THOST_FTDC_FC_BrokerPasswordUpdate = '4';
    /** 变更投资者口令 */
    public static final char THOST_FTDC_FC_InvestorPasswordUpdate = '5';
    /** 报单插入 */
    public static final char THOST_FTDC_FC_OrderInsert = '6';
    /** 报单操作 */
    public static final char THOST_FTDC_FC_OrderAction = '7';
    /** 同步系统信息 */
    public static final char THOST_FTDC_FC_SyncSystemData = '8';
    /** 同步经纪公司信息 */
    public static final char THOST_FTDC_FC_SyncBrokerData = '9';
    /** 批量同步经纪公司信息 */
    public static final char THOST_FTDC_FC_BachSyncBrokerData = 'A';
    /** 超级查询 */
    public static final char THOST_FTDC_FC_SuperQuery = 'B';
    /** 预埋报单插入 */
    public static final char THOST_FTDC_FC_ParkedOrderInsert = 'C';
    /** 预埋报单操作 */
    public static final char THOST_FTDC_FC_ParkedOrderAction = 'D';
    /** 同步动态令牌 */
    public static final char THOST_FTDC_FC_SyncOTP = 'E';
    /** 删除未知单 */
    public static final char THOST_FTDC_FC_DeleteOrder = 'F';

    // ===== 报单操作状态 TFtdcOrderActionStatusType =====
    /** 已经提交 */
    public static final char THOST_FTDC_OAS_Submitted = 'a';
    /** 已经接受 */
    public static final char THOST_FTDC_OAS_Accepted = 'b';
    /** 已经被拒绝 */
    public static final char THOST_FTDC_OAS_Rejected = 'c';

    // ===== 报单状态 TFtdcOrderStatusType =====
    /** 全部成交 */
    public static final char THOST_FTDC_OST_AllTraded = '0';
    /** 部分成交还在队列中 */
    public static final char THOST_FTDC_OST_PartTradedQueueing = '1';
    /** 部分成交不在队列中 */
    public static final char THOST_FTDC_OST_PartTradedNotQueueing = '2';
    /** 未成交还在队列中 */
    public static final char THOST_FTDC_OST_NoTradeQueueing = '3';
    /** 未成交不在队列中 */
    public static final char THOST_FTDC_OST_NoTradeNotQueueing = '4';
    /** 撤单 */
    public static final char THOST_FTDC_OST_Canceled = '5';
    /** 未知 */
    public static final char THOST_FTDC_OST_Unknown = 'a';
    /** 尚未触发 */
    public static final char THOST_FTDC_OST_NotTouched = 'b';
    /** 已触发 */
    public static final char THOST_FTDC_OST_Touched = 'c';

    // ===== 报单提交状态 TFtdcOrderSubmitStatusType =====
    /** 已经提交 */
    public static final char THOST_FTDC_OSS_InsertSubmitted = '0';
    /** 撤单已经提交 */
    public static final char THOST_FTDC_OSS_CancelSubmitted = '1';
    /** 修改已经提交 */
    public static final char THOST_FTDC_OSS_ModifySubmitted = '2';
    /** 已经接受 */
    public static final char THOST_FTDC_OSS_Accepted = '3';
    /** 报单已经被拒绝 */
    public static final char THOST_FTDC_OSS_InsertRejected = '4';
    /** 撤单已经被拒绝 */
    public static final char THOST_FTDC_OSS_CancelRejected = '5';
    /** 改单已经被拒绝 */
    public static final char THOST_FTDC_OSS_ModifyRejected = '6';

    // ===== 持仓日期 TFtdcPositionDateType =====
    /** 今日持仓 */
    public static final char THOST_FTDC_PSD_Today = '1';
    /** 历史持仓 */
    public static final char THOST_FTDC_PSD_History = '2';

    // ===== 持仓日期类型 TFtdcPositionDateTypeType =====
    /** 使用历史持仓 */
    public static final char THOST_FTDC_PDT_UseHistory = '1';
    /** 不使用历史持仓 */
    public static final char THOST_FTDC_PDT_NoUseHistory = '2';

    // ===== 交易角色 TFtdcTradingRoleType =====
    /** 代理 */
    public static final char THOST_FTDC_ER_Broker = '1';
    /** 自营 */
    public static final char THOST_FTDC_ER_Host = '2';
    /** 做市商 */
    public static final char THOST_FTDC_ER_Maker = '3';

    // ===== 产品类型 TFtdcProductClassType =====
    /** 期货 */
    public static final char THOST_FTDC_PC_Futures = '1';
    /** 期货期权 */
    public static final char THOST_FTDC_PC_Options = '2';
    /** 组合 */
    public static final char THOST_FTDC_PC_Combination = '3';
    /** 即期 */
    public static final char THOST_FTDC_PC_Spot = '4';
    /** 期转现 */
    public static final char THOST_FTDC_PC_EFP = '5';
    /** 现货期权 */
    public static final char THOST_FTDC_PC_SpotOption = '6';
    /** TAS合约 */
    public static final char THOST_FTDC_PC_TAS = '7';

    // ===== 合约生命周期状态 TFtdcInstLifePhaseType =====
    /** 未上市 */
    public static final char THOST_FTDC_IP_NotStart = '0';
    /** 上市 */
    public static final char THOST_FTDC_IP_Started = '1';
    /** 停牌 */
    public static final char THOST_FTDC_IP_Pause = '2';
    /** 到期 */
    public static final char THOST_FTDC_IP_Expired = '3';

    // ===== 买卖方向 TFtdcDirectionType =====
    /** 买 */
    public static final char THOST_FTDC_D_Buy = '0';
    /** 卖 */
    public static final char THOST_FTDC_D_Sell = '1';

    // ===== 持仓类型 TFtdcPositionTypeType =====
    /** 净持仓 */
    public static final char THOST_FTDC_PT_Net = '1';
    /** 综合持仓 */
    public static final char THOST_FTDC_PT_Gross = '2';

    // ===== 持仓多空方向 TFtdcPosiDirectionType =====
    /** 净 */
    public static final char THOST_FTDC_PD_Net = '1';
    /** 多头 */
    public static final char THOST_FTDC_PD_Long = '2';
    /** 空头 */
    public static final char THOST_FTDC_PD_Short = '3';

    // ===== 系统结算状态 TFtdcSysSettlementStatusType =====
    /** 不活跃 */
    public static final char THOST_FTDC_SS_NonActive = '1';
    /** 启动 */
    public static final char THOST_FTDC_SS_Startup = '2';
    /** 操作 */
    public static final char THOST_FTDC_SS_Operating = '3';
    /** 结算 */
    public static final char THOST_FTDC_SS_Settlement = '4';
    /** 结算完成 */
    public static final char THOST_FTDC_SS_SettlementFinished = '5';

    // ===== 投机套保标志 TFtdcHedgeFlagType =====
    /** 投机 */
    public static final char THOST_FTDC_HF_Speculation = '1';
    /** 套利 */
    public static final char THOST_FTDC_HF_Arbitrage = '2';
    /** 套保 */
    public static final char THOST_FTDC_HF_Hedge = '3';
    /** 做市商 */
    public static final char THOST_FTDC_HF_MarketMaker = '5';
    /** 第一腿投机第二腿套保 */
    public static final char THOST_FTDC_HF_SpecHedge = '6';
    /** 第一腿套保第二腿投机 */
    public static final char THOST_FTDC_HF_HedgeSpec = '7';

    // ===== 客户端编码类型 TFtdcClientIDTypeType =====
    /** 投机 */
    public static final char THOST_FTDC_CIDT_Speculation = '1';
    /** 套利 */
    public static final char THOST_FTDC_CIDT_Arbitrage = '2';
    /** 套保 */
    public static final char THOST_FTDC_CIDT_Hedge = '3';
    /** 做市商 */
    public static final char THOST_FTDC_CIDT_MarketMaker = '5';

    // ===== 报单价格条件 TFtdcOrderPriceTypeType =====
    /** 任意价 */
    public static final char THOST_FTDC_OPT_AnyPrice = '1';
    /** 限价 */
    public static final char THOST_FTDC_OPT_LimitPrice = '2';
    /** 最优价 */
    public static final char THOST_FTDC_OPT_BestPrice = '3';
    /** 最新价 */
    public static final char THOST_FTDC_OPT_LastPrice = '4';
    /** 最新价浮动上浮1个ticks */
    public static final char THOST_FTDC_OPT_LastPricePlusOneTicks = '5';
    /** 最新价浮动上浮2个ticks */
    public static final char THOST_FTDC_OPT_LastPricePlusTwoTicks = '6';
    /** 最新价浮动上浮3个ticks */
    public static final char THOST_FTDC_OPT_LastPricePlusThreeTicks = '7';
    /** 卖一价 */
    public static final char THOST_FTDC_OPT_AskPrice1 = '8';
    /** 卖一价浮动上浮1个ticks */
    public static final char THOST_FTDC_OPT_AskPrice1PlusOneTicks = '9';
    /** 卖一价浮动上浮2个ticks */
    public static final char THOST_FTDC_OPT_AskPrice1PlusTwoTicks = 'A';
    /** 卖一价浮动上浮3个ticks */
    public static final char THOST_FTDC_OPT_AskPrice1PlusThreeTicks = 'B';
    /** 买一价 */
    public static final char THOST_FTDC_OPT_BidPrice1 = 'C';
    /** 买一价浮动上浮1个ticks */
    public static final char THOST_FTDC_OPT_BidPrice1PlusOneTicks = 'D';
    /** 买一价浮动上浮2个ticks */
    public static final char THOST_FTDC_OPT_BidPrice1PlusTwoTicks = 'E';
    /** 买一价浮动上浮3个ticks */
    public static final char THOST_FTDC_OPT_BidPrice1PlusThreeTicks = 'F';
    /** 五档价 */
    public static final char THOST_FTDC_OPT_FiveLevelPrice = 'G';

    // ===== 开平标志 TFtdcOffsetFlagType =====
    /** 开仓 */
    public static final char THOST_FTDC_OF_Open = '0';
    /** 平仓 */
    public static final char THOST_FTDC_OF_Close = '1';
    /** 强平 */
    public static final char THOST_FTDC_OF_ForceClose = '2';
    /** 平今 */
    public static final char THOST_FTDC_OF_CloseToday = '3';
    /** 平昨 */
    public static final char THOST_FTDC_OF_CloseYesterday = '4';
    /** 强减 */
    public static final char THOST_FTDC_OF_ForceOff = '5';
    /** 本地强平 */
    public static final char THOST_FTDC_OF_LocalForceClose = '6';

    // ===== 强平原因 TFtdcForceCloseReasonType =====
    /** 非强平 */
    public static final char THOST_FTDC_FCC_NotForceClose = '0';
    /** 资金不足 */
    public static final char THOST_FTDC_FCC_LackDeposit = '1';
    /** 客户超仓 */
    public static final char THOST_FTDC_FCC_ClientOverPositionLimit = '2';
    /** 会员超仓 */
    public static final char THOST_FTDC_FCC_MemberOverPositionLimit = '3';
    /** 持仓非整数倍 */
    public static final char THOST_FTDC_FCC_NotMultiple = '4';
    /** 违规 */
    public static final char THOST_FTDC_FCC_Violation = '5';
    /** 其它 */
    public static final char THOST_FTDC_FCC_Other = '6';
    /** 自然人临近交割 */
    public static final char THOST_FTDC_FCC_PersonDeliv = '7';

    // ===== 报单类型 TFtdcOrderTypeType =====
    /** 正常 */
    public static final char THOST_FTDC_ORDT_Normal = '0';
    /** 报价衍生 */
    public static final char THOST_FTDC_ORDT_DeriveFromQuote = '1';
    /** 组合衍生 */
    public static final char THOST_FTDC_ORDT_DeriveFromCombination = '2';
    /** 组合报单 */
    public static final char THOST_FTDC_ORDT_Combination = '3';
    /** 条件单 */
    public static final char THOST_FTDC_ORDT_ConditionalOrder = '4';
    /** 互换单 */
    public static final char THOST_FTDC_ORDT_Swap = '5';

    // ===== 有效期类型 TFtdcTimeConditionType =====
    /** 立即完成，否则撤销 */
    public static final char THOST_FTDC_TC_IOC = '1';
    /** 本节有效 */
    public static final char THOST_FTDC_TC_GFS = '2';
    /** 当日有效 */
    public static final char THOST_FTDC_TC_GFD = '3';
    /** 指定日期前有效 */
    public static final char THOST_FTDC_TC_GTD = '4';
    /** 撤销前有效 */
    public static final char THOST_FTDC_TC_GTC = '5';
    /** 集合竞价有效 */
    public static final char THOST_FTDC_TC_GFA = '6';

    // ===== 成交量类型 TFtdcVolumeConditionType =====
    /** 任何数量 */
    public static final char THOST_FTDC_VC_AV = '1';
    /** 最小数量 */
    public static final char THOST_FTDC_VC_MV = '2';
    /** 全部数量 */
    public static final char THOST_FTDC_VC_CV = '3';

    // ===== 触发条件 TFtdcContingentConditionType =====
    /** 立即 */
    public static final char THOST_FTDC_CC_Immediately = '1';
    /** 止损 */
    public static final char THOST_FTDC_CC_Touch = '2';
    /** 止赢 */
    public static final char THOST_FTDC_CC_TouchProfit = '3';
    /** 预埋单 */
    public static final char THOST_FTDC_CC_ParkedOrder = '4';
    /** 最新价大于条件价 */
    public static final char THOST_FTDC_CC_LastPriceGreaterThanStopPrice = '5';
    /** 最新价大于等于条件价 */
    public static final char THOST_FTDC_CC_LastPriceGreaterEqualStopPrice = '6';
    /** 最新价小于条件价 */
    public static final char THOST_FTDC_CC_LastPriceLesserThanStopPrice = '7';
    /** 最新价小于等于条件价 */
    public static final char THOST_FTDC_CC_LastPriceLesserEqualStopPrice = '8';
    /** 卖一价大于条件价 */
    public static final char THOST_FTDC_CC_AskPriceGreaterThanStopPrice = '9';
    /** 卖一价大于等于条件价 */
    public static final char THOST_FTDC_CC_AskPriceGreaterEqualStopPrice = 'A';
    /** 卖一价小于条件价 */
    public static final char THOST_FTDC_CC_AskPriceLesserThanStopPrice = 'B';
    /** 卖一价小于等于条件价 */
    public static final char THOST_FTDC_CC_AskPriceLesserEqualStopPrice = 'C';
    /** 买一价大于条件价 */
    public static final char THOST_FTDC_CC_BidPriceGreaterThanStopPrice = 'D';
    /** 买一价大于等于条件价 */
    public static final char THOST_FTDC_CC_BidPriceGreaterEqualStopPrice = 'E';
    /** 买一价小于条件价 */
    public static final char THOST_FTDC_CC_BidPriceLesserThanStopPrice = 'F';
    /** 买一价小于等于条件价 */
    public static final char THOST_FTDC_CC_BidPriceLesserEqualStopPrice = 'H';

    // ===== 操作标志 TFtdcActionFlagType =====
    /** 删除 */
    public static final char THOST_FTDC_AF_Delete = '0';
    /** 修改 */
    public static final char THOST_FTDC_AF_Modify = '3';

    // ===== 执行类型 TFtdcActionTypeType =====
    /** 执行 */
    public static final char THOST_FTDC_ACTP_Exec = '1';
    /** 放弃 */
    public static final char THOST_FTDC_ACTP_Abandon = '2';

    // ===== 批量撤单模式 TFtdcMKActionModeType =====
    /** 产品 */
    public static final char THOST_FTDC_MKAM_Product = '1';
    /** OrderRef */
    public static final char THOST_FTDC_MKAM_OrderRef = '2';

    // ===== 交易权限 TFtdcTradingRightType =====
    /** 可以交易 */
    public static final char THOST_FTDC_TR_Allow = '0';
    /** 只能平仓 */
    public static final char THOST_FTDC_TR_CloseOnly = '1';
    /** 不能交易 */
    public static final char THOST_FTDC_TR_Forbidden = '2';

    // ===== 报单来源 TFtdcOrderSourceType =====
    /** 来自参与者 */
    public static final char THOST_FTDC_OSRC_Participant = '0';
    /** 来自管理员 */
    public static final char THOST_FTDC_OSRC_Administrator = '1';

    // ===== 成交类型 TFtdcTradeTypeType =====
    /** 组合持仓拆分为单一持仓,初始化对应的持仓日期类型的持仓 */
    public static final char THOST_FTDC_TRDT_SplitCombination = '#';
    /** 普通成交 */
    public static final char THOST_FTDC_TRDT_Common = '0';
    /** 期权执行 */
    public static final char THOST_FTDC_TRDT_OptionsExecution = '1';
    /** OTC成交 */
    public static final char THOST_FTDC_TRDT_OTC = '2';
    /** 期转现衍生成交 */
    public static final char THOST_FTDC_TRDT_EFPDerived = '3';
    /** 组合衍生成交 */
    public static final char THOST_FTDC_TRDT_CombinationDerived = '4';

    // ===== 成交价来源 TFtdcPriceSourceType =====
    /** 前成交价 */
    public static final char THOST_FTDC_PSRC_LastPrice = '0';
    /** 买委托价 */
    public static final char THOST_FTDC_PSRC_Buy = '1';
    /** 卖委托价 */
    public static final char THOST_FTDC_PSRC_Sell = '2';

    // ===== 合约交易状态 TFtdcInstrumentStatusType =====
    /** 开盘前 */
    public static final char THOST_FTDC_IS_BeforeTrading = '0';
    /** 非交易 */
    public static final char THOST_FTDC_IS_NoTrading = '1';
    /** 连续交易 */
    public static final char THOST_FTDC_IS_Continous = '2';
    /** 集合竞价报单 */
    public static final char THOST_FTDC_IS_AuctionOrdering = '3';
    /** 集合竞价价格平衡 */
    public static final char THOST_FTDC_IS_AuctionBalance = '4';
    /** 集合竞价撮合 */
    public static final char THOST_FTDC_IS_AuctionMatch = '5';
    /** 收盘 */
    public static final char THOST_FTDC_IS_Closed = '6';

    // ===== 品种进入交易状态原因 TFtdcInstStatusEnterReasonType =====
    /** 自动切换 */
    public static final char THOST_FTDC_IER_Automatic = '1';
    /** 手动切换 */
    public static final char THOST_FTDC_IER_Manual = '2';
    /** 熔断 */
    public static final char THOST_FTDC_IER_Fuse = '3';

    // ===== 查询错误代码 =====
    public static final int QRY_ERROR_NONE = 0;
    public static final int QRY_ERROR_INVALID_LOGIN = -1;
    public static final int QRY_ERROR_DUPLICATE_LOGIN = 2;
    public static final int QRY_ERROR_NOT_LOGIN_YET = -3;
    /** 无此权限，或者已管理员未登录 */
    public static final int QRY_ERROR_NO_PRIVILEGE = -4;
    /** 查询错误：查询拒绝，存在未完成的查询请求 */
    public static final int QRY_ERROR_REQUEST = -6;

    private ThostFtdcUserApiDataType() {
        // 工具类，不允许实例化
    }
}
