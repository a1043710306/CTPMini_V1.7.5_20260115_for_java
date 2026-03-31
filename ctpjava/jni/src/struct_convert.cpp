/**
 * struct_convert.cpp
 * CTP C++ struct <-> Java POJO 字段映射实现
 *
 * ToJava_XYZ   : CThostFtdcXYZField* -> jobject (com/ctpmini/struct/CThostFtdcXYZField)
 * FromJava_XYZ : jobject             -> CThostFtdcXYZField&
 */

#include "jni_utils.h"

/* ---- 字段操作快捷宏（函数体内已有 env/obj/cls） ---- */
#define S(f,v) SET_STR(env,obj,cls,f,v)
#define I(f,v) SET_INT(env,obj,cls,f,v)
#define D(f,v) SET_DBL(env,obj,cls,f,v)
#define C(f,v) SET_CHR(env,obj,cls,f,v)

#define BEGIN_TO_JAVA(javaClass) \
    if (!p) return nullptr; \
    jobject obj = NewJavaObject(env, javaClass); \
    if (!obj) return nullptr; \
    jclass cls = env->GetObjectClass(obj);

#define END_TO_JAVA \
    env->DeleteLocalRef(cls); \
    return obj;

#define BEGIN_FROM_JAVA \
    memset(&out, 0, sizeof(out)); \
    if (!obj) return; \
    jclass cls = env->GetObjectClass(obj);

#define END_FROM_JAVA \
    env->DeleteLocalRef(cls);

/* ============================================================
   ToJava_* : CTP struct -> Java POJO
   ============================================================ */

jobject ToJava_RspInfo(JNIEnv* env, CThostFtdcRspInfoField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRspInfoField")
    I("errorID",  p->ErrorID);
    S("errorMsg", p->ErrorMsg);
    END_TO_JAVA
}

jobject ToJava_RspUserLogin(JNIEnv* env, CThostFtdcRspUserLoginField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRspUserLoginField")
    S("tradingDay",  p->TradingDay);
    S("loginTime",   p->LoginTime);
    S("brokerID",    p->BrokerID);
    S("userID",      p->UserID);
    S("systemName",  p->SystemName);
    I("frontID",     p->FrontID);
    I("sessionID",   p->SessionID);
    S("maxOrderRef", p->MaxOrderRef);
    S("sHFETime",    p->SHFETime);
    S("dCETime",     p->DCETime);
    S("cZCETime",    p->CZCETime);
    S("fFEXTime",    p->FFEXTime);
    S("iNETime",     p->INETime);
    S("gFEXTime",    p->GFEXTime);
    END_TO_JAVA
}

jobject ToJava_UserLogout(JNIEnv* env, CThostFtdcUserLogoutField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcUserLogoutField")
    S("brokerID", p->BrokerID);
    S("userID",   p->UserID);
    END_TO_JAVA
}

jobject ToJava_RspAuthenticate(JNIEnv* env, CThostFtdcRspAuthenticateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRspAuthenticateField")
    S("brokerID",        p->BrokerID);
    S("userID",          p->UserID);
    S("userProductInfo", p->UserProductInfo);
    S("appID",           p->AppID);
    END_TO_JAVA
}

jobject ToJava_SpecificInstrument(JNIEnv* env, CThostFtdcSpecificInstrumentField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcSpecificInstrumentField")
    S("instrumentID", p->InstrumentID);
    END_TO_JAVA
}

jobject ToJava_DepthMarketData(JNIEnv* env, CThostFtdcDepthMarketDataField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcDepthMarketDataField")
    S("tradingDay",         p->TradingDay);
    S("instrumentID",       p->InstrumentID);
    S("exchangeID",         p->ExchangeID);
    S("exchangeInstID",     p->ExchangeInstID);
    D("lastPrice",          p->LastPrice);
    D("preSettlementPrice", p->PreSettlementPrice);
    D("preClosePrice",      p->PreClosePrice);
    D("preOpenInterest",    p->PreOpenInterest);
    D("openPrice",          p->OpenPrice);
    D("highestPrice",       p->HighestPrice);
    D("lowestPrice",        p->LowestPrice);
    I("volume",             p->Volume);
    D("turnover",           p->Turnover);
    D("openInterest",       p->OpenInterest);
    D("closePrice",         p->ClosePrice);
    D("settlementPrice",    p->SettlementPrice);
    D("upperLimitPrice",    p->UpperLimitPrice);
    D("lowerLimitPrice",    p->LowerLimitPrice);
    D("preDelta",           p->PreDelta);
    D("currDelta",          p->CurrDelta);
    S("updateTime",         p->UpdateTime);
    I("updateMillisec",     p->UpdateMillisec);
    D("bidPrice1",          p->BidPrice1);
    I("bidVolume1",         p->BidVolume1);
    D("askPrice1",          p->AskPrice1);
    I("askVolume1",         p->AskVolume1);
    D("bidPrice2",          p->BidPrice2);
    I("bidVolume2",         p->BidVolume2);
    D("askPrice2",          p->AskPrice2);
    I("askVolume2",         p->AskVolume2);
    D("bidPrice3",          p->BidPrice3);
    I("bidVolume3",         p->BidVolume3);
    D("askPrice3",          p->AskPrice3);
    I("askVolume3",         p->AskVolume3);
    D("bidPrice4",          p->BidPrice4);
    I("bidVolume4",         p->BidVolume4);
    D("askPrice4",          p->AskPrice4);
    I("askVolume4",         p->AskVolume4);
    D("bidPrice5",          p->BidPrice5);
    I("bidVolume5",         p->BidVolume5);
    D("askPrice5",          p->AskPrice5);
    I("askVolume5",         p->AskVolume5);
    D("averagePrice",       p->AveragePrice);
    S("actionDay",          p->ActionDay);
    END_TO_JAVA
}

jobject ToJava_DepthMarketDataQry(JNIEnv* env, CThostFtdcDepthMarketDataField* p) {
    return ToJava_DepthMarketData(env, p);
}

jobject ToJava_MBLMarketData(JNIEnv* env, CThostFtdcMBLMarketDataField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcMBLMarketDataField")
    S("instrumentID", p->InstrumentID);
    C("direction",    p->Direction);
    D("price",        p->Price);
    I("volume",       p->Volume);
    END_TO_JAVA
}

jobject ToJava_ForQuoteRsp(JNIEnv* env, CThostFtdcForQuoteRspField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcForQuoteRspField")
    S("tradingDay",    p->TradingDay);
    S("instrumentID",  p->InstrumentID);
    S("forQuoteSysID", p->ForQuoteSysID);
    S("forQuoteTime",  p->ForQuoteTime);
    S("actionDay",     p->ActionDay);
    S("exchangeID",    p->ExchangeID);
    END_TO_JAVA
}

