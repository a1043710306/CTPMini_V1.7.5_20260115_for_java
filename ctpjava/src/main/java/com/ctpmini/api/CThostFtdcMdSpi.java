package com.ctpmini.api;

import com.ctpmini.struct.*;

/**
 * 行情回调接口（SPI）
 * 对应 C++ 类: CThostFtdcMdSpi
 *
 * 用户需继承此类并重写感兴趣的回调方法。
 * 所有方法均提供空实现，可按需选择性覆盖。
 */
public class CThostFtdcMdSpi {

    /**
     * 当客户端与交易后台建立起通信连接时（还未登录前），该方法被调用。
     */
    public void OnFrontConnected() {}

    /**
     * 当客户端与交易后台通信连接断开时，该方法被调用。
     * 当发生这个情况后，API会自动重新连接，客户端可不做处理。
     *
     * @param nReason 错误原因
     *                0x1001 网络读失败
     *                0x1002 网络写失败
     *                0x2001 接收心跳超时
     *                0x2002 发送心跳失败
     *                0x2003 收到错误报文
     */
    public void OnFrontDisconnected(int nReason) {}

    /**
     * 心跳超时警告。当长时间未收到报文时，该方法被调用。
     *
     * @param nTimeLapse 距上次接收报文的时间
     */
    public void OnHeartBeatWarning(int nTimeLapse) {}

    /**
     * 登录请求响应
     *
     * @param pRspUserLogin 用户登录应答
     * @param pRspInfo      响应信息
     * @param nRequestID    请求ID
     * @param bIsLast       是否为最后一条响应
     */
    public void OnRspUserLogin(CThostFtdcRspUserLoginField pRspUserLogin,
                               CThostFtdcRspInfoField pRspInfo,
                               int nRequestID, boolean bIsLast) {}

    /**
     * 登出请求响应
     *
     * @param pUserLogout 用户登出域
     * @param pRspInfo    响应信息
     * @param nRequestID  请求ID
     * @param bIsLast     是否为最后一条响应
     */
    public void OnRspUserLogout(CThostFtdcUserLogoutField pUserLogout,
                                CThostFtdcRspInfoField pRspInfo,
                                int nRequestID, boolean bIsLast) {}

    /**
     * 错误应答
     *
     * @param pRspInfo   响应信息
     * @param nRequestID 请求ID
     * @param bIsLast    是否为最后一条响应
     */
    public void OnRspError(CThostFtdcRspInfoField pRspInfo,
                           int nRequestID, boolean bIsLast) {}

    /**
     * 订阅行情应答
     *
     * @param pSpecificInstrument 指定合约
     * @param pRspInfo            响应信息
     * @param nRequestID          请求ID
     * @param bIsLast             是否为最后一条响应
     */
    public void OnRspSubMarketData(CThostFtdcSpecificInstrumentField pSpecificInstrument,
                                   CThostFtdcRspInfoField pRspInfo,
                                   int nRequestID, boolean bIsLast) {}

    /**
     * 取消订阅行情应答
     *
     * @param pSpecificInstrument 指定合约
     * @param pRspInfo            响应信息
     * @param nRequestID          请求ID
     * @param bIsLast             是否为最后一条响应
     */
    public void OnRspUnSubMarketData(CThostFtdcSpecificInstrumentField pSpecificInstrument,
                                     CThostFtdcRspInfoField pRspInfo,
                                     int nRequestID, boolean bIsLast) {}

    /**
     * 订阅询价应答
     *
     * @param pSpecificInstrument 指定合约
     * @param pRspInfo            响应信息
     * @param nRequestID          请求ID
     * @param bIsLast             是否为最后一条响应
     */
    public void OnRspSubForQuoteRsp(CThostFtdcSpecificInstrumentField pSpecificInstrument,
                                    CThostFtdcRspInfoField pRspInfo,
                                    int nRequestID, boolean bIsLast) {}

    /**
     * 取消订阅询价应答
     *
     * @param pSpecificInstrument 指定合约
     * @param pRspInfo            响应信息
     * @param nRequestID          请求ID
     * @param bIsLast             是否为最后一条响应
     */
    public void OnRspUnSubForQuoteRsp(CThostFtdcSpecificInstrumentField pSpecificInstrument,
                                      CThostFtdcRspInfoField pRspInfo,
                                      int nRequestID, boolean bIsLast) {}

    /**
     * 深度行情通知（行情推送）
     *
     * @param pDepthMarketData 深度行情
     */
    public void OnRtnDepthMarketData(CThostFtdcDepthMarketDataField pDepthMarketData) {}

    /**
     * 逐笔行情通知（MBL行情推送）
     *
     * @param pMBLMarketData MBL行情
     */
    public void OnRtnMBLMarketData(CThostFtdcMBLMarketDataField pMBLMarketData) {}

    /**
     * 询价通知
     *
     * @param pForQuoteRsp 询价应答域
     */
    public void OnRtnForQuoteRsp(CThostFtdcForQuoteRspField pForQuoteRsp) {}
}
