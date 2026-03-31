package com.ctpmini.api;

import com.ctpmini.struct.*;

/**
 * 行情API接口
 * 对应 C++ 类: CThostFtdcMdApi
 *
 * 使用方式（通过JNI桥接本地库）：
 * <pre>
 * CThostFtdcMdApi mdApi = CThostFtdcMdApi.CreateFtdcMdApi("./flow/");
 * mdApi.RegisterSpi(mySpi);
 * mdApi.RegisterFront("tcp://127.0.0.1:27213");
 * mdApi.Init();
 * </pre>
 *
 * 注意：本类为Java接口层定义，实际调用需通过JNI加载 libthostmduserapi.so 本地库实现。
 */
public abstract class CThostFtdcMdApi {

    /**
     * 创建MdApi实例（工厂方法，需要JNI实现）
     *
     * @param pszFlowPath 存储订阅信息文件的目录，默认为当前目录
     * @param bIsUsingUdp 是否使用UDP（mini版本不使用）
     * @param bIsMulticast 是否使用组播（mini版本不使用，API根据连接的后台自动判断）
     * @return MdApi实例
     */
    public static native CThostFtdcMdApi CreateFtdcMdApi(String pszFlowPath,
                                                          boolean bIsUsingUdp,
                                                          boolean bIsMulticast);

    /**
     * 创建MdApi实例（使用默认参数）
     *
     * @param pszFlowPath 存储订阅信息文件的目录
     * @return MdApi实例
     */
    public static CThostFtdcMdApi CreateFtdcMdApi(String pszFlowPath) {
        return CreateFtdcMdApi(pszFlowPath, false, false);
    }

    /**
     * 获取API版本信息
     *
     * @return 版本号字符串
     */
    public static native String GetApiVersion();

    /**
     * 删除接口对象本身（释放资源）
     * 不再使用本接口对象时，调用该函数删除接口对象
     */
    public abstract void Release();

    /**
     * 初始化
     * 初始化运行环境，只有调用后，接口才开始工作
     *
     * @param bContinuousm 是否保持连接（false = 断线重连）
     */
    public abstract void Init(boolean bContinuousm);

    /**
     * 初始化（默认参数）
     */
    public void Init() {
        Init(false);
    }

    /**
     * 等待接口线程结束运行
     *
     * @return 线程退出代码
     */
    public abstract int Join();

    /**
     * 获取当前交易日
     *
     * @return 交易日字符串 (yyyyMMdd)，只有登录成功后才能获取正确的交易日
     */
    public abstract String GetTradingDay();

    /**
     * 注册前置机网络地址
     *
     * @param pszFrontAddress 前置机网络地址，格式: "tcp://ip:port"，例如: "tcp://127.0.0.1:17001"
     */
    public abstract void RegisterFront(String pszFrontAddress);

    /**
     * 注册回调接口（SPI）
     *
     * @param pSpi 派生自回调接口类的实例
     */
    public abstract void RegisterSpi(CThostFtdcMdSpi pSpi);

    /**
     * 订阅行情
     *
     * @param ppInstrumentID 合约ID数组
     * @param nCount         要订阅/退订的合约个数
     * @return 0=成功，非0=失败
     */
    public abstract int SubscribeMarketData(String[] ppInstrumentID, int nCount);

    /**
     * 退订行情
     *
     * @param ppInstrumentID 合约ID数组
     * @param nCount         要退订的合约个数
     * @return 0=成功，非0=失败
     */
    public abstract int UnSubscribeMarketData(String[] ppInstrumentID, int nCount);

    /**
     * 订阅询价
     *
     * @param ppInstrumentID 合约ID数组
     * @param nCount         要订阅的合约个数
     * @return 0=成功，非0=失败
     */
    public abstract int SubscribeForQuoteRsp(String[] ppInstrumentID, int nCount);

    /**
     * 退订询价
     *
     * @param ppInstrumentID 合约ID数组
     * @param nCount         要退订的合约个数
     * @return 0=成功，非0=失败
     */
    public abstract int UnSubscribeForQuoteRsp(String[] ppInstrumentID, int nCount);

    /**
     * 用户登录请求
     *
     * @param pReqUserLoginField 登录请求域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLogin(CThostFtdcReqUserLoginField pReqUserLoginField, int nRequestID);

    /**
     * 用户加密登录请求
     *
     * @param pReqUserLoginField 登录请求域
     * @param nRequestID         请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLoginEncrypt(CThostFtdcReqUserLoginField pReqUserLoginField, int nRequestID);

    /**
     * 登出请求
     *
     * @param pUserLogout 登出请求域
     * @param nRequestID  请求ID
     * @return 0=成功，非0=失败
     */
    public abstract int ReqUserLogout(CThostFtdcUserLogoutField pUserLogout, int nRequestID);
}