jobject ToJava_InputOrder(JNIEnv* env, CThostFtdcInputOrderField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputOrderField")
    S("brokerID",            p->BrokerID);
    S("investorID",          p->InvestorID);
    S("instrumentID",        p->InstrumentID);
    S("orderRef",            p->OrderRef);
    S("userID",              p->UserID);
    C("orderPriceType",      p->OrderPriceType);
    C("direction",           p->Direction);
    S("combOffsetFlag",      p->CombOffsetFlag);
    S("combHedgeFlag",       p->CombHedgeFlag);
    D("limitPrice",          p->LimitPrice);
    I("volumeTotalOriginal", p->VolumeTotalOriginal);
    C("timeCondition",       p->TimeCondition);
    S("gTDDate",             p->GTDDate);
    C("volumeCondition",     p->VolumeCondition);
    I("minVolume",           p->MinVolume);
    C("contingentCondition", p->ContingentCondition);
    D("stopPrice",           p->StopPrice);
    C("forceCloseReason",    p->ForceCloseReason);
    I("isAutoSuspend",       p->IsAutoSuspend);
    S("businessUnit",        p->BusinessUnit);
    I("requestID",           p->RequestID);
    I("userForceClose",      p->UserForceClose);
    I("isSwapOrder",         p->IsSwapOrder);
    S("exchangeID",          p->ExchangeID);
    S("investUnitID",        p->InvestUnitID);
    S("accountID",           p->AccountID);
    S("currencyID",          p->CurrencyID);
    S("clientID",            p->ClientID);
    S("ipAddress",           p->IPAddress);
    S("macAddress",          p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputOrderAction(JNIEnv* env, CThostFtdcInputOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputOrderActionField")
    S("brokerID",       p->BrokerID);
    S("investorID",     p->InvestorID);
    I("orderActionRef", p->OrderActionRef);
    S("orderRef",       p->OrderRef);
    I("requestID",      p->RequestID);
    I("frontID",        p->FrontID);
    I("sessionID",      p->SessionID);
    S("exchangeID",     p->ExchangeID);
    S("orderSysID",     p->OrderSysID);
    C("actionFlag",     p->ActionFlag);
    D("limitPrice",     p->LimitPrice);
    I("volumeChange",   p->VolumeChange);
    S("userID",         p->UserID);
    S("instrumentID",   p->InstrumentID);
    S("investUnitID",   p->InvestUnitID);
    S("ipAddress",      p->IPAddress);
    S("macAddress",     p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_Order(JNIEnv* env, CThostFtdcOrderField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOrderField")
    S("brokerID",            p->BrokerID);
    S("investorID",          p->InvestorID);
    S("instrumentID",        p->InstrumentID);
    S("orderRef",            p->OrderRef);
    S("userID",              p->UserID);
    C("orderPriceType",      p->OrderPriceType);
    C("direction",           p->Direction);
    S("combOffsetFlag",      p->CombOffsetFlag);
    S("combHedgeFlag",       p->CombHedgeFlag);
    D("limitPrice",          p->LimitPrice);
    I("volumeTotalOriginal", p->VolumeTotalOriginal);
    C("timeCondition",       p->TimeCondition);
    S("gTDDate",             p->GTDDate);
    C("volumeCondition",     p->VolumeCondition);
    I("minVolume",           p->MinVolume);
    C("contingentCondition", p->ContingentCondition);
    D("stopPrice",           p->StopPrice);
    C("forceCloseReason",    p->ForceCloseReason);
    I("isAutoSuspend",       p->IsAutoSuspend);
    S("businessUnit",        p->BusinessUnit);
    I("requestID",           p->RequestID);
    S("orderLocalID",        p->OrderLocalID);
    S("exchangeID",          p->ExchangeID);
    S("participantID",       p->ParticipantID);
    S("clientID",            p->ClientID);
    S("exchangeInstID",      p->ExchangeInstID);
    S("traderID",            p->TraderID);
    I("installID",           p->InstallID);
    C("orderSubmitStatus",   p->OrderSubmitStatus);
    I("notifySequence",      p->NotifySequence);
    S("tradingDay",          p->TradingDay);
    I("settlementID",        p->SettlementID);
    S("orderSysID",          p->OrderSysID);
    C("orderSource",         p->OrderSource);
    C("orderStatus",         p->OrderStatus);
    C("orderType",           p->OrderType);
    I("volumeTraded",        p->VolumeTraded);
    I("volumeTotal",         p->VolumeTotal);
    S("insertDate",          p->InsertDate);
    S("insertTime",          p->InsertTime);
    S("activeTime",          p->ActiveTime);
    S("suspendTime",         p->SuspendTime);
    S("updateTime",          p->UpdateTime);
    S("cancelTime",          p->CancelTime);
    S("activeTraderID",      p->ActiveTraderID);
    S("clearingPartID",      p->ClearingPartID);
    I("sequenceNo",          p->SequenceNo);
    I("frontID",             p->FrontID);
    I("sessionID",           p->SessionID);
    S("userProductInfo",     p->UserProductInfo);
    S("statusMsg",           p->StatusMsg);
    I("userForceClose",      p->UserForceClose);
    S("activeUserID",        p->ActiveUserID);
    I("brokerOrderSeq",      p->BrokerOrderSeq);
    S("relativeOrderSysID",  p->RelativeOrderSysID);
    I("zCETotalTradedVolume",p->ZCETotalTradedVolume);
    I("isSwapOrder",         p->IsSwapOrder);
    S("branchID",            p->BranchID);
    S("investUnitID",        p->InvestUnitID);
    S("accountID",           p->AccountID);
    S("currencyID",          p->CurrencyID);
    S("ipAddress",           p->IPAddress);
    S("macAddress",          p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_Trade(JNIEnv* env, CThostFtdcTradeField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcTradeField")
    S("brokerID",       p->BrokerID);
    S("investorID",     p->InvestorID);
    S("instrumentID",   p->InstrumentID);
    S("orderRef",       p->OrderRef);
    S("userID",         p->UserID);
    S("exchangeID",     p->ExchangeID);
    S("tradeID",        p->TradeID);
    C("direction",      p->Direction);
    S("orderSysID",     p->OrderSysID);
    S("participantID",  p->ParticipantID);
    S("clientID",       p->ClientID);
    C("tradingRole",    p->TradingRole);
    S("exchangeInstID", p->ExchangeInstID);
    C("offsetFlag",     p->OffsetFlag);
    C("hedgeFlag",      p->HedgeFlag);
    D("price",          p->Price);
    I("volume",         p->Volume);
    S("tradeDate",      p->TradeDate);
    S("tradeTime",      p->TradeTime);
    C("tradeType",      p->TradeType);
    C("priceSource",    p->PriceSource);
    S("traderID",       p->TraderID);
    S("orderLocalID",   p->OrderLocalID);
    S("clearingPartID", p->ClearingPartID);
    S("businessUnit",   p->BusinessUnit);
    I("sequenceNo",     p->SequenceNo);
    S("tradingDay",     p->TradingDay);
    I("settlementID",   p->SettlementID);
    I("brokerOrderSeq", p->BrokerOrderSeq);
    C("tradeSource",    p->TradeSource);
    END_TO_JAVA
}

jobject ToJava_OrderAction(JNIEnv* env, CThostFtdcOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOrderActionField")
    S("brokerID",          p->BrokerID);
    S("investorID",        p->InvestorID);
    I("orderActionRef",    p->OrderActionRef);
    S("orderRef",          p->OrderRef);
    I("requestID",         p->RequestID);
    I("frontID",           p->FrontID);
    I("sessionID",         p->SessionID);
    S("exchangeID",        p->ExchangeID);
    S("orderSysID",        p->OrderSysID);
    C("actionFlag",        p->ActionFlag);
    D("limitPrice",        p->LimitPrice);
    I("volumeChange",      p->VolumeChange);
    S("actionDate",        p->ActionDate);
    S("actionTime",        p->ActionTime);
    S("traderID",          p->TraderID);
    I("installID",         p->InstallID);
    S("orderLocalID",      p->OrderLocalID);
    S("actionLocalID",     p->ActionLocalID);
    S("participantID",     p->ParticipantID);
    S("clientID",          p->ClientID);
    S("businessUnit",      p->BusinessUnit);
    C("orderActionStatus", p->OrderActionStatus);
    S("userID",            p->UserID);
    S("statusMsg",         p->StatusMsg);
    S("instrumentID",      p->InstrumentID);
    S("branchID",          p->BranchID);
    S("investUnitID",      p->InvestUnitID);
    S("ipAddress",         p->IPAddress);
    S("macAddress",        p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InvestorPosition(JNIEnv* env, CThostFtdcInvestorPositionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInvestorPositionField")
    S("instrumentID",       p->InstrumentID);
    S("brokerID",           p->BrokerID);
    S("investorID",         p->InvestorID);
    C("posiDirection",      p->PosiDirection);
    C("hedgeFlag",          p->HedgeFlag);
    C("positionDate",       p->PositionDate);
    I("ydPosition",         p->YdPosition);
    I("position",           p->Position);
    I("longFrozen",         p->LongFrozen);
    I("shortFrozen",        p->ShortFrozen);
    D("longFrozenAmount",   p->LongFrozenAmount);
    D("shortFrozenAmount",  p->ShortFrozenAmount);
    I("openVolume",         p->OpenVolume);
    I("closeVolume",        p->CloseVolume);
    D("openAmount",         p->OpenAmount);
    D("closeAmount",        p->CloseAmount);
    D("positionCost",       p->PositionCost);
    D("preMargin",          p->PreMargin);
    D("useMargin",          p->UseMargin);
    D("frozenMargin",       p->FrozenMargin);
    D("frozenCash",         p->FrozenCash);
    D("frozenCommission",   p->FrozenCommission);
    D("cashIn",             p->CashIn);
    D("commission",         p->Commission);
    D("closeProfit",        p->CloseProfit);
    D("positionProfit",     p->PositionProfit);
    D("preSettlementPrice", p->PreSettlementPrice);
    D("settlementPrice",    p->SettlementPrice);
    S("tradingDay",         p->TradingDay);
    I("settlementID",       p->SettlementID);
    D("openCost",           p->OpenCost);
    D("exchangeMargin",     p->ExchangeMargin);
    I("combPosition",       p->CombPosition);
    I("combLongFrozen",     p->CombLongFrozen);
    I("combShortFrozen",    p->CombShortFrozen);
    D("closeProfitByDate",  p->CloseProfitByDate);
    D("closeProfitByTrade", p->CloseProfitByTrade);
    I("todayPosition",      p->TodayPosition);
    D("marginRateByMoney",  p->MarginRateByMoney);
    D("marginRateByVolume", p->MarginRateByVolume);
    I("strikeFrozen",       p->StrikeFrozen);
    D("strikeFrozenAmount", p->StrikeFrozenAmount);
    I("abandonFrozen",      p->AbandonFrozen);
    END_TO_JAVA
}

jobject ToJava_TradingAccount(JNIEnv* env, CThostFtdcTradingAccountField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcTradingAccountField")
    S("brokerID",                    p->BrokerID);
    S("accountID",                   p->AccountID);
    D("preMortgage",                 p->PreMortgage);
    D("preCredit",                   p->PreCredit);
    D("preDeposit",                  p->PreDeposit);
    D("preBalance",                  p->PreBalance);
    D("preMargin",                   p->PreMargin);
    D("interestBase",                p->InterestBase);
    D("interest",                    p->Interest);
    D("deposit",                     p->Deposit);
    D("withdraw",                    p->Withdraw);
    D("frozenMargin",                p->FrozenMargin);
    D("frozenCash",                  p->FrozenCash);
    D("frozenCommission",            p->FrozenCommission);
    D("currMargin",                  p->CurrMargin);
    D("cashIn",                      p->CashIn);
    D("commission",                  p->Commission);
    D("closeProfit",                 p->CloseProfit);
    D("positionProfit",              p->PositionProfit);
    D("balance",                     p->Balance);
    D("available",                   p->Available);
    D("withdrawQuota",               p->WithdrawQuota);
    D("reserve",                     p->Reserve);
    S("tradingDay",                  p->TradingDay);
    I("settlementID",                p->SettlementID);
    D("credit",                      p->Credit);
    D("mortgage",                    p->Mortgage);
    D("exchangeMargin",              p->ExchangeMargin);
    D("deliveryMargin",              p->DeliveryMargin);
    D("exchangeDeliveryMargin",      p->ExchangeDeliveryMargin);
    D("reserveBalance",              p->ReserveBalance);
    S("currencyID",                  p->CurrencyID);
    D("preFundMortgageIn",           p->PreFundMortgageIn);
    D("preFundMortgageOut",          p->PreFundMortgageOut);
    D("fundMortgageIn",              p->FundMortgageIn);
    D("fundMortgageOut",             p->FundMortgageOut);
    D("fundMortgageAvailable",       p->FundMortgageAvailable);
    D("mortgageableFund",            p->MortgageableFund);
    D("specProductMargin",           p->SpecProductMargin);
    D("specProductFrozenMargin",     p->SpecProductFrozenMargin);
    D("specProductCommission",       p->SpecProductCommission);
    D("specProductFrozenCommission", p->SpecProductFrozenCommission);
    D("specProductPositionProfit",   p->SpecProductPositionProfit);
    D("specProductCloseProfit",      p->SpecProductCloseProfit);
    D("specProductPositionProfitByAlg", p->SpecProductPositionProfitByAlg);
    D("specProductExchangeMargin",   p->SpecProductExchangeMargin);
    END_TO_JAVA
}

jobject ToJava_Investor(JNIEnv* env, CThostFtdcInvestorField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInvestorField")
    S("investorID",        p->InvestorID);
    S("brokerID",          p->BrokerID);
    S("investorGroupID",   p->InvestorGroupID);
    S("investorName",      p->InvestorName);
    C("identifiedCardType",p->IdentifiedCardType);
    S("identifiedCardNo",  p->IdentifiedCardNo);
    I("isActive",          p->IsActive);
    S("telephone",         p->Telephone);
    S("address",           p->Address);
    S("openDate",          p->OpenDate);
    S("mobile",            p->Mobile);
    S("commModelID",       p->CommModelID);
    S("marginModelID",     p->MarginModelID);
    END_TO_JAVA
}

jobject ToJava_TradingCode(JNIEnv* env, CThostFtdcTradingCodeField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcTradingCodeField")
    S("investorID",   p->InvestorID);
    S("brokerID",     p->BrokerID);
    S("exchangeID",   p->ExchangeID);
    S("clientID",     p->ClientID);
    I("isActive",     p->IsActive);
    C("clientIDType", p->ClientIDType);
    END_TO_JAVA
}

jobject ToJava_Exchange(JNIEnv* env, CThostFtdcExchangeField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcExchangeField")
    S("exchangeID",       p->ExchangeID);
    S("exchangeName",     p->ExchangeName);
    C("exchangeProperty", p->ExchangeProperty);
    END_TO_JAVA
}

jobject ToJava_Product(JNIEnv* env, CThostFtdcProductField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcProductField")
    S("productID",            p->ProductID);
    S("productName",          p->ProductName);
    S("exchangeID",           p->ExchangeID);
    C("productClass",         p->ProductClass);
    I("volumeMultiple",       p->VolumeMultiple);
    D("priceTick",            p->PriceTick);
    I("maxMarketOrderVolume", p->MaxMarketOrderVolume);
    I("minMarketOrderVolume", p->MinMarketOrderVolume);
    I("maxLimitOrderVolume",  p->MaxLimitOrderVolume);
    I("minLimitOrderVolume",  p->MinLimitOrderVolume);
    C("positionType",         p->PositionType);
    C("positionDateType",     p->PositionDateType);
    C("closeDealType",        p->CloseDealType);
    S("tradeCurrencyID",      p->TradeCurrencyID);
    END_TO_JAVA
}

jobject ToJava_Instrument(JNIEnv* env, CThostFtdcInstrumentField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInstrumentField")
    S("instrumentID",          p->InstrumentID);
    S("exchangeID",            p->ExchangeID);
    S("instrumentName",        p->InstrumentName);
    S("exchangeInstID",        p->ExchangeInstID);
    S("productID",             p->ProductID);
    C("productClass",          p->ProductClass);
    I("deliveryYear",          p->DeliveryYear);
    I("deliveryMonth",         p->DeliveryMonth);
    I("maxMarketOrderVolume",  p->MaxMarketOrderVolume);
    I("minMarketOrderVolume",  p->MinMarketOrderVolume);
    I("maxLimitOrderVolume",   p->MaxLimitOrderVolume);
    I("minLimitOrderVolume",   p->MinLimitOrderVolume);
    I("volumeMultiple",        p->VolumeMultiple);
    D("priceTick",             p->PriceTick);
    S("createDate",            p->CreateDate);
    S("openDate",              p->OpenDate);
    S("expireDate",            p->ExpireDate);
    S("startDelivDate",        p->StartDelivDate);
    S("endDelivDate",          p->EndDelivDate);
    C("instLifePhase",         p->InstLifePhase);
    I("isTrading",             p->IsTrading);
    C("positionType",          p->PositionType);
    C("positionDateType",      p->PositionDateType);
    D("longMarginRatio",       p->LongMarginRatio);
    D("shortMarginRatio",      p->ShortMarginRatio);
    C("maxMarginSideAlgorithm",p->MaxMarginSideAlgorithm);
    S("underlyingInstrID",     p->UnderlyingInstrID);
    D("strikePrice",           p->StrikePrice);
    C("optionsType",           p->OptionsType);
    D("underlyingMultiple",    p->UnderlyingMultiple);
    C("combinationType",       p->CombinationType);
    END_TO_JAVA
}

jobject ToJava_CombInstrument(JNIEnv* env, CThostFtdcCombInstrumentField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcCombInstrumentField")
    S("exchangeID",       p->ExchangeID);
    S("productID",        p->ProductID);
    END_TO_JAVA
}

jobject ToJava_InstrumentStatus(JNIEnv* env, CThostFtdcInstrumentStatusField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInstrumentStatusField")
    S("exchangeID",       p->ExchangeID);
    S("exchangeInstID",   p->ExchangeInstID);
    S("settlementGroupID",p->SettlementGroupID);
    S("instrumentID",     p->InstrumentID);
    I("tradingSegmentSN", p->TradingSegmentSN);
    S("enterTime",        p->EnterTime);
    C("enterReason",      p->EnterReason);
    END_TO_JAVA
}

jobject ToJava_InstrMarginRate(JNIEnv* env, CThostFtdcInstrumentMarginRateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInstrumentMarginRateField")
    S("instrumentID",            p->InstrumentID);
    C("investorRange",           p->InvestorRange);
    S("brokerID",                p->BrokerID);
    S("investorID",              p->InvestorID);
    C("hedgeFlag",               p->HedgeFlag);
    D("longMarginRatioByMoney",  p->LongMarginRatioByMoney);
    D("longMarginRatioByVolume", p->LongMarginRatioByVolume);
    D("shortMarginRatioByMoney", p->ShortMarginRatioByMoney);
    D("shortMarginRatioByVolume",p->ShortMarginRatioByVolume);
    I("isRelative",              p->IsRelative);
    END_TO_JAVA
}

jobject ToJava_InstrCommRate(JNIEnv* env, CThostFtdcInstrumentCommissionRateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInstrumentCommissionRateField")
    S("instrumentID",           p->InstrumentID);
    C("investorRange",          p->InvestorRange);
    S("brokerID",               p->BrokerID);
    S("investorID",             p->InvestorID);
    D("openRatioByMoney",       p->OpenRatioByMoney);
    D("openRatioByVolume",      p->OpenRatioByVolume);
    D("closeRatioByMoney",      p->CloseRatioByMoney);
    D("closeRatioByVolume",     p->CloseRatioByVolume);
    D("closeTodayRatioByMoney", p->CloseTodayRatioByMoney);
    D("closeTodayRatioByVolume",p->CloseTodayRatioByVolume);
    END_TO_JAVA
}

jobject ToJava_ExchMarginRate(JNIEnv* env, CThostFtdcExchangeMarginRateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcExchangeMarginRateField")
    S("brokerID",                p->BrokerID);
    S("instrumentID",            p->InstrumentID);
    C("hedgeFlag",               p->HedgeFlag);
    D("longMarginRatioByMoney",  p->LongMarginRatioByMoney);
    D("longMarginRatioByVolume", p->LongMarginRatioByVolume);
    D("shortMarginRatioByMoney", p->ShortMarginRatioByMoney);
    D("shortMarginRatioByVolume",p->ShortMarginRatioByVolume);
    END_TO_JAVA
}

jobject ToJava_ExchMarginRateAdj(JNIEnv* env, CThostFtdcExchangeMarginRateAdjustField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcExchangeMarginRateAdjustField")
    S("brokerID",                       p->BrokerID);
    S("instrumentID",                   p->InstrumentID);
    C("hedgeFlag",                      p->HedgeFlag);
    D("longMarginRatioByMoney",         p->LongMarginRatioByMoney);
    D("longMarginRatioByVolume",        p->LongMarginRatioByVolume);
    D("shortMarginRatioByMoney",        p->ShortMarginRatioByMoney);
    D("shortMarginRatioByVolume",       p->ShortMarginRatioByVolume);
    D("exchLongMarginRatioByMoney",     p->ExchLongMarginRatioByMoney);
    D("exchLongMarginRatioByVolume",    p->ExchLongMarginRatioByVolume);
    D("exchShortMarginRatioByMoney",    p->ExchShortMarginRatioByMoney);
    D("exchShortMarginRatioByVolume",   p->ExchShortMarginRatioByVolume);
    END_TO_JAVA
}

jobject ToJava_InvestorPosDetail(JNIEnv* env, CThostFtdcInvestorPositionDetailField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInvestorPositionDetailField")
    S("instrumentID",         p->InstrumentID);
    S("brokerID",             p->BrokerID);
    S("investorID",           p->InvestorID);
    C("hedgeFlag",            p->HedgeFlag);
    C("direction",            p->Direction);
    S("openDate",             p->OpenDate);
    S("tradeID",              p->TradeID);
    I("volume",               p->Volume);
    D("openPrice",            p->OpenPrice);
    S("tradingDay",           p->TradingDay);
    I("settlementID",         p->SettlementID);
    C("tradeType",            p->TradeType);
    S("combInstrumentID",     p->CombInstrumentID);
    S("exchangeID",           p->ExchangeID);
    D("closeProfitByDate",    p->CloseProfitByDate);
    D("closeProfitByTrade",   p->CloseProfitByTrade);
    D("positionProfitByDate", p->PositionProfitByDate);
    D("positionProfitByTrade",p->PositionProfitByTrade);
    D("margin",               p->Margin);
    D("exchMargin",           p->ExchMargin);
    D("marginRateByMoney",    p->MarginRateByMoney);
    D("marginRateByVolume",   p->MarginRateByVolume);
    D("lastSettlementPrice",  p->LastSettlementPrice);
    D("settlementPrice",      p->SettlementPrice);
    I("closeVolume",          p->CloseVolume);
    D("closeAmount",          p->CloseAmount);
    END_TO_JAVA
}

jobject ToJava_OptionInstrTradeCost(JNIEnv* env, CThostFtdcOptionInstrTradeCostField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOptionInstrTradeCostField")
    S("brokerID",       p->BrokerID);
    S("investorID",     p->InvestorID);
    S("instrumentID",   p->InstrumentID);
    C("hedgeFlag",      p->HedgeFlag);
    D("fixedMargin",    p->FixedMargin);
    D("miniMargin",     p->MiniMargin);
    D("exchFixedMargin",p->ExchFixedMargin);
    D("exchMiniMargin", p->ExchMiniMargin);
    END_TO_JAVA
}

jobject ToJava_OptionInstrCommRate(JNIEnv* env, CThostFtdcOptionInstrCommRateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOptionInstrCommRateField")
    S("instrumentID",           p->InstrumentID);
    C("investorRange",          p->InvestorRange);
    S("brokerID",               p->BrokerID);
    S("investorID",             p->InvestorID);
    D("openRatioByMoney",       p->OpenRatioByMoney);
    D("openRatioByVolume",      p->OpenRatioByVolume);
    D("closeRatioByMoney",      p->CloseRatioByMoney);
    D("closeRatioByVolume",     p->CloseRatioByVolume);
    D("closeTodayRatioByMoney", p->CloseTodayRatioByMoney);
    D("closeTodayRatioByVolume",p->CloseTodayRatioByVolume);
    D("strikeRatioByMoney",     p->StrikeRatioByMoney);
    D("strikeRatioByVolume",    p->StrikeRatioByVolume);
    END_TO_JAVA
}

jobject ToJava_ExecOrder(JNIEnv* env, CThostFtdcExecOrderField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcExecOrderField")
    S("brokerID",           p->BrokerID);
    S("investorID",         p->InvestorID);
    S("instrumentID",       p->InstrumentID);
    S("execOrderRef",       p->ExecOrderRef);
    S("userID",             p->UserID);
    I("volume",             p->Volume);
    I("requestID",          p->RequestID);
    S("businessUnit",       p->BusinessUnit);
    C("offsetFlag",         p->OffsetFlag);
    C("hedgeFlag",          p->HedgeFlag);
    C("actionType",         p->ActionType);
    C("posiDirection",      p->PosiDirection);
    C("reservePositionFlag",p->ReservePositionFlag);
    C("closeFlag",          p->CloseFlag);
    S("execOrderLocalID",   p->ExecOrderLocalID);
    S("exchangeID",         p->ExchangeID);
    S("participantID",      p->ParticipantID);
    S("clientID",           p->ClientID);
    S("exchangeInstID",     p->ExchangeInstID);
    S("traderID",           p->TraderID);
    I("installID",          p->InstallID);
    C("orderSubmitStatus",  p->OrderSubmitStatus);
    I("notifySequence",     p->NotifySequence);
    S("tradingDay",         p->TradingDay);
    I("settlementID",       p->SettlementID);
    S("execOrderSysID",     p->ExecOrderSysID);
    S("insertDate",         p->InsertDate);
    S("insertTime",         p->InsertTime);
    S("cancelTime",         p->CancelTime);
    C("execResult",         p->ExecResult);
    S("clearingPartID",     p->ClearingPartID);
    I("sequenceNo",         p->SequenceNo);
    I("frontID",            p->FrontID);
    I("sessionID",          p->SessionID);
    S("userProductInfo",    p->UserProductInfo);
    S("statusMsg",          p->StatusMsg);
    S("activeUserID",       p->ActiveUserID);
    I("brokerExecOrderSeq", p->BrokerExecOrderSeq);
    S("branchID",           p->BranchID);
    S("investUnitID",       p->InvestUnitID);
    S("accountID",          p->AccountID);
    S("currencyID",         p->CurrencyID);
    S("ipAddress",          p->IPAddress);
    S("macAddress",         p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputExecOrder(JNIEnv* env, CThostFtdcInputExecOrderField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputExecOrderField")
    S("brokerID",           p->BrokerID);
    S("investorID",         p->InvestorID);
    S("instrumentID",       p->InstrumentID);
    S("execOrderRef",       p->ExecOrderRef);
    S("userID",             p->UserID);
    I("volume",             p->Volume);
    I("requestID",          p->RequestID);
    S("businessUnit",       p->BusinessUnit);
    C("offsetFlag",         p->OffsetFlag);
    C("hedgeFlag",          p->HedgeFlag);
    C("actionType",         p->ActionType);
    C("posiDirection",      p->PosiDirection);
    C("reservePositionFlag",p->ReservePositionFlag);
    C("closeFlag",          p->CloseFlag);
    S("exchangeID",         p->ExchangeID);
    S("investUnitID",       p->InvestUnitID);
    S("accountID",          p->AccountID);
    S("currencyID",         p->CurrencyID);
    S("clientID",           p->ClientID);
    S("ipAddress",          p->IPAddress);
    S("macAddress",         p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputExecOrderAction(JNIEnv* env, CThostFtdcInputExecOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputExecOrderActionField")
    S("brokerID",          p->BrokerID);
    S("investorID",        p->InvestorID);
    I("execOrderActionRef",p->ExecOrderActionRef);
    S("execOrderRef",      p->ExecOrderRef);
    I("requestID",         p->RequestID);
    I("frontID",           p->FrontID);
    I("sessionID",         p->SessionID);
    S("exchangeID",        p->ExchangeID);
    S("execOrderSysID",    p->ExecOrderSysID);
    C("actionFlag",        p->ActionFlag);
    S("userID",            p->UserID);
    S("instrumentID",      p->InstrumentID);
    S("investUnitID",      p->InvestUnitID);
    S("ipAddress",         p->IPAddress);
    S("macAddress",        p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_ForQuote(JNIEnv* env, CThostFtdcForQuoteField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcForQuoteField")
    S("brokerID",        p->BrokerID);
    S("investorID",      p->InvestorID);
    S("instrumentID",    p->InstrumentID);
    S("forQuoteRef",     p->ForQuoteRef);
    S("userID",          p->UserID);
    S("forQuoteLocalID", p->ForQuoteLocalID);
    S("exchangeID",      p->ExchangeID);
    S("participantID",   p->ParticipantID);
    S("clientID",        p->ClientID);
    S("exchangeInstID",  p->ExchangeInstID);
    S("traderID",        p->TraderID);
    I("installID",       p->InstallID);
    S("insertDate",      p->InsertDate);
    S("insertTime",      p->InsertTime);
    C("forQuoteStatus",  p->ForQuoteStatus);
    S("statusMsg",       p->StatusMsg);
    S("activerUserID",   p->ActiveUserID);
    I("brokerForQutoSeq",p->BrokerForQutoSeq);
    I("frontID",         p->FrontID);
    I("sessionID",       p->SessionID);
    S("investUnitID",    p->InvestUnitID);
    S("ipAddress",       p->IPAddress);
    S("macAddress",      p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputForQuote(JNIEnv* env, CThostFtdcInputForQuoteField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputForQuoteField")
    S("brokerID",     p->BrokerID);
    S("investorID",   p->InvestorID);
    S("instrumentID", p->InstrumentID);
    S("forQuoteRef",  p->ForQuoteRef);
    S("userID",       p->UserID);
    S("exchangeID",   p->ExchangeID);
    S("investUnitID", p->InvestUnitID);
    S("ipAddress",    p->IPAddress);
    S("macAddress",   p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputQuote(JNIEnv* env, CThostFtdcInputQuoteField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputQuoteField")
    S("brokerID",      p->BrokerID);
    S("investorID",    p->InvestorID);
    S("instrumentID",  p->InstrumentID);
    S("quoteRef",      p->QuoteRef);
    S("userID",        p->UserID);
    D("askPrice",      p->AskPrice);
    D("bidPrice",      p->BidPrice);
    I("askVolume",     p->AskVolume);
    I("bidVolume",     p->BidVolume);
    I("requestID",     p->RequestID);
    S("businessUnit",  p->BusinessUnit);
    C("askOffsetFlag", p->AskOffsetFlag);
    C("bidOffsetFlag", p->BidOffsetFlag);
    C("askHedgeFlag",  p->AskHedgeFlag);
    C("bidHedgeFlag",  p->BidHedgeFlag);
    S("exchangeID",    p->ExchangeID);
    S("investUnitID",  p->InvestUnitID);
    S("clientID",      p->ClientID);
    S("ipAddress",     p->IPAddress);
    S("macAddress",    p->MacAddress);
    S("forQuoteSysID", p->ForQuoteSysID);
    S("askOrderRef",   p->AskOrderRef);
    S("bidOrderRef",   p->BidOrderRef);
    END_TO_JAVA
}

jobject ToJava_InputQuoteAction(JNIEnv* env, CThostFtdcInputQuoteActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputQuoteActionField")
    S("brokerID",       p->BrokerID);
    S("investorID",     p->InvestorID);
    I("quoteActionRef", p->QuoteActionRef);
    S("quoteRef",       p->QuoteRef);
    I("requestID",      p->RequestID);
    I("frontID",        p->FrontID);
    I("sessionID",      p->SessionID);
    S("exchangeID",     p->ExchangeID);
    S("quoteSysID",     p->QuoteSysID);
    C("actionFlag",     p->ActionFlag);
    S("userID",         p->UserID);
    S("instrumentID",   p->InstrumentID);
    S("investUnitID",   p->InvestUnitID);
    S("clientID",       p->ClientID);
    S("ipAddress",      p->IPAddress);
    S("macAddress",     p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_Quote(JNIEnv* env, CThostFtdcQuoteField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcQuoteField")
    S("brokerID",         p->BrokerID);
    S("investorID",       p->InvestorID);
    S("instrumentID",     p->InstrumentID);
    S("quoteRef",         p->QuoteRef);
    S("userID",           p->UserID);
    D("askPrice",         p->AskPrice);
    D("bidPrice",         p->BidPrice);
    I("askVolume",        p->AskVolume);
    I("bidVolume",        p->BidVolume);
    I("requestID",        p->RequestID);
    S("businessUnit",     p->BusinessUnit);
    C("askOffsetFlag",    p->AskOffsetFlag);
    C("bidOffsetFlag",    p->BidOffsetFlag);
    C("askHedgeFlag",     p->AskHedgeFlag);
    C("bidHedgeFlag",     p->BidHedgeFlag);
    S("quoteLocalID",     p->QuoteLocalID);
    S("exchangeID",       p->ExchangeID);
    S("participantID",    p->ParticipantID);
    S("clientID",         p->ClientID);
    S("exchangeInstID",   p->ExchangeInstID);
    S("traderID",         p->TraderID);
    I("installID",        p->InstallID);
    I("notifySequence",   p->NotifySequence);
    C("orderSubmitStatus",p->OrderSubmitStatus);
    S("tradingDay",       p->TradingDay);
    I("settlementID",     p->SettlementID);
    S("quoteSysID",       p->QuoteSysID);
    S("insertDate",       p->InsertDate);
    S("insertTime",       p->InsertTime);
    S("cancelTime",       p->CancelTime);
    C("quoteStatus",      p->QuoteStatus);
    S("clearingPartID",   p->ClearingPartID);
    I("sequenceNo",       p->SequenceNo);
    S("askOrderSysID",    p->AskOrderSysID);
    S("bidOrderSysID",    p->BidOrderSysID);
    I("frontID",          p->FrontID);
    I("sessionID",        p->SessionID);
    S("userProductInfo",  p->UserProductInfo);
    S("statusMsg",        p->StatusMsg);
    S("activeUserID",     p->ActiveUserID);
    I("brokerQuoteSeq",   p->BrokerQuoteSeq);
    S("askOrderRef",      p->AskOrderRef);
    S("bidOrderRef",      p->BidOrderRef);
    S("forQuoteSysID",    p->ForQuoteSysID);
    S("branchID",         p->BranchID);
    S("investUnitID",     p->InvestUnitID);
    S("accountID",        p->AccountID);
    S("currencyID",       p->CurrencyID);
    S("ipAddress",        p->IPAddress);
    S("macAddress",       p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_QuoteAction(JNIEnv* env, CThostFtdcQuoteActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcQuoteActionField")
    S("brokerID",          p->BrokerID);
    S("investorID",        p->InvestorID);
    I("quoteActionRef",    p->QuoteActionRef);
    S("quoteRef",          p->QuoteRef);
    I("requestID",         p->RequestID);
    I("frontID",           p->FrontID);
    I("sessionID",         p->SessionID);
    S("exchangeID",        p->ExchangeID);
    S("quoteSysID",        p->QuoteSysID);
    C("actionFlag",        p->ActionFlag);
    S("actionDate",        p->ActionDate);
    S("actionTime",        p->ActionTime);
    S("traderID",          p->TraderID);
    I("installID",         p->InstallID);
    S("quoteLocalID",      p->QuoteLocalID);
    S("actionLocalID",     p->ActionLocalID);
    S("participantID",     p->ParticipantID);
    S("clientID",          p->ClientID);
    S("businessUnit",      p->BusinessUnit);
    C("orderActionStatus", p->OrderActionStatus);
    S("userID",            p->UserID);
    S("statusMsg",         p->StatusMsg);
    S("instrumentID",      p->InstrumentID);
    S("branchID",          p->BranchID);
    S("investUnitID",      p->InvestUnitID);
    S("ipAddress",         p->IPAddress);
    S("macAddress",        p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_BatchOrderAction(JNIEnv* env, CThostFtdcBatchOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcBatchOrderActionField")
    S("brokerID",          p->BrokerID);
    S("investorID",        p->InvestorID);
    I("orderActionRef",    p->OrderActionRef);
    I("requestID",         p->RequestID);
    I("frontID",           p->FrontID);
    I("sessionID",         p->SessionID);
    S("exchangeID",        p->ExchangeID);
    S("actionDate",        p->ActionDate);
    S("actionTime",        p->ActionTime);
    S("traderID",          p->TraderID);
    I("installID",         p->InstallID);
    S("actionLocalID",     p->ActionLocalID);
    S("participantID",     p->ParticipantID);
    S("clientID",          p->ClientID);
    S("businessUnit",      p->BusinessUnit);
    C("orderActionStatus", p->OrderActionStatus);
    S("userID",            p->UserID);
    S("statusMsg",         p->StatusMsg);
    S("investUnitID",      p->InvestUnitID);
    S("ipAddress",         p->IPAddress);
    S("macAddress",        p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputBatchOrderAction(JNIEnv* env, CThostFtdcInputBatchOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputBatchOrderActionField")
    S("brokerID",      p->BrokerID);
    S("investorID",    p->InvestorID);
    I("orderActionRef",p->OrderActionRef);
    I("requestID",     p->RequestID);
    I("frontID",       p->FrontID);
    I("sessionID",     p->SessionID);
    S("exchangeID",    p->ExchangeID);
    S("userID",        p->UserID);
    S("investUnitID",  p->InvestUnitID);
    S("ipAddress",     p->IPAddress);
    S("macAddress",    p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_OptionSelfClose(JNIEnv* env, CThostFtdcOptionSelfCloseField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOptionSelfCloseField")
    S("brokerID",             p->BrokerID);
    S("investorID",           p->InvestorID);
    S("instrumentID",         p->InstrumentID);
    S("userID",               p->UserID);
    I("volume",               p->Volume);
    I("requestID",            p->RequestID);
    S("businessUnit",         p->BusinessUnit);
    C("hedgeFlag",            p->HedgeFlag);
    C("optSelfCloseFlag",     p->OptSelfCloseFlag);
    S("exchangeID",           p->ExchangeID);
    S("participantID",        p->ParticipantID);
    S("clientID",             p->ClientID);
    S("exchangeInstID",       p->ExchangeInstID);
    S("traderID",             p->TraderID);
    I("installID",            p->InstallID);
    C("orderSubmitStatus",    p->OrderSubmitStatus);
    I("notifySequence",       p->NotifySequence);
    S("tradingDay",           p->TradingDay);
    I("settlementID",         p->SettlementID);
    S("insertDate",           p->InsertDate);
    S("insertTime",           p->InsertTime);
    S("cancelTime",           p->CancelTime);
    C("execResult",           p->ExecResult);
    S("clearingPartID",       p->ClearingPartID);
    I("sequenceNo",           p->SequenceNo);
    I("frontID",              p->FrontID);
    I("sessionID",            p->SessionID);
    S("userProductInfo",      p->UserProductInfo);
    S("statusMsg",            p->StatusMsg);
    S("activeUserID",         p->ActiveUserID);
    S("branchID",             p->BranchID);
    S("investUnitID",         p->InvestUnitID);
    S("accountID",            p->AccountID);
    S("currencyID",           p->CurrencyID);
    S("ipAddress",            p->IPAddress);
    S("macAddress",           p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputOptionSelfClose(JNIEnv* env, CThostFtdcInputOptionSelfCloseField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputOptionSelfCloseField")
    S("brokerID",        p->BrokerID);
    S("investorID",      p->InvestorID);
    S("instrumentID",    p->InstrumentID);
    S("userID",          p->UserID);
    I("volume",          p->Volume);
    I("requestID",       p->RequestID);
    S("businessUnit",    p->BusinessUnit);
    C("hedgeFlag",       p->HedgeFlag);
    C("optSelfCloseFlag",p->OptSelfCloseFlag);
    S("exchangeID",      p->ExchangeID);
    S("investUnitID",    p->InvestUnitID);
    S("accountID",       p->AccountID);
    S("currencyID",      p->CurrencyID);
    S("clientID",        p->ClientID);
    S("ipAddress",       p->IPAddress);
    S("macAddress",      p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputOptionSelfCloseAction(JNIEnv* env, CThostFtdcInputOptionSelfCloseActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputOptionSelfCloseActionField")
    S("brokerID",             p->BrokerID);
    S("investorID",           p->InvestorID);
    I("requestID",            p->RequestID);
    I("frontID",              p->FrontID);
    I("sessionID",            p->SessionID);
    S("exchangeID",           p->ExchangeID);
    C("actionFlag",           p->ActionFlag);
    S("userID",               p->UserID);
    S("instrumentID",         p->InstrumentID);
    S("investUnitID",         p->InvestUnitID);
    S("ipAddress",            p->IPAddress);
    S("macAddress",           p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_OptionSelfCloseAction(JNIEnv* env, CThostFtdcOptionSelfCloseActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOptionSelfCloseActionField")
    S("brokerID",             p->BrokerID);
    S("investorID",           p->InvestorID);
    END_TO_JAVA
}

jobject ToJava_CombAction(JNIEnv* env, CThostFtdcCombActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcCombActionField")
    S("brokerID",         p->BrokerID);
    S("investorID",       p->InvestorID);
    S("instrumentID",     p->InstrumentID);
    S("combActionRef",    p->CombActionRef);
    S("userID",           p->UserID);
    C("direction",        p->Direction);
    I("volume",           p->Volume);
    C("combDirection",    p->CombDirection);
    C("hedgeFlag",        p->HedgeFlag);
    S("exchangeID",       p->ExchangeID);
    S("participantID",    p->ParticipantID);
    S("clientID",         p->ClientID);
    S("exchangeInstID",   p->ExchangeInstID);
    S("traderID",         p->TraderID);
    I("installID",        p->InstallID);
    C("actionStatus",     p->ActionStatus);
    I("notifySequence",   p->NotifySequence);
    S("tradingDay",       p->TradingDay);
    I("settlementID",     p->SettlementID);
    I("sequenceNo",       p->SequenceNo);
    I("frontID",          p->FrontID);
    I("sessionID",        p->SessionID);
    S("userProductInfo",  p->UserProductInfo);
    S("statusMsg",        p->StatusMsg);
    S("ipAddress",        p->IPAddress);
    S("macAddress",       p->MacAddress);
    END_TO_JAVA
}

jobject ToJava_InputCombAction(JNIEnv* env, CThostFtdcInputCombActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputCombActionField")
    S("brokerID",     p->BrokerID);
    S("investorID",   p->InvestorID);
    S("instrumentID", p->InstrumentID);
    S("combActionRef",p->CombActionRef);
    S("userID",       p->UserID);
    C("direction",    p->Direction);
    I("volume",       p->Volume);
    C("combDirection",p->CombDirection);
    C("hedgeFlag",    p->HedgeFlag);
    S("exchangeID",   p->ExchangeID);
    S("ipAddress",    p->IPAddress);
    S("macAddress",   p->MacAddress);
    S("investUnitID", p->InvestUnitID);
    END_TO_JAVA
}

jobject ToJava_InvestorPosForComb(JNIEnv* env, CThostFtdcInvestorPositionForCombField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInvestorPositionForCombField")
    END_TO_JAVA
}

jobject ToJava_ForQuoteParam(JNIEnv* env, CThostFtdcForQuoteParamField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcForQuoteParamField")
    S("brokerID",        p->BrokerID);
    S("exchangeID",      p->ExchangeID);
    S("instrumentID",    p->InstrumentID);
    D("lastPrice",       p->LastPrice);
    END_TO_JAVA
}

jobject ToJava_InstrOrderCommRate(JNIEnv* env, CThostFtdcInstrumentOrderCommRateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInstrumentOrderCommRateField")
    S("instrumentID",           p->InstrumentID);
    C("investorRange",          p->InvestorRange);
    S("brokerID",               p->BrokerID);
    S("investorID",             p->InvestorID);
    C("hedgeFlag",              p->HedgeFlag);
    D("orderCommByVolume",      p->OrderCommByVolume);
    D("orderActionCommByVolume",p->OrderActionCommByVolume);
    END_TO_JAVA
}

jobject ToJava_FlowCtrlWarning(JNIEnv* env, CThostFtdcFlowCtrlWarningField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcFlowCtrlWarningField")
    END_TO_JAVA
}

jobject ToJava_SpecificTrader(JNIEnv* env, CThostFtdcSpecificTraderField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcSpecificTraderField")
    S("traderID", p->TraderID);
    END_TO_JAVA
}

jobject ToJava_TraderOffer(JNIEnv* env, CThostFtdcTraderOfferField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcTraderOfferField")
    S("exchangeID",              p->ExchangeID);
    S("traderID",                p->TraderID);
    S("participantID",           p->ParticipantID);
    S("password",                p->Password);
    I("installID",               p->InstallID);
    S("orderLocalID",            p->OrderLocalID);
    C("traderConnectStatus",     p->TraderConnectStatus);
    S("connectRequestDate",      p->ConnectRequestDate);
    S("connectRequestTime",      p->ConnectRequestTime);
    S("lastReportDate",          p->LastReportDate);
    S("lastReportTime",          p->LastReportTime);
    S("connectDate",             p->ConnectDate);
    S("connectTime",             p->ConnectTime);
    S("startDate",               p->StartDate);
    S("startTime",               p->StartTime);
    S("tradingDay",              p->TradingDay);
    S("brokerID",                p->BrokerID);
    S("maxTradeID",              p->MaxTradeID);
    S("maxOrderMessageReference",p->MaxOrderMessageReference);
    END_TO_JAVA
}

jobject ToJava_RCAMSProdMargin(JNIEnv* env, CThostFtdcRCAMSInvestorProdMarginField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRCAMSInvestorProdMarginField")
    S("brokerID",            p->BrokerID);
    S("investorID",          p->InvestorID);
    S("exchangeID",          p->ExchangeID);
    END_TO_JAVA
}

jobject ToJava_RCAMSCombPos(JNIEnv* env, CThostFtdcRCAMSInvestorCombPositionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRCAMSInvestorCombPositionField")
    S("exchangeID",  p->ExchangeID);
    S("brokerID",    p->BrokerID);
    S("investorID",  p->InvestorID);
    END_TO_JAVA
}

jobject ToJava_SPBMDetail(JNIEnv* env, CThostFtdcInvestorProdSPBMDetailField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInvestorProdSPBMDetailField")
    S("exchangeID",   p->ExchangeID);
    S("brokerID",     p->BrokerID);
    S("investorID",   p->InvestorID);
    END_TO_JAVA
}

jobject ToJava_SPMMGroupMargin(JNIEnv* env, CThostFtdcSPMMInvestorCommodityGroupMarginField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcSPMMInvestorCommodityGroupMarginField")
    S("exchangeID",      p->ExchangeID);
    S("brokerID",        p->BrokerID);
    S("investorID",      p->InvestorID);
    END_TO_JAVA
}

jobject ToJava_RULEProdMargin(JNIEnv* env, CThostFtdcRULEInvestorProdMarginField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcRULEInvestorProdMarginField")
    S("exchangeID",       p->ExchangeID);
    S("brokerID",         p->BrokerID);
    S("investorID",       p->InvestorID);
    END_TO_JAVA
}

jobject ToJava_ControlParam(JNIEnv* env, CThostFtdcControlParamField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcControlParamField")
    END_TO_JAVA
}

jobject ToJava_OffsetSetting(JNIEnv* env, CThostFtdcOffsetSettingField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcOffsetSettingField")
    S("brokerID",    p->BrokerID);
    S("investorID",  p->InvestorID);
    S("exchangeID",  p->ExchangeID);
    S("instrumentID",p->InstrumentID);
    END_TO_JAVA
}

jobject ToJava_CancelOffsetSetting(JNIEnv* env, CThostFtdcCancelOffsetSettingField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcCancelOffsetSettingField")
    S("brokerID",    p->BrokerID);
    S("investorID",  p->InvestorID);
    S("exchangeID",  p->ExchangeID);
    S("instrumentID",p->InstrumentID);
    END_TO_JAVA
}

jobject ToJava_InputOffsetSetting(JNIEnv* env, CThostFtdcInputOffsetSettingField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcInputOffsetSettingField")
    S("brokerID",    p->BrokerID);
    S("investorID",  p->InvestorID);
    S("exchangeID",  p->ExchangeID);
    S("instrumentID",p->InstrumentID);
    END_TO_JAVA
}

jobject ToJava_UserPasswordUpdate(JNIEnv* env, CThostFtdcUserPasswordUpdateField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcUserPasswordUpdateField")
    S("brokerID",   p->BrokerID);
    S("userID",     p->UserID);
    S("oldPassword",p->OldPassword);
    S("newPassword",p->NewPassword);
    END_TO_JAVA
}

jobject ToJava_MKInputOrderAction(JNIEnv* env, CThostFtdcMKInputOrderActionField* p) {
    BEGIN_TO_JAVA("com/ctpmini/struct/CThostFtdcMKInputOrderActionField")
    S("brokerID",      p->BrokerID);
    S("investorID",    p->InvestorID);
    I("orderActionRef",p->OrderActionRef);
    I("requestID",     p->RequestID);
    I("frontID",       p->FrontID);
    I("sessionID",     p->SessionID);
    S("exchangeID",    p->ExchangeID);
    C("actionFlag",    p->ActionFlag);
    S("userID",        p->UserID);
    S("instrumentID",  p->InstrumentID);
    S("investUnitID",  p->InvestUnitID);
    S("ipAddress",     p->IPAddress);
    S("macAddress",    p->MacAddress);
    END_TO_JAVA
}

/* ============================================================
   FromJava_* : Java POJO -> CTP struct
   ============================================================ */

void FromJava_ReqUserLogin(JNIEnv* env, jobject obj, CThostFtdcReqUserLoginField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"tradingDay",          out.TradingDay,          sizeof(out.TradingDay));
    GET_STR(env,obj,cls,"brokerID",            out.BrokerID,            sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"userID",              out.UserID,              sizeof(out.UserID));
    GET_STR(env,obj,cls,"password",            out.Password,            sizeof(out.Password));
    GET_STR(env,obj,cls,"userProductInfo",     out.UserProductInfo,     sizeof(out.UserProductInfo));
    GET_STR(env,obj,cls,"interfaceProductInfo",out.InterfaceProductInfo,sizeof(out.InterfaceProductInfo));
    GET_STR(env,obj,cls,"protocolInfo",        out.ProtocolInfo,        sizeof(out.ProtocolInfo));
    GET_STR(env,obj,cls,"macAddress",          out.MacAddress,          sizeof(out.MacAddress));
    GET_STR(env,obj,cls,"oneTimePassword",     out.OneTimePassword,     sizeof(out.OneTimePassword));
    GET_STR(env,obj,cls,"clientIPAddress",     out.ClientIPAddress,     sizeof(out.ClientIPAddress));
    GET_STR(env,obj,cls,"loginRemark",         out.LoginRemark,         sizeof(out.LoginRemark));
    END_FROM_JAVA
}

void FromJava_UserLogout(JNIEnv* env, jobject obj, CThostFtdcUserLogoutField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",out.BrokerID,sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"userID",  out.UserID,  sizeof(out.UserID));
    END_FROM_JAVA
}

void FromJava_ReqAuthenticate(JNIEnv* env, jobject obj, CThostFtdcReqAuthenticateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"userID",          out.UserID,          sizeof(out.UserID));
    GET_STR(env,obj,cls,"userProductInfo", out.UserProductInfo, sizeof(out.UserProductInfo));
    GET_STR(env,obj,cls,"authCode",        out.AuthCode,        sizeof(out.AuthCode));
    GET_STR(env,obj,cls,"appID",           out.AppID,           sizeof(out.AppID));
    END_FROM_JAVA
}

void FromJava_InputOrder(JNIEnv* env, jobject obj, CThostFtdcInputOrderField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",           out.BrokerID,           sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",         out.InvestorID,         sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",       out.InstrumentID,       sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"orderRef",           out.OrderRef,           sizeof(out.OrderRef));
    GET_STR(env,obj,cls,"userID",             out.UserID,             sizeof(out.UserID));
    GET_CHR(env,obj,cls,"orderPriceType",     out.OrderPriceType);
    GET_CHR(env,obj,cls,"direction",          out.Direction);
    GET_STR(env,obj,cls,"combOffsetFlag",     out.CombOffsetFlag,     sizeof(out.CombOffsetFlag));
    GET_STR(env,obj,cls,"combHedgeFlag",      out.CombHedgeFlag,      sizeof(out.CombHedgeFlag));
    GET_DBL(env,obj,cls,"limitPrice",         out.LimitPrice);
    GET_INT(env,obj,cls,"volumeTotalOriginal",out.VolumeTotalOriginal);
    GET_CHR(env,obj,cls,"timeCondition",      out.TimeCondition);
    GET_STR(env,obj,cls,"gTDDate",            out.GTDDate,            sizeof(out.GTDDate));
    GET_CHR(env,obj,cls,"volumeCondition",    out.VolumeCondition);
    GET_INT(env,obj,cls,"minVolume",          out.MinVolume);
    GET_CHR(env,obj,cls,"contingentCondition",out.ContingentCondition);
    GET_DBL(env,obj,cls,"stopPrice",          out.StopPrice);
    GET_CHR(env,obj,cls,"forceCloseReason",   out.ForceCloseReason);
    GET_INT(env,obj,cls,"isAutoSuspend",      out.IsAutoSuspend);
    GET_STR(env,obj,cls,"businessUnit",       out.BusinessUnit,       sizeof(out.BusinessUnit));
    GET_INT(env,obj,cls,"requestID",          out.RequestID);
    GET_INT(env,obj,cls,"userForceClose",     out.UserForceClose);
    GET_INT(env,obj,cls,"isSwapOrder",        out.IsSwapOrder);
    GET_STR(env,obj,cls,"exchangeID",         out.ExchangeID,         sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"investUnitID",       out.InvestUnitID,       sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"accountID",          out.AccountID,          sizeof(out.AccountID));
    GET_STR(env,obj,cls,"currencyID",         out.CurrencyID,         sizeof(out.CurrencyID));
    GET_STR(env,obj,cls,"clientID",           out.ClientID,           sizeof(out.ClientID));
    GET_STR(env,obj,cls,"ipAddress",          out.IPAddress,          sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",         out.MacAddress,         sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputOrderActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,     sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,   sizeof(out.InvestorID));
    GET_INT(env,obj,cls,"orderActionRef",out.OrderActionRef);
    GET_STR(env,obj,cls,"orderRef",      out.OrderRef,     sizeof(out.OrderRef));
    GET_INT(env,obj,cls,"requestID",     out.RequestID);
    GET_INT(env,obj,cls,"frontID",       out.FrontID);
    GET_INT(env,obj,cls,"sessionID",     out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"orderSysID",    out.OrderSysID,   sizeof(out.OrderSysID));
    GET_CHR(env,obj,cls,"actionFlag",    out.ActionFlag);
    GET_DBL(env,obj,cls,"limitPrice",    out.LimitPrice);
    GET_INT(env,obj,cls,"volumeChange",  out.VolumeChange);
    GET_STR(env,obj,cls,"userID",        out.UserID,       sizeof(out.UserID));
    GET_STR(env,obj,cls,"instrumentID",  out.InstrumentID, sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"investUnitID",  out.InvestUnitID, sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",     out.IPAddress,    sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",    out.MacAddress,   sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_MKInputOrderAction(JNIEnv* env, jobject obj, CThostFtdcMKInputOrderActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,     sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,   sizeof(out.InvestorID));
    GET_INT(env,obj,cls,"orderActionRef",out.OrderActionRef);
    GET_INT(env,obj,cls,"requestID",     out.RequestID);
    GET_INT(env,obj,cls,"frontID",       out.FrontID);
    GET_INT(env,obj,cls,"sessionID",     out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,   sizeof(out.ExchangeID));
    GET_CHR(env,obj,cls,"actionFlag",    out.ActionFlag);
    GET_STR(env,obj,cls,"userID",        out.UserID,       sizeof(out.UserID));
    GET_STR(env,obj,cls,"instrumentID",  out.InstrumentID, sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"investUnitID",  out.InvestUnitID, sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",     out.IPAddress,    sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",    out.MacAddress,   sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputExecOrder(JNIEnv* env, jobject obj, CThostFtdcInputExecOrderField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",           out.BrokerID,           sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",         out.InvestorID,         sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",       out.InstrumentID,       sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"execOrderRef",       out.ExecOrderRef,       sizeof(out.ExecOrderRef));
    GET_STR(env,obj,cls,"userID",             out.UserID,             sizeof(out.UserID));
    GET_INT(env,obj,cls,"volume",             out.Volume);
    GET_INT(env,obj,cls,"requestID",          out.RequestID);
    GET_STR(env,obj,cls,"businessUnit",       out.BusinessUnit,       sizeof(out.BusinessUnit));
    GET_CHR(env,obj,cls,"offsetFlag",         out.OffsetFlag);
    GET_CHR(env,obj,cls,"hedgeFlag",          out.HedgeFlag);
    GET_CHR(env,obj,cls,"actionType",         out.ActionType);
    GET_CHR(env,obj,cls,"posiDirection",      out.PosiDirection);
    GET_CHR(env,obj,cls,"reservePositionFlag",out.ReservePositionFlag);
    GET_CHR(env,obj,cls,"closeFlag",          out.CloseFlag);
    GET_STR(env,obj,cls,"exchangeID",         out.ExchangeID,         sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"investUnitID",       out.InvestUnitID,       sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"accountID",          out.AccountID,          sizeof(out.AccountID));
    GET_STR(env,obj,cls,"currencyID",         out.CurrencyID,         sizeof(out.CurrencyID));
    GET_STR(env,obj,cls,"clientID",           out.ClientID,           sizeof(out.ClientID));
    GET_STR(env,obj,cls,"ipAddress",          out.IPAddress,          sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",         out.MacAddress,         sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputExecOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputExecOrderActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",           out.BrokerID,         sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",         out.InvestorID,       sizeof(out.InvestorID));
    GET_INT(env,obj,cls,"execOrderActionRef", out.ExecOrderActionRef);
    GET_STR(env,obj,cls,"execOrderRef",       out.ExecOrderRef,     sizeof(out.ExecOrderRef));
    GET_INT(env,obj,cls,"requestID",          out.RequestID);
    GET_INT(env,obj,cls,"frontID",            out.FrontID);
    GET_INT(env,obj,cls,"sessionID",          out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",         out.ExchangeID,       sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"execOrderSysID",     out.ExecOrderSysID,   sizeof(out.ExecOrderSysID));
    GET_CHR(env,obj,cls,"actionFlag",         out.ActionFlag);
    GET_STR(env,obj,cls,"userID",             out.UserID,           sizeof(out.UserID));
    GET_STR(env,obj,cls,"instrumentID",       out.InstrumentID,     sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"investUnitID",       out.InvestUnitID,     sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",          out.IPAddress,        sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",         out.MacAddress,       sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputForQuote(JNIEnv* env, jobject obj, CThostFtdcInputForQuoteField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"forQuoteRef", out.ForQuoteRef, sizeof(out.ForQuoteRef));
    GET_STR(env,obj,cls,"userID",      out.UserID,      sizeof(out.UserID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"investUnitID",out.InvestUnitID,sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",   out.IPAddress,   sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",  out.MacAddress,  sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputQuote(JNIEnv* env, jobject obj, CThostFtdcInputQuoteField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,      sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,    sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",  out.InstrumentID,  sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"quoteRef",      out.QuoteRef,      sizeof(out.QuoteRef));
    GET_STR(env,obj,cls,"userID",        out.UserID,        sizeof(out.UserID));
    GET_DBL(env,obj,cls,"askPrice",      out.AskPrice);
    GET_DBL(env,obj,cls,"bidPrice",      out.BidPrice);
    GET_INT(env,obj,cls,"askVolume",     out.AskVolume);
    GET_INT(env,obj,cls,"bidVolume",     out.BidVolume);
    GET_INT(env,obj,cls,"requestID",     out.RequestID);
    GET_STR(env,obj,cls,"businessUnit",  out.BusinessUnit,  sizeof(out.BusinessUnit));
    GET_CHR(env,obj,cls,"askOffsetFlag", out.AskOffsetFlag);
    GET_CHR(env,obj,cls,"bidOffsetFlag", out.BidOffsetFlag);
    GET_CHR(env,obj,cls,"askHedgeFlag",  out.AskHedgeFlag);
    GET_CHR(env,obj,cls,"bidHedgeFlag",  out.BidHedgeFlag);
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,    sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"investUnitID",  out.InvestUnitID,  sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"clientID",      out.ClientID,      sizeof(out.ClientID));
    GET_STR(env,obj,cls,"ipAddress",     out.IPAddress,     sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",    out.MacAddress,    sizeof(out.MacAddress));
    GET_STR(env,obj,cls,"forQuoteSysID", out.ForQuoteSysID, sizeof(out.ForQuoteSysID));
    GET_STR(env,obj,cls,"askOrderRef",   out.AskOrderRef,   sizeof(out.AskOrderRef));
    GET_STR(env,obj,cls,"bidOrderRef",   out.BidOrderRef,   sizeof(out.BidOrderRef));
    END_FROM_JAVA
}

void FromJava_InputQuoteAction(JNIEnv* env, jobject obj, CThostFtdcInputQuoteActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,     sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,   sizeof(out.InvestorID));
    GET_INT(env,obj,cls,"quoteActionRef",out.QuoteActionRef);
    GET_STR(env,obj,cls,"quoteRef",      out.QuoteRef,     sizeof(out.QuoteRef));
    GET_INT(env,obj,cls,"requestID",     out.RequestID);
    GET_INT(env,obj,cls,"frontID",       out.FrontID);
    GET_INT(env,obj,cls,"sessionID",     out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"quoteSysID",    out.QuoteSysID,   sizeof(out.QuoteSysID));
    GET_CHR(env,obj,cls,"actionFlag",    out.ActionFlag);
    GET_STR(env,obj,cls,"userID",        out.UserID,       sizeof(out.UserID));
    GET_STR(env,obj,cls,"instrumentID",  out.InstrumentID, sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"investUnitID",  out.InvestUnitID, sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"clientID",      out.ClientID,     sizeof(out.ClientID));
    GET_STR(env,obj,cls,"ipAddress",     out.IPAddress,    sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",    out.MacAddress,   sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputBatchOrderAction(JNIEnv* env, jobject obj, CThostFtdcInputBatchOrderActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,     sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,   sizeof(out.InvestorID));
    GET_INT(env,obj,cls,"orderActionRef",out.OrderActionRef);
    GET_INT(env,obj,cls,"requestID",     out.RequestID);
    GET_INT(env,obj,cls,"frontID",       out.FrontID);
    GET_INT(env,obj,cls,"sessionID",     out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"userID",        out.UserID,       sizeof(out.UserID));
    GET_STR(env,obj,cls,"investUnitID",  out.InvestUnitID, sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",     out.IPAddress,    sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",    out.MacAddress,   sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputOptionSelfClose(JNIEnv* env, jobject obj, CThostFtdcInputOptionSelfCloseField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",      out.InvestorID,      sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",    out.InstrumentID,    sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"userID",          out.UserID,          sizeof(out.UserID));
    GET_INT(env,obj,cls,"volume",          out.Volume);
    GET_INT(env,obj,cls,"requestID",       out.RequestID);
    GET_STR(env,obj,cls,"businessUnit",    out.BusinessUnit,    sizeof(out.BusinessUnit));
    GET_CHR(env,obj,cls,"hedgeFlag",       out.HedgeFlag);
    GET_CHR(env,obj,cls,"optSelfCloseFlag",out.OptSelfCloseFlag);
    GET_STR(env,obj,cls,"exchangeID",      out.ExchangeID,      sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"investUnitID",    out.InvestUnitID,    sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"accountID",       out.AccountID,       sizeof(out.AccountID));
    GET_STR(env,obj,cls,"currencyID",      out.CurrencyID,      sizeof(out.CurrencyID));
    GET_STR(env,obj,cls,"clientID",        out.ClientID,        sizeof(out.ClientID));
    GET_STR(env,obj,cls,"ipAddress",       out.IPAddress,       sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",      out.MacAddress,      sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputOptionSelfCloseAction(JNIEnv* env, jobject obj, CThostFtdcInputOptionSelfCloseActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",              out.BrokerID,             sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",            out.InvestorID,           sizeof(out.InvestorID));
    
    GET_INT(env,obj,cls,"requestID",             out.RequestID);
    GET_INT(env,obj,cls,"frontID",               out.FrontID);
    GET_INT(env,obj,cls,"sessionID",             out.SessionID);
    GET_STR(env,obj,cls,"exchangeID",            out.ExchangeID,           sizeof(out.ExchangeID));
    GET_CHR(env,obj,cls,"actionFlag",            out.ActionFlag);
    GET_STR(env,obj,cls,"userID",                out.UserID,               sizeof(out.UserID));
    GET_STR(env,obj,cls,"instrumentID",          out.InstrumentID,         sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"investUnitID",          out.InvestUnitID,         sizeof(out.InvestUnitID));
    GET_STR(env,obj,cls,"ipAddress",             out.IPAddress,            sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",            out.MacAddress,           sizeof(out.MacAddress));
    END_FROM_JAVA
}

void FromJava_InputCombAction(JNIEnv* env, jobject obj, CThostFtdcInputCombActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",     out.BrokerID,     sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",   out.InvestorID,   sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID", out.InstrumentID, sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"combActionRef",out.CombActionRef,sizeof(out.CombActionRef));
    GET_STR(env,obj,cls,"userID",       out.UserID,       sizeof(out.UserID));
    GET_CHR(env,obj,cls,"direction",    out.Direction);
    GET_INT(env,obj,cls,"volume",       out.Volume);
    GET_CHR(env,obj,cls,"combDirection",out.CombDirection);
    GET_CHR(env,obj,cls,"hedgeFlag",    out.HedgeFlag);
    GET_STR(env,obj,cls,"exchangeID",   out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"ipAddress",    out.IPAddress,    sizeof(out.IPAddress));
    GET_STR(env,obj,cls,"macAddress",   out.MacAddress,   sizeof(out.MacAddress));
    GET_STR(env,obj,cls,"investUnitID", out.InvestUnitID, sizeof(out.InvestUnitID));
    END_FROM_JAVA
}

void FromJava_InputOffsetSetting(JNIEnv* env, jobject obj, CThostFtdcInputOffsetSettingField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    END_FROM_JAVA
}

void FromJava_UserPasswordUpdate(JNIEnv* env, jobject obj, CThostFtdcUserPasswordUpdateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",   out.BrokerID,   sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"userID",     out.UserID,     sizeof(out.UserID));
    GET_STR(env,obj,cls,"oldPassword",out.OldPassword,sizeof(out.OldPassword));
    GET_STR(env,obj,cls,"newPassword",out.NewPassword,sizeof(out.NewPassword));
    END_FROM_JAVA
}

/* ---- Qry FromJava ---- */

void FromJava_QryOrder(JNIEnv* env, jobject obj, CThostFtdcQryOrderField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",      out.InvestorID,      sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",    out.InstrumentID,    sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",      out.ExchangeID,      sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"orderSysID",      out.OrderSysID,      sizeof(out.OrderSysID));
    GET_STR(env,obj,cls,"insertTimeStart", out.InsertTimeStart, sizeof(out.InsertTimeStart));
    GET_STR(env,obj,cls,"insertTimeEnd",   out.InsertTimeEnd,   sizeof(out.InsertTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryTrade(JNIEnv* env, jobject obj, CThostFtdcQryTradeField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",      out.BrokerID,      sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",    out.InvestorID,    sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",  out.InstrumentID,  sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",    out.ExchangeID,    sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"tradeID",       out.TradeID,       sizeof(out.TradeID));
    GET_STR(env,obj,cls,"tradeTimeStart",out.TradeTimeStart,sizeof(out.TradeTimeStart));
    GET_STR(env,obj,cls,"tradeTimeEnd",  out.TradeTimeEnd,  sizeof(out.TradeTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryInvestorPos(JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    END_FROM_JAVA
}

void FromJava_QryTradingAcct(JNIEnv* env, jobject obj, CThostFtdcQryTradingAccountField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"currencyID",out.CurrencyID,sizeof(out.CurrencyID));
    END_FROM_JAVA
}

void FromJava_QryInvestor(JNIEnv* env, jobject obj, CThostFtdcQryInvestorField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    END_FROM_JAVA
}

void FromJava_QryTradingCode(JNIEnv* env, jobject obj, CThostFtdcQryTradingCodeField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",   out.BrokerID,   sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID", out.InvestorID, sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"exchangeID", out.ExchangeID, sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"clientID",   out.ClientID,   sizeof(out.ClientID));
    GET_CHR(env,obj,cls,"clientIDType",out.ClientIDType);
    END_FROM_JAVA
}

void FromJava_QryInstrMarginRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentMarginRateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_CHR(env,obj,cls,"hedgeFlag",   out.HedgeFlag);
    END_FROM_JAVA
}

void FromJava_QryInstrCommRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentCommissionRateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    END_FROM_JAVA
}

void FromJava_QryExchange(JNIEnv* env, jobject obj, CThostFtdcQryExchangeField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"exchangeID",out.ExchangeID,sizeof(out.ExchangeID));
    END_FROM_JAVA
}

void FromJava_QryProduct(JNIEnv* env, jobject obj, CThostFtdcQryProductField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"productID",  out.ProductID,  sizeof(out.ProductID));
    GET_CHR(env,obj,cls,"productClass",out.ProductClass);
    END_FROM_JAVA
}

void FromJava_QryInstrument(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"instrumentID", out.InstrumentID, sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",   out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"exchangeInstID",out.ExchangeInstID,sizeof(out.ExchangeInstID));
    GET_STR(env,obj,cls,"productID",    out.ProductID,    sizeof(out.ProductID));
    END_FROM_JAVA
}

void FromJava_QryCombInstrument(JNIEnv* env, jobject obj, CThostFtdcQryCombInstrumentField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"exchangeID",     out.ExchangeID,     sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"productID",      out.ProductID,      sizeof(out.ProductID));
   
    END_FROM_JAVA
}

void FromJava_QryDepthMD(JNIEnv* env, jobject obj, CThostFtdcQryDepthMarketDataField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
   
    END_FROM_JAVA
}

void FromJava_QryInstrStatus(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentStatusField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"exchangeID",   out.ExchangeID,   sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"exchangeInstID",out.ExchangeInstID,sizeof(out.ExchangeInstID));
    END_FROM_JAVA
}

void FromJava_QryInvestorPosDetail(JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionDetailField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));


    END_FROM_JAVA
}

void FromJava_QryExchMarginRate(JNIEnv* env, jobject obj, CThostFtdcQryExchangeMarginRateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_CHR(env,obj,cls,"hedgeFlag",   out.HedgeFlag);
    END_FROM_JAVA
}

void FromJava_QryExchMarginRateAdj(JNIEnv* env, jobject obj, CThostFtdcQryExchangeMarginRateAdjustField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_CHR(env,obj,cls,"hedgeFlag",   out.HedgeFlag);
    END_FROM_JAVA
}

void FromJava_QryOptInstrTradeCost(JNIEnv* env, jobject obj, CThostFtdcQryOptionInstrTradeCostField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",      out.InvestorID,      sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",    out.InstrumentID,    sizeof(out.InstrumentID));
    GET_CHR(env,obj,cls,"hedgeFlag",       out.HedgeFlag);
    END_FROM_JAVA
}

void FromJava_QryOptInstrCommRate(JNIEnv* env, jobject obj, CThostFtdcQryOptionInstrCommRateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    END_FROM_JAVA
}

void FromJava_QryExecOrder(JNIEnv* env, jobject obj, CThostFtdcQryExecOrderField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",          out.BrokerID,          sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",        out.InvestorID,        sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",      out.InstrumentID,      sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",        out.ExchangeID,        sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"execOrderSysID",    out.ExecOrderSysID,    sizeof(out.ExecOrderSysID));
    GET_STR(env,obj,cls,"insertTimeStart",   out.InsertTimeStart,   sizeof(out.InsertTimeStart));
    GET_STR(env,obj,cls,"insertTimeEnd",     out.InsertTimeEnd,     sizeof(out.InsertTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryForQuote(JNIEnv* env, jobject obj, CThostFtdcQryForQuoteField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",      out.InvestorID,      sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",    out.InstrumentID,    sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",      out.ExchangeID,      sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"insertTimeStart", out.InsertTimeStart, sizeof(out.InsertTimeStart));
    GET_STR(env,obj,cls,"insertTimeEnd",   out.InsertTimeEnd,   sizeof(out.InsertTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryQuote(JNIEnv* env, jobject obj, CThostFtdcQryQuoteField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",        out.BrokerID,        sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",      out.InvestorID,      sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",    out.InstrumentID,    sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",      out.ExchangeID,      sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"quoteSysID",      out.QuoteSysID,      sizeof(out.QuoteSysID));
    GET_STR(env,obj,cls,"insertTimeStart", out.InsertTimeStart, sizeof(out.InsertTimeStart));
    GET_STR(env,obj,cls,"insertTimeEnd",   out.InsertTimeEnd,   sizeof(out.InsertTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryOptionSelfClose(JNIEnv* env, jobject obj, CThostFtdcQryOptionSelfCloseField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",           out.BrokerID,           sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",         out.InvestorID,         sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",       out.InstrumentID,       sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",         out.ExchangeID,         sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"insertTimeStart",    out.InsertTimeStart,    sizeof(out.InsertTimeStart));
    GET_STR(env,obj,cls,"insertTimeEnd",      out.InsertTimeEnd,      sizeof(out.InsertTimeEnd));
    END_FROM_JAVA
}

void FromJava_QryCombAction(JNIEnv* env, jobject obj, CThostFtdcQryCombActionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    END_FROM_JAVA
}

void FromJava_QryInvestorPosForComb(JNIEnv* env, jobject obj, CThostFtdcQryInvestorPositionForCombField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    END_FROM_JAVA
}

void FromJava_QryRCAMSProdMargin(JNIEnv* env, jobject obj, CThostFtdcQryRCAMSInvestorProdMarginField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    END_FROM_JAVA
}

void FromJava_QryRCAMSCombPos(JNIEnv* env, jobject obj, CThostFtdcQryRCAMSInvestorCombPositionField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    END_FROM_JAVA
}

void FromJava_QrySPBMDetail(JNIEnv* env, jobject obj, CThostFtdcQryInvestorProdSPBMDetailField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"exchangeID",out.ExchangeID,sizeof(out.ExchangeID));
    END_FROM_JAVA
}

void FromJava_QrySPMMGroupMargin(JNIEnv* env, jobject obj, CThostFtdcQrySPMMInvestorCommodityGroupMarginField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",       out.BrokerID,       sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",     out.InvestorID,     sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"commodityGroupID",out.CommodityGroupID,sizeof(out.CommodityGroupID));
    END_FROM_JAVA
}

void FromJava_QryRULEProdMargin(JNIEnv* env, jobject obj, CThostFtdcQryRULEInvestorProdMarginField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",  out.BrokerID,  sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",out.InvestorID,sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"exchangeID",out.ExchangeID,sizeof(out.ExchangeID));
    END_FROM_JAVA
}

void FromJava_QryControlParam(JNIEnv* env, jobject obj, CThostFtdcQryControlParamField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    END_FROM_JAVA
}

void FromJava_QryOffsetSetting(JNIEnv* env, jobject obj, CThostFtdcQryOffsetSettingField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    END_FROM_JAVA
}

void FromJava_QryInstrOrderCommRate(JNIEnv* env, jobject obj, CThostFtdcQryInstrumentOrderCommRateField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"investorID",  out.InvestorID,  sizeof(out.InvestorID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    GET_CHR(env,obj,cls,"hedgeFlag",   out.HedgeFlag);
    END_FROM_JAVA
}

void FromJava_QryForQuoteParam(JNIEnv* env, jobject obj, CThostFtdcQryForQuoteParamField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"brokerID",    out.BrokerID,    sizeof(out.BrokerID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    GET_STR(env,obj,cls,"instrumentID",out.InstrumentID,sizeof(out.InstrumentID));
    END_FROM_JAVA
}

void FromJava_QryTraderOffer(JNIEnv* env, jobject obj, CThostFtdcQryTraderOfferField& out) {
    BEGIN_FROM_JAVA
    GET_STR(env,obj,cls,"traderID",    out.TraderID,    sizeof(out.TraderID));
    GET_STR(env,obj,cls,"exchangeID",  out.ExchangeID,  sizeof(out.ExchangeID));
    END_FROM_JAVA
}
